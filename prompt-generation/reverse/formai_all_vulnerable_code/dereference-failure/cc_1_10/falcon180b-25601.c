//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

char *read_line(FILE *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    line = malloc(MAX_LINE_LEN);
    if (line == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file))!= -1) {
        if (read > 0 && line[read - 1] == '\n') {
            line[--read] = '\0';
        } else {
            line = realloc(line, len + 1);
            if (line == NULL) {
                fprintf(stderr, "Error: Failed to reallocate memory.\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    return line;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Failed to open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Failed to open output file.\n");
        fclose(input_file);
        return 1;
    }

    char *line;
    while ((line = read_line(input_file))!= NULL) {
        fputs(line, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}