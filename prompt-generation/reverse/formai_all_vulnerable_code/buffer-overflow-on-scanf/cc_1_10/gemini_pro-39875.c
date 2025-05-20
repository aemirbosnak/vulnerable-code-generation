//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to indent a string by a given number of spaces
char *indent(char *str, int num_spaces) {
    char *new_str = malloc(strlen(str) + num_spaces + 1);
    for (int i = 0; i < num_spaces; i++) {
        new_str[i] = ' ';
    }
    strcat(new_str, str);
    return new_str;
}

// Function to beautify a given HTML string
char *beautify_html(char *html) {
    // Allocate memory for the beautified HTML string
    char *beautified_html = malloc(strlen(html) * 2);

    // Initialize the current indentation level
    int indentation_level = 0;

    // Loop through each character in the HTML string
    for (int i = 0; i < strlen(html); i++) {
        // Get the current character
        char c = html[i];

        // If the current character is a newline character, increase the indentation level
        if (c == '\n') {
            indentation_level++;
        }

        // If the current character is a closing angle bracket, decrease the indentation level
        else if (c == '>') {
            indentation_level--;
        }

        // If the current character is a space character, ignore it
        else if (c == ' ') {
            continue;
        }

        // Otherwise, append the current character to the beautified HTML string, indented by the current indentation level
        else {
            strcat(beautified_html, indent(html + i, indentation_level));
            i += strlen(html + i) - 1;  // Skip the current HTML tag
        }
    }

    // Return the beautified HTML string
    return beautified_html;
}

// Main function
int main() {
    // Get the HTML string from the user
    char *html = malloc(1000);
    printf("Enter the HTML string: ");
    scanf("%s", html);

    // Beautify the HTML string
    char *beautified_html = beautify_html(html);

    // Print the beautified HTML string
    printf("Beautified HTML string:\n");
    printf("%s", beautified_html);

    // Free the allocated memory
    free(html);
    free(beautified_html);

    return 0;
}