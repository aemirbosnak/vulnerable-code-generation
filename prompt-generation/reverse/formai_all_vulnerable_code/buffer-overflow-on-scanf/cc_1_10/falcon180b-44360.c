//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void encrypt(char *message, char *key, char *cipher, int block_size) {
    int i = 0, j = 0;
    char ch;

    while (*message) {
        ch = *message;

        if (isalpha(ch)) {
            if (isupper(ch)) {
                cipher[i] = ((ch - 'A' + key[j]) % 26) + 'A';
            } else {
                cipher[i] = ((ch - 'a' + key[j]) % 26) + 'a';
            }
        } else {
            cipher[i] = ch;
        }

        i++;

        if (i == block_size) {
            j++;
            i = 0;
        }
    }

    cipher[i] = '\0';
}

void decrypt(char *cipher, char *key, char *message, int block_size) {
    int i = 0, j = 0;
    char ch;

    while (*cipher) {
        ch = *cipher;

        if (isalpha(ch)) {
            if (isupper(ch)) {
                message[i] = ((ch - 'A' - key[j]) % 26) + 'A';
            } else {
                message[i] = ((ch - 'a' - key[j]) % 26) + 'a';
            }
        } else {
            message[i] = ch;
        }

        i++;

        if (i == block_size) {
            j++;
            i = 0;
        }
    }

    message[i] = '\0';
}

int main() {
    char message[1000];
    char key[KEY_SIZE];
    char cipher[1000];

    printf("Enter message: ");
    scanf("%s", message);

    printf("Enter key: ");
    scanf("%s", key);

    encrypt(message, key, cipher, BLOCK_SIZE);

    printf("Encrypted message: %s\n", cipher);

    decrypt(cipher, key, message, BLOCK_SIZE);

    printf("Decrypted message: %s\n", message);

    return 0;
}