//Code Llama-13B DATASET v1.0 Category: HTML beautifier ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1000

int main() {
    char* html_text = NULL;
    char* beautified_html = NULL;
    int line_len = 0;
    int indent_level = 0;

    // Read the HTML text from the standard input
    html_text = (char*)malloc(MAX_LINE_LEN);
    while (fgets(html_text, MAX_LINE_LEN, stdin)) {
        // Check if the line is a start tag
        if (html_text[0] == '<' && html_text[1] != '/') {
            // Increase the indent level
            indent_level++;

            // Add a newline and the indent string to the output
            beautified_html = (char*)realloc(beautified_html, strlen(beautified_html) + indent_level + 2);
            strcat(beautified_html, "\n");
            for (int i = 0; i < indent_level; i++) {
                strcat(beautified_html, "  ");
            }
        }

        // Add the HTML text to the output
        beautified_html = (char*)realloc(beautified_html, strlen(beautified_html) + strlen(html_text));
        strcat(beautified_html, html_text);

        // Check if the line is an end tag
        if (html_text[0] == '<' && html_text[1] == '/') {
            // Decrease the indent level
            indent_level--;

            // Add a newline and the indent string to the output
            beautified_html = (char*)realloc(beautified_html, strlen(beautified_html) + indent_level + 2);
            strcat(beautified_html, "\n");
            for (int i = 0; i < indent_level; i++) {
                strcat(beautified_html, "  ");
            }
        }
    }

    // Print the beautified HTML text
    printf("%s", beautified_html);

    // Free the allocated memory
    free(html_text);
    free(beautified_html);

    return 0;
}