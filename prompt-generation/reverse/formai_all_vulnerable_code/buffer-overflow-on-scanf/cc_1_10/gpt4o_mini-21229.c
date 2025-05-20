//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PHRASE_LENGTH 100
#define MAX_TRANSLATIONS 10

// Structure to hold English-Cat translations
typedef struct {
    char *english;
    char *catLanguage;
} Translation;

// Function to display the menu
void displayMenu() {
    printf("Welcome to the Cat Language Translator!\n");
    printf("Please choose an option:\n");
    printf("1. Translate a phrase to Cat Language\n");
    printf("2. List all translations\n");
    printf("3. Exit\n");
}

// Function to translate a phrase
void translatePhrase(Translation translations[], int translationCount) {
    char input[MAX_PHRASE_LENGTH];
    printf("Enter a phrase in English (up to %d characters): ", MAX_PHRASE_LENGTH - 1);
    getchar();  // Clear the buffer
    fgets(input, MAX_PHRASE_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    int found = 0;

    for (int i = 0; i < translationCount; i++) {
        if (strcasecmp(input, translations[i].english) == 0) {
            printf("Translation in Cat Language: %s\n", translations[i].catLanguage);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Sorry, I don't know how to say '%s' in Cat Language.\n", input);
    }
}

// Function to list all translations
void listTranslations(Translation translations[], int translationCount) {
    printf("Available translations:\n");
    for (int i = 0; i < translationCount; i++) {
        printf("'%s' -> '%s'\n", translations[i].english, translations[i].catLanguage);
    }
}

int main() {
    // Define some translations
    Translation translations[MAX_TRANSLATIONS] = {
        {"Hello", "Meow"},
        {"Food", "NomNom"},
        {"Play", "Pounce"},
        {"Sleep", "Zzz"},
        {"Goodbye", "Pawpaw"},
        {"Cat", "Feline"},
        {"Dog", "Mutt"},
        {"Mouse", "Squeak"},
        {"Human", "Servant"},
        {"Help", "Purr"},
    };

    int translationCount = 10;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                translatePhrase(translations, translationCount);
                break;
            case 2:
                listTranslations(translations, translationCount);
                break;
            case 3:
                printf("Exiting the Cat Language Translator. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}