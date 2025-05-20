//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random prime number
int isPrime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i <= num / 2; i++)
        if (num % i == 0)
            return 0;
    return 1;
}

// Function to generate public and private keys
void generateKeys(int *publicKey, int *privateKey) {
    *publicKey = 0;
    *privateKey = 0;
    srand(time(NULL));
    int randomNum1, randomNum2;
    do {
        randomNum1 = rand() % 1000000 + 1;
        randomNum2 = rand() % 1000000 + 1;
    } while (!isPrime(randomNum1) ||!isPrime(randomNum2));
    *publicKey = randomNum1;
    *privateKey = randomNum2;
}

// Function to encrypt message using public key
void encryptMessage(int message, int publicKey, int *encryptedMessage) {
    *encryptedMessage = 0;
    int power = 1;
    while (publicKey > 1) {
        if (publicKey % 2 == 1) {
            power *= message;
            message *= message;
        }
        publicKey /= 2;
    }
    if (publicKey == 1)
        *encryptedMessage = power * message;
    else
        *encryptedMessage = -1; // Invalid public key
}

// Function to decrypt message using private key
void decryptMessage(int encryptedMessage, int privateKey, int *decryptedMessage) {
    *decryptedMessage = 0;
    int power = 1;
    while (privateKey > 1) {
        if (privateKey % 2 == 1) {
            power *= encryptedMessage;
            encryptedMessage *= encryptedMessage;
        }
        privateKey /= 2;
    }
    if (privateKey == 1)
        *decryptedMessage = power * encryptedMessage;
    else
        *decryptedMessage = -1; // Invalid private key
}

int main() {
    int publicKey, privateKey, message, encryptedMessage, decryptedMessage;
    generateKeys(&publicKey, &privateKey);
    printf("Public Key: %d\n", publicKey);
    printf("Private Key: %d\n", privateKey);
    printf("Enter message to encrypt: ");
    scanf("%d", &message);
    encryptMessage(message, publicKey, &encryptedMessage);
    printf("Encrypted Message: %d\n", encryptedMessage);
    decryptMessage(encryptedMessage, privateKey, &decryptedMessage);
    printf("Decrypted Message: %d\n", decryptedMessage);
    return 0;
}