//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

void translateToCatLanguage(const char *input, char *output) {
    int index = 0;

    while (*input) {
        // Translate vowels to Cat Language
        switch (*input) {
            case 'a':
            case 'A':
                output[index++] = 'm';
                output[index++] = 'e';
                output[index++] = 'o';
                break;
            case 'e':
            case 'E':
                output[index++] = 'm';
                output[index++] = 'e';
                output[index++] = 'w';
                break;
            case 'i':
            case 'I':
                output[index++] = 'm';
                output[index++] = 'i';
                output[index++] = 'a';
                break;
            case 'o':
            case 'O':
                output[index++] = 'm';
                output[index++] = 'o';
                output[index++] = 'w';
                break;
            case 'u':
            case 'U':
                output[index++] = 'm';
                output[index++] = 'u';
                output[index++] = 'h';
                break;
            default:
                output[index++] = *input;
                break;
        }
        input++;
    }
    output[index] = '\0'; // Null-terminate the output string
}

void displayMenu() {
    printf("Welcome to the Cat Language Translator!\n");
    printf("1. Translate a phrase\n");
    printf("2. Exit\n");
}

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter a phrase to translate: ");
                fgets(input, MAX_LENGTH, stdin);
                // Remove newline character from input
                input[strcspn(input, "\n")] = 0; 

                translateToCatLanguage(input, output);
                printf("Cat Language Translation: %s\n", output);
                break;

            case 2:
                printf("Exiting the translator. Have a nice day!\n");
                exit(0);

            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    }

    return 0;
}