//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_HTML_LENGTH 65536

void beautify_html(const char *input, char *output) {
    int indent_level = 0;
    char buffer[MAX_LINE_LENGTH];
    int output_index = 0;
    int i = 0, j = 0;

    while (input[i] != '\0') {
        // Handle opening tags
        if (input[i] == '<' && input[i + 1] != '/') {
            // Print current indentation
            for (j = 0; j < indent_level; j++) {
                output[output_index++] = '\t';
            }
            output[output_index++] = '<';
            i++;
            while (input[i] != '>' && input[i] != '\0') {
                output[output_index++] = input[i++];
            }
            output[output_index++] = '>';
            indent_level++;
            if (input[i] == '>') {
                output[output_index++] = '\n';
            }
        }
        // Handle closing tags
        else if (input[i] == '<' && input[i + 1] == '/') {
            indent_level--;
            // Print current indentation
            for (j = 0; j < indent_level; j++) {
                output[output_index++] = '\t';
            }
            output[output_index++] = '<';
            i += 2; // Move past "</"
            while (input[i] != '>' && input[i] != '\0') {
                output[output_index++] = input[i++];
            }
            output[output_index++] = '>';
            if (input[i] == '>') {
                output[output_index++] = '\n';
            }
        }
        // Handle regular text
        else {
            while (input[i] != '<' && input[i] != '\0') {
                output[output_index++] = input[i++];
            }
            output[output_index++] = '\n'; // New line after text
        }
        // Move to the next character
        if (input[i] != '\0') {
            i++;
        }
    }
    output[output_index] = '\0'; // Null terminate the output string
}

int main() {
    char *html_input = malloc(MAX_HTML_LENGTH);
    char *formatted_html = malloc(MAX_HTML_LENGTH);

    if (html_input == NULL || formatted_html == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter your HTML code (end with EOF or Ctrl+D):\n");
    
    // Read multi-line input until EOF
    int length = 0;
    while (fgets(html_input + length, MAX_LINE_LENGTH, stdin)) {
        length += strlen(html_input + length);
        if (length >= MAX_HTML_LENGTH - MAX_LINE_LENGTH) {
            fprintf(stderr, "Input too long\n");
            free(html_input);
            free(formatted_html);
            return 1;
        }
    }

    beautify_html(html_input, formatted_html);

    printf("\nFormatted HTML:\n%s", formatted_html);

    free(html_input);
    free(formatted_html);

    return 0;
}