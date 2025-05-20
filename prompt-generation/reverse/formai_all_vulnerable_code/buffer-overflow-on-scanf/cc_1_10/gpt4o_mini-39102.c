//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024
#define DICTIONARY_SIZE 10

// Structure to represent a word and its translation
typedef struct {
    char english[20];
    char alien[20];
} Translation;

// Pre-defined dictionary for English to Alien language
Translation dictionary[DICTIONARY_SIZE] = {
    {"hello", "xarim"},
    {"world", "zotul"},
    {"yes", "glar"},
    {"no", "kree"},
    {"please", "thuka"},
    {"thank", "balur"},
    {"goodbye", "sevrak"},
    {"friend", "zali"},
    {"love", "tana"},
    {"help", "mrito"}
};

// Function to translate from English to Alien language
void translateToAlien(char *input) {
    char *token = strtok(input, " ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < DICTIONARY_SIZE; i++) {
            if (strcasecmp(token, dictionary[i].english) == 0) {
                printf("%s ", dictionary[i].alien);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s ", token); // Print the original word if no translation is found
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}

// Function to print the dictionary
void printDictionary() {
    printf("English to Alien Dictionary:\n");
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        printf("%s -> %s\n", dictionary[i].english, dictionary[i].alien);
    }
}

// Main menu function
void displayMenu() {
    printf("\n===== Alien Language Translator =====\n");
    printf("1. Translate English to Alien\n");
    printf("2. Display Dictionary\n");
    printf("3. Exit\n");
}

int main() {
    char input[MAX_LENGTH];
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                printf("Enter a sentence in English: ");
                fgets(input, MAX_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline character
                printf("Translation: ");
                translateToAlien(input);
                break;
            case 2:
                printDictionary();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    return 0;
}