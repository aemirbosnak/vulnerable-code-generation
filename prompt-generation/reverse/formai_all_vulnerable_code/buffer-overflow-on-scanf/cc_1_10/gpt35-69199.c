//FormAI DATASET v1.0 Category: Spell checking ; Style: mathematical
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100 // Maximum string length
#define NUM_LETTERS 26 // Number of letters in the alphabet

int letterCount[NUM_LETTERS];

// Function to reset the letter count
void resetLetterCount() {
    for(int i = 0; i < NUM_LETTERS; i++) {
        letterCount[i] = 0;
    }
}

// Function to count the number of occurrences of each letter in a string
void countLetters(char *str) {
    resetLetterCount();
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        int index = tolower(str[i]) - 'a';
        if(index >= 0 && index < NUM_LETTERS) {
            letterCount[index]++;
        }
    }
}

// Function to check if a string can be formed from a given set of letters
int canBeFormed(char *str) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        int index = tolower(str[i]) - 'a';
        if(index >= 0 && index < NUM_LETTERS) {
            if(letterCount[index] == 0) {
                return 0;
            } else {
                letterCount[index]--;
            }
        } else {
            return 0;
        }
    }
    return 1;
}

int main() {
    char dictionary[][MAX_LENGTH] = {"mathematics", "equation", "calculus", "geometry", "trigonometry", "algebra"};
    int dictionarySize = sizeof(dictionary) / sizeof(dictionary[0]);

    printf("Enter a word to check if it is spelled correctly: ");
    char input[MAX_LENGTH];
    scanf("%s", input);

    printf("\nThe word \"%s\" is spelled ", input);
    if(canBeFormed(input)) {
        printf("correctly.\n");
    } else {
        printf("incorrectly.\n");
        printf("\nPossible correct spellings:\n");
        for(int i = 0; i < dictionarySize; i++) {
            countLetters(dictionary[i]);
            if(canBeFormed(input)) {
                printf("%s\n", dictionary[i]);
            }
        }
    }

    return 0;
}