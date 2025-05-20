//Falcon-180B DATASET v1.0 Category: Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

void encrypt(char *message, int key) {
    int i, j;
    char result[SIZE];

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            result[i] = (char) ((int) message[i] + key - 97);
        } else {
            result[i] = message[i];
        }
    }

    printf("Encrypted message: %s\n", result);
}

void decrypt(char *message, int key) {
    int i, j;
    char result[SIZE];

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            result[i] = (char) ((int) message[i] - key - 97 + 26);
        } else {
            result[i] = message[i];
        }
    }

    printf("Decrypted message: %s\n", result);
}

int main() {
    char message[SIZE];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, SIZE, stdin);

    printf("Enter a key (0-25): ");
    scanf("%d", &key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}