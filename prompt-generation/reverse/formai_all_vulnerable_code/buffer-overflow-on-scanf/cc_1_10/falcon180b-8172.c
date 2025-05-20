//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1024 // Maximum size of message
#define PRIME 17 // Prime number used in encryption
#define BASE 256 // Base used in encryption

// Function to generate random prime numbers
int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate public and private keys
void generateKeys(int* publicKey, int* privateKey) {
    int p, q;
    do {
        p = rand() % MAX_SIZE + 1;
        q = rand() % MAX_SIZE + 1;
    } while (!isPrime(p) ||!isPrime(q));

    *publicKey = p;
    *privateKey = q;
}

// Function to encrypt message using public key
void encrypt(char* message, int publicKey) {
    int key = publicKey - 1;
    int i = 0;
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            message[i] = (char) ((message[i] - 65 + key) % 26 + 65);
        }
        i++;
    }
}

// Function to decrypt message using private key
void decrypt(char* message, int privateKey) {
    int key = privateKey - 1;
    int i = 0;
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            message[i] = (char) ((message[i] - 65 - key + 26) % 26 + 65);
        }
        i++;
    }
}

int main() {
    srand(time(NULL));
    int publicKey, privateKey;
    generateKeys(&publicKey, &privateKey);

    char message[MAX_SIZE];
    printf("Enter message to encrypt: ");
    scanf("%s", message);

    encrypt(message, publicKey);
    printf("Encrypted message: %s\n", message);

    decrypt(message, privateKey);
    printf("Decrypted message: %s\n", message);

    return 0;
}