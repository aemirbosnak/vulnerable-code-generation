//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Generate a random prime number between low and high
int generatePrime(int low, int high) {
    int i, j;

    for (i = low; i <= high; i++) {
        for (j = 2; j < i; j++) {
            if (i % j == 0)
                break;
        }
        if (j == i)
            return i;
    }

    return -1;
}

// Calculate modular exponentiation
int modExp(int base, int exponent, int modulus) {
    int result = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = floor(exponent / 2);
        base = (base * base) % modulus;
    }

    return result;
}

// Check whether a number is prime or not
int isPrime(int n) {
    int i;
    for (i = 2; i < n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

// Generate public key (e, n)
void generatePublicKey(int* e, int* n, int p, int q) {
    int phi = (p - 1) * (q - 1);
    *e = generatePrime(2, phi - 1);
    while (1) {
        if (isPrime(*e) && (*e < phi) && (phi % *e != 0))
            break;
        *e = generatePrime(2, phi - 1);
    }
    *n = p * q;
}

// Generate private key (d, n)
void generatePrivateKey(int* d, int* n, int e, int p, int q) {
    int phi = (p - 1) * (q - 1);
    int k = 2;
    *d = (1 + k * phi) / e;

    while (1) {
        if ((((*d) * e) % phi) == 1)
            break;
        k++;
        *d = (1 + k * phi) / e;
    }

    *n = p * q;
}

int main() {
    int p, q, e, d, n, message, encrypted_message, decrypted_message;
    printf("Enter two prime numbers: ");
    scanf("%d %d", &p, &q);

    generatePublicKey(&e, &n, p, q);
    generatePrivateKey(&d, &n, e, p, q);

    printf("\nPublic key: (%d, %d)", e, n);
    printf("\nPrivate key: (%d, %d)\n", d, n);

    printf("\nEnter message to encrypt: ");
    scanf("%d", &message);

    encrypted_message = modExp(message, e, n);
    printf("\nEncrypted message: %d\n", encrypted_message);

    decrypted_message = modExp(encrypted_message, d, n);
    printf("\nDecrypted message: %d\n", decrypted_message);

    return 0;
}