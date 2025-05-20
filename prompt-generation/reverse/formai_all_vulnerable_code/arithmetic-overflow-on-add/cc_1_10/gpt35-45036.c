//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define our function prototypes
int generateRandomPrime(int max);
int calculateGCD(int a, int b);
int calculatePublicKey(int p, int q);
int calculatePrivateKey(int p, int q, int publicKey);

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    // Generate two large random prime numbers
    int p = generateRandomPrime(10000);
    int q = generateRandomPrime(10000);
    
    // Calculate our public and private keys
    int publicKey = calculatePublicKey(p, q);
    int privateKey = calculatePrivateKey(p, q, publicKey);
    
    printf("Public key: %d\n", publicKey);
    printf("Private key: %d\n", privateKey);
    
    return 0;
}

// Generates a random prime number up to the specified maximum
int generateRandomPrime(int max) {
    int randNum = rand() % max + 1;
    int isPrime = 0;
    
    while (!isPrime) {
        isPrime = 1;
        
        // Check if the number is divisible by anything other than 1 and itself
        for (int i = 2; i < randNum; i++) {
            if (randNum % i == 0) {
                isPrime = 0;
                break;
            }
        }
        
        // If the number is not prime, generate a new random number
        if (!isPrime) {
            randNum = rand() % max + 1;
        }
    }
    
    return randNum;
}

// Calculates the greatest common divisor of two numbers using the Euclidean algorithm
int calculateGCD(int a, int b) {
    int remainder = a % b;
    
    while (remainder != 0) {
        a = b;
        b = remainder;
        remainder = a % b;
    }
    
    return b;
}

// Calculates the public key based on two prime numbers p and q
int calculatePublicKey(int p, int q) {
    int n = p * q;
    int totient = (p - 1) * (q - 1);
    
    int publicKey = rand() % (totient - 2) + 2;
    
    while (calculateGCD(publicKey, totient) != 1) {
        publicKey = rand() % (totient - 2) + 2;
    }
    
    return publicKey;
}

// Calculates the private key using the extended Euclidean algorithm
int calculatePrivateKey(int p, int q, int publicKey) {
    int n = p * q;
    int totient = (p - 1) * (q - 1);
    
    int a = publicKey;
    int b = totient;
    int t = 0, newt = 1;
    int r = b, newr = a;
    
    while (newr != 0) {
        int quotient = r / newr;
        
        int temp = t;
        t = newt;
        newt = temp - quotient * newt;
        
        temp = r;
        r = newr;
        newr = temp - quotient * newr;
    }
    
    if (r > 1) {
        printf("Error: Public key is not valid\n");
        exit(1);
    }
    
    if (t < 0) {
        t = t + b;
    }
    
    return t;
}