//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

char *key = "secretkey";
char *message = "Hello, World!";
char *ciphertext;
char *decrypted_message;

void generate_key(char *key, int length) {
    int i;
    for (i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

void encrypt(char *message, char *key) {
    int i, j;
    char *ciphertext = malloc(strlen(message) + 1);
    for (i = 0, j = 0; message[i]; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            ciphertext[j++] = (message[i] - 'a' + key[i % strlen(key)]) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            ciphertext[j++] = (message[i] - 'A' + key[i % strlen(key)]) % 26 + 'a';
        } else {
            ciphertext[j++] = message[i];
        }
    }
    ciphertext[j] = '\0';
    printf("Ciphertext: %s\n", ciphertext);
}

void decrypt(char *ciphertext, char *key) {
    int i, j;
    char *decrypted_message = malloc(strlen(ciphertext) + 1);
    for (i = 0, j = 0; ciphertext[i]; i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            decrypted_message[j++] = (ciphertext[i] - key[i % strlen(key)] + 26) % 26 + 'a';
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            decrypted_message[j++] = (ciphertext[i] - key[i % strlen(key)] + 26) % 26 + 'a';
        } else {
            decrypted_message[j++] = ciphertext[i];
        }
    }
    decrypted_message[j] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    generate_key(key, strlen(message));
    printf("Key: %s\n", key);
    encrypt(message, key);
    decrypt(ciphertext, key);
    free(ciphertext);
    return 0;
}