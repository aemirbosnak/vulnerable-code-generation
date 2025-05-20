//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void encrypt(char *message, int key) {
    int i, j;
    for (i = 0, j = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            message[j++] = (char) (((int) message[i] - 65 + key) % 26 + 65);
        } else {
            message[j++] = message[i];
        }
    }
    message[j] = '\0';
}

void decrypt(char *message, int key) {
    int i, j;
    for (i = 0, j = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            message[j++] = (char) (((int) message[i] - 65 - key + 26) % 26 + 65);
        } else {
            message[j++] = message[i];
        }
    }
    message[j] = '\0';
}

int main() {
    char message[MAX_SIZE];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}