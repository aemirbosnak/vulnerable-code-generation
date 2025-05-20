//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024
#define INDENT_SIZE 2

void beautify_html(FILE *input, FILE *output) {
    char buffer[BUFFER_SIZE];
    int indent_level = 0;
    bool in_tag = false, is_closing_tag = false, ignore_whitespace = false;

    while (fgets(buffer, BUFFER_SIZE, input) != NULL) {
        size_t len = strlen(buffer);
        for (size_t i = 0; i < len; i++) {
            if (buffer[i] == '<') {
                if (buffer[i + 1] == '/') {
                    is_closing_tag = true;
                    i++; // Skip '/'
                } else {
                    is_closing_tag = false;
                }
                // Print new line and indentation if not empty line
                if (i > 0 && buffer[i - 1] != '\n') {
                    fprintf(output, "\n");
                }
                // Adjust indent level
                if (!is_closing_tag) {
                    fprintf(output, "%*s", indent_level, " ");
                    indent_level += INDENT_SIZE; // Increase indent level
                }
                in_tag = true;
                fprintf(output, "<");
            } 
            else if (buffer[i] == '>') {
                fprintf(output, ">");
                in_tag = false;
                if (is_closing_tag) {
                    indent_level -= INDENT_SIZE; // Decrease indent level for closing tag
                }
                ignore_whitespace = true; // ignore the white space after `>`
            } 
            else {
                if (!ignore_whitespace || (buffer[i] != ' ' && buffer[i] != '\t')) {
                    fprintf(output, "%c", buffer[i]);
                }
                ignore_whitespace = false;
            }
        }
        // Handle the end of line
        if (!in_tag && buffer[len - 1] != '\n') {
            fprintf(output, "\n");
        }
    }
    
    // Print a final newline for cleanliness
    fprintf(output, "\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Could not open input file");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        perror("Could not open output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    beautify_html(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("HTML beautification complete. Output saved to %s\n", argv[2]);
    return EXIT_SUCCESS;
}