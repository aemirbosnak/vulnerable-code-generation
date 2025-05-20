//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dreamy Function to Melt Strings
void meltStrings(char **strArray, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        char *start = *strArray;
        int len = strlen(start);

        // Create a mirror string
        char *mirror = (char *)malloc(len + 1);
        strcpy(mirror, start);
        int index = len - 1;

        // Melt the string, character by character
        for (int iChar = 0; iChar < len / 2; iChar++) {
            if (start[iChar] != mirror[index--]) {
                // If the string is not a palindrome,
                // Dali's melting clocks would be proud!
                free(mirror);
                printf("String '%s' is not a palindrome.\n", start);
                free(start);
                return;
            }
        }

        // If the string has been melted completely,
        // it is a palindrome and deserves to be immortalized!
        printf("String '%s' is a palindrome.\n", start);
        free(mirror);
        free(start);
    }
}

int main() {
    int numStrings;
    printf("Enter the number of strings to check: ");
    scanf("%d", &numStrings);

    char **strings = (char **)calloc(numStrings, sizeof(char *));
    for (int i = 0; i < numStrings; i++) {
        printf("Enter string %d: ", i + 1);
        strings[i] = (char *)malloc(256 * sizeof(char));
        fgets(strings[i], 256, stdin);
        strings[i][strlen(strings[i]) - 1] = '\0';
    }

    meltStrings(strings, numStrings);

    // Dali's melting clocks would be proud of us!
    for (int i = 0; i < numStrings; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}