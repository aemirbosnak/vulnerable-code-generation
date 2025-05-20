//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define CAT_KEYWORD_COUNT 5

char *catKeywords[CAT_KEYWORD_COUNT][2] = {
    {"meow", "hello"},
    {"purr", "good"},
    {"hiss", "bad"},
    {"paw", "friend"},
    {"mew", "yes"}
};

void initializeCatKeywords() {
    // Populate catKeywords array with translations
    // This is a placeholder for any dynamic initialization if needed in future
}

const char* translateToCatLanguage(const char* word) {
    for (int i = 0; i < CAT_KEYWORD_COUNT; i++) {
        if (strcmp(word, catKeywords[i][0]) == 0) {
            return catKeywords[i][1]; // Return the corresponding English word
        }
    }
    return NULL; // Return NULL if the word is not found
}

const char* translateToEnglish(const char* word) {
    for (int i = 0; i < CAT_KEYWORD_COUNT; i++) {
        if (strcmp(word, catKeywords[i][1]) == 0) {
            return catKeywords[i][0]; // Return the corresponding Cat word
        }
    }
    return NULL; // Return NULL if the word is not found
}

void displayTranslationMenu() {
    printf("Welcome to the Cat Language Translator!\n");
    printf("1. Translate from Cat to English\n");
    printf("2. Translate from English to Cat\n");
    printf("3. Show available keywords\n");
    printf("4. Exit\n");
}

void showKeywords() {
    printf("Available Cat Language Keywords:\n");
    for (int i = 0; i < CAT_KEYWORD_COUNT; i++) {
        printf("%s -> %s\n", catKeywords[i][0], catKeywords[i][1]);
    }
}

int main() {
    char input[MAX_LENGTH];
    int choice;

    initializeCatKeywords();

    while (1) {
        displayTranslationMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character after the number input

        switch (choice) {
            case 1: // Cat to English
                printf("Enter a word in Cat Language: ");
                fgets(input, MAX_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0; // Remove the newline character

                {
                    const char *translation = translateToEnglish(input);
                    if (translation) {
                        printf("Translation: %s\n", translation);
                    } else {
                        printf("No translation found for '%s'.\n", input);
                    }
                }
                break;

            case 2: // English to Cat
                printf("Enter a word in English: ");
                fgets(input, MAX_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0; // Remove the newline character

                {
                    const char *translation = translateToCatLanguage(input);
                    if (translation) {
                        printf("Translation: %s\n", translation);
                    } else {
                        printf("No translation found for '%s'.\n", input);
                    }
                }
                break;

            case 3:
                showKeywords();
                break;

            case 4:
                printf("Thank you for using the Cat Language Translator! Goodbye!\n");
                exit(0);
            
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}