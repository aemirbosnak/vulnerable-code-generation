//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 256
#define MAX_BLOCK_SIZE 1024

// Function to encrypt the message using the key
void encrypt(char *message, char *key) {
    int i, j, n;
    char *cipher_text = malloc(strlen(message) + 1);

    for(i = 0, j = 0; message[i]!= '\0'; i++) {
        if(isalpha(message[i])) {
            n = message[i] - 'a';

            if(isupper(message[i])) {
                cipher_text[j++] = (char) ((n + 13) % 26 + 'A');
            } else {
                cipher_text[j++] = (char) ((n + 13) % 26 + 'a');
            }
        } else {
            cipher_text[j++] = message[i];
        }
    }

    cipher_text[j] = '\0';

    printf("Encrypted message: %s\n", cipher_text);

    free(cipher_text);
}

// Function to decrypt the encrypted message using the key
void decrypt(char *cipher_text, char *key) {
    int i, j, n;
    char *message = malloc(strlen(cipher_text) + 1);

    for(i = 0, j = 0; cipher_text[i]!= '\0'; i++) {
        if(isalpha(cipher_text[i])) {
            n = cipher_text[i] - 'A';

            if(isupper(cipher_text[i])) {
                message[j++] = (char) ((n - 13 + 26) % 26 + 'A');
            } else {
                message[j++] = (char) ((n - 13 + 26) % 26 + 'a');
            }
        } else {
            message[j++] = cipher_text[i];
        }
    }

    message[j] = '\0';

    printf("Decrypted message: %s\n", message);

    free(message);
}

int main() {
    char message[MAX_BLOCK_SIZE], key[MAX_KEY_SIZE];
    int key_size;

    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    printf("Enter the key size (1-256): ");
    scanf("%d", &key_size);

    printf("Enter the key: ");
    scanf("%s", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}