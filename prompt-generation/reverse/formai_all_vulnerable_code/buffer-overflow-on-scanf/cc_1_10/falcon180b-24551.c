//Falcon-180B DATASET v1.0 Category: Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_TEXT_LENGTH 1000

// Function to encrypt the given text using the given key
void encrypt(char *text, char *key) {
    int i, j, k, n;
    char encrypted_text[MAX_TEXT_LENGTH];
    memset(encrypted_text, 0, sizeof(encrypted_text));

    // Calculate the length of the key
    n = strlen(key);

    // Encrypt the text
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                text[i] = tolower(text[i]);
            }
            j = tolower(text[i]) - 'a';
            k = (key[j % n] - 'a' + 26) % 26;
            encrypted_text[i] = (char) (k + 'a');
        } else {
            encrypted_text[i] = text[i];
        }
    }

    // Print the encrypted text
    printf("Encrypted text: %s\n", encrypted_text);
}

// Function to decrypt the given text using the given key
void decrypt(char *text, char *key) {
    int i, j, k, n;
    char decrypted_text[MAX_TEXT_LENGTH];
    memset(decrypted_text, 0, sizeof(decrypted_text));

    // Calculate the length of the key
    n = strlen(key);

    // Decrypt the text
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                text[i] = tolower(text[i]);
            }
            j = tolower(text[i]) - 'a';
            k = ('a' + 26 - key[j % n]) % 26;
            decrypted_text[i] = (char) (k + 'a');
        } else {
            decrypted_text[i] = text[i];
        }
    }

    // Print the decrypted text
    printf("Decrypted text: %s\n", decrypted_text);
}

int main() {
    char text[MAX_TEXT_LENGTH], key[MAX_KEY_LENGTH];

    // Get the text to be encrypted/decrypted
    printf("Enter the text to be encrypted/decrypted: ");
    scanf("%s", text);

    // Get the encryption/decryption key
    printf("Enter the encryption/decryption key: ");
    scanf("%s", key);

    // Encrypt the text
    encrypt(text, key);

    // Decrypt the encrypted text
    decrypt(text, key);

    return 0;
}