//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256

// Function to convert a string to uppercase
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to encrypt a message using the Vigenère cipher
void encrypt(char *message, char *key, char *cipherText) {
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    int j = 0;

    for (int i = 0; i < messageLen; i++) {
        if (isalnum(message[i])) {
            char m = toupper(message[i]);
            char k = toupper(key[j % keyLen]);
            cipherText[i] = 'A' + (m + k - 2 * 'A') % 26;
            j++;
        } else {
            cipherText[i] = message[i];
        }
    }
    cipherText[messageLen] = '\0'; // Null-terminate the string
}

// Function to decrypt a message using the Vigenère cipher
void decrypt(char *cipherText, char *key, char *message) {
    int cipherLen = strlen(cipherText);
    int keyLen = strlen(key);
    int j = 0;

    for (int i = 0; i < cipherLen; i++) {
        if (isalnum(cipherText[i])) {
            char c = toupper(cipherText[i]);
            char k = toupper(key[j % keyLen]);
            message[i] = 'A' + (c - k + 26) % 26;
            j++;
        } else {
            message[i] = cipherText[i];
        }
    }
    message[cipherLen] = '\0'; // Null-terminate the string
}

// Main function to handle user interaction
int main() {
    char message[MAX_LENGTH];
    char key[MAX_LENGTH];
    char cipherText[MAX_LENGTH];
    char decryptedText[MAX_LENGTH];
    int choice;

    printf("Welcome to the Vigenère Cipher Implementation!\n");
  
    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character after choice input

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0;  // Remove newline character
                printf("Enter the encryption key: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0;  // Remove newline character
                
                toUpperCase(key);  // Convert key to uppercase for uniformity
                encrypt(message, key, cipherText);
                
                printf("Encrypted Message: %s\n", cipherText);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                fgets(cipherText, sizeof(cipherText), stdin);
                cipherText[strcspn(cipherText, "\n")] = 0;  // Remove newline character
                printf("Enter the decryption key: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0;  // Remove newline character
                
                toUpperCase(key);  // Convert key to uppercase for uniformity
                decrypt(cipherText, key, decryptedText);
                
                printf("Decrypted Message: %s\n", decryptedText);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}