//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

void printMenu() {
    printf("Simple Encryption Program\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
}

void encrypt(const char *key, const char *message, char *encrypted) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = key[message[i] - 'A'];
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = key[message[i] - 'a'] + 32; // Convert to lowercase
        } else {
            encrypted[i] = message[i]; // Non-alphabetical characters remain unchanged
        }
    }
    encrypted[len] = '\0'; // Null-terminate the string
}

void decrypt(const char *key, const char *encrypted, char *decrypted) {
    int len = strlen(encrypted);
    for (int i = 0; i < len; i++) {
        if (encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            // Find the index of the character in key
            for (int j = 0; j < 26; j++) {
                if (key[j] == encrypted[i]) {
                    decrypted[i] = 'A' + j; // Convert back to original
                    break;
                }
            }
        } else if (encrypted[i] >= 'a' && encrypted[i] <= 'z') {
            // Find the index of the character in key
            for (int j = 0; j < 26; j++) {
                if (key[j] + 32 == encrypted[i]) {
                    decrypted[i] = 'a' + j; // Convert back to original
                    break;
                }
            }
        } else {
            decrypted[i] = encrypted[i]; // Non-alphabetical characters remain unchanged
        }
    }
    decrypted[len] = '\0'; // Null-terminate the string
}

int main() {
    char key[26 + 1] = "QWERTYUIOPASDFGHJKLZXCVBNM"; // Simple substitution key
    char message[MAX_LEN];
    char encrypted[MAX_LEN];
    char decrypted[MAX_LEN];
    int choice;

    while (1) {
        printMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter message to encrypt (up to %d characters): ", MAX_LEN - 1);
                fgets(message, MAX_LEN, stdin);
                message[strcspn(message, "\n")] = '\0'; // Remove newline
                encrypt(key, message, encrypted);
                printf("Encrypted message: %s\n", encrypted);
                break;
            case 2:
                printf("Enter message to decrypt (up to %d characters): ", MAX_LEN - 1);
                fgets(encrypted, MAX_LEN, stdin);
                encrypted[strcspn(encrypted, "\n")] = '\0'; // Remove newline
                decrypt(key, encrypted, decrypted);
                printf("Decrypted message: %s\n", decrypted);
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