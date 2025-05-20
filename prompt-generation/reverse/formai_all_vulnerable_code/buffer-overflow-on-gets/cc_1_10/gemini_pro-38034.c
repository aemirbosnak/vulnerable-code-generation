//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify HTML code
char *beautify_html(char *html) {
    // Allocate memory for the beautified HTML code
    char *beautified_html = malloc(strlen(html) * 2);

    // Initialize the beautified HTML code
    beautified_html[0] = '\0';

    // Iterate over the HTML code
    for (int i = 0; i < strlen(html); i++) {
        // Check if the current character is a space or a newline
        if (html[i] == ' ' || html[i] == '\n') {
            // If the current character is a space, replace it with a non-breaking space
            if (html[i] == ' ') {
                strcat(beautified_html, "&nbsp;");
            }
            // If the current character is a newline, replace it with a line break
            else {
                strcat(beautified_html, "<br>");
            }
        }
        // If the current character is not a space or a newline, append it to the beautified HTML code
        else {
            char c[2];
            c[0] = html[i];
            c[1] = '\0';
            strcat(beautified_html, c);
        }
    }

    // Return the beautified HTML code
    return beautified_html;
}

// Main function
int main() {
    // Get the HTML code from the user
    char *html = malloc(1000);
    printf("Enter HTML code: ");
    gets(html);

    // Beautify the HTML code
    char *beautified_html = beautify_html(html);

    // Print the beautified HTML code
    printf("Beautified HTML code: %s", beautified_html);

    // Free the allocated memory
    free(html);
    free(beautified_html);

    return 0;
}