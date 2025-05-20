//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1024

void encrypt(const char *input, char *output, int key);
void decrypt(const char *input, char *output, int key);
void handleEncryptionAndDecryption();
void displayMenu();
int getKeyFromUser();

int main() {
    printf("************ Welcome to Shocked Cryptography! ************\n");
    while (1) {
        displayMenu();
        handleEncryptionAndDecryption();
    }
    return 0;
}

void displayMenu() {
    printf("\nChoose an option:\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void handleEncryptionAndDecryption() {
    int choice;
    char input[MAX], output[MAX];
    int key;

    scanf("%d", &choice);
    getchar(); // consume newline
    switch (choice) {
        case 1:
            printf("Enter the message to encrypt: ");
            fgets(input, MAX, stdin);
            input[strcspn(input, "\n")] = 0; // Remove trailing newline
            key = getKeyFromUser();
            encrypt(input, output, key);
            printf("Encrypted message: %s\n", output);
            break;
        case 2:
            printf("Enter the message to decrypt: ");
            fgets(input, MAX, stdin);
            input[strcspn(input, "\n")] = 0; // Remove trailing newline
            key = getKeyFromUser();
            decrypt(input, output, key);
            printf("Decrypted message: %s\n", output);
            break;
        case 3:
            printf("Exiting the program... Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
}

int getKeyFromUser() {
    int key;
    printf("Enter the encryption/decryption key (1-25): ");
    while (1) {
        scanf("%d", &key);
        if (key >= 1 && key <= 25) {
            return key;
        } else {
            printf("Invalid key! Please enter a number between 1 and 25: ");
        }
    }
}

void encrypt(const char *input, char *output, int key) {
    int i = 0;
    while (input[i]) {
        if (isalpha(input[i])) {
            char offset = islower(input[i]) ? 'a' : 'A';
            output[i] = (input[i] - offset + key) % 26 + offset;
        } else {
            output[i] = input[i]; // Non-alphabetic characters remain unchanged
        }
        i++;
    }
    output[i] = '\0'; // Null-terminate the output string
}

void decrypt(const char *input, char *output, int key) {
    int i = 0;
    while (input[i]) {
        if (isalpha(input[i])) {
            char offset = islower(input[i]) ? 'a' : 'A';
            output[i] = (input[i] - offset - key + 26) % 26 + offset;
        } else {
            output[i] = input[i]; // Non-alphabetic characters remain unchanged
        }
        i++;
    }
    output[i] = '\0'; // Null-terminate the output string
}