//Falcon-180B DATASET v1.0 Category: Encryption ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100
#define ALPHABET_LEN 26

char alphabet[ALPHABET_LEN] = "abcdefghijklmnopqrstuvwxyz";

void encrypt(char *message, char *key) {
    int i, j;
    char encrypted_message[MAX_LEN];
    encrypted_message[0] = '\0';
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = tolower(message[i]);
        }
    }
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            int index = tolower(message[i]) - 'a';
            if (index >= 0 && index < ALPHABET_LEN) {
                if (isalpha(key[index])) {
                    encrypted_message[i] = key[index];
                } else {
                    encrypted_message[i] = alphabet[index];
                }
            }
        } else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[i] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *message, char *key) {
    int i, j;
    char decrypted_message[MAX_LEN];
    decrypted_message[0] = '\0';
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            int index = tolower(message[i]) - 'a';
            if (index >= 0 && index < ALPHABET_LEN) {
                if (isalpha(key[index])) {
                    decrypted_message[i] = key[index];
                } else {
                    decrypted_message[i] = alphabet[index];
                }
            }
        } else {
            decrypted_message[i] = message[i];
        }
    }
    decrypted_message[i] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_LEN];
    char key[MAX_LEN];
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    printf("Enter encryption key: ");
    scanf("%s", key);
    encrypt(message, key);
    printf("\n");
    decrypt(message, key);
    return 0;
}