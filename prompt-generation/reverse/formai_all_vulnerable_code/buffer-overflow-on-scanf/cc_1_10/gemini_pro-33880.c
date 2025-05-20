//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// HTML beautifier function
char *beautify_html(char *html) {
    // Allocate memory for the beautified HTML
    char *beautified_html = malloc(strlen(html) * 2);

    // Initialize the beautified HTML string
    strcpy(beautified_html, "");

    // Initialize the indentation level
    int indent_level = 0;

    // Iterate over each character in the HTML string
    for (int i = 0; i < strlen(html); i++) {
        // Get the current character
        char c = html[i];

        // Handle whitespace characters
        if (c == ' ' || c == '\t' || c == '\n') {
            // If the current character is a newline character, increase the indentation level
            if (c == '\n') {
                indent_level++;
            }

            // Append a newline character to the beautified HTML string
            strcat(beautified_html, "\n");

            // Append the appropriate number of indentation spaces to the beautified HTML string
            for (int j = 0; j < indent_level; j++) {
                strcat(beautified_html, "    ");
            }

            // Continue to the next character
            continue;
        }

        // Handle HTML tags
        if (c == '<') {
            // Append the current character to the beautified HTML string
            strcat(beautified_html, &c);

            // If the next character is a slash, it is a closing tag
            if (html[i + 1] == '/') {
                // Decrease the indentation level
                indent_level--;

                // Continue to the next character
                i++;
            }

            // Continue to the next character
            continue;
        }

        // Handle HTML attributes
        if (c == ' ' && html[i - 1] == '<') {
            // Append the current character to the beautified HTML string
            strcat(beautified_html, &c);

            // Continue to the next character
            continue;
        }

        // Handle HTML text
        // Append the current character to the beautified HTML string
        strcat(beautified_html, &c);
    }

    // Return the beautified HTML string
    return beautified_html;
}

// Main function
int main() {
    // Get the HTML string from the user
    char *html = malloc(1024);
    printf("Enter HTML string: ");
    scanf("%s", html);

    // Beautify the HTML string
    char *beautified_html = beautify_html(html);

    // Print the beautified HTML string
    printf("Beautified HTML string: \n\n%s", beautified_html);

    // Free the memory allocated for the HTML strings
    free(html);
    free(beautified_html);

    return 0;
}