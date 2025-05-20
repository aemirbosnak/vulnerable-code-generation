//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void encrypt(char *plaintext, char *key, char *ciphertext);
void decrypt(char *ciphertext, char *key, char *plaintext);
void prepare_key(char *key, int length);
void to_lowercase(char *str);

int main() {
    char plaintext[256], key[100], ciphertext[256], decrypted[256];
    int choice;

    printf("=== Vigenère Cipher Implementation ===\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);
    
    // Clear input buffer
    while (getchar() != '\n');

    switch (choice) {
        case 1:
            printf("Enter the message to encrypt: ");
            fgets(plaintext, sizeof(plaintext), stdin);
            // Remove newline character from fgets
            plaintext[strcspn(plaintext, "\n")] = 0; 

            printf("Enter the key: ");
            fgets(key, sizeof(key), stdin);
            key[strcspn(key, "\n")] = 0; 
            prepare_key(key, strlen(plaintext));
            encrypt(plaintext, key, ciphertext);
            printf("Encrypted message: %s\n", ciphertext);
            break;

        case 2:
            printf("Enter the message to decrypt: ");
            fgets(ciphertext, sizeof(ciphertext), stdin);
            ciphertext[strcspn(ciphertext, "\n")] = 0; 

            printf("Enter the key: ");
            fgets(key, sizeof(key), stdin);
            key[strcspn(key, "\n")] = 0; 
            prepare_key(key, strlen(ciphertext));
            decrypt(ciphertext, key, decrypted);
            printf("Decrypted message: %s\n", decrypted);
            break;

        default:
            printf("Invalid choice. Please select 1 or 2.\n");
            return 1;
    }

    return 0;
}

// Encrypt function using Vigenère cipher
void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i, j = 0;
    int key_length = strlen(key);
    int plaintext_length = strlen(plaintext);
    
    for (i = 0; i < plaintext_length; i++) {
        if (isalpha(plaintext[i])) {
            char offset = islower(plaintext[i]) ? 'a' : 'A';
            char key_char = tolower(key[j % key_length]) - 'a';
            ciphertext[i] = ((plaintext[i] - offset + key_char) % 26) + offset;
            j++;
        } else {
            ciphertext[i] = plaintext[i]; // Non-alpha characters remain unchanged
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the string
}

// Decrypt function using Vigenère cipher
void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i, j = 0;
    int key_length = strlen(key);
    int ciphertext_length = strlen(ciphertext);
    
    for (i = 0; i < ciphertext_length; i++) {
        if (isalpha(ciphertext[i])) {
            char offset = islower(ciphertext[i]) ? 'a' : 'A';
            char key_char = tolower(key[j % key_length]) - 'a';
            plaintext[i] = ((ciphertext[i] - offset - key_char + 26) % 26) + offset;
            j++;
        } else {
            plaintext[i] = ciphertext[i]; // Non-alpha characters remain unchanged
        }
    }
    plaintext[i] = '\0'; // Null-terminate the string
}

// Prepare key by converting to lowercase and ignoring non-alpha characters
void prepare_key(char *key, int length) {
    char temp[100];
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (isalpha(key[i])) {
            temp[j++] = tolower(key[i]);
        }
    }
    temp[j] = '\0';
    strncpy(key, temp, 100);
}

// Make a string lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}