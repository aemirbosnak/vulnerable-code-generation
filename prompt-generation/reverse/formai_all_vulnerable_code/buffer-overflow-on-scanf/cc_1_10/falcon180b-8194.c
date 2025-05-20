//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void encrypt(char* message, int key) {
    int i, j;
    char temp;

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' + key) % 26 + 'A';
            } else {
                message[i] = (message[i] - 'a' + key) % 26 + 'a';
            }
        }
    }
}

void decrypt(char* message, int key) {
    int i, j;
    char temp;

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
            } else {
                message[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
            }
        }
    }
}

int main() {
    char message[MAX_LENGTH];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_LENGTH, stdin);

    printf("Enter a key (0-25): ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}