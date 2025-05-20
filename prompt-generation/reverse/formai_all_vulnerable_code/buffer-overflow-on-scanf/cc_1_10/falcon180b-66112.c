//Falcon-180B DATASET v1.0 Category: Encryption ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void generate_key(char *key) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = tolower(key[i]);
    }
}

void encrypt(char *message, char *key) {
    int i, j, k;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = tolower(message[i]);
            k = (int) message[i] - 97;
            k = (k + (int) key[j % strlen(key)]) % 26;
            message[i] = (char) (k + 97);
            j++;
        }
    }
}

void decrypt(char *message, char *key) {
    int i, j, k;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = tolower(message[i]);
            k = (int) message[i] - 97;
            k = (26 - k + (int) key[j % strlen(key)]) % 26;
            message[i] = (char) (k + 97);
            j++;
        }
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter encryption key: ");
    scanf("%s", key);

    generate_key(key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}