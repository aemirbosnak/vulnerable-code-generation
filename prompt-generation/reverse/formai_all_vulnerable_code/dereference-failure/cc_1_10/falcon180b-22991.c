//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 32

void generate_key(char *key, int key_len) {
    int i;
    for (i = 0; i < key_len; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_len] = '\0';
}

void encrypt(char *message, char *key, int key_len) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' + key[j]) % 26 + 'A';
            } else {
                message[i] = (message[i] - 'a' + key[j]) % 26 + 'a';
            }
            j = (j + 1) % key_len;
        }
    }
}

void decrypt(char *message, char *key, int key_len) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - key[j] + 26) % 26 + 'A';
            } else {
                message[i] = (message[i] - key[j] + 26) % 26 + 'a';
            }
            j = (j + 1) % key_len;
        }
    }
}

int main(int argc, char *argv[]) {
    char message[100];
    char key[MAX_KEY_LEN];
    int key_len;

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter key length (max %d): ", MAX_KEY_LEN);
    scanf("%d", &key_len);

    generate_key(key, key_len);
    encrypt(message, key, key_len);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key, key_len);
    printf("Decrypted message: %s\n", message);

    return 0;
}