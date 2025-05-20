//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_BUF_SIZE 1024

// Function to check if a number is prime
int isPrime(int n) {
    int i;
    if(n <= 1) {
        return 0;
    }
    for(i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to find the greatest common divisor of two numbers
int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to generate random prime number between two values
int generateRandomPrime(int start, int end) {
    int prime = rand() % (end - start + 1) + start;
    while(!isPrime(prime)) {
        prime = rand() % (end - start + 1) + start;
    }
    return prime;
}

// Function to generate public and private keys
void generateKeys(int p, int q, int *publicKey, int *privateKey) {
    int n = p * q; // Calculate n
    int phi = (p - 1) * (q - 1); // Calculate phi

    int e = generateRandomPrime(2, phi - 1); // Generate e
    while(gcd(e, phi) != 1) {
        e = generateRandomPrime(2, phi - 1);
    }
    *publicKey = e; // Set public key to e

    int d = 2;
    while((d * e) % phi != 1) { // Generate d
        d++;
    }
    *privateKey = d; // Set private key to d
}

// Function to encrypt and decrypt message
void encryptDecrypt(char *plainText, int *cipherText, int len, int key, int n) {
    int i;
    for(i = 0; i < len; i++) {
        cipherText[i] = fmod(pow(plainText[i], key), n); // Encrypt plain text to cipher text
        plainText[i] = fmod(pow(cipherText[i], key), n); // Decrypt cipher text to plain text
    }
}

int main() {
    int p, q, publicKey, privateKey;
    char plainText[MAX_BUF_SIZE];
    int cipherText[MAX_BUF_SIZE];
    int len, i;

    srand(time(NULL)); // Seed random generator with current time

    printf("Enter value for p (prime number): ");
    scanf("%d", &p);
    while(!isPrime(p)) {
        printf("Invalid value! Please enter a prime number: ");
        scanf("%d", &p);
    }

    printf("Enter value for q (prime number): ");
    scanf("%d", &q);
    while(!isPrime(q) || q == p) {
        printf("Invalid value! Please enter a prime number that is not equal to p: ");
        scanf("%d", &q);
    }

    generateKeys(p, q, &publicKey, &privateKey);

    printf("Public Key: %d\nPrivate Key: %d\n", publicKey, privateKey);

    printf("Enter plain text message: ");
    scanf(" %[^\n]", plainText);
    len = strlen(plainText);

    encryptDecrypt(plainText, cipherText, len, publicKey, p * q); // Encrypt plain text to cipher text

    printf("\nEncrypted message: ");
    for(i = 0; i < len; i++) {
        printf("%d ", cipherText[i]);
    }

    encryptDecrypt(plainText, cipherText, len, privateKey, p * q); // Decrypt cipher text to plain text

    printf("\nDecrypted message: %s\n", plainText);

    return 0;
}