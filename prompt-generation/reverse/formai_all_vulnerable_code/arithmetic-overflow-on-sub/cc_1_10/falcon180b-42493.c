//Falcon-180B DATASET v1.0 Category: Encryption ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void encrypt(char* message, int key) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[j] = (message[i] - key - 65) % 26 + 65;
        } else {
            message[j] = message[i];
        }
        j++;
    }
    message[j] = '\0';
}

void decrypt(char* message, int key) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[j] = (message[i] - key - 65 + 26) % 26 + 65;
        } else {
            message[j] = message[i];
        }
        j++;
    }
    message[j] = '\0';
}

int main() {
    char message[MAX_SIZE];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);

    printf("Enter a key (1-25): ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}