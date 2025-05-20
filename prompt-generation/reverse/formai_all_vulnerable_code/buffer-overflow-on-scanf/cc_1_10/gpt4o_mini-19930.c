//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256

// A simple XOR cipher function for encryption and decryption
void xorCipher(char *input, const char *key, char *output, int length) {
    for (int i = 0; i < length; i++) {
        output[i] = input[i] ^ key[i % strlen(key)];
    }
}

void encrypt() {
    char input[MAX_INPUT_LENGTH];
    char key[MAX_INPUT_LENGTH];
    char encrypted[MAX_INPUT_LENGTH];

    printf("Enter the text to encrypt: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    printf("Enter the encryption key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0; // Remove newline character

    xorCipher(input, key, encrypted, strlen(input));

    printf("\nEncrypted text: ");
    for (int i = 0; i < strlen(input); i++) {
        printf("\\x%02x", (unsigned char)encrypted[i]); // Print hex encoded
    }
    printf("\n");
}

void decrypt() {
    char encrypted[MAX_INPUT_LENGTH];
    char key[MAX_INPUT_LENGTH];
    char decrypted[MAX_INPUT_LENGTH];

    printf("Enter the text to decrypt (hex encoded): ");
    fgets(encrypted, sizeof(encrypted), stdin);
    encrypted[strcspn(encrypted, "\n")] = 0; // Remove newline character

    printf("Enter the decryption key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0; // Remove newline character

    // Convert hex encoded string to raw encrypted data
    int length = strlen(encrypted) / 4;
    char rawEncrypted[MAX_INPUT_LENGTH];
    for (int i = 0; i < length; i++) {
        sscanf(&encrypted[i * 4 + 2], "%2hhx", (unsigned char *)&rawEncrypted[i]);
    }

    xorCipher(rawEncrypted, key, decrypted, length);
    decrypted[length] = '\0'; // Null-terminate the decrypted string

    printf("\nDecrypted text: %s\n", decrypted);
}

int main() {
    int choice;

    do {
        printf("\n--- Simple XOR Encryption Program ---\n");
        printf("1. Encrypt text\n");
        printf("2. Decrypt text\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left by scanf

        switch (choice) {
            case 1:
                encrypt();
                break;
            case 2:
                decrypt();
                break;
            case 3:
                printf("Goodbye! Stay safe!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}