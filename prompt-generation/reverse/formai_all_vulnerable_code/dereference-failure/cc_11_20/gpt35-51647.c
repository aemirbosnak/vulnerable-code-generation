//FormAI DATASET v1.0 Category: HTML beautifier ; Style: surprised
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000

int main() {
    char html[MAX_SIZE];

    printf("Welcome to the HTML beautifier program!\n");
    printf("Please enter the HTML code you wish to beautify:\n");
    fgets(html, MAX_SIZE, stdin); // Read input from user
    printf("\nOriginal HTML code:\n%s\n", html);

    // Remove leading and trailing whitespace characters
    char *begin = html;
    char *end = &html[strlen(html) - 1];

    while (*begin == ' ' || *begin == '\t' || *begin == '\r' || *begin == '\n') {
        begin++;
    }

    while (*end == ' ' || *end == '\t' || *end == '\r' || *end == '\n') {
        *end-- = '\0';
    }

    // Format the HTML code
    int level = 0;
    char *current = html;
    char *output = (char*) malloc(strlen(html) + 1);

    while (*current != '\0') {
        if (*current == '<') {
            if (*(current + 1) == '/') {
                level--;
            }

            for (int i = 0; i < level; i++) {
                strcat(output, "    ");
            }
            level++;

            strcat(output, "<");
            current++;

            while (*current != '>' && *current != '/') {
                strncat(output, current, 1);
                current++;
            }

            strcat(output, ">\n");
        }
        else if (*current == '>') {
            strcat(output, ">\n");
        }
        else {
            strncat(output, current, 1);
        }

        current++;
    }

    printf("\nBeautified HTML code:\n%s", output);
    free(output);
    return 0;
}