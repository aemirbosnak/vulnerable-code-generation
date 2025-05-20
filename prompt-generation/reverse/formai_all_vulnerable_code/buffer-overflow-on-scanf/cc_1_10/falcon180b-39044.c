//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32
#define MAX_TEXT_SIZE 1000

// Function to encrypt the given text using Caesar cipher
void caesar_encrypt(char *text, int key, char *encrypted_text) {
    int i, j;
    for (i = 0, j = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                encrypted_text[j++] = (char) (((int) text[i] + key - 65) % 26 + 65);
            } else {
                encrypted_text[j++] = (char) (((int) text[i] + key - 97) % 26 + 97);
            }
        } else {
            encrypted_text[j++] = text[i];
        }
    }
    encrypted_text[j] = '\0';
}

// Function to decrypt the given text using Caesar cipher
void caesar_decrypt(char *encrypted_text, int key, char *decrypted_text) {
    int i, j;
    for (i = 0, j = 0; i < strlen(encrypted_text); i++) {
        if (isalpha(encrypted_text[i])) {
            if (isupper(encrypted_text[i])) {
                decrypted_text[j++] = (char) (((int) encrypted_text[i] - key - 65) % 26 + 65);
            } else {
                decrypted_text[j++] = (char) (((int) encrypted_text[i] - key - 97) % 26 + 97);
            }
        } else {
            decrypted_text[j++] = encrypted_text[i];
        }
    }
    decrypted_text[j] = '\0';
}

// Function to generate a random key of given size
void generate_key(char *key, int size) {
    int i;
    for (i = 0; i < size; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[size] = '\0';
}

int main() {
    char text[MAX_TEXT_SIZE], encrypted_text[MAX_TEXT_SIZE], decrypted_text[MAX_TEXT_SIZE];
    char key[MAX_KEY_SIZE];
    int key_size;

    // Get the text to be encrypted/decrypted
    printf("Enter the text to be encrypted/decrypted: ");
    scanf("%s", text);

    // Get the key size
    printf("Enter the key size (1-32): ");
    scanf("%d", &key_size);

    // Generate a random key of given size
    generate_key(key, key_size);

    // Encrypt the text using Caesar cipher
    caesar_encrypt(text, key_size, encrypted_text);

    // Decrypt the encrypted text using Caesar cipher
    caesar_decrypt(encrypted_text, key_size, decrypted_text);

    // Display the original text, encrypted text, and decrypted text
    printf("Original Text: %s\n", text);
    printf("Encrypted Text: %s\n", encrypted_text);
    printf("Decrypted Text: %s\n", decrypted_text);

    return 0;
}