//Falcon-180B DATASET v1.0 Category: Error handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_FILE 100

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", strerror(errno));
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", strerror(errno));
        return 1;
    }

    char line[MAX_LINE];
    char *token;
    int line_number = 1;

    while (fgets(line, MAX_LINE, input_file)!= NULL) {
        line_number++;

        // Remove leading and trailing whitespace
        char *trimmed_line = line;
        while (isspace(*trimmed_line)) {
            trimmed_line++;
        }
        while (isspace(*(trimmed_line + strlen(trimmed_line) - 1))) {
            trimmed_line[strlen(trimmed_line) - 1] = '\0';
        }

        // Check for empty lines
        if (trimmed_line == line) {
            fprintf(stderr, "Empty line at line %d\n", line_number);
            continue;
        }

        // Split line into tokens
        token = strtok(trimmed_line, " ");
        while (token!= NULL) {
            fprintf(output_file, "%s ", token);
            token = strtok(NULL, " ");
        }
        fprintf(output_file, "\n");
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}