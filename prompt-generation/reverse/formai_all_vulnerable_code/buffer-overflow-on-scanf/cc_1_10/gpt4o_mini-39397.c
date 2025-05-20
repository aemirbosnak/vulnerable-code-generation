//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void cleanBuffer() {
    while (getchar() != '\n'); // Flush the input buffer
}

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int textLen = strlen(plaintext);
    int keyLen = strlen(key);
    int j = 0;

    for (int i = 0; i < textLen; i++) {
        if (isalpha(plaintext[i])) {
            char currentKey = key[j % keyLen];
            currentKey = toupper(currentKey); // Uppercase the key letter

            ciphertext[i] = 'A' + (toupper(plaintext[i]) - 'A' + (currentKey - 'A')) % 26;
            j++;
        } else {
            ciphertext[i] = plaintext[i]; // Non-alpha characters remain unchanged
        }
    }
    ciphertext[textLen] = '\0'; // Null-terminate the ciphertext
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int textLen = strlen(ciphertext);
    int keyLen = strlen(key);
    int j = 0;

    for (int i = 0; i < textLen; i++) {
        if (isalpha(ciphertext[i])) {
            char currentKey = key[j % keyLen];
            currentKey = toupper(currentKey); // Uppercase the key letter
            
            plaintext[i] = 'A' + (toupper(ciphertext[i]) - 'A' - (currentKey - 'A') + 26) % 26;
            j++;
        } else {
            plaintext[i] = ciphertext[i]; // Non-alpha characters remain unchanged
        }
    }
    plaintext[textLen] = '\0'; // Null-terminate the plaintext
}

void toUpperCase(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    char choice;
    char plaintext[256], ciphertext[256], key[256];
    
    printf("=== Vigenère Cipher ===\n\n");
    printf("Please enter the key (only alphabetic characters): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove newline character
    toUpperCase(key); // Normalize the key to uppercase

    do {
        printf("\nChoose an option:\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf(" %c", &choice);
        cleanBuffer(); // Clean out the input buffer

        switch (choice) {
            case '1':
                printf("Enter plaintext message: ");
                fgets(plaintext, sizeof(plaintext), stdin);
                plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character

                encrypt(plaintext, key, ciphertext);
                printf("Ciphertext: %s\n", ciphertext);
                break;

            case '2':
                printf("Enter ciphertext message: ");
                fgets(ciphertext, sizeof(ciphertext), stdin);
                ciphertext[strcspn(ciphertext, "\n")] = '\0'; // Remove newline character

                decrypt(ciphertext, key, plaintext);
                printf("Plaintext: %s\n", plaintext);
                break;

            case '3':
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    } while (choice != '3');

    return 0;
}