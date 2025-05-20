//FormAI DATASET v1.0 Category: modern Encryption ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random key
void generateKey(char *key, int keySize) {
    int i;
    srand(time(NULL));
    for(i = 0; i < keySize; i++) {
        key[i] = 'A' + rand() % 26;
    }
    key[keySize] = '\0';
}

// Function to encrypt the message using the generated key
void encrypt(char *message, char *key, int messageSize) {
    int i;
    for(i = 0; i < messageSize; i++) {
        message[i] ^= key[i];
    }
}

int main() {

    char message[100];
    char key[100];
    int messageSize, keySize;

    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin);

    messageSize = strlen(message) - 1;

    printf("Enter the size of the key (maximum 100): ");
    scanf("%d", &keySize);

    if(keySize > 100) {
        printf("Key size too large. Maximum is 100.\n");
        return 1;
    }

    generateKey(key, keySize);

    printf("Generated key: %s\n", key);

    encrypt(message, key, messageSize);

    printf("Encrypted message: %s\n", message);

    return 0;
}