//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LEN 50

// Struct to hold alien language translations
typedef struct {
    char english[MAX_LEN];
    char alien[MAX_LEN];
} Translation;

// Function prototypes
void loadTranslations(Translation translations[], int *count);
void translateWord(const Translation translations[], int count, const char *word, char *output);
void displayTranslations(const Translation translations[], int count);
void freeTranslations(Translation translations[]);

int main() {
    Translation translations[MAX_WORDS];
    int count = 0;
    char input[MAX_LEN], output[MAX_LEN];

    loadTranslations(translations, &count);
    
    printf("Welcome to the C Alien Language Translator!\n");
    printf("You can type in an English word to translate it into Alien language.\n");
    printf("To exit, type 'exit'.\n");

    while (1) {
        printf("\nEnter a word to translate: ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        translateWord(translations, count, input, output);
        
        if (strlen(output) > 0) {
            printf("Alien Translation: %s\n", output);
        } else {
            printf("Sorry, no translation found for '%s'.\n", input);
        }
    }

    freeTranslations(translations);
    printf("Thank you for using the C Alien Language Translator! Goodbye.\n");
    return 0;
}

// Load translations from a file
void loadTranslations(Translation translations[], int *count) {
    FILE *file = fopen("translations.txt", "r");
    if (file == NULL) {
        perror("Error opening translations file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %s", translations[*count].english, translations[*count].alien) != EOF) {
        (*count)++;
        if (*count >= MAX_WORDS) {
            printf("Max translations reached, stopping load.\n");
            break;
        }
    }
    fclose(file);
}

// Translate an English word to Alien language
void translateWord(const Translation translations[], int count, const char *word, char *output) {
    output[0] = '\0'; // Clear the output
    for (int i = 0; i < count; i++) {
        if (strcmp(translations[i].english, word) == 0) {
            strcpy(output, translations[i].alien);
            return;
        }
    }
}

// Display all translations (for testing)
void displayTranslations(const Translation translations[], int count) {
    printf("\n--- Current Translations ---\n");
    for (int i = 0; i < count; i++) {
        printf("%s -> %s\n", translations[i].english, translations[i].alien);
    }
}

// Free dynamic memory allocated for translations (if necessary)
void freeTranslations(Translation translations[]) {
    // No dynamic allocation used in this example, but in case of future use
}