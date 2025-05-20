//FormAI DATASET v1.0 Category: HTML beautifier ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000  // Maximum length of input string
#define TAB_SIZE 4  // Number of spaces to replace one tab

int main() {
    char input[MAX_LEN];
    char output[MAX_LEN * TAB_SIZE];  // Output string
    int i, j, k = 0;
    int tab_count = 0;  // Number of tabs encountered
    int inside_tag = 0;  // Flag for whether we are inside an HTML tag

    // Read input string
    printf("Enter the HTML code to beautify:\n");
    fgets(input, MAX_LEN, stdin);

    // Check for and remove any existing whitespace
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '\n' || input[i] == '\r' || input[i] == ' ' || input[i] == '\t') {
            continue;
        }
        input[k++] = input[i];  // Move non-whitespace characters to the beginning of input
    }
    input[k] = '\0';  // Add null terminator to input string

    // Loop through input string
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '<') {
            inside_tag = 1;  // We are now inside an HTML tag
            // Add spaces for indentation
            for (j = 0; j < tab_count; j++) {
                output[k++] = ' ';
            }
        }
        // Copy character to output string
        output[k++] = input[i];
        if (input[i] == '>') {
            inside_tag = 0;  // We are now outside of an HTML tag
            output[k++] = '\n';  // Add newline after closing tag
            // Increase or decrease tab count based on tag type
            if (input[i-1] == '/') {
                tab_count--;  // Decrease tab count for self-closing tag
            } else if (input[i-1] == ' ') {
                tab_count++;  // Increase tab count for starting tag
            }
        }
        // Replace tabs with spaces inside HTML tag
        if (inside_tag && input[i] == '\t') {
            for (j = 0; j < TAB_SIZE; j++) {
                output[k++] = ' ';
            }
        }
    }
    output[k] = '\0';  // Add null terminator to output string

    // Print output string
    printf("\nBeautified HTML code:\n%s\n", output);

    return 0;
}