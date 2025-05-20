//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 16
#define BLOCK_LENGTH 8

char *key = "mysecretkey123";

void encrypt(char *message, char *result) {
    char *key_copy = malloc(KEY_LENGTH);
    strcpy(key_copy, key);
    int key_index = 0;

    for (int i = 0; i < strlen(message); i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            int letter_index = c - 'a';
            result[i] = key_copy[key_index] ^ ((letter_index + key_index) % 26);
            key_index = (key_index + 1) % KEY_LENGTH;
        } else {
            result[i] = message[i];
        }
    }
}

void decrypt(char *message, char *result) {
    char *key_copy = malloc(KEY_LENGTH);
    strcpy(key_copy, key);
    int key_index = 0;

    for (int i = 0; i < strlen(message); i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            int letter_index = c - 'a';
            int decrypted_letter_index = ((result[i] - key_copy[key_index]) % 26) + letter_index;
            if (decrypted_letter_index < 0) {
                decrypted_letter_index += 26;
            }
            result[i] = decrypted_letter_index + 'a';
            key_index = (key_index + 1) % KEY_LENGTH;
        } else {
            result[i] = message[i];
        }
    }
}

int main() {
    char message[100];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    char result[100];
    encrypt(message, result);

    printf("Encrypted message: %s\n", result);

    char decrypted_message[100];
    decrypt(result, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}