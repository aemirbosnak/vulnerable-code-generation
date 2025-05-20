//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 1024

// Function to generate a random prime number
int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate random public and private keys
void generateKeys(int *publicKey, int *privateKey) {
    srand(time(NULL));
    int p = 0, q = 0;
    do {
        p = rand() % 1000 + 1;
        q = rand() % 1000 + 1;
    } while (!isPrime(p) ||!isPrime(q));

    *publicKey = p * q;
    *privateKey = (p - 1) * (q - 1);
}

// Function to encrypt a message using the public key
void encryptMessage(char *message, int publicKey, char *encryptedMessage) {
    strcpy(encryptedMessage, message);
    for (int i = 0; i < strlen(message); i++) {
        encryptedMessage[i] = encryptedMessage[i] % publicKey + 'A';
    }
}

// Function to decrypt a message using the private key
void decryptMessage(char *encryptedMessage, int privateKey, char *decryptedMessage) {
    strcpy(decryptedMessage, encryptedMessage);
    for (int i = 0; i < strlen(encryptedMessage); i++) {
        decryptedMessage[i] = decryptedMessage[i] % privateKey + 'A';
    }
}

int main() {
    int publicKey, privateKey;
    char message[MAX_LENGTH];
    char encryptedMessage[MAX_LENGTH];
    char decryptedMessage[MAX_LENGTH];

    // Generate public and private keys
    generateKeys(&publicKey, &privateKey);

    // Prompt user for message to encrypt and decrypt
    printf("Enter a message to encrypt and decrypt: ");
    scanf("%s", message);

    // Encrypt the message
    encryptMessage(message, publicKey, encryptedMessage);

    // Decrypt the message
    decryptMessage(encryptedMessage, privateKey, decryptedMessage);

    // Print the original and decrypted messages
    printf("Original message: %s\n", message);
    printf("Decrypted message: %s\n", decryptedMessage);

    return 0;
}