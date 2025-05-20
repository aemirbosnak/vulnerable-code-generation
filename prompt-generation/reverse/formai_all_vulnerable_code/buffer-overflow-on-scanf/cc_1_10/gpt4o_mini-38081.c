//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

void encrypt(const char *input, char *output, int key) {
    for (int i = 0; input[i] != '\0'; ++i) {
        output[i] = input[i] + key;
    }
    output[strlen(input)] = '\0'; // Null-terminate the output string
}

void decrypt(const char *input, char *output, int key) {
    for (int i = 0; input[i] != '\0'; ++i) {
        output[i] = input[i] - key;
    }
    output[strlen(input)] = '\0'; // Null-terminate the output string
}

void displayMenu() {
    printf("\n*** Simple Encryption Program ***\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Exit\n");
    printf("Please select an option (1-3): ");
}

int main() {
    char plaintext[MAX_LENGTH] = {0};
    char ciphertext[MAX_LENGTH] = {0};
    char decryptedtext[MAX_LENGTH] = {0};
    int key, choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the text to encrypt: ");
            getchar(); // Consume newline
            fgets(plaintext, MAX_LENGTH, stdin);
            plaintext[strcspn(plaintext, "\n")] = 0; // Remove newline char

            printf("Enter the encryption key (integer): ");
            scanf("%d", &key);

            encrypt(plaintext, ciphertext, key);
            printf("Encrypted text: %s\n", ciphertext);
            break;

        case 2:
            printf("Enter the text to decrypt: ");
            getchar(); // Consume newline
            fgets(ciphertext, MAX_LENGTH, stdin);
            ciphertext[strcspn(ciphertext, "\n")] = 0; // Remove newline char

            printf("Enter the decryption key (integer): ");
            scanf("%d", &key);

            decrypt(ciphertext, decryptedtext, key);
            printf("Decrypted text: %s\n", decryptedtext);
            break;

        case 3:
            printf("Exiting the program. Goodbye!\n");
            exit(0);

        default:
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}