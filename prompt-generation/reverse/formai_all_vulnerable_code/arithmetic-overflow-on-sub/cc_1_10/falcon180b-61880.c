//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to generate prime numbers
int isPrime(int num) {
    int i;
    for(i=2;i<=num/2;i++) {
        if(num%i==0) {
            return 0;
        }
    }
    return 1;
}

// Function to calculate GCD
int gcd(int num1, int num2) {
    int temp;
    while(num2!= 0) {
        temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

// Function to generate public and private keys
void generateKeys(int p, int q, int *publicKey, int *privateKey) {
    int n = p*q;
    int totient = (p-1)*(q-1);
    int e = 65537;
    while(gcd(e, totient)!= 1) {
        e++;
    }
    *publicKey = e;
    *privateKey = (totient-1)/e;
}

// Function to encrypt message
void encrypt(int publicKey, int message, char *encryptedMessage) {
    int n = message;
    int e = publicKey;
    int m = 0;
    while(n > 0) {
        m += (n%10)*pow(e,0);
        n /= 10;
    }
    sprintf(encryptedMessage, "%d", m);
}

// Function to decrypt message
void decrypt(int privateKey, char *encryptedMessage, int *message) {
    int n = atoi(encryptedMessage);
    int d = privateKey;
    int m = 0;
    while(n > 0) {
        m += (n%10)*pow(d,0);
        n /= 10;
    }
    *message = m;
}

// Main function
int main() {
    int p, q, publicKey, privateKey, message, encryptedMessage[100], decryptedMessage;
    printf("Enter two prime numbers: ");
    scanf("%d %d", &p, &q);
    generateKeys(p, q, &publicKey, &privateKey);
    printf("Public Key: %d\nPrivate Key: %d\n", publicKey, privateKey);
    printf("Enter message to encrypt: ");
    scanf("%d", &message);
    encrypt(publicKey, message, encryptedMessage);
    printf("Encrypted message: %s\n", encryptedMessage);
    decrypt(privateKey, encryptedMessage, &decryptedMessage);
    printf("Decrypted message: %d\n", decryptedMessage);
    return 0;
}