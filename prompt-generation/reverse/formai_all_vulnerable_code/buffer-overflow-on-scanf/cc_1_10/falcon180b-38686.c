//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void shift(char* message, int key, int direction) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                if (direction == 1) {
                    message[i] += key;
                    if (message[i] > 'Z') {
                        message[i] = 'A';
                    }
                } else {
                    message[i] -= key;
                    if (message[i] < 'A') {
                        message[i] = 'Z';
                    }
                }
            } else {
                if (direction == 1) {
                    message[i] += key;
                    if (message[i] > 'z') {
                        message[i] = 'a';
                    }
                } else {
                    message[i] -= key;
                    if (message[i] < 'a') {
                        message[i] = 'z';
                    }
                }
            }
        }
    }
}

void encrypt(char* message, int key) {
    shift(message, key, 1);
}

void decrypt(char* message, int key) {
    shift(message, key, -1);
}

int main() {
    char message[100];
    int key;
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
    printf("Enter the encryption key (0-25): ");
    scanf("%d", &key);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}