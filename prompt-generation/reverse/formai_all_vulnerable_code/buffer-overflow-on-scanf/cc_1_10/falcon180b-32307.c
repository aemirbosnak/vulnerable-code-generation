//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000 // Maximum length of input string
#define KEY_LENGTH 8 // Length of the encryption key

char encryption_key[KEY_LENGTH + 1] = "secretkey"; // Encryption key

void encrypt(char* message, int length) {
    int i, j;
    for (i = 0, j = 0; i < length; i++) {
        if (isalpha(message[i])) {
            message[i] = (char) ((int) message[i] + (int) encryption_key[j % KEY_LENGTH]);
            j++;
        } else {
            message[i] = message[i];
        }
    }
}

void decrypt(char* message, int length) {
    int i, j;
    for (i = 0, j = 0; i < length; i++) {
        if (isalpha(message[i])) {
            message[i] = (char) ((int) message[i] - (int) encryption_key[j % KEY_LENGTH]);
            j++;
        } else {
            message[i] = message[i];
        }
    }
}

int main() {
    char message[MAX_LENGTH];
    int length;

    printf("Enter a message to encrypt/decrypt: ");
    scanf("%s", message);
    length = strlen(message);

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(message, length);
        printf("Encrypted message: %s\n", message);
    } else if (choice == 2) {
        decrypt(message, length);
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}