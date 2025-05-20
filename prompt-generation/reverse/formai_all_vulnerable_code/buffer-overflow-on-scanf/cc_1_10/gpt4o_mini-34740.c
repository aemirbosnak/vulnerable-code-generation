//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: lively
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 10

// Function to translate a word into Alien Language
void translateToAlien(char *englishWord, char *alienWord) {
    char *dictionary[DICTIONARY_SIZE][2] = {
        {"hello", "zorp"},
        {"friend", "blix"},
        {"computer", "glorp"},
        {"alien", "wook"},
        {"language", "fizzle"},
        {"generic", "squorp"},
        {"program", "dibb"},
        {"happy", "goo"},
        {"moon", "drek"},
        {"star", "mib"}
    };

    int found = 0;

    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (strcmp(englishWord, dictionary[i][0]) == 0) {
            strcpy(alienWord, dictionary[i][1]);
            found = 1;
            break;
        }
    }

    if (!found) {
        strcpy(alienWord, "unknown");
    }
}

// Function to print the translation
void printTranslation(char *englishWord) {
    char alienWord[MAX_WORD_LENGTH];
    translateToAlien(englishWord, alienWord);
    
    printf("The Alien translation of '%s' is: '%s'\n", englishWord, alienWord);
}

int main() {
    char englishWord[MAX_WORD_LENGTH];
    char continueTranslate = 'y';

    printf("Welcome to the Galactic Translator!\n");
    printf("Translate your English words into the mysterious Alien language.\n");

    while (continueTranslate == 'y' || continueTranslate == 'Y') {
        printf("\nEnter an English word to translate: ");
        scanf("%s", englishWord);

        // Print the translation
        printTranslation(englishWord);

        // Ask if the user wants to continue
        printf("Do you want to translate another word? (y/n): ");
        getchar(); // to consume the newline character
        scanf("%c", &continueTranslate);
    }

    printf("\nThank you for using the Galactic Translator!\n");
    printf("Until we meet again in the cosmos!\n");
    return 0;
}