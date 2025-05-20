//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 100

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void encrypt(char *message) {
    int i, j, key;
    char temp;

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    for(i = 0; message[i]!= '\0'; i++) {
        if(isalpha(message[i])) {
            temp = message[i];
            message[i] = ((temp - 65 + key) % 26) + 65;
        }
    }

    printf("Encrypted message: %s\n", message);
}

void decrypt(char *message) {
    int i, j, key;
    char temp;

    printf("Enter the decryption key: ");
    scanf("%d", &key);

    for(i = 0; message[i]!= '\0'; i++) {
        if(isalpha(message[i])) {
            temp = message[i];
            message[i] = ((temp - 65 - key + 26) % 26) + 65;
        }
    }

    printf("Decrypted message: %s\n", message);
}

int main() {
    char message[SIZE];
    int choice, i;

    printf("Enter the message to encrypt/decrypt: ");
    scanf("%s", message);

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            encrypt(message);
            break;
        case 2:
            decrypt(message);
            break;
        default:
            printf("Invalid choice.\n");
            return 0;
    }

    return 0;
}