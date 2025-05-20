//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// function declarations
void beautify_html(FILE *input, FILE *output);

// main function
int main(int argc, char *argv[]) {
    FILE *input, *output;

    if (argc < 3) {
        printf("Usage: beautify input_file_name output_file_name\n");
        exit(EXIT_FAILURE);
    }

    input = fopen(argv[1], "r");
    output = fopen(argv[2], "w");

    if (input == NULL || output == NULL) {
        printf("Error opening files. Exiting.\n");
        exit(EXIT_FAILURE);
    }

    beautify_html(input, output);

    fclose(input);
    fclose(output);

    return 0;
}

// function definition
void beautify_html(FILE *input, FILE *output) {
    char c, prev_c;
    bool in_tag = false, in_single_quotes = false, in_double_quotes = false;
    int indent_level = 0;
    bool line_start = true;
    bool preserve_space = false;

    while ((c = fgetc(input)) != EOF) {
        // handle opening and closing tags
        if (c == '<') {
            in_tag = true;
            preserve_space = true;
        } else if (c == '>') {
            in_tag = false;
            preserve_space = false;
        }

        if (line_start) {
            for (int i = 0; i < indent_level; i++) {
                fputc('\t', output);
            }
            line_start = false;
        }

        if (!preserve_space && !isspace(c)) {
            fputc(c, output);
        } else if (c == '\n') {
            fputc(c, output);
            line_start = true;
        } else if (preserve_space) {
            fputc(c, output);
            if (c == '\'' && !in_double_quotes) {
                in_single_quotes = !in_single_quotes;
            } else if (c == '"' && !in_single_quotes) {
                in_double_quotes = !in_double_quotes;
            } else if (!in_single_quotes && !in_double_quotes) {
                if (c == '/') {
                    indent_level--;
                }
                if (prev_c == '<' && c != '/') {
                    indent_level++;
                }
            }
        } else if (isspace(c) && !line_start) {
            fputc(' ', output);
        }

        prev_c = c;
    }
}