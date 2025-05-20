//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define MAX_KEY_LENGTH 256
#define MAX_TEXT_LENGTH 1024

// Function to encrypt the given text using the key
void encrypt(char *text, char *key) {
    int i, j, k;
    char enc_text[MAX_TEXT_LENGTH];
    memset(enc_text, 0, MAX_TEXT_LENGTH);

    // Apply Caesar cipher to encrypt the text
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                enc_text[i] = (char) (((int) text[i] - 65 + (int) key[i % strlen(key)]) % 26 + 65);
            }
            else {
                enc_text[i] = (char) (((int) text[i] - 97 + (int) key[i % strlen(key)]) % 26 + 97);
            }
        }
        else {
            enc_text[i] = text[i];
        }
    }

    printf("Encrypted text: %s\n", enc_text);
}

// Function to decrypt the given text using the key
void decrypt(char *text, char *key) {
    int i, j, k;
    char dec_text[MAX_TEXT_LENGTH];
    memset(dec_text, 0, MAX_TEXT_LENGTH);

    // Apply Caesar cipher to decrypt the text
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                dec_text[i] = (char) (((int) text[i] - 65 - (int) key[i % strlen(key)]) % 26 + 65);
            }
            else {
                dec_text[i] = (char) (((int) text[i] - 97 - (int) key[i % strlen(key)]) % 26 + 97);
            }
        }
        else {
            dec_text[i] = text[i];
        }
    }

    printf("Decrypted text: %s\n", dec_text);
}

int main() {
    char text[MAX_TEXT_LENGTH], key[MAX_KEY_LENGTH];
    printf("Enter the text to encrypt/decrypt: ");
    scanf("%s", text);

    printf("Enter the encryption/decryption key: ");
    scanf("%s", key);

    // Encrypt the text using the key
    encrypt(text, key);

    // Decrypt the encrypted text using the same key
    decrypt(text, key);

    return 0;
}