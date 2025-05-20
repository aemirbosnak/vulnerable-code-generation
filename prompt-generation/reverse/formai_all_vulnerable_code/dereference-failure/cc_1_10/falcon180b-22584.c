//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ENCRYPT 1
#define DECRYPT 2

// Function to encrypt/decrypt data
void encrypt_decrypt(char* data, int mode, int key) {
    int len = strlen(data);
    char* result = malloc(len + 1);
    result[len] = '\0';

    for (int i = 0; i < len; i++) {
        char c = tolower(data[i]);

        if (isalpha(c)) {
            if (mode == ENCRYPT) {
                if (isalpha(c)) {
                    if (isupper(c)) {
                        result[i] = (c + key - 65) % 26 + 65;
                    } else {
                        result[i] = (c + key - 97) % 26 + 97;
                    }
                } else {
                    result[i] = c;
                }
            } else if (mode == DECRYPT) {
                if (isalpha(c)) {
                    if (isupper(c)) {
                        result[i] = (c - key - 65) % 26 + 65;
                    } else {
                        result[i] = (c - key - 97) % 26 + 97;
                    }
                } else {
                    result[i] = c;
                }
            }
        } else {
            result[i] = c;
        }
    }

    strcpy(data, result);
    free(result);
}

int main() {
    char* data;
    int key;
    int mode;

    // Get the data to encrypt/decrypt
    printf("Enter the data to encrypt/decrypt: ");
    scanf("%s", data);

    // Get the encryption/decryption mode
    printf("Enter the mode (1 for encryption, 2 for decryption): ");
    scanf("%d", &mode);

    // Get the encryption/decryption key
    printf("Enter the key: ");
    scanf("%d", &key);

    // Encrypt/decrypt the data
    encrypt_decrypt(data, mode, key);

    // Print the result
    printf("Result: %s\n", data);

    return 0;
}