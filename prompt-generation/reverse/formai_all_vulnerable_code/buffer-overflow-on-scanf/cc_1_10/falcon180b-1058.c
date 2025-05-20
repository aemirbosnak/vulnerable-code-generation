//Falcon-180B DATASET v1.0 Category: Error handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ERRORS 10

typedef struct {
    char *filename;
    int line_number;
    char *message;
} Error;

Error errors[MAX_ERRORS];
int error_count = 0;

void add_error(char *filename, int line_number, char *message) {
    if (error_count >= MAX_ERRORS) {
        fprintf(stderr, "Error: too many errors\n");
        exit(1);
    }

    errors[error_count].filename = filename;
    errors[error_count].line_number = line_number;
    errors[error_count].message = message;

    error_count++;
}

void print_errors() {
    if (error_count == 0) {
        fprintf(stdout, "No errors found\n");
        return;
    }

    fprintf(stdout, "Errors found:\n");
    for (int i = 0; i < error_count; i++) {
        fprintf(stdout, "In file %s, line %d: %s\n", errors[i].filename, errors[i].line_number, errors[i].message);
    }
}

int main() {
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    FILE *file;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        add_error(filename, 0, "Failed to open file");
        return 1;
    }

    int line_number = 1;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *newline = strdup(line);
        char *token = strtok(newline, " ");
        while (token!= NULL) {
            if (strcmp(token, "error") == 0) {
                add_error(filename, line_number, "Invalid syntax");
                break;
            }
            token = strtok(NULL, " ");
        }
        free(newline);
        line_number++;
    }

    fclose(file);

    if (error_count > 0) {
        print_errors();
        return 1;
    }

    return 0;
}