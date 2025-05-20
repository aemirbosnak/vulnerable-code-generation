//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_ALIEN_WORD_LENGTH 25
#define DICTIONARY_SIZE 10

// Structure for alien words and their translations
typedef struct {
    char alien[MAX_ALIEN_WORD_LENGTH];
    char english[MAX_ALIEN_WORD_LENGTH];
} Translation;

// The dictionary of translations
Translation dictionary[DICTIONARY_SIZE] = {
    {"zor", "hello"},
    {"norb", "thank you"},
    {"velk", "friend"},
    {"grim", "goodbye"},
    {"baxu", "please"},
    {"torb", "yes"},
    {"norv", "no"},
    {"zush", "love"},
    {"brik", "peace"},
    {"kalb", "dream"}
};

// Function prototypes
void translateToAlien(char *input);
void translateToEnglish(char *input);
void printDictionary();

int main() {
    char input[MAX_INPUT_LENGTH];
    int choice;

    printf("✨ Welcome to the C Alien Language Translator! ✨\n");
    printf("1. Translate English to Alien\n");
    printf("2. Translate Alien to English\n");
    printf("3. Print Translation Dictionary\n");
    printf("4. Exit\n");

    while (1) {
        printf("\nPlease choose an option (1-4): ");
        scanf("%d", &choice);
        getchar();  // Consume the newline character

        switch (choice) {
            case 1:
                printf("Enter English phrase to translate: ");
                fgets(input, MAX_INPUT_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0;  // Remove newline character
                translateToAlien(input);
                break;
            case 2:
                printf("Enter Alien phrase to translate: ");
                fgets(input, MAX_INPUT_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0;  // Remove newline character
                translateToEnglish(input);
                break;
            case 3:
                printDictionary();
                break;
            case 4:
                printf("🌌 Thank you for using the C Alien Language Translator! 🌌\n");
                return 0;
            default:
                printf("🚫 Invalid choice. Please try again.\n");
                break;
        }
    }
}

// Function to translate English phrases into Alien language
void translateToAlien(char *input) {
    char *token = strtok(input, " ");
    int found;

    printf("👽 Alien Translation: ");
    while (token != NULL) {
        found = 0;
        for (int i = 0; i < DICTIONARY_SIZE; i++) {
            if (strcmp(token, dictionary[i].english) == 0) {
                printf("%s ", dictionary[i].alien);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s ", token);  // If no translation found, keep the original word
        }
        token = strtok(NULL, " ");
    }
    printf("👽\n");
}

// Function to translate Alien phrases into English language
void translateToEnglish(char *input) {
    char *token = strtok(input, " ");
    int found;

    printf("🌌 English Translation: ");
    while (token != NULL) {
        found = 0;
        for (int i = 0; i < DICTIONARY_SIZE; i++) {
            if (strcmp(token, dictionary[i].alien) == 0) {
                printf("%s ", dictionary[i].english);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s ", token);  // If no translation found, keep the original word
        }
        token = strtok(NULL, " ");
    }
    printf("🌌\n");
}

// Function to print the translation dictionary
void printDictionary() {
    printf("📖 Translation Dictionary:\n");
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        printf("   Alien: %s <=> English: %s\n", dictionary[i].alien, dictionary[i].english);
    }
}