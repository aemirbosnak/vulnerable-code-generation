//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256

void encrypt(char *plaintext, int key, char *ciphertext) {
    int i = 0;
    while (plaintext[i] != '\0' && i < MAX_LENGTH) {
        if (isalpha(plaintext[i])) {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            ciphertext[i] = (plaintext[i] - base + key) % 26 + base;
        } else {
            ciphertext[i] = plaintext[i]; // Non-alpha characters remain the same
        }
        i++;
    }
    ciphertext[i] = '\0'; // Null terminate the string
}

void decrypt(char *ciphertext, int key, char *plaintext) {
    int i = 0;
    while (ciphertext[i] != '\0' && i < MAX_LENGTH) {
        if (isalpha(ciphertext[i])) {
            char base = islower(ciphertext[i]) ? 'a' : 'A';
            plaintext[i] = (ciphertext[i] - base - key + 26) % 26 + base;
        } else {
            plaintext[i] = ciphertext[i]; // Non-alpha characters remain the same
        }
        i++;
    }
    plaintext[i] = '\0'; // Null terminate the string
}

void print_instructions() {
    printf("Caesar Cipher Encryption/Decryption\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
}

int main() {
    char choice;
    char plaintext[MAX_LENGTH], ciphertext[MAX_LENGTH];
    int key;

    while (1) {
        print_instructions();
        printf("Choose an option (1-3): ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the plaintext: ");
                getchar(); // Clear newline character from buffer
                fgets(plaintext, MAX_LENGTH, stdin);
                plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline

                printf("Enter the encryption key (0-25): ");
                scanf("%d", &key);
                key = key % 26; // Ensure key is within 0-25

                encrypt(plaintext, key, ciphertext);
                printf("Encrypted text: %s\n", ciphertext);
                break;

            case '2':
                printf("Enter the ciphertext: ");
                getchar(); // Clear newline character from buffer
                fgets(ciphertext, MAX_LENGTH, stdin);
                ciphertext[strcspn(ciphertext, "\n")] = '\0'; // Remove newline

                printf("Enter the decryption key (0-25): ");
                scanf("%d", &key);
                key = key % 26; // Ensure key is within 0-25

                decrypt(ciphertext, key, plaintext);
                printf("Decrypted text: %s\n", plaintext);
                break;

            case '3':
                printf("Exiting the program.\n");
                exit(0);
            
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}