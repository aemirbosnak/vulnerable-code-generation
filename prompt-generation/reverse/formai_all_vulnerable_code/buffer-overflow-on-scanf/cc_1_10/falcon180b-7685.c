//Falcon-180B DATASET v1.0 Category: Encryption ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "secret"
#define ENCRYPT 1
#define DECRYPT 2

// Function to encrypt the message
void encrypt(char *message, int key_size) {
    int i, j;
    char *key = (char *)malloc(key_size * sizeof(char));
    strcpy(key, KEY);

    for (i = 0; message[i]!= '\0'; i++) {
        message[i] = message[i] ^ key[i % key_size];
    }
}

// Function to decrypt the message
void decrypt(char *message, int key_size) {
    int i;
    char *key = (char *)malloc(key_size * sizeof(char));
    strcpy(key, KEY);

    for (i = 0; message[i]!= '\0'; i++) {
        message[i] = message[i] ^ key[i % key_size];
    }
}

int main() {
    char message[1000], choice;
    int key_size;

    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]", message);

    printf("Enter the key size (between 1 and %d): ", strlen(KEY));
    scanf("%d", &key_size);

    printf("Enter 1 to encrypt the message or 2 to decrypt the message: ");
    scanf("%d", &choice);

    switch (choice) {
        case ENCRYPT:
            encrypt(message, key_size);
            printf("Encrypted message: %s\n", message);
            break;
        case DECRYPT:
            decrypt(message, key_size);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}