//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if(num <= 1) return false;
    for(int i = 2; i < num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

// Function to generate a random prime number
int generatePrimeNum() {
    int count = 0, num;
    while(count < 1) {
        num = rand() % 100;
        if(isPrime(num)) count++;
    }
    return num;
}

// Function to calculate power of a number
int power(int a, int b) {
    int result = 1;
    for(int i = 0; i < b; i++) {
        result = result * a;
    }
    return result;
}

// Function to calculate gcd of two numbers
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

// Function to calculate public key
int calculatePublicKey(int p, int q) {
    int n = p * q, e;
    for(int i = 2; i < n; i++) {
        if(gcd(i, (p-1) * (q-1)) == 1) {
            e = i;
            break;
        }
    }
    return e;
}

// Function to calculate private key
int calculatePrivateKey(int p, int q, int e) {
    int n = p * q, d;
    for(int i = 1; i < n; i++) {
        if(((i * e) % ((p-1) * (q-1))) == 1) {
            d = i;
            break;
        }
    }
    return d;
}

int main() {
    int p, q, publicKey, privateKey;
    // Generate two random prime numbers
    p = generatePrimeNum();
    q = generatePrimeNum();
    // Calculate public key
    publicKey = calculatePublicKey(p, q);
    // Calculate private key
    privateKey = calculatePrivateKey(p, q, publicKey);

    printf("Prime Numbers: %d and %d\n", p, q);
    printf("Public Key: %d\n", publicKey);
    printf("Private Key: %d\n", privateKey);

    // Encryption
    int plaintext, ciphertext;
    printf("\nEnter the plaintext: ");
    scanf("%d", &plaintext);
    // Calculate ciphertext
    ciphertext = power(plaintext, publicKey) % (p * q);
    printf("Ciphertext: %d\n", ciphertext);

    // Decryption
    int decryptedText;
    decryptedText = power(ciphertext, privateKey) % (p * q);
    printf("Decrypted Text: %d\n", decryptedText);

    return 0;
}