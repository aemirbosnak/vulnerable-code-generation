//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language characters
char alienChars[] = {'@', '#', '$', '%', '^', '&', '*', '(', ')'};

// Define the corresponding English characters
char englishChars[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};

// Translate an alien word to English
char *alienToEnglish(char *alienWord) {
    int len = strlen(alienWord);
    char *englishWord = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 9; j++) {
            if (alienWord[i] == alienChars[j]) {
                englishWord[i] = englishChars[j];
                break;
            }
        }
    }
    englishWord[len] = '\0';
    return englishWord;
}

// Translate an English word to alien
char *englishToAlien(char *englishWord) {
    int len = strlen(englishWord);
    char *alienWord = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 9; j++) {
            if (englishWord[i] == englishChars[j]) {
                alienWord[i] = alienChars[j];
                break;
            }
        }
    }
    alienWord[len] = '\0';
    return alienWord;
}

// Main function
int main() {
    // Get the user's choice
    printf("Enter 1 to translate from Alien to English, or 2 to translate from English to Alien: ");
    int choice;
    scanf("%d", &choice);

    // Get the word to be translated
    printf("Enter the word to be translated: ");
    char word[100];
    scanf("%s", word);

    // Translate the word
    char *translatedWord;
    if (choice == 1) {
        translatedWord = alienToEnglish(word);
    } else if (choice == 2) {
        translatedWord = englishToAlien(word);
    } else {
        printf("Invalid choice.");
        return 1;
    }

    // Print the translated word
    printf("The translated word is: %s\n", translatedWord);

    free(translatedWord);
    return 0;
}