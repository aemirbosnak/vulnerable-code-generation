//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_TRANSLATIONS 100

typedef struct {
    char alienWord[MAX_WORD_LENGTH];
    char englishWord[MAX_WORD_LENGTH];
} Translation;

Translation translations[MAX_TRANSLATIONS];
int translationCount = 0;

// Function to load alien words and translations from a file
void loadTranslations(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open translation file");
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(file, "%s %s", translations[translationCount].alienWord, translations[translationCount].englishWord) == 2) {
        translationCount++;
        if (translationCount >= MAX_TRANSLATIONS) {
            break;
        }
    }
    
    fclose(file);
}

// Function to translate words from alien language to English
void translateToEnglish(const char *alienText) {
    char word[MAX_WORD_LENGTH];
    int index = 0;

    for (int i = 0; ; i++) {
        if (alienText[i] == ' ' || alienText[i] == '\0') {
            word[index] = '\0';
            int found = 0;

            // Find the translation for the current word
            for (int j = 0; j < translationCount; j++) {
                if (strcmp(word, translations[j].alienWord) == 0) {
                    printf("%s ", translations[j].englishWord);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("[untranslated: %s] ", word);
            }
            index = 0; // Reset index to start new word

            if (alienText[i] == '\0') {
                break; // End of input
            }
        } else {
            word[index++] = alienText[i]; // Build the word character by character
        }
    }
    printf("\n"); // Newline after translation
}

// Function to perform a simple menu
void menu() {
    int choice;
    char alienText[256];
    
    while (1) {
        printf("Alien Language Translator\n");
        printf("1. Translate a phrase\n");
        printf("2. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter the alien phrase: ");
                fgets(alienText, sizeof(alienText), stdin);
                alienText[strcspn(alienText, "\n")] = 0; // Remove newline character
                translateToEnglish(alienText);
                break;
            case 2:
                printf("Exiting translator. Goodbye!\n");
                return;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
}

int main() {
    loadTranslations("translations.txt"); // Load translations from a file
    menu(); // Start the interactive menu
    return 0;
}