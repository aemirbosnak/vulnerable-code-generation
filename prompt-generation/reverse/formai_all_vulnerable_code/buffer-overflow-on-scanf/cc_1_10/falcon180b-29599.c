//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PRIME 10000
#define MAX_NUMBER 1000000

// Function to check if a number is prime or not
int isPrime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

// Function to generate a prime number
int generatePrime() {
    int num = rand() % MAX_NUMBER + 1;
    while (!isPrime(num)) {
        num = rand() % MAX_NUMBER + 1;
    }
    return num;
}

// Function to generate public and private keys
void generateKeys(int *publicKey, int *privateKey) {
    *publicKey = generatePrime();
    *privateKey = generatePrime();
}

// Function to encrypt a message using the public key
int encrypt(int message, int publicKey) {
    return (message * publicKey) % MAX_NUMBER;
}

// Function to decrypt a message using the private key
int decrypt(int encryptedMessage, int privateKey) {
    return (encryptedMessage * privateKey) % MAX_NUMBER;
}

int main() {
    int publicKey, privateKey, message, encryptedMessage, decryptedMessage;
    srand(time(NULL));
    generateKeys(&publicKey, &privateKey);
    printf("Public key: %d\n", publicKey);
    printf("Private key: %d\n", privateKey);
    scanf("%d", &message);
    encryptedMessage = encrypt(message, publicKey);
    printf("Encrypted message: %d\n", encryptedMessage);
    decryptedMessage = decrypt(encryptedMessage, privateKey);
    printf("Decrypted message: %d\n", decryptedMessage);
    return 0;
}