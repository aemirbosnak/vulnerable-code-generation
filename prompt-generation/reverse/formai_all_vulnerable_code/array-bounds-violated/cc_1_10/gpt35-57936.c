//FormAI DATASET v1.0 Category: HTML beautifier ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

// helper function to check whether a character is a whitespace character or not
int is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

// main HTML beautifier function
void beautify_html(FILE* input_file, FILE* output_file) {
    char current_char;
    char buffer[MAX_LINE_LENGTH];
    int buffer_index = 0;
    int indent_level = 0;

    // read characters from input file one by one
    while ((current_char = fgetc(input_file)) != EOF) {
        if (current_char == '<') {
            // write out any text that we have buffered so far
            if (buffer_index > 0) {
                buffer[buffer_index] = '\0';
                fprintf(output_file, "%s", buffer);
                buffer_index = 0;
            }

            // read the entire tag
            while ((current_char = fgetc(input_file)) != '>') {
                buffer[buffer_index++] = current_char;
            }
            buffer[buffer_index++] = '>';
            buffer[buffer_index] = '\0';

            // determine the type of tag (opening, closing, or self-closing)
            int is_closing_tag = buffer[1] == '/';
            int is_self_closing_tag = buffer[buffer_index - 2] == '/';

            // add the appropriate amount of indentation
            if (!is_closing_tag) {
                for (int i = 0; i < indent_level; i++) {
                    fputc('\t', output_file);
                }
                indent_level++;

                // special case for self-closing tags
                if (is_self_closing_tag) {
                    indent_level--;
                }
            } else {
                indent_level--;
                for (int i = 0; i < indent_level; i++) {
                    fputc('\t', output_file);
                }
            }

            // write out the tag
            fprintf(output_file, "%s\n", buffer);
        } else if (!is_whitespace(current_char)) {
            // buffer any non-whitespace text
            buffer[buffer_index++] = current_char;
        }
    }

    // write out any text that we have buffered so far
    if (buffer_index > 0) {
        buffer[buffer_index] = '\0';
        fprintf(output_file, "%s", buffer);
    }
}

int main(int argc, char** argv) {
    // check for the correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    // open the input and output files
    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: failed to open input file '%s'\n", argv[1]);
        return 2;
    }

    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: failed to open output file '%s'\n", argv[2]);
        fclose(input_file);
        return 3;
    }

    // beautify the HTML and close the files
    beautify_html(input_file, output_file);
    fclose(input_file);
    fclose(output_file);

    return 0;
}