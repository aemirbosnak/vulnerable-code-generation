//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size constants
#define MAX_WORD_LENGTH 100
#define MAX_TRANSLATIONS 100

// Structure to hold Cat words and their corresponding English translations
typedef struct {
    char cat_word[MAX_WORD_LENGTH];
    char english_translation[MAX_WORD_LENGTH];
} Translation;

// Function to load translations from a file
int load_translations(const char *filename, Translation translations[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return -1;
    }

    int count = 0;
    while (count < MAX_TRANSLATIONS && fscanf(file, "%s %s", translations[count].cat_word, translations[count].english_translation) == 2) {
        count++;
    }

    fclose(file);
    return count;
}

// Function to translate a word from Cat Language to English
const char* translate(const char *cat_word, Translation translations[], int num_translations) {
    for (int i = 0; i < num_translations; i++) {
        if (strcmp(cat_word, translations[i].cat_word) == 0) {
            return translations[i].english_translation;
        }
    }
    return "Translation not found";
}

// Function to display the menu
void display_menu() {
    printf("\n--- Cat Language Translator ---\n");
    printf("1. Translate a word\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

// Main function
int main() {
    Translation translations[MAX_TRANSLATIONS];
    
    // Load translations from a file
    int num_translations = load_translations("translations.txt", translations);
    if (num_translations == -1) {
        return EXIT_FAILURE;
    }

    char input[MAX_WORD_LENGTH];
    int choice;

    // Main loop for the translator interface
    while (1) {
        display_menu();
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter a Cat word to translate: ");
            scanf("%s", input);
            const char *result = translate(input, translations, num_translations);
            printf("Translation: %s\n", result);
        } else if (choice == 2) {
            printf("Exiting the translator. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return EXIT_SUCCESS;
}