//Falcon-180B DATASET v1.0 Category: Error handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ERROR_LENGTH 256

typedef struct {
    char *message;
    int line_number;
} Error;

void add_error(Error *errors, int count, char *message, int line_number) {
    if (count >= MAX_ERROR_LENGTH) {
        printf("Error: Too many errors.\n");
        exit(1);
    }
    errors[count].message = strdup(message);
    errors[count].line_number = line_number;
    count++;
}

void print_errors(Error errors[], int count) {
    printf("Errors:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", errors[i].line_number, errors[i].message);
    }
}

char *read_line(FILE *file) {
    char *line = NULL;
    size_t capacity = 0;
    ssize_t read;

    while ((read = getline(&line, &capacity, file))!= -1) {
        if (line[read - 1] == '\n') {
            line[--read] = '\0';
        } else {
            line = realloc(line, read + 1);
            line[read] = '\0';
        }
    }

    return line;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    Error errors[MAX_ERROR_LENGTH] = {0};
    int error_count = 0;

    char *line = NULL;
    while ((line = read_line(file))!= NULL) {
        int line_number = 1;
        for (char *p = line; *p!= '\0'; p++) {
            if (*p == '\n') {
                line_number++;
            }
        }

        if (strstr(line, "error")!= NULL) {
            char *message = strdup(line);
            add_error(errors, error_count, message, line_number);
        }

        free(line);
        line = NULL;
    }

    fclose(file);

    if (error_count > 0) {
        print_errors(errors, error_count);
        return 1;
    } else {
        printf("No errors found.\n");
        return 0;
    }
}