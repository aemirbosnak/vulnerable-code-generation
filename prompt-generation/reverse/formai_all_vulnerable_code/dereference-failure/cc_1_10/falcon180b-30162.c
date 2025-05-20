//Falcon-180B DATASET v1.0 Category: Error handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#define MAX_LINE_LENGTH 1024
#define MAX_STR_LENGTH 256
#define MAX_ERRORS 100

typedef struct {
    char *message;
    int line;
} Error;

int error_count = 0;
Error errors[MAX_ERRORS];

void add_error(char *message, int line) {
    if (error_count >= MAX_ERRORS) {
        fprintf(stderr, "Error: Too many errors\n");
        exit(1);
    }
    errors[error_count].message = strdup(message);
    errors[error_count].line = line;
    error_count++;
}

void print_errors() {
    printf("Errors:\n");
    for (int i = 0; i < error_count; i++) {
        printf("%d: %s\n", errors[i].line, errors[i].message);
    }
}

void clear_errors() {
    error_count = 0;
}

char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        add_error("Unexpected end of file", 0);
        return NULL;
    }
    line[strcspn(line, "\n")] = '\0';
    return line;
}

int main() {
    FILE *file = fopen("example.c", "r");
    if (file == NULL) {
        add_error("Failed to open file", __LINE__);
        return 1;
    }

    char *line = read_line(file);
    while (line!= NULL) {
        if (strstr(line, "error")!= NULL) {
            add_error("Found error in code", __LINE__);
        }
        line = read_line(file);
    }

    fclose(file);

    if (error_count > 0) {
        print_errors();
        return 1;
    }

    return 0;
}