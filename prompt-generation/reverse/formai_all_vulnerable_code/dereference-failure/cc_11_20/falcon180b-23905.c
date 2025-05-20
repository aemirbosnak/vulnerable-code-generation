//Falcon-180B DATASET v1.0 Category: Error handling ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", strerror(errno));
        return 2;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", strerror(errno));
        return 3;
    }

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, input_file)!= NULL) {
        int line_len = strlen(line);
        if (line_len == 0 || line[line_len - 1]!= '\n') {
            fprintf(stderr, "Error: Input file contains invalid line\n");
            return 4;
        }

        int num_words = 0;
        char *word = strtok(line, " ");
        while (word!= NULL) {
            num_words++;
            word = strtok(NULL, " ");
        }

        if (num_words == 0) {
            fprintf(output_file, "\n");
        } else {
            fprintf(output_file, "%s\n", line);
        }
    }

    if (fclose(input_file)!= 0) {
        fprintf(stderr, "Error closing input file: %s\n", strerror(errno));
        return 5;
    }

    if (fclose(output_file)!= 0) {
        fprintf(stderr, "Error closing output file: %s\n", strerror(errno));
        return 6;
    }

    return 0;
}