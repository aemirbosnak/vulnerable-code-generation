//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_TRANSLATIONS 100

// Structure to hold alien translations
typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Translation;

// Function to convert a word to the alien language
void convertToAlien(char *input, Translation *translations, int totalTranslations) {
    for (int i = 0; i < totalTranslations; i++) {
        if (strcmp(translations[i].english, input) == 0) {
            printf("Alien Translation: %s\n", translations[i].alien);
            return;
        }
    }
    printf("Alien Translation: Unknown Word\n");
}

// Function to load translations from a file
int loadTranslations(const char *filename, Translation *translations) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open translation file");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%s %s", translations[count].english, translations[count].alien) == 2) {
        count++;
    }

    fclose(file);
    return count;
}

// Function to convert the entire input to the alien language
void convertSentenceToAlien(char *sentence, Translation *translations, int totalTranslations) {
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        convertToAlien(word, translations, totalTranslations);
        word = strtok(NULL, " ");
    }
}

int main() {
    Translation translations[MAX_TRANSLATIONS];
    int totalTranslations = loadTranslations("translations.txt", translations);

    if (totalTranslations <= 0) {
        printf("No translations available. Please check the translation file.\n");
        return 1;
    }

    char inputSentence[256];
    printf("Welcome to the Alien Language Translator!\n");
    printf("Enter a sentence to be translated into the alien language:\n");

    // Read user input sentence
    fgets(inputSentence, sizeof(inputSentence), stdin);
    inputSentence[strcspn(inputSentence, "\n")] = 0; // Remove newline character

    printf("Translating...\n");
    convertSentenceToAlien(inputSentence, translations, totalTranslations);

    return 0;
}