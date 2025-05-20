//FormAI DATASET v1.0 Category: Spell checking ; Style: systematic
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void spellCheck(char word[], char dict[][20], int dictSize);

int main() {

    char dictionary[][20] = {"hello", "world", "programming", "language", "computer", "science", "algorithm"};
    int dictSize = sizeof(dictionary) / sizeof(dictionary[0]);

    char word[20];
    printf("Enter a word to spell check:\n");
    scanf("%s", word);

    spellCheck(word, dictionary, dictSize);

    return 0;
}

void spellCheck(char word[], char dict[][20], int dictSize) {
    int i, j;
    int wordLength = strlen(word);

    // Convert word to lowercase
    for (i = 0; i < wordLength; i++) {
        word[i] = tolower(word[i]);
    }

    // Check if word is in dictionary
    for (i = 0; i < dictSize; i++) {
        if (strcmp(word, dict[i]) == 0) {
            printf("%s is spelled correctly.\n", word);
            return;
        }
    }

    // If not in dictionary, check for possible spelling errors
    printf("%s is not spelled correctly. Possible corrections:\n", word);

    // Check for one-letter substitutions
    char tempWord[20];
    for (i = 0; i < wordLength; i++) {
        for (j = 0; j < 26; j++) {
            // Generate new word with one-letter substitution
            strcpy(tempWord, word);
            tempWord[i] = 'a' + j;

            // Check if new word is in dictionary
            for (int k = 0; k < dictSize; k++) {
                if (strcmp(tempWord, dict[k]) == 0) {
                    printf("%s\n", tempWord);
                }
            }
        }
    }

    // Check for one-letter deletions
    for (i = 0; i < wordLength; i++) {
        // Generate new word by deleting one letter
        char tempWord[20];
        int index = 0;
        for (j = 0; j < wordLength; j++) {
            if (j != i) {
                tempWord[index] = word[j];
                index++;
            }
        }
        tempWord[index] = '\0';

        // Check if new word is in dictionary
        for (int k = 0; k < dictSize; k++) {
            if (strcmp(tempWord, dict[k]) == 0) {
                printf("%s\n", tempWord);
            }
        }
    }

    // Check for one-letter insertions
    for (i = 0; i <= wordLength; i++) {
        for (j = 0; j < 26; j++) {
            // Generate new word with one-letter insertion
            char tempWord[20];
            int index = 0;
            for (int k = 0; k < wordLength; k++) {
                if (k == i) {
                    tempWord[index] = 'a' + j;
                    index++;
                }
                tempWord[index] = word[k];
                index++;
            }
            tempWord[index] = '\0';

            // Check if new word is in dictionary
            for (int k = 0; k < dictSize; k++) {
                if (strcmp(tempWord, dict[k]) == 0) {
                    printf("%s\n", tempWord);
                }
            }
        }
    }
}