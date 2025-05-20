//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input text
#define MAX_INPUT_LENGTH 100

// Define the maximum number of translations that can be stored
#define MAX_TRANSLATIONS 10

// Define a struct for storing translations
typedef struct {
    char original[20];
    char translated[20];
} Translation;

// Define an array to store translations
Translation translations[MAX_TRANSLATIONS];

// Define a function to get input from the user
char* get_input() {
    char* input = (char*) malloc(sizeof(char) * MAX_INPUT_LENGTH);
    printf("Enter text to translate: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline
    return input;
}

// Define a function to search for a translation
char* search_translation(char* original) {
    for (int i = 0; i < MAX_TRANSLATIONS; i++) {
        if (strcmp(original, translations[i].original) == 0) {
            return translations[i].translated;
        }
    }
    return NULL;
}

// Define a function to add a translation
void add_translation(char* original, char* translated) {
    for (int i = 0; i < MAX_TRANSLATIONS; i++) {
        if (strlen(translations[i].original) == 0) {
            strcpy(translations[i].original, original);
            strcpy(translations[i].translated, translated);
            printf("Translation added.\n");
            return;
        }
    }
    printf("Maximum number of translations reached.\n");
}

// Define the main function
int main() {
    printf("Welcome to the C Cat Language Translator!\n");
    while (1) {
        printf("\n");
        printf("1. Translate text\n");
        printf("2. Add translation\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);
        getchar(); // Clear the newline from the input buffer
        switch (choice) {
            case 1: {
                char* original = get_input();
                char* translated = search_translation(original);
                if (translated == NULL) {
                    printf("Translation not found.\n");
                } else {
                    printf("Translation: %s\n", translated);
                }
                free(original);
                break;
            }
            case 2: {
                char* original = get_input();
                char* translated = get_input();
                add_translation(original, translated);
                free(original);
                free(translated);
                break;
            }
            case 3: {
                printf("Goodbye!\n");
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    }
    return 0;
}