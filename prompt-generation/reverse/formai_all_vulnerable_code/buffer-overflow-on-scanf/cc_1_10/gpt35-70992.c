//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MESSAGE_LENGTH 1000
#define MAX_INT 2147483647

// Function to generate an RSA key pair
void generateKeyPair(int p, int q, int *n, int *e, int *d) {
    *n = p * q;
    int phi = (p - 1) * (q - 1);
    *e = rand() % phi;
    while (1) {
        if (gcd(*e, phi) == 1) {
            break;
        }
        *e = rand() % phi;
    }
    *d = multiplicativeInverse(*e, phi);
}

// Function to compute the greatest common divisor of two numbers
int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute the multiplicative inverse of a modulo m
int multiplicativeInverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1) {
        return 0;
    }

    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }

    if (x < 0) {
        x += m0;
    }

    return x;
}

// Function to encrypt a message using the RSA public key
void encrypt(char *message, int messageLength, int n, int e) {
    printf("Encrypted message: ");
    for (int i = 0; i < messageLength; i++) {
        int x = message[i];
        int cipher = 1;
        for (int j = 0; j < e; j++) {
            cipher = (cipher * x) % n;
        }
        printf("%d ", cipher);
    }
    printf("\n");
}

// Function to decrypt an encrypted message using the RSA private key
void decrypt(int *encryptedMessage, int messageLength, int n, int d) {
    printf("Decrypted message: ");
    for (int i = 0; i < messageLength; i++) {
        int x = encryptedMessage[i];
        int plain = 1;
        for (int j = 0; j < d; j++) {
            plain = (plain * x) % n;
        }
        printf("%c", plain);
    }
    printf("\n");
}

int main() {
    int p, q, n, e, d;
    char message[MAX_MESSAGE_LENGTH];

    printf("Enter two prime numbers (p and q): ");
    scanf("%d %d", &p, &q);

    generateKeyPair(p, q, &n, &e, &d);

    printf("Public Key (n, e): (%d, %d)\n", n, e);
    printf("Private Key (n, d): (%d, %d)\n", n, d);

    printf("Enter a message to encrypt: ");
    scanf(" %[^\n]s", message);

    int messageLength = strlen(message);

    // Encrypt the message using the RSA public key
    encrypt(message, messageLength, n, e);

    // Decrypt the message using the RSA private key
    int encryptedMessage[MAX_MESSAGE_LENGTH];
    printf("Enter the encrypted message: ");
    for (int i = 0; i < messageLength; i++) {
        scanf("%d", &encryptedMessage[i]);
    }
    decrypt(encryptedMessage, messageLength, n, d);

    return 0;
}