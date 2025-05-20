//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char **argv) {
    FILE *input_file = NULL;
    FILE *output_file = NULL;
    char line[MAX_LINE_LENGTH];
    int line_number = 1;
    int num_chars_written = 0;
    char *output_filename = "output.txt";

    if (argc > 1) {
        input_file = fopen(argv[1], "r");
        if (input_file == NULL) {
            fprintf(stderr, "Error: Could not open input file %s\n", argv[1]);
            return 1;
        }
    } else {
        fprintf(stderr, "Error: No input file specified\n");
        return 1;
    }

    if (argc > 2) {
        output_filename = argv[2];
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Could not open output file %s\n", output_filename);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        line[strcspn(line, "\n")] = '\0'; // Remove newline character

        int num_spaces = 0;
        int num_tabs = 0;
        int num_letters = 0;
        int num_digits = 0;
        int num_special = 0;

        for (int i = 0; i < strlen(line); i++) {
            if (isspace(line[i])) {
                num_spaces++;
            } else if (line[i] == '\t') {
                num_tabs++;
            } else if (isalpha(line[i])) {
                num_letters++;
            } else if (isdigit(line[i])) {
                num_digits++;
            } else {
                num_special++;
            }
        }

        fprintf(output_file, "Line %d: %d spaces, %d tabs, %d letters, %d digits, %d special characters\n",
                line_number, num_spaces, num_tabs, num_letters, num_digits, num_special);
        num_chars_written += strlen(line);
        line_number++;
    }

    fclose(input_file);
    fclose(output_file);

    printf("Processed %d characters\n", num_chars_written);

    return 0;
}