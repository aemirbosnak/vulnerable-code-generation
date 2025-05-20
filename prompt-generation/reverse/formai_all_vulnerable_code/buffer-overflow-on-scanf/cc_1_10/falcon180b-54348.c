//Falcon-180B DATASET v1.0 Category: Encryption ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1000
#define KEY "mysecretkey"

void encrypt(char *message, char *key) {
    int i, j, k = 0;
    char encrypted[SIZE];

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            encrypted[k] = message[i] + key[k % strlen(key)];
            k++;
        } else {
            encrypted[k] = message[i];
            k++;
        }
    }

    encrypted[k] = '\0';
    strcpy(message, encrypted);
}

void decrypt(char *message, char *key) {
    int i, j, k = 0;
    char decrypted[SIZE];

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            decrypted[k] = message[i] - key[k % strlen(key)];
            k++;
        } else {
            decrypted[k] = message[i];
            k++;
        }
    }

    decrypted[k] = '\0';
    strcpy(message, decrypted);
}

int main() {
    char message[SIZE], key[SIZE];
    int i, choice;

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    printf("Enter choice:\n1. Encrypt again\n2. Decrypt\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter new encryption key: ");
        scanf("%s", key);
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    } else if (choice == 2) {
        printf("Enter decryption key: ");
        scanf("%s", key);
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}