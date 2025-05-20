//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32
#define MAX_MESSAGE_SIZE 1024

void encrypt(char *message, char *key) {
    int i, j;
    char *encrypted_message = malloc(MAX_MESSAGE_SIZE);
    memset(encrypted_message, 0, MAX_MESSAGE_SIZE);

    for (i = 0, j = 0; message[i]!= '\0'; i++, j++) {
        if (isalpha(message[i])) {
            encrypted_message[j] = (char) (((int) message[i] + (int) key[j % strlen(key)]) % 26 + 97);
        } else {
            encrypted_message[j] = message[i];
        }
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *encrypted_message, char *key) {
    int i, j;
    char *decrypted_message = malloc(MAX_MESSAGE_SIZE);
    memset(decrypted_message, 0, MAX_MESSAGE_SIZE);

    for (i = 0, j = 0; encrypted_message[i]!= '\0'; i++, j++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[j] = (char) (((int) encrypted_message[i] - (int) key[j % strlen(key)]) % 26 + 97);
        } else {
            decrypted_message[j] = encrypted_message[i];
        }
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_SIZE] = "Hello, world!";
    char key[MAX_KEY_SIZE] = "secret";

    printf("Message: %s\n", message);
    encrypt(message, key);
    decrypt(message, key);

    return 0;
}