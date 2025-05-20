//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20
#define MAX_TRANSLATIONS 100

// Structure to hold Cat Language translations.
typedef struct {
    char *english;
    char *catLang;
} Translation;

// Global array to store translations.
Translation translations[MAX_TRANSLATIONS];
int translationCount = 0;

// Function declarations.
void addTranslation(const char *english, const char *catLang);
void translateToCatLang(const char *input);
void loadTranslations(const char *filename);
void displayTranslations();

// Main function.
int main() {
    // Load predefined translations from a file.
    loadTranslations("translations.txt");

    // User interaction loop.
    char input[MAX_WORD_LENGTH];
    printf("Welcome to the Cat Language Translator!\n");
    printf("Type 'exit' to quit.\n");
    
    while (true) {
        printf("Enter an English word/phrase to translate: ");
        fgets(input, MAX_WORD_LENGTH, stdin);
        
        // Remove the newline character.
        input[strcspn(input, "\n")] = 0;

        // Exit condition.
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Perform translation.
        translateToCatLang(input);
    }

    // Display all translations.
    displayTranslations();
    return 0;
}

// Function to add translations to the global array.
void addTranslation(const char *english, const char *catLang) {
    if (translationCount < MAX_TRANSLATIONS) {
        translations[translationCount].english = strdup(english);
        translations[translationCount].catLang = strdup(catLang);
        translationCount++;
    } else {
        printf("Translation limit reached! Cannot add more translations.\n");
    }
}

// Function to translate input English words/phrases to Cat Language.
void translateToCatLang(const char *input) {
    bool found = false;
    for (int i = 0; i < translationCount; i++) {
        if (strcmp(translations[i].english, input) == 0) {
            printf("In Cat Language: %s\n", translations[i].catLang);
            found = true;
            break;
        }
    }
    if (!found) {
        printf("Sorry, no translation found for '%s'.\n", input);
    }
}

// Function to load translations from a text file.
void loadTranslations(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open translations file.");
        return;
    }

    char english[MAX_WORD_LENGTH];
    char catLang[MAX_WORD_LENGTH];
    
    while (fscanf(file, "%s %s", english, catLang) == 2) {
        addTranslation(english, catLang);
    }

    fclose(file);
}

// Function to display all translations.
void displayTranslations() {
    printf("\nTranslations Available:\n");
    for (int i = 0; i < translationCount; i++) {
        printf("%s => %s\n", translations[i].english, translations[i].catLang);
    }
}

// Sample translations file contents (translations.txt):
// cat meow
// dog woof
// hello purr
// food nomnom
// sleep zzz
// treat crunchy
// play chase
// love snuggle