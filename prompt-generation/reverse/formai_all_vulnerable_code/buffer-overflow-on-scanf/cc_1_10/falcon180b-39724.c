//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000
#define MAX_PRIME 10000

//Function to generate a prime number
int generatePrime() {
    int num = 0;
    while (num <= 1) {
        num = rand() % MAX_PRIME + 2;
    }
    return num;
}

//Function to generate public and private keys
void generateKeys(int *publicKey, int *privateKey) {
    int p = generatePrime();
    int q = generatePrime();
    *publicKey = p * q;
    *privateKey = (p - 1) * (q - 1);
}

//Function to encrypt a message
void encrypt(int publicKey, char *message, char *encryptedMessage, int messageLength) {
    int i = 0;
    int n = publicKey;
    while (i < messageLength) {
        encryptedMessage[i] = message[i] ^ (i % n);
        i++;
    }
}

//Function to decrypt a message
void decrypt(int privateKey, char *encryptedMessage, char *decryptedMessage, int messageLength) {
    int i = 0;
    int n = privateKey;
    while (i < messageLength) {
        decryptedMessage[i] = encryptedMessage[i] ^ (i % n);
        i++;
    }
}

//Main function
int main() {
    char message[MAX_SIZE];
    char encryptedMessage[MAX_SIZE];
    char decryptedMessage[MAX_SIZE];
    int publicKey, privateKey, messageLength;

    //Get message from user
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    messageLength = strlen(message);

    //Generate public and private keys
    generateKeys(&publicKey, &privateKey);

    //Encrypt message
    encrypt(publicKey, message, encryptedMessage, messageLength);

    //Print encrypted message
    printf("Encrypted message: %s\n", encryptedMessage);

    //Decrypt message
    decrypt(privateKey, encryptedMessage, decryptedMessage, messageLength);

    //Print decrypted message
    printf("Decrypted message: %s\n", decryptedMessage);

    return 0;
}