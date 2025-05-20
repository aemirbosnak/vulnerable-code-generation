//Falcon-180B DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

char *read_line(FILE *file) {
    char *line = NULL;
    size_t line_capacity = 0;
    ssize_t bytes_read;

    while ((bytes_read = getline(&line, &line_capacity, file))!= -1) {
        if (bytes_read >= MAX_LINE_LENGTH) {
            fprintf(stderr, "Line is too long: %.*s\n", (int) bytes_read, line);
            exit(EXIT_FAILURE);
        }

        line[bytes_read - 1] = '\0';
    }

    return line;
}

void write_line(FILE *file, const char *line) {
    if (fputs(line, file) == EOF) {
        fprintf(stderr, "Failed to write line: %s\n", line);
        exit(EXIT_FAILURE);
    }
}

int main() {
    FILE *input_file = NULL;
    FILE *output_file = NULL;
    char *line = NULL;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Failed to open input file\n");
        exit(EXIT_FAILURE);
    }

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        fprintf(stderr, "Failed to open output file\n");
        exit(EXIT_FAILURE);
    }

    while ((line = read_line(input_file))!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (isalpha(token[0])) {
                write_line(output_file, token);
            }

            token = strtok(NULL, " ");
        }

        write_line(output_file, "\n");
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}