//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define SIZE 100

void encrypt(char *message, int key) {
    int i, j, k;
    char *cipher = (char *) malloc(sizeof(char) * strlen(message));

    for (i = 0, j = 0; i < strlen(message); i++, j++) {
        if (j == SIZE) {
            j = 0;
        }
        cipher[i] = message[i] + key - 65;
        if (cipher[i] < 65) {
            cipher[i] = cipher[i] + 26;
        }
        if (cipher[i] > 90) {
            cipher[i] = cipher[i] - 26;
        }
    }

    printf("Encrypted message: %s\n", cipher);
}

void decrypt(char *cipher, int key) {
    int i, j, k;
    char *message = (char *) malloc(sizeof(char) * strlen(cipher));

    for (i = 0, j = 0; i < strlen(cipher); i++, j++) {
        if (j == SIZE) {
            j = 0;
        }
        message[i] = cipher[i] - key - 65;
        if (message[i] < 65) {
            message[i] = message[i] + 26;
        }
        if (message[i] > 90) {
            message[i] = message[i] - 26;
        }
    }

    printf("Decrypted message: %s\n", message);
}

int main() {
    char *message;
    int key;

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter key (1-25): ");
    scanf("%d", &key);

    encrypt(message, key);

    return 0;
}