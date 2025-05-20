//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_TRANSLATIONS 100

// Struct to hold the translations
typedef struct {
    char english[MAX_WORD_LENGTH];
    char catLanguage[MAX_WORD_LENGTH];
} Translation;

// Function declarations
void loadTranslations(Translation translations[], int *count);
void translateWord(Translation translations[], int count);
void displayTranslations(Translation translations[], int count);
void saveTranslations(Translation translations[], int count);

// Main function
int main() {
    Translation translations[MAX_TRANSLATIONS];
    int count = 0;
    int choice;

    loadTranslations(translations, &count);

    do {
        printf("\nCat Language Translator Menu:\n");
        printf("1. Translate a word\n");
        printf("2. Display translations\n");
        printf("3. Save translations\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                translateWord(translations, count);
                break;
            case 2:
                displayTranslations(translations, count);
                break;
            case 3:
                saveTranslations(translations, count);
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to load translations from a file
void loadTranslations(Translation translations[], int *count) {
    FILE *file = fopen("translations.txt", "r");
    if (file == NULL) {
        printf("Could not open translations.txt. Starting with an empty list.\n");
        *count = 0;
        return;
    }

    while (fscanf(file, "%s %s", translations[*count].english, translations[*count].catLanguage) != EOF) {
        (*count)++;
        if (*count >= MAX_TRANSLATIONS) break;
    }

    fclose(file);
    printf("Loaded %d translations.\n", *count);
}

// Function to translate a word
void translateWord(Translation translations[], int count) {
    char word[MAX_WORD_LENGTH];
    printf("Enter an English word to translate: ");
    scanf("%s", word);

    for (int i = 0; i < count; i++) {
        if (strcmp(translations[i].english, word) == 0) {
            printf("The cat language translation of '%s' is '%s'.\n", word, translations[i].catLanguage);
            return;
        }
    }

    printf("Translation for '%s' not found! Would you like to add it? (y/n): ", word);
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y') {
        if (count < MAX_TRANSLATIONS) {
            printf("Enter the cat language translation: ");
            scanf("%s", translations[count].catLanguage);
            strcpy(translations[count].english, word);
            count++;
            printf("Added new translation!\n");
        } else {
            printf("Translation list is full!\n");
        }
    }
}

// Function to display all translations
void displayTranslations(Translation translations[], int count) {
    if (count == 0) {
        printf("No translations available.\n");
        return;
    }

    printf("\nTranslations:\n");
    for (int i = 0; i < count; i++) {
        printf("%s -> %s\n", translations[i].english, translations[i].catLanguage);
    }
}

// Function to save translations to a file
void saveTranslations(Translation translations[], int count) {
    FILE *file = fopen("translations.txt", "w");
    if (file == NULL) {
        printf("Could not open translations.txt for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s\n", translations[i].english, translations[i].catLanguage);
    }

    fclose(file);
    printf("Saved %d translations to translations.txt.\n", count);
}