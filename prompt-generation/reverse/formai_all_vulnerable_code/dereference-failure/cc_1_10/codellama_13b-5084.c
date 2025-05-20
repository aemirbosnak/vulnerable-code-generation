//Code Llama-13B DATASET v1.0 Category: HTML beautifier ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HTML_SIZE 10000

int main() {
    char html[MAX_HTML_SIZE];
    int html_size;

    // Get the HTML input from the user
    printf("Enter the HTML code: ");
    fgets(html, MAX_HTML_SIZE, stdin);

    // Remove the newline character at the end of the string
    html[strlen(html) - 1] = '\0';

    // Initialize the HTML beautifier
    html_size = strlen(html);
    char* output = (char*)malloc(html_size * sizeof(char));
    int output_size = 0;

    // Beautify the HTML code
    for (int i = 0; i < html_size; i++) {
        if (html[i] == '<') {
            // Remove any whitespace before the tag
            while (isspace(html[i])) {
                i++;
            }
            // Add a newline and indentation before the tag
            output[output_size++] = '\n';
            output[output_size++] = '\t';
            // Add the tag
            output[output_size++] = html[i];
        } else if (html[i] == '>') {
            // Add the tag
            output[output_size++] = html[i];
            // Add a newline and indentation after the tag
            output[output_size++] = '\n';
            output[output_size++] = '\t';
        } else {
            // Add the character to the output
            output[output_size++] = html[i];
        }
    }

    // Add a newline at the end of the output
    output[output_size++] = '\n';

    // Print the beautified HTML code
    printf("Beautified HTML code:\n");
    printf("%s", output);

    // Free the memory allocated for the output
    free(output);

    return 0;
}