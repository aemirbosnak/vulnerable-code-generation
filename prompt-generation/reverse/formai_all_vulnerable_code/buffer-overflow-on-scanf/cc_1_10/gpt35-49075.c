//FormAI DATASET v1.0 Category: Modern Encryption ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 500

void generateRandomKey(char* key, int keySize) {
    int i;
    srand(time(NULL));
    for (i = 0; i < keySize; i++) {
        key[i] = rand() % 128;   
    }
}

void encrypt(char* message, char* key, int keySize) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++, j++) {
        if (j == keySize) {
            j = 0;
        }
        message[i] = message[i] ^ key[j];
    }
}

void decrypt(char* message, char* key, int keySize) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++, j++) {
        if (j == keySize) {
            j = 0;
        }
        message[i] = message[i] ^ key[j];
    }
}

int main() {
    char message[MAX_SIZE], key[MAX_SIZE];
    printf("Enter the message you want to encrypt: ");
    fgets(message, MAX_SIZE, stdin);
    message[strcspn(message, "\n")] = '\0';
    int messageSize = strlen(message);
    printf("Enter the key size: ");
    int keySize;
    scanf("%d", &keySize);
    generateRandomKey(key, keySize);
    encrypt(message, key, keySize);
    printf("\nEncrypted message is: %s", message);
    decrypt(message, key, keySize);
    printf("\nDecrypted message is: %s", message);
    return 0;
}