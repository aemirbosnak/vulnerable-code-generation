//FormAI DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50 // Maximum length of a word

// Function to remove non-alphabetic characters from a word
void removeNonAlphabeticChars(char *word) {
    int i, j = 0;

    for (i = 0; word[i] != '\0'; i++) {
        if (isalpha(word[i])) {
            word[j++] = tolower(word[i]);
        }
    }
    word[j] = '\0';
}

// Function to check if a word is spelled correctly
int spellCheck(char *word, char dictionary[][MAX_WORD_LENGTH], int size) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char dictionary[][MAX_WORD_LENGTH] = {"hello", "world", "computer", "science", "programming"};
    int dictionarySize = sizeof(dictionary) / sizeof(dictionary[0]);

    char input[MAX_WORD_LENGTH];
    printf("Enter a word to check its spelling: ");
    scanf("%s", input);

    removeNonAlphabeticChars(input);

    int isCorrectSpelling = spellCheck(input, dictionary, dictionarySize);

    if (isCorrectSpelling) {
        printf("The word \"%s\" is spelled correctly\n", input);
    } else {
        printf("The word \"%s\" is spelled incorrectly\n", input);
    }

    return 0;
}