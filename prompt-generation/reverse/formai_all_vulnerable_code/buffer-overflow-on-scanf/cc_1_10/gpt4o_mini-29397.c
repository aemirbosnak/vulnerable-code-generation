//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256

// Function prototypes
void toAlienLanguage(const char *input, char *output);
void fromAlienLanguage(const char *input, char *output);
void toLower(char *str);
void displayMenu();

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    int choice;
    
    printf("Welcome to the Alien Language Translator, dear Watson!\n");
    displayMenu();

    while(1) {
        printf("Please make a choice (1-3): ");
        scanf("%d", &choice);
        getchar();  // To consume the newline after the choice.

        switch(choice) {
            case 1: // Translate to Alien Language
                printf("Enter the text to translate to Alien Language: ");
                fgets(input, MAX_LENGTH, stdin);
                toAlienLanguage(input, output);
                printf("Translated to Alien Language: %s\n", output);
                break;

            case 2: // Translate from Alien Language
                printf("Enter the text to translate from Alien Language: ");
                fgets(input, MAX_LENGTH, stdin);
                fromAlienLanguage(input, output);
                printf("Translated from Alien Language: %s\n", output);
                break;

            case 3: // Exit
                printf("Farewell, dear Watson! Until we meet again.\n");
                exit(0);

            default:
                printf("Invalid choice. Please select a valid option.\n");
                displayMenu();
                break;
        }
    }
}

void displayMenu() {
    printf("1. Translate to Alien Language\n");
    printf("2. Translate from Alien Language\n");
    printf("3. Exit\n");
}

void toAlienLanguage(const char *input, char *output) {
    int i, j = 0;
    int len = strlen(input);
    for (i = 0; i < len; i++) {
        if (isalpha(input[i])) {
            // Convert letters to Alien Language
            output[j++] = (input[i] + 3); // Simple Caesar Cipher
        } else {
            output[j++] = input[i]; // Non-alphabetic characters remain unchanged
        }
    }
    output[j] = '\0'; // Null-terminate the output string
}

void fromAlienLanguage(const char *input, char *output) {
    int i, j = 0;
    int len = strlen(input);
    for (i = 0; i < len; i++) {
        if (isalpha(input[i])) {
            // Revert letters from Alien Language
            output[j++] = (input[i] - 3); // Simple reverse Caesar Cipher
        } else {
            output[j++] = input[i]; // Non-alphabetic characters remain unchanged
        }
    }
    output[j] = '\0'; // Null-terminate the output string
}

void toLower(char *str) {
    int i;
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// The following function is just for illustrating the smartness of the algorithm used.
void intriguingTidbit() {
    printf("In the process of translation, the simple yet profound variation in character coding creates a fascinating twist, much like a twist in a well-spun mystery!\n");
}