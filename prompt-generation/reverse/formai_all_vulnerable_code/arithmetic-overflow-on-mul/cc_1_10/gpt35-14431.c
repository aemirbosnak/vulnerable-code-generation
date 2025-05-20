//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate modular exponentiation
int fastModularExponentiation(int base, int exponent, int modulus) {
    int result = 1;
    while(exponent > 0) {
        if(exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

int main() {
    // Selecting two prime numbers p and q
    int p = 547, q = 823;
    printf("Selected prime numbers are: p = %d and q = %d\n", p, q);
    
    // Calculating n
    int n = p * q;
    printf("Value of n (public key): %d\n", n);

    // Calculating Euler's totient function
    int phi = (p - 1) * (q - 1);
    
    // Selecting public key e
    int e;
    srand(time(NULL));
    do {
        e = rand() % phi;
    } while(euclid_gcd(e, phi) != 1);
    printf("Value of e (public key): %d\n", e);

    // Finding inverse of e
    int d = modInverse(e, phi);
    printf("Value of d (private key): %d\n", d);

    // Encryption
    char message[] = "Hello world";
    int messageLength = sizeof(message) / sizeof(char);
    printf("\nMessage: %s\n", message);
    printf("Message length: %d\n", messageLength);

    int encryptedMessage[messageLength];
    for(int i = 0; i < messageLength; i++) {
        encryptedMessage[i] = fastModularExponentiation(message[i], e, n);
    }
    printf("Encrypted message: ");
    for(int i = 0; i < messageLength; i++) {
        printf("%d ", encryptedMessage[i]);
    }

    // Decryption
    char decryptedMessage[messageLength];
    for(int i = 0; i < messageLength; i++) {
        decryptedMessage[i] = fastModularExponentiation(encryptedMessage[i], d, n);
    }
    printf("\nDecrypted message: %s", decryptedMessage);

    return 0;
}

// Function to calculate gcd using Euclid's algorithm
int euclid_gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return euclid_gcd(b, a % b);
}

// Function to calculate modular inverse using Extended Euclidean algorithm
int modInverse(int a, int m) {
    a = a % m;
    for(int x = 1; x < m; x++) {
        if((a * x) % m == 1) {
            return x;
        }
    }
}