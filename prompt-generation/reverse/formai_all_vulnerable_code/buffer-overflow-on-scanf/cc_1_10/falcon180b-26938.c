//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 100

// Function to generate random prime number
int isPrime(int n) {
    if (n <= 1)
        return 0;
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

// Function to generate public and private keys
void generateKeys(int *publicKey, int *privateKey) {
    *publicKey = rand() % MAX_SIZE + 2;
    *privateKey = rand() % MAX_SIZE + 2;
    while (!isPrime(*publicKey) ||!isPrime(*privateKey)) {
        *publicKey = rand() % MAX_SIZE + 2;
        *privateKey = rand() % MAX_SIZE + 2;
    }
}

// Function to encrypt message using public key
void encrypt(int publicKey, char *message, char *encryptedMessage) {
    int n = strlen(message);
    int m = 0;
    for (int i = 0; i < n; i++) {
        encryptedMessage[m++] = message[i] ^ (publicKey % 26 + 'A');
    }
    encryptedMessage[m] = '\0';
}

// Function to decrypt message using private key
void decrypt(int privateKey, char *encryptedMessage, char *decryptedMessage) {
    int n = strlen(encryptedMessage);
    int m = 0;
    for (int i = 0; i < n; i++) {
        decryptedMessage[m++] = encryptedMessage[i] ^ ((26 - privateKey % 26) + 'A');
    }
    decryptedMessage[m] = '\0';
}

int main() {
    int publicKey, privateKey;
    generateKeys(&publicKey, &privateKey);

    char message[MAX_SIZE];
    printf("Enter message to encrypt: ");
    scanf("%s", message);

    char encryptedMessage[MAX_SIZE];
    encrypt(publicKey, message, encryptedMessage);

    printf("Encrypted message: %s\n", encryptedMessage);

    char decryptedMessage[MAX_SIZE];
    decrypt(privateKey, encryptedMessage, decryptedMessage);

    printf("Decrypted message: %s\n", decryptedMessage);

    return 0;
}