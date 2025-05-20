//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 256

char *generate_key(int length) {
    char *key = malloc(length + 1);
    int i;

    for (i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }

    key[length] = '\0';

    return key;
}

void encrypt(char *message, char *key) {
    int i, j;

    for (i = 0, j = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]);
            message[i] = ((message[i] - 'A' + key[j]) % 26) + 'A';
            j = (j + 1) % strlen(key);
        } else {
            message[i] = message[i];
        }
    }
}

void decrypt(char *ciphertext, char *key) {
    int i, j;

    for (i = 0, j = 0; ciphertext[i]; i++) {
        if (isalpha(ciphertext[i])) {
            ciphertext[i] = toupper(ciphertext[i]);
            ciphertext[i] = ((ciphertext[i] - 'A' - key[j]) % 26) + 'A';
            j = (j + 1) % strlen(key);
        } else {
            ciphertext[i] = ciphertext[i];
        }
    }
}

int main() {
    char *message, *key, *ciphertext;
    int length;

    printf("Enter the length of the key: ");
    scanf("%d", &length);

    key = generate_key(length);
    message = malloc(MAX_KEY_LENGTH + 1);

    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    ciphertext = malloc(MAX_KEY_LENGTH + 1);

    strcpy(ciphertext, message);

    decrypt(ciphertext, key);

    printf("Decrypted message: %s\n", ciphertext);

    free(key);
    free(message);
    free(ciphertext);

    return 0;
}