//FormAI DATASET v1.0 Category: Spell checking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to check for invalid characters
int checkInvalidChar(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 0;
    else
        return 1;
}

int main() {
    char input[1000];
    printf("Enter the text to be checked: ");
    fgets(input, 1000, stdin);

    // Replace newlines with null terminator
    int len = strlen(input);
    if (input[len-1] == '\n')
        input[len-1] = '\0';

    // Tokenize the input string by spaces
    char* token = strtok(input, " ");
    while (token != NULL) {
        int tokenLen = strlen(token);
        int isValid = 1;

        // Check for invalid chars in the token
        for (int i = 0; i < tokenLen; i++) {
            if (checkInvalidChar(token[i])) {
                isValid = 0;
                break;
            }
        }

        // If token contains invalid chars, print error message
        if (!isValid) {
            printf("%s: Contains invalid characters\n", token);
        } else {
            // Check for misspelled words
            char* dict[] = {"hello", "world", "good", "morning", "afternoon", "evening"};
            int dictSize = 6;

            int found = 0;
            for (int i = 0; i < dictSize; i++) {
                if (strcmp(dict[i], token) == 0) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("%s: Misspelled word\n", token);
            }
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    return 0;
}