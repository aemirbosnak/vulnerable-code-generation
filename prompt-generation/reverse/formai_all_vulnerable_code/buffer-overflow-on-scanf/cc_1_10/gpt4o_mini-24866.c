//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_TRANSLATIONS 100

// Structure to hold each English word and its corresponding Alien language translated word
typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Translation;

// Function prototypes
void loadTranslations(Translation translations[], int *count);
void translateWord(Translation translations[], int count, const char *word);
void displayTranslations(Translation translations[], int count);
void cleanBuffer();

int main() {
    Translation translations[MAX_TRANSLATIONS];
    int count = 0;
    int choice;
    
    // Load translations from a file or directly
    loadTranslations(translations, &count);

    printf("Welcome to the Alien Language Translator!\n");
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Translate a word\n");
        printf("2. Display all translations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        cleanBuffer(); // Clear the input buffer

        switch (choice) {
            case 1: {
                char word[MAX_WORD_LENGTH];
                printf("Enter the English word to translate: ");
                fgets(word, MAX_WORD_LENGTH, stdin);
                word[strcspn(word, "\n")] = 0; // Remove newline character
                translateWord(translations, count, word);
                break;
            }
            case 2:
                displayTranslations(translations, count);
                break;
            case 3:
                printf("Exiting the translator. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void loadTranslations(Translation translations[], int *count) {
    // Hardcoded translations for demonstration. In a real application,
    // you might load this from an external file.
    snprintf(translations[(*count)++].english, MAX_WORD_LENGTH, "hello");
    snprintf(translations[(*count)++].alien, MAX_WORD_LENGTH, "zxylo");

    snprintf(translations[(*count)++].english, MAX_WORD_LENGTH, "world");
    snprintf(translations[(*count)++].alien, MAX_WORD_LENGTH, "planto");

    snprintf(translations[(*count)++].english, MAX_WORD_LENGTH, "friend");
    snprintf(translations[(*count)++].alien, MAX_WORD_LENGTH, "gleeb");

    snprintf(translations[(*count)++].english, MAX_WORD_LENGTH, "computer");
    snprintf(translations[(*count)++].alien, MAX_WORD_LENGTH, "kribl");

    snprintf(translations[(*count)++].english, MAX_WORD_LENGTH, "translate");
    snprintf(translations[(*count)++].alien, MAX_WORD_LENGTH, "troglog");
}

void translateWord(Translation translations[], int count, const char *word) {
    for (int i = 0; i < count; i++) {
        if (strcmp(translations[i].english, word) == 0) {
            printf("The translation of '%s' in Alien language is: '%s'\n", word, translations[i].alien);
            return;
        }
    }
    printf("Sorry, the word '%s' is not in the translation dictionary.\n", word);
}

void displayTranslations(Translation translations[], int count) {
    printf("\nTranslations in the dictionary:\n");
    for (int i = 0; i < count; i++) {
        printf("English: %s - Alien: %s\n", translations[i].english, translations[i].alien);
    }
}

void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}