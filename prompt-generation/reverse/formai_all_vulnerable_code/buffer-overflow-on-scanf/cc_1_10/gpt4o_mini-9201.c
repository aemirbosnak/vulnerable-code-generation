//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 256
#define ALIEN_COUNT 3

// All the Alien language transformations we will create
const char* alienLanguages[ALIEN_COUNT][2] = {
    {"human", "blorp"},
    {"hello", "zorp"},
    {"friend", "gloop"}
};

// Function to translate from human language to Alien language
void translateToAlien(char* input, char* translation) {
    char* token = strtok(input, " ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < ALIEN_COUNT; i++) {
            if (strcmp(token, alienLanguages[i][0]) == 0) {
                strcat(translation, alienLanguages[i][1]);
                strcat(translation, " ");
                found = 1;
                break;
            }
        }
        if (!found) {
            strcat(translation, token);
            strcat(translation, " ");
        }
        token = strtok(NULL, " ");
    }
    translation[strlen(translation) - 1] = '\0'; // Remove the trailing space
}

// Function to show the main menu
void displayMenu() {
    printf("Welcome to the Alien Language Translator!\n");
    printf("1. Translate Text to Alien Language\n");
    printf("2. Exit\n");
}

// Main function
int main() {
    char input[MAX_LENGTH];
    char translation[MAX_LENGTH] = "";

    while (1) {
        displayMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline character

        if (choice == 1) {
            printf("Enter a sentence in human language: ");
            fgets(input, MAX_LENGTH, stdin);
            // Remove newline character from fgets
            input[strcspn(input, "\n")] = 0;

            // Prepare translation
            memset(translation, 0, sizeof(translation)); // Clear previous translation
            translateToAlien(input, translation);

            printf("Translated to Alien Language: %s\n", translation);
        } else if (choice == 2) {
            printf("Exiting the Alien Language Translator. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice, please try again!\n");
        }
    }

    return 0;
}