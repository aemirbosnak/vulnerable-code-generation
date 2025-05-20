//FormAI DATASET v1.0 Category: HTML beautifier ; Style: interoperable
/*
 * C HTML beautifier program 
 * 
 * This program performs the following tasks:
 *   1. Reads an input Html file.
 *   2. Beautifies the source code to make it human readable.
 *   3. Outputs the beautified HTML file to an output location.
 *
 * Input: HTML file path.
 * Output: Beautified HTML file path.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// Function to check if we are inside a tag
bool is_inside_tag = false;

//Function to check if we are inside a comment
bool is_inside_comment = false;

// Function to beautify HTML code
void beautify(FILE *input_file, FILE *output_file) {
    char current_char, previous_char = '\0';

    while ((current_char = fgetc(input_file)) != EOF) {
        if (current_char == '<') {
            is_inside_tag = true;
        }

        if (is_inside_tag) {
            fputc(current_char, output_file);

            if (current_char == '>') {
                is_inside_tag = false;

                if (previous_char != ' ' && previous_char != '\n') {
                    fputc('\n', output_file);
                }
            }
        } else {
            if (current_char == ' ' || current_char == '\n') {
                if (previous_char != ' ' && previous_char != '\n') {
                    fputc(' ', output_file);
                }
            } else {
                fputc(current_char, output_file);
            }
        }

        if (previous_char == '<' && current_char == '!') {
            is_inside_comment = true;
        }

        if (previous_char == '-' && current_char == '-' && is_inside_comment) {
            is_inside_comment = false;
        }

        if (previous_char == '\n' && !is_inside_tag && !is_inside_comment) {
            fputc('\n', output_file);
        }

        previous_char = current_char;
    }
}

int main(void) {
    char *input_file_name = "sample.html";
    char *output_file_name = "beautified.html";

    FILE *input_file = fopen(input_file_name, "r");

    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE *output_file = fopen(output_file_name, "w");

    if (output_file == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }

    beautify(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}