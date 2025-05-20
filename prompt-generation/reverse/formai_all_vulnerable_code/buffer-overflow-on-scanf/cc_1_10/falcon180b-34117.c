//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000
#define SIZE 100
#define BASE 11
#define MOD 1000000007

// Function to calculate the power of a number
long long int power(long long int base, int exponent) {
    long long int result = 1;
    while (exponent > 0) {
        result = (result * base) % MOD;
        exponent--;
    }
    return result;
}

// Function to generate a random prime number
int generatePrime() {
    int num = rand() % MAX + 2;
    while (num % 2 == 0) {
        num += 2;
    }
    return num;
}

// Function to generate the public and private keys
void generateKeys() {
    int p = generatePrime();
    int q = generatePrime();
    int n = p * q;
    int phi_n = (p - 1) * (q - 1);
    int e = 2;
    while (power(e, phi_n) % phi_n!= 1) {
        e++;
    }
    int d = power(e, -1) % phi_n;
    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);
}

// Function to encrypt the message
void encrypt(int e, int n, char message[SIZE]) {
    int m = strlen(message);
    int result = 0;
    for (int i = 0; i < m; i++) {
        result = (result * BASE + message[i]) % n;
    }
    printf("Encrypted message: %d\n", result);
}

// Function to decrypt the message
void decrypt(int d, int n, int encrypted_message) {
    int m = encrypted_message;
    int result = 0;
    while (m > 0) {
        result = (result * BASE + m % 10) % n;
        m /= 10;
    }
    printf("Decrypted message: %s\n", result == 0? "" : "Error");
}

int main() {
    srand(time(NULL));
    generateKeys();
    char message[SIZE];
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    encrypt(2, 7, message);
    int encrypted_message = 123456789;
    decrypt(7, 7, encrypted_message);
    return 0;
}