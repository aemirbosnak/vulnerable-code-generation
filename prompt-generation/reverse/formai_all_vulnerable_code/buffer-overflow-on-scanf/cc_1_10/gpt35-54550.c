//FormAI DATASET v1.0 Category: Spell checking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function to check if a word is spelled correctly
int checkSpelling(char *word) {
    char dictionary[MAX_LEN][MAX_LEN] = {"apple", "banana", "orange", "grape", "kiwi"};
    int dictSize = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Correctly spelled
        }
    }
    return 0; // Incorrectly spelled
}

// Function to suggest a correction for a misspelled word
char *suggestCorrection(char *word) {
    char *correction = (char *) malloc(MAX_LEN * sizeof(char));
    char dictionary[MAX_LEN][MAX_LEN] = {"apple", "banana", "orange", "grape", "kiwi"};
    int dictSize = sizeof(dictionary)/sizeof(dictionary[0]);
    int accuracy = 0;
    int closestMatch = -1;
    for (int i = 0; i < dictSize; i++) {
        int match = 0;
        int wordLen = strlen(word);
        int dictWordLen = strlen(dictionary[i]);
        if (wordLen == dictWordLen) {
            for (int j = 0; j < wordLen; j++) {
                if (word[j] == dictionary[i][j]) {
                    match++;
                }
            }
            if (match > accuracy) {
                accuracy = match;
                closestMatch = i;
            }
        }
    }
    if (closestMatch != -1) {
        strcpy(correction, dictionary[closestMatch]);
    } else {
        strcpy(correction, "No suggestions found.");
    }
    return correction;
}

int main() {
    char input[MAX_LEN];
    printf("Enter a word to check its spelling: ");
    scanf("%s", input);
    if (checkSpelling(input)) {
        printf("The word \"%s\" is spelled correctly.\n", input);
    } else {
        char *correction = suggestCorrection(input);
        printf("The word \"%s\" is misspelled. Did you mean \"%s\"?\n", input, correction);
    }
    return 0;
}