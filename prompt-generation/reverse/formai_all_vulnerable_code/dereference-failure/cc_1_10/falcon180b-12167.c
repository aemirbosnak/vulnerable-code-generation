//Falcon-180B DATASET v1.0 Category: Error handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

int main(int argc, char *argv[]) {
    FILE *file;
    char *filename = argv[1];
    char *line = NULL;
    size_t len = 0;
    int num_lines = 0;

    file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        return 1;
    }

    while ((getline(&line, &len, file))!= -1) {
        if (num_lines >= MAX_NUM_LINES) {
            fprintf(stderr, "Error: Too many lines in file '%s'\n", filename);
            return 1;
        }

        if (line[0] == '#') {
            continue;
        }

        if (strlen(line) > MAX_LINE_LENGTH) {
            fprintf(stderr, "Error: Line too long in file '%s'\n", filename);
            return 1;
        }

        printf("%s", line);
        num_lines++;
    }

    if (ferror(file)) {
        fprintf(stderr, "Error: Failed to read file '%s'\n", filename);
        return 1;
    }

    if (fclose(file)!= 0) {
        fprintf(stderr, "Error: Failed to close file '%s'\n", filename);
        return 1;
    }

    return 0;
}