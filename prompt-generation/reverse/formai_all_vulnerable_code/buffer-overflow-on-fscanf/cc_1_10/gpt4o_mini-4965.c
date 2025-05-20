//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_TRANSLATIONS 100

// Structure to store words and their translations
typedef struct {
    char alienWord[MAX_WORD_LENGTH];
    char englishTranslation[MAX_WORD_LENGTH];
} Translation;

// Function to read translations from a file
int loadTranslations(const char *filename, Translation translations[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening the file");
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%s %s", translations[count].alienWord, translations[count].englishTranslation) != EOF) {
        count++;
        if (count >= MAX_TRANSLATIONS) {
            break;
        }
    }

    fclose(file);
    return count;
}

// Function to translate an alien word to English
const char* translateWord(const char *alienWord, Translation translations[], int translationCount) {
    for (int i = 0; i < translationCount; i++) {
        if (strcmp(alienWord, translations[i].alienWord) == 0) {
            return translations[i].englishTranslation;
        }
    }
    return NULL; // Word not found
}

// Main function to handle user input and perform translations
int main() {
    Translation translations[MAX_TRANSLATIONS];
    int translationCount = loadTranslations("translations.txt", translations);
    
    if (translationCount < 0) {
        return EXIT_FAILURE;
    }

    char inputWord[MAX_WORD_LENGTH];
    printf("Welcome to the Alien Language Translator!\n");
    printf("Enter an alien word to translate (or 'exit' to quit): \n");

    while (1) {
        printf("Alien Word: ");
        scanf("%s", inputWord);

        if (strcmp(inputWord, "exit") == 0) {
            break;
        }

        const char *translated = translateWord(inputWord, translations, translationCount);
        if (translated != NULL) {
            printf("Translation: %s\n", translated);
        } else {
            printf("Translation not found for '%s'.\n", inputWord);
        }
    }

    printf("Thank you for using the Alien Language Translator!\n");
    return EXIT_SUCCESS;
}