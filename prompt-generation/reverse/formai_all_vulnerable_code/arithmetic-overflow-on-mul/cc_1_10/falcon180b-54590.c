//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10000
#define MAX_PRIME 1000

int isPrime(int num);
int generateRandomPrime(int max);
int generatePublicPrivateKeys(int prime);
void encrypt(int publicKey, int message);
int decrypt(int privateKey, int encryptedMessage);

int main() {
    int prime, publicKey, privateKey, message, encryptedMessage, decryptedMessage;
    printf("Welcome to the Public-Key Algorithm Implementation!\n");
    prime = generateRandomPrime(MAX_PRIME);
    printf("The prime number is: %d\n", prime);
    publicKey = generatePublicPrivateKeys(prime);
    printf("Your public key is: %d\n", publicKey);
    printf("Please enter your message (less than %d characters): ", MAX_NUM);
    scanf("%d", &message);
    encrypt(publicKey, message);
    printf("Your encrypted message is: %d\n", encryptedMessage);
    privateKey = generatePublicPrivateKeys(prime);
    decryptedMessage = decrypt(privateKey, encryptedMessage);
    printf("Your decrypted message is: %d\n", decryptedMessage);
    return 0;
}

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int generateRandomPrime(int max) {
    int num;
    srand(time(NULL));
    num = rand() % max;
    while (!isPrime(num)) {
        num = rand() % max;
    }
    return num;
}

int generatePublicPrivateKeys(int prime) {
    int num;
    do {
        num = rand() % prime;
    } while (num == 1 || num == prime - 1);
    return num;
}

void encrypt(int publicKey, int message) {
    int encryptedMessage = 0;
    for (int i = 0; i < strlen(message) + 1; i++) {
        encryptedMessage += (message % publicKey) * (publicKey - 1);
        message /= publicKey;
    }
    printf("Your encrypted message is: %d\n", encryptedMessage);
}

int decrypt(int privateKey, int encryptedMessage) {
    int message = 0;
    for (int i = 0; i < strlen(encryptedMessage) + 1; i++) {
        message += encryptedMessage % privateKey;
        message /= privateKey;
    }
    printf("Your decrypted message is: %d\n", message);
    return message;
}