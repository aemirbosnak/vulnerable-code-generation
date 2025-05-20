//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify HTML code
char* beautify_html(char* html) {
    // Allocate memory for the beautified HTML code
    char* beautified_html = malloc(strlen(html) * 2);  // Double the size to account for indentation and newlines
    int beautified_html_length = 0;

    // Iterate over the HTML code character by character
    int i = 0;
    while (html[i] != '\0') {
        // If the current character is a '<' character, then it is the start of a tag
        if (html[i] == '<') {
            // Copy the '<' character to the beautified HTML code
            beautified_html[beautified_html_length++] = '<';

            // Skip the next character, which is the '/' or '!' character
            i++;

            // If the next character is an '!', then it is a comment
            if (html[i] == '!') {
                // Copy the comment to the beautified HTML code
                while (html[i] != '>') {
                    beautified_html[beautified_html_length++] = html[i++];
                }

                // Copy the '>' character to the beautified HTML code
                beautified_html[beautified_html_length++] = '>';
            } else {  // Otherwise, it is a tag
                // Copy the tag to the beautified HTML code
                while (html[i] != '>' && html[i] != ' ') {
                    beautified_html[beautified_html_length++] = html[i++];
                }

                // If the tag is a self-closing tag, then add a newline to the beautified HTML code
                if (html[i] == '/') {
                    beautified_html[beautified_html_length++] = '\n';
                }

                // Copy the '>' character to the beautified HTML code
                beautified_html[beautified_html_length++] = '>';
            }
        } else {  // Otherwise, it is not a tag
            // Copy the character to the beautified HTML code
            beautified_html[beautified_html_length++] = html[i++];
        }
    }

    // Add a newline to the end of the beautified HTML code
    beautified_html[beautified_html_length++] = '\n';

    // Return the beautified HTML code
    return beautified_html;
}

// Main function
int main() {
    // Get the HTML code from the user
    char* html = malloc(1024);
    printf("Enter the HTML code:\n");
    gets(html);

    // Beautify the HTML code
    char* beautified_html = beautify_html(html);

    // Print the beautified HTML code
    printf("Beautified HTML code:\n%s\n", beautified_html);

    // Free the memory allocated for the HTML code and the beautified HTML code
    free(html);
    free(beautified_html);

    return 0;
}