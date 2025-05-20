//FormAI DATASET v1.0 Category: Spell checking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024

// Define the dictionary structure
struct Dictionary {
    char word[100];
};

int main() {
    struct Dictionary dict[MAX_SIZE];

    // Load the dictionary file
    FILE *dictionaryFile = fopen("dictionary.txt", "r");
    if (!dictionaryFile) {
        printf("Error: Cannot open dictionary file.\n");
        exit(1);
    }

    int numWords = 0;
    char buffer[100];
    while (fgets(buffer, 100, dictionaryFile)) {
        strcpy(dict[numWords].word, buffer);
        dict[numWords].word[strlen(dict[numWords].word) - 1] = '\0';
        numWords++;
    }
    fclose(dictionaryFile);

    // Get the input string from user
    char inputString[MAX_SIZE];
    printf("Enter the string to be checked: ");
    fgets(inputString, MAX_SIZE, stdin);
    inputString[strlen(inputString) - 1] = '\0';

    // Tokenize the input string
    char *token = strtok(inputString, " ,.!?");

    while (token != NULL) {
        // Ignore token if it contains non-alphabetic characters
        int validToken = 1;
        for (int i = 0; i < strlen(token); i++) {
            if (!isalpha(token[i])) {
                validToken = 0;
                break;
            }
        }

        if (validToken) {
            // Convert the token to lowercase
            char lowercaseToken[100];
            for (int i = 0; i < strlen(token); i++) {
                lowercaseToken[i] = tolower(token[i]);
            }
            lowercaseToken[strlen(token)] = '\0';

            // Check if the token is in the dictionary
            int found = 0;
            for (int i = 0; i < numWords; i++) {
                if (strcmp(dict[i].word, lowercaseToken) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Misspelled word: %s\n", token);
            }
        }

        token = strtok(NULL, " ,.!?");
    }

    return 0;
}