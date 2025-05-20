//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000
#define PRIME_NUM 17

typedef struct {
    int a;
    int b;
} KeyPair;

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int generateRandomNumber(int max) {
    srand(time(NULL));
    return rand() % max;
}

int generatePublicKey(int privateKey) {
    int publicKey = generateRandomNumber(MAX_NUM);
    while (publicKey % PRIME_NUM == 0 || publicKey == privateKey) {
        publicKey = generateRandomNumber(MAX_NUM);
    }
    return publicKey;
}

int generatePrivateKey(int publicKey) {
    int privateKey = generateRandomNumber(MAX_NUM);
    while (privateKey % PRIME_NUM == 0 || privateKey == publicKey) {
        privateKey = generateRandomNumber(MAX_NUM);
    }
    return privateKey;
}

int encrypt(int publicKey, int message) {
    int encryptedMessage = (message * publicKey) % MAX_NUM;
    return encryptedMessage;
}

int decrypt(int privateKey, int encryptedMessage) {
    int decryptedMessage = (encryptedMessage * privateKey) % MAX_NUM;
    return decryptedMessage;
}

int main() {
    int publicKey, privateKey;
    int message;

    // Generate public and private keys
    publicKey = generatePublicKey(0);
    privateKey = generatePrivateKey(publicKey);

    // Encrypt a message
    printf("Enter a message: ");
    scanf("%d", &message);
    int encryptedMessage = encrypt(publicKey, message);
    printf("Encrypted message: %d\n", encryptedMessage);

    // Decrypt the message
    int decryptedMessage = decrypt(privateKey, encryptedMessage);
    printf("Decrypted message: %d\n", decryptedMessage);

    return 0;
}