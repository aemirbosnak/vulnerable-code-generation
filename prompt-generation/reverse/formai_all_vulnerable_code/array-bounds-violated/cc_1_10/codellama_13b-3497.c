//Code Llama-13B DATASET v1.0 Category: HTML beautifier ; Style: visionary
/*
 * HTML Beautifier Example Program
 *
 * This program takes a HTML file as input and outputs a beautified version of the HTML
 * with proper indentation and spacing.
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check for valid number of arguments
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    // Open input file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Failed to open input file: %s\n", argv[1]);
        return 1;
    }

    // Initialize variables
    char line[1024];
    int indent_level = 0;
    int tag_level = 0;

    // Loop through input file
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Check if line starts with a tag
        if (line[0] == '<') {
            // Increment tag level
            tag_level++;

            // Check if line ends with a closing tag
            if (line[strlen(line) - 2] == '/') {
                // Decrement tag level
                tag_level--;
            }

            // Print indentation
            for (int i = 0; i < indent_level; i++) {
                printf("    ");
            }

            // Print line
            printf("%s", line);
        } else {
            // Print line with proper indentation
            for (int i = 0; i < indent_level; i++) {
                printf("    ");
            }
            printf("%s", line);
        }

        // Increment indent level if line starts with a tag
        if (line[0] == '<') {
            indent_level++;
        }

        // Decrement indent level if line ends with a closing tag
        if (line[strlen(line) - 2] == '/') {
            indent_level--;
        }
    }

    // Close input file
    fclose(fp);

    return 0;
}