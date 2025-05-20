//Code Llama-13B DATASET v1.0 Category: HTML beautifier ; Style: unmistakable
// Example C HTML beautifier program
#include <stdio.h>
#include <string.h>

int main() {
    char input[1024];
    char output[1024];
    int i = 0;
    int j = 0;
    int k = 0;
    int spaces = 0;
    int tabs = 0;

    while (1) {
        // Read input from stdin
        scanf("%s", input);

        // Check for end of input
        if (strcmp(input, "EOF") == 0) {
            break;
        }

        // Remove leading and trailing whitespace
        while (input[i] == ' ' || input[i] == '\t') {
            i++;
        }
        while (input[j] != ' ' && input[j] != '\t' && input[j] != '\0') {
            j++;
        }
        k = 0;
        while (input[k] != '\0') {
            output[k] = input[i + k];
            k++;
        }

        // Add indentation
        if (input[i] == '<') {
            tabs++;
            for (int t = 0; t < tabs; t++) {
                printf("\t");
            }
        }

        // Add closing tags
        if (input[i] == '>') {
            tabs--;
            for (int t = 0; t < tabs; t++) {
                printf("\t");
            }
        }

        // Add newlines
        if (input[i] == '\n') {
            printf("\n");
        }

        // Add output
        printf("%s", output);
    }

    return 0;
}