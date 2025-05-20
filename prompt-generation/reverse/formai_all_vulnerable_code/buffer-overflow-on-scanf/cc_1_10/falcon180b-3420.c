//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 128 // Key size

// Function to generate a random prime number
int isPrime(int num) {
    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate a random prime number
int generatePrime() {
    int num;
    do {
        num = rand() % (2 * SIZE) + 2;
    } while (!isPrime(num));
    return num;
}

// Function to generate public and private keys
void generateKeys() {
    int e, d, p, q;
    do {
        p = generatePrime();
        q = generatePrime();
    } while (p == q);
    e = 17;
    d = (int) pow(e, -1) % (p - 1) * (q - 1) % p;
    printf("Public Key: %d %d\n", e, p * q);
    printf("Private Key: %d %d\n", d, p * q);
}

// Function to encrypt a message
void encrypt(char message[], int key[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        message[i] = message[i] ^ key[i];
    }
}

// Function to decrypt a message
void decrypt(char message[], int key[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        message[i] = message[i] ^ key[i];
    }
}

int main() {
    char message[SIZE];
    int key[SIZE];
    generateKeys();
    printf("Enter your message: ");
    scanf("%s", message);
    encrypt(message, key, SIZE);
    printf("Encrypted message: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", key[i]);
    }
    printf("\n");
    decrypt(key, message, SIZE);
    printf("Decrypted message: %s\n", message);
    return 0;
}