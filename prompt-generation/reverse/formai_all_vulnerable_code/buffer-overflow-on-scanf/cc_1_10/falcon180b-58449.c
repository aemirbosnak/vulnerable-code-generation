//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1024
#define M 32
#define Q 160

// Function to generate random prime number
int isPrime(int n) {
    int i;
    if (n <= 1) {
        return 0;
    }
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate random prime number
int generatePrime(int *num) {
    int i;
    srand(time(NULL));
    *num = rand() % (N - M) + M;
    while (!isPrime(*num)) {
        *num = rand() % (N - M) + M;
    }
    return 1;
}

// Function to generate public and private keys
void generateKeys(int prime, int *pubKey, int *priKey) {
    int g;
    do {
        g = rand() % (prime - 2) + 2;
    } while (gcd(g, prime)!= 1);
    *pubKey = g;
    *priKey = (gcd(g, prime - 1) + 1) % prime;
}

// Function to calculate GCD
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to encrypt message
void encrypt(int pubKey, int *text, int *cipher) {
    int i;
    for (i = 0; i < strlen((char *)text); i++) {
        cipher[i] = (text[i] * pubKey) % Q;
    }
}

// Function to decrypt cipher
void decrypt(int priKey, int *cipher, int *text) {
    int i;
    for (i = 0; i < strlen((char *)cipher); i++) {
        text[i] = (cipher[i] * priKey) % Q;
    }
}

int main() {
    int prime, pubKey, priKey, cipher[100], text[100];
    printf("Enter the message to be encrypted: ");
    scanf("%s", (char *)text);
    generatePrime(&prime);
    generateKeys(prime, &pubKey, &priKey);
    encrypt(pubKey, text, cipher);
    printf("Encrypted message: ");
    for (int i = 0; i < strlen((char *)cipher); i++) {
        printf("%d ", cipher[i]);
    }
    printf("\n");
    decrypt(priKey, cipher, text);
    printf("Decrypted message: %s\n", (char *)text);
    return 0;
}