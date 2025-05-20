//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 256
#define MAX_BUFFER 1024

// Function Prototypes
void encryptString(char *input, char *output);
void decryptString(char *input, char *output);
void randomizeString(char *str);
void displayMenu();

int main() {
    char userInput[MAX_INPUT];
    char encrypted[MAX_BUFFER];
    char decrypted[MAX_BUFFER];
    int choice;

    // Main Interface Loop
    do {
        displayMenu();
        printf("Select an option (1-5): ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left in buffer

        switch (choice) {
            case 1:
                printf("Enter a string to encrypt: ");
                fgets(userInput, MAX_INPUT, stdin);
                userInput[strcspn(userInput, "\n")] = 0; // Strip newline
                encryptString(userInput, encrypted);
                printf("Encrypted String: %s\n", encrypted);
                break;
            case 2:
                printf("Enter a string to decrypt: ");
                fgets(userInput, MAX_INPUT, stdin);
                userInput[strcspn(userInput, "\n")] = 0; // Strip newline
                decryptString(userInput, decrypted);
                printf("Decrypted String: %s\n", decrypted);
                break;
            case 3:
                printf("Enter a string to randomize: ");
                fgets(userInput, MAX_INPUT, stdin);
                userInput[strcspn(userInput, "\n")] = 0; // Strip newline
                randomizeString(userInput);
                printf("Randomized String: %s\n", userInput);
                break;
            case 4:
                printf("Exiting the Cyberpunk Matrix...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void encryptString(char *input, char *output) {
    int key = 5; // Simple encryption key
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] + key; // Shift character by key
    }
    output[strlen(input)] = '\0'; // Null-terminate
}

void decryptString(char *input, char *output) {
    int key = 5; // Simple decryption key
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] - key; // Shift character back by key
    }
    output[strlen(input)] = '\0'; // Null-terminate
}

void randomizeString(char *str) {
    int length = strlen(str);
    char temp;

    // Shuffle the string using Fisher-Yates algorithm
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Swap characters
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void displayMenu() {
    printf("\n=== Cyberpunk String Manipulation Utility ===\n");
    printf("1. Encrypt a String\n");
    printf("2. Decrypt a String\n");
    printf("3. Randomize a String\n");
    printf("4. Exit\n");
}