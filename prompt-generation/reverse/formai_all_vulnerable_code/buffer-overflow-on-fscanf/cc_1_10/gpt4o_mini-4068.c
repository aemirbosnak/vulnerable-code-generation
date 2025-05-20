//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Alien Language Translators
#define MAX_WORD_LENGTH 100
#define MAX_TRANSLATIONS 100

// Structure to hold alien words and their translations
typedef struct {
    char alien[MAX_WORD_LENGTH];
    char human[MAX_WORD_LENGTH];
} Translation;

// Function prototypes
void loadTranslations(Translation translations[], int *count);
void translateToHuman(const Translation translations[], int count);
void printTranslations(const Translation translations[], int count);
void addTranslation(Translation translations[], int *count);
void saveTranslations(const Translation translations[], int count);

int main() {
    Translation translations[MAX_TRANSLATIONS];
    int count = 0;
    int choice;

    loadTranslations(translations, &count);

    do {
        printf("\n--- Alien Language Translator ---\n");
        printf("1. Translate to Human Language\n");
        printf("2. Add a Translation\n");
        printf("3. Print All Translations\n");
        printf("4. Save Translations to File\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume the newline character

        switch (choice) {
            case 1:
                translateToHuman(translations, count);
                break;
            case 2:
                addTranslation(translations, &count);
                break;
            case 3:
                printTranslations(translations, count);
                break;
            case 4:
                saveTranslations(translations, count);
                break;
            case 0:
                printf("Exiting the Alien Language Translator. Farewell Traveler!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to load translations from a file
void loadTranslations(Translation translations[], int *count) {
    FILE *file = fopen("translations.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open translations.txt for reading.\n");
        return;
    }

    while (fscanf(file, "%s %s", translations[*count].alien, translations[*count].human) != EOF) {
        (*count)++;
    }
    fclose(file);
}

// Function to translate an alien word to human language
void translateToHuman(const Translation translations[], int count) {
    char word[MAX_WORD_LENGTH];
    printf("Enter an alien word to translate: ");
    fgets(word, MAX_WORD_LENGTH, stdin);
    word[strcspn(word, "\n")] = 0; // Remove newline character

    for (int i = 0; i < count; i++) {
        if (strcmp(translations[i].alien, word) == 0) {
            printf("The human translation of '%s' is '%s'.\n", word, translations[i].human);
            return;
        }
    }
    printf("Sorry, the translation for '%s' was not found.\n", word);
}

// Function to print all translations
void printTranslations(const Translation translations[], int count) {
    printf("\nCurrent Translations:\n");
    for (int i = 0; i < count; i++) {
        printf("Alien: %s -> Human: %s\n", translations[i].alien, translations[i].human);
    }
}

// Function to add a new translation
void addTranslation(Translation translations[], int *count) {
    if (*count >= MAX_TRANSLATIONS) {
        printf("Maximum translations reached. Cannot add more.\n");
        return;
    }

    printf("Enter the alien word: ");
    fgets(translations[*count].alien, MAX_WORD_LENGTH, stdin);
    translations[*count].alien[strcspn(translations[*count].alien, "\n")] = 0; // Remove newline

    printf("Enter the human translation: ");
    fgets(translations[*count].human, MAX_WORD_LENGTH, stdin);
    translations[*count].human[strcspn(translations[*count].human, "\n")] = 0; // Remove newline

    (*count)++;
    printf("Translation added!\n");
}

// Function to save translations to a file
void saveTranslations(const Translation translations[], int count) {
    FILE *file = fopen("translations.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open translations.txt for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s\n", translations[i].alien, translations[i].human);
    }
    fclose(file);
    printf("Translations saved successfully!\n");
}