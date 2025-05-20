//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 256

// A structure to hold translator mappings
struct Translation {
    char *alienWord;
    char *humanWord;
};

// Function to display the translation menu
void displayMenu() {
    printf("Welcome to the Alien Language Translator!\n");
    printf("1. Translate Alien to Human\n");
    printf("2. Translate Human to Alien\n");
    printf("3. Exit\n");
    printf("Please select an option (1-3): ");
}

// Function to initialize translation data
void initializeTranslations(struct Translation *translations, int *size) {
    translations[0] = (struct Translation) {"Xabool", "Hello"};
    translations[1] = (struct Translation) {"Kreezle", "Friend"};
    translations[2] = (struct Translation) {"Zonplax", "Alien"};
    translations[3] = (struct Translation) {"Vlukor", "Goodbye"};
    translations[4] = (struct Translation) {"Qroth", "Yes"};
    translations[5] = (struct Translation) {"Zekra", "No"};
    *size = 6; // Total number of translations
}

// Function to fetch the human translation for a given alien word
const char* translateToHuman(const char *alienWord, struct Translation *translations, int size) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(translations[i].alienWord, alienWord) == 0) {
            return translations[i].humanWord;
        }
    }
    return "Unknown translation";
}

// Function to fetch the alien translation for a given human word
const char* translateToAlien(const char *humanWord, struct Translation *translations, int size) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(translations[i].humanWord, humanWord) == 0) {
            return translations[i].alienWord;
        }
    }
    return "Unknown translation";
}

// Main function to execute the program
int main() {
    struct Translation translations[MAX_LENGTH];
    int size, choice;
    char input[MAX_LENGTH];

    initializeTranslations(translations, &size);

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // To consume newline after the number input

        if (choice == 3) {
            printf("Thank you for using the Alien Language Translator. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter the alien word: ");
                fgets(input, MAX_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline character
                printf("Human translation: %s\n", translateToHuman(input, translations, size));
                break;
            case 2:
                printf("Enter the human word: ");
                fgets(input, MAX_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline character
                printf("Alien translation: %s\n", translateToAlien(input, translations, size));
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    }

    return 0;
}