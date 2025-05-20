//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Generate a random prime number
int isPrime(int num) {
    if(num <= 1) return 0;
    if(num == 2) return 1;
    if(num % 2 == 0) return 0;

    int maxFactor = sqrt(num);
    for(int i = 3; i <= maxFactor; i += 2) {
        if(num % i == 0) return 0;
    }
    return 1;
}

int getRandomPrime() {
    int result;
    do {
        result = rand() % 100 + 1; // change 100 to a larger number for more security
    } while(!isPrime(result));
    return result;
}

// Calculate the greatest common divisor
int gcd(int a, int b) {
    int temp;
    while(b > 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Find the modular inverse of a number
int modInverse(int a, int m) {
    for(int i = 0; i < m; i++) {
        if((a * i) % m == 1) return i;
    }
    return -1;
}

// Encryption and decryption functions
int encrypt(int message, int e, int n) {
    int result = 1;
    for(int i = 0; i < e; i++) {
        result = (result * message) % n;
    }
    return result;
}

int decrypt(int message, int d, int n) {
    int result = 1;
    for(int i = 0; i < d; i++) {
        result = (result * message) % n;
    }
    return result;
}

// Main function
int main() {
    srand(time(NULL));

    // Generate two large prime numbers
    int p = getRandomPrime();
    int q = getRandomPrime();
    printf("p = %d, q = %d\n", p, q);

    // Calculate n and phi(n)
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Choose a random number for public key e
    int e;
    do {
        e = rand() % phi;
    } while(gcd(e, phi) != 1);

    // Calculate private key d
    int d = modInverse(e, phi);

    // Print public and private keys
    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);

    // Encrypt and decrypt a message
    int message;
    printf("Enter a message to encrypt: ");
    scanf("%d", &message);

    int encrypted = encrypt(message, e, n);
    int decrypted = decrypt(encrypted, d, n);

    printf("Encrypted message: %d\n", encrypted);
    printf("Decrypted message: %d\n", decrypted);

    return 0;
}