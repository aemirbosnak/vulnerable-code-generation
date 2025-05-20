//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The maze of translations
// A structure to hold Cat language symbols
struct CatLanguage {
    char *english;
    char *catSpeak;
};

// Our dictionary, a meow-tastic collection
struct CatLanguage dictionary[] = {
    {"hello", "meow"}, 
    {"goodbye", "meow meow"},
    {"food", "mew"},
    {"friend", "purr"},
    {"play", "hiss hiss"},
    {"yes", "meowww"},
    {"no", "nyan"},
    {"please", "purrr"},
    {"thank you", "mrow"},
    {"sorry", "mew?"},
    {"love", "purr purr"}
};

// Function declarations
void translateToCatSpeak(char *input);
void displayDictionary();
int findTranslation(char *word);
void clearInputBuffer();

int main() {
    char input[100];
    int choice;

    printf("Welcome to the Cat Language Translator!\n");
    printf("What would you like to do?\n");
    printf("1. Translate a word/phrase to Cat Language\n");
    printf("2. View the Cat Language Dictionary\n");
    printf("3. Exit the translator\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                printf("Enter the English word/phrase: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove trailing newline
                translateToCatSpeak(input);
                break;
            case 2:
                displayDictionary();
                break;
            case 3:
                printf("Goodbye! May your days be filled with purrs!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    return 0;
}

void translateToCatSpeak(char *input) {
    int found = findTranslation(input);
    if (found >= 0) {
        printf("In Cat Language: %s\n", dictionary[found].catSpeak);
    } else {
        printf("Sorry, I don't know how to say '%s' in Cat Language.\n", input);
    }
}

// Find the translation of an input word
int findTranslation(char *word) {
    for (int i = 0; i < sizeof(dictionary) / sizeof(dictionary[0]); i++) {
        if (strcasecmp(dictionary[i].english, word) == 0) {
            return i; // Return the index of the found word
        }
    }
    return -1; // Not found
}

// Display the Cat Language Dictionary
void displayDictionary() {
    printf("\n--- Cat Language Dictionary ---\n");
    for (int i = 0; i < sizeof(dictionary) / sizeof(dictionary[0]); i++) {
        printf("%s -> %s\n", dictionary[i].english, dictionary[i].catSpeak);
    }
    printf("-------------------------------\n");
}

// Clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}