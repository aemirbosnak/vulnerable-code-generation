//Falcon-180B DATASET v1.0 Category: Error handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ERROR_STRING_LENGTH 256

typedef struct {
    char *message;
    int line_number;
} Error;

void error_init(Error *error) {
    error->message = NULL;
    error->line_number = 0;
}

void error_destroy(Error *error) {
    if (error->message!= NULL) {
        free(error->message);
        error->message = NULL;
    }
}

void error_set(Error *error, char *message, int line_number) {
    if (error->message!= NULL) {
        free(error->message);
        error->message = NULL;
    }
    error->message = strdup(message);
    error->line_number = line_number;
}

bool error_is_set(Error *error) {
    return error->message!= NULL;
}

char *error_message(Error *error) {
    return error->message;
}

int error_line_number(Error *error) {
    return error->line_number;
}

char *read_file(const char *filename, int *file_size) {
    char *buffer = NULL;
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        char error_buffer[MAX_ERROR_STRING_LENGTH];
        strerror_r(errno, error_buffer, MAX_ERROR_STRING_LENGTH);
        fprintf(stderr, "Error opening file '%s': %s\n", filename, error_buffer);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    *file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = malloc(*file_size + 1);
    if (buffer == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }

    fread(buffer, *file_size, 1, file);
    fclose(file);

    return buffer;
}

int count_lines(char *buffer, int buffer_size) {
    int line_count = 0;
    bool in_comment = false;

    for (int i = 0; i < buffer_size; i++) {
        if (buffer[i] == '\n') {
            line_count++;
        } else if (buffer[i] == '/' && buffer[i + 1] == '*') {
            in_comment = true;
        } else if (buffer[i] == '*' && buffer[i + 1] == '/') {
            in_comment = false;
        }
    }

    return line_count;
}

int main() {
    Error error;
    error_init(&error);

    char *filename = "example.c";
    char *buffer = read_file(filename, &error.line_number);

    if (error_is_set(&error)) {
        return 1;
    }

    int line_count = count_lines(buffer, error.line_number);

    printf("File '%s' has %d lines\n", filename, line_count);

    error_destroy(&error);
    free(buffer);

    return 0;
}