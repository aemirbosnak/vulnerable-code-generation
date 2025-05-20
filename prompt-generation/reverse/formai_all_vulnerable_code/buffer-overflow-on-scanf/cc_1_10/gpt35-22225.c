//FormAI DATASET v1.0 Category: HTML beautifier ; Style: curious
#include <stdio.h>

int main() {
    // Display a curious message
    printf("Let us beautify some HTML code!\n");

    // Get input from the user
    printf("Enter the HTML code you want to beautify:\n");
    char htmlCode[1000];
    scanf("%[^\n]", htmlCode);

    // Variables to keep track of HTML tags and indentation level
    int indentLevel = 0;
    int tagOpen = 0;
    int i = 0;

    // Loop through each character in the input HTML code
    while (htmlCode[i] != '\0') {
        char c = htmlCode[i];

        // If the current character is a tag opener
        if (c == '<') {
            tagOpen = 1;

            // Print the current line with proper indentation
            printf("\n");
            for (int j = 0; j < indentLevel; j++) {
                printf("  ");
            }

            printf("<");

            // If the next character is a slash, then it's a closing tag
            if (htmlCode[i+1] == '/') {
                indentLevel--;
            }
            else {
                indentLevel++;
            }
        }

        // If the current character is a tag closer
        else if (c == '>') {
            tagOpen = 0;
            printf(">");
        }

        // If the current character is whitespace
        else if (c == ' ' || c == '\t' || c == '\n') {
            // Ignore whitespace between tags
            if (tagOpen == 0) {
                printf("%c", c);
            }
        }

        // If the current character is text
        else {
            printf("%c", c);
        }

        i++;
    }

    printf("\n");

    // Display a curious message
    printf("Voila! Your HTML code is now beautified.\n");

    return 0;
}