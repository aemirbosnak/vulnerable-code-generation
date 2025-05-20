//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_TRANSLATIONS 100

typedef struct {
    char alienWord[MAX_WORD_LENGTH];
    char englishWord[MAX_WORD_LENGTH];
} Translation;

Translation glossary[MAX_TRANSLATIONS];
int translationCount = 0;

// Function prototypes
void addTranslation(const char *alienWord, const char *englishWord);
void translateToEnglish(const char *alienText);
void loadTranslationsFromFile(const char *fileName);
void displayTranslations();
void clearGlossary();

int main() {
    int choice;
    char alienText[MAX_WORD_LENGTH];

    loadTranslationsFromFile("translations.txt");

    do {
        printf("\n--- Alien Language Translator ---\n");
        printf("1. Translate alien text to English\n");
        printf("2. Display existing translations\n");
        printf("3. Clear all translations\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline character

        switch (choice) {
            case 1:
                printf("Enter alien text to translate: ");
                fgets(alienText, MAX_WORD_LENGTH, stdin);
                alienText[strcspn(alienText, "\n")] = 0; // Remove trailing newline
                translateToEnglish(alienText);
                break;
            case 2:
                displayTranslations();
                break;
            case 3:
                clearGlossary();
                printf("All translations cleared.\n");
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addTranslation(const char *alienWord, const char *englishWord) {
    if (translationCount < MAX_TRANSLATIONS) {
        strcpy(glossary[translationCount].alienWord, alienWord);
        strcpy(glossary[translationCount].englishWord, englishWord);
        translationCount++;
    } else {
        printf("Glossary is full, cannot add more translations.\n");
    }
}

void translateToEnglish(const char *alienText) {
    printf("Translating alien text: '%s'\n", alienText);
    char *token;
    char alienWord[MAX_WORD_LENGTH];

    token = strtok((char*)alienText, " ");
    while (token != NULL) {
        strcpy(alienWord, token);
        int found = 0;
        
        for (int i = 0; i < translationCount; i++) {
            if (strcmp(glossary[i].alienWord, alienWord) == 0) {
                printf("%s ", glossary[i].englishWord);
                found = 1;
                break;
            }
        }
        
        if (!found) {
            printf("[unknown word: %s] ", alienWord);
        }
        
        token = strtok(NULL, " ");
    }
    printf("\n");
}

void loadTranslationsFromFile(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Could not open file %s for reading.\n", fileName);
        return;
    }

    char alienWord[MAX_WORD_LENGTH];
    char englishWord[MAX_WORD_LENGTH];

    while (fscanf(file, "%s %s", alienWord, englishWord) == 2) {
        addTranslation(alienWord, englishWord);
    }

    fclose(file);
    printf("Loaded %d translations from %s\n", translationCount, fileName);
}

void displayTranslations() {
    printf("\nCurrent Translations:\n");
    for (int i = 0; i < translationCount; i++) {
        printf("%s -> %s\n", glossary[i].alienWord, glossary[i].englishWord);
    }
}

void clearGlossary() {
    translationCount = 0;
}