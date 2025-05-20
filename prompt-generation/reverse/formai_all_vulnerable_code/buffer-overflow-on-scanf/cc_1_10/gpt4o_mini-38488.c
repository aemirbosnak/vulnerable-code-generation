//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define MAX_TRANSLATIONS 100

typedef struct {
    char english[MAX_WORD_LENGTH];
    char catLanguage[MAX_WORD_LENGTH];
} Translation;

Translation dictionary[MAX_TRANSLATIONS];
int dictSize = 0;

void loadTranslations() {
    // Adding some sample translations
    strcpy(dictionary[dictSize].english, "cat");
    strcpy(dictionary[dictSize++].catLanguage, "meow");
    
    strcpy(dictionary[dictSize].english, "dog");
    strcpy(dictionary[dictSize++].catLanguage, "woof");

    strcpy(dictionary[dictSize].english, "hello");
    strcpy(dictionary[dictSize++].catLanguage, "mew");

    strcpy(dictionary[dictSize].english, "friend");
    strcpy(dictionary[dictSize++].catLanguage, "purr");

    strcpy(dictionary[dictSize].english, "food");
    strcpy(dictionary[dictSize++].catLanguage, "nibble");

    // Add more translations as needed
}

void translateWord(const char* input) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(dictionary[i].english, input) == 0) {
            printf("English: %s - Cat Language: %s\n", input, dictionary[i].catLanguage);
            return;
        }
    }
    printf("Translation not found for: %s\n", input);
}

void displayMenu() {
    printf("\n--- Cat Language Translator ---\n");
    printf("1. Translate a word\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char input[MAX_WORD_LENGTH];
    int choice;

    loadTranslations();

    while (true) {
        displayMenu();
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Enter a word in English to translate: ");
            scanf("%s", input);
            translateWord(input);
        } else if (choice == 2) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}