//Code Llama-13B DATASET v1.0 Category: HTML beautifier ; Style: careful
// HTML beautifier program in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDENT_SIZE 4

int main(int argc, char *argv[]) {
    // Check if there is an argument
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    // Open the input file
    FILE *in = fopen(argv[1], "r");
    if (in == NULL) {
        printf("Failed to open input file: %s\n", argv[1]);
        return 1;
    }

    // Create a new file for the output
    FILE *out = fopen("output.html", "w");
    if (out == NULL) {
        printf("Failed to open output file: output.html\n");
        return 1;
    }

    // Variables for the loop
    char c;
    int indent = 0;
    int space = 0;
    int last_was_tag = 0;

    // Loop through the input file
    while ((c = fgetc(in)) != EOF) {
        // Check if the character is a tag
        if (c == '<') {
            // If the last character was not a tag, increase the indent level
            if (!last_was_tag) {
                indent += INDENT_SIZE;
            }

            // Output the tag with the current indent level
            fprintf(out, "%*c%c", indent, ' ', c);

            // Set the last character as a tag
            last_was_tag = 1;
        }
        // Check if the character is a space
        else if (c == ' ') {
            // If the last character was not a space, increase the space level
            if (!space) {
                space = 1;
            }

            // Output the space with the current space level
            fprintf(out, "%*c", space, c);
        }
        // Check if the character is a newline
        else if (c == '\n') {
            // If the last character was not a newline, output a newline
            if (!last_was_tag) {
                fprintf(out, "\n");
            }

            // Reset the indent level and space level
            indent = 0;
            space = 0;

            // Set the last character as a newline
            last_was_tag = 0;
        }
        // If the character is any other character, output it without modification
        else {
            fprintf(out, "%c", c);
        }
    }

    // Close the input and output files
    fclose(in);
    fclose(out);

    return 0;
}