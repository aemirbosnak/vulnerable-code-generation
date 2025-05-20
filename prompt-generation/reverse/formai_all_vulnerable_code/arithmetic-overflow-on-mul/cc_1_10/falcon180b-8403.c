//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000
#define PRIME 1048576
#define BASE 10

int isPrime(int n) {
    int i;
    for(i=2; i*i<=n; i++) {
        if(n%i == 0) {
            return 0;
        }
    }
    return 1;
}

int generateKey(int *publicKey, int *privateKey) {
    int i;
    for(i=0; i<2; i++) {
        do {
            *publicKey = rand() % PRIME;
        } while(!isPrime(*publicKey));
        do {
            *privateKey = rand() % PRIME;
        } while(!isPrime(*privateKey));
    }
    return 1;
}

int encrypt(int message, int publicKey, int *encryptedMessage) {
    int i;
    for(i=0; i<2; i++) {
        *encryptedMessage = (message * publicKey) % PRIME;
    }
    return 1;
}

int decrypt(int encryptedMessage, int privateKey, int *message) {
    int i;
    for(i=0; i<2; i++) {
        *message = (encryptedMessage * privateKey) % PRIME;
    }
    return 1;
}

int main() {
    int publicKey, privateKey, message, encryptedMessage, decryptedMessage;
    srand(time(NULL));
    generateKey(&publicKey, &privateKey);
    printf("Public Key: %d\n", publicKey);
    printf("Private Key: %d\n", privateKey);
    printf("Enter message to encrypt: ");
    scanf("%d", &message);
    encrypt(message, publicKey, &encryptedMessage);
    printf("Encrypted Message: %d\n", encryptedMessage);
    decrypt(encryptedMessage, privateKey, &decryptedMessage);
    printf("Decrypted Message: %d\n", decryptedMessage);
    return 0;
}