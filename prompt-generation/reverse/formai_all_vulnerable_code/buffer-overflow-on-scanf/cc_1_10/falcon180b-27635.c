//Falcon-180B DATASET v1.0 Category: Encryption ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

void encrypt(char* message, int key) {
    int length = strlen(message);
    char encrypted_message[SIZE];
    int i, j;

    for (i = 0, j = 0; i < length; i++, j++) {
        if (j == SIZE) {
            j = 0;
        }
        encrypted_message[j] = message[i] + key;
    }

    encrypted_message[j] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* message, int key) {
    int length = strlen(message);
    char decrypted_message[SIZE];
    int i, j;

    for (i = 0, j = 0; i < length; i++, j++) {
        if (j == SIZE) {
            j = 0;
        }
        decrypted_message[j] = message[i] - key;
    }

    decrypted_message[j] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[SIZE];
    int key;

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    printf("Enter a key (0-25): ");
    scanf("%d", &key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}