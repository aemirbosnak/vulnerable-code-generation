//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 26
#define KEY "mysecretkey"
#define ALPHABET "abcdefghijklmnopqrstuvwxyz"
#define ENCRYPT 0
#define DECRYPT 1

int main() {
    char message[1000];
    char key[N];
    int mode;
    int i;

    printf("Enter message to encrypt/decrypt: ");
    scanf("%[^\n]", message);

    printf("Enter mode (encrypt/decrypt): ");
    scanf("%d", &mode);

    strcpy(key, KEY);

    if (mode == ENCRYPT) {
        printf("Encrypting message...\n");
        for (i = 0; i < strlen(message); i++) {
            message[i] = toupper(message[i]);
        }
        for (i = 0; i < strlen(message); i++) {
            if (strchr(ALPHABET, message[i])) {
                message[i] = (message[i] - 'A' + (int)key[i % N] - 65) % 26 + 65;
            } else {
                message[i] = message[i];
            }
        }
        printf("Encrypted message: %s\n", message);
    } else if (mode == DECRYPT) {
        printf("Decrypting message...\n");
        for (i = 0; i < strlen(message); i++) {
            message[i] = toupper(message[i]);
        }
        for (i = 0; i < strlen(message); i++) {
            if (strchr(ALPHABET, message[i])) {
                message[i] = (message[i] - 'A' - (int)key[i % N] + 26) % 26 + 65;
            } else {
                message[i] = message[i];
            }
        }
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid mode.\n");
    }

    return 0;
}