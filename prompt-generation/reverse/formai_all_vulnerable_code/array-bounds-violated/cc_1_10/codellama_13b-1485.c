//Code Llama-13B DATASET v1.0 Category: HTML beautifier ; Style: visionary
/*
 * Beautifier.c
 *
 * A C HTML beautifier program that takes in a HTML document
 * and outputs a beautified version of the document.
 *
 * Usage: ./beautifier < input.html > output.html
 *
 */

#include <stdio.h>
#include <string.h>

// Global variables
char line[256];
char *tag;
int indent = 0;

// Function to indent the output
void indent_output(int n) {
    for (int i = 0; i < n; i++) {
        printf("    ");
    }
}

// Function to handle a start tag
void handle_start_tag(char *tag) {
    // Print the tag
    printf("%s", tag);

    // Increment the indent level
    indent++;
}

// Function to handle an end tag
void handle_end_tag(char *tag) {
    // Decrement the indent level
    indent--;

    // Print the tag
    printf("%s", tag);
}

// Function to handle a text node
void handle_text_node(char *text) {
    // Print the text
    printf("%s", text);
}

// Main function
int main(int argc, char *argv[]) {
    // Initialize the global variables
    tag = "";
    indent = 0;

    // Read in the HTML document
    while (fgets(line, sizeof(line), stdin)) {
        // Remove the newline character
        line[strlen(line) - 1] = '\0';

        // Check if the line is a start tag
        if (line[0] == '<') {
            // Handle the start tag
            handle_start_tag(line);
        }

        // Check if the line is an end tag
        else if (line[0] == '>') {
            // Handle the end tag
            handle_end_tag(line);
        }

        // Check if the line is a text node
        else {
            // Handle the text node
            handle_text_node(line);
        }
    }

    // Return success
    return 0;
}