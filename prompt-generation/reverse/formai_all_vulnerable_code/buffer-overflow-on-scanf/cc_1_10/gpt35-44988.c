//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define maximum value of prime number
#define MAX_PRIME_VALUE 100

// Function to calculate greatest common divisor using Euclid's algorithm
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

// Function to find the smallest prime number greater than the input value
int find_next_prime(int n) {
    int i, j;
    for (i = n + 1; i <= MAX_PRIME_VALUE; i++) {
        for (j = 2; j <= (int)sqrt(i); j++) {
            if (i % j == 0)
                break;
        }
        if (j > (int)sqrt(i))
            return i;
    }
    return -1;
}

// Function to generate public and private key pairs
void generate_key_pairs(int *p, int *q, int *n, int *e, int *d) {
    int phi_n;
    *p = rand() % MAX_PRIME_VALUE + 1;
    *q = find_next_prime(*p);
    *n = (*p) * (*q);
    phi_n = (*p - 1) * (*q - 1);
    do {
        *e = rand() % phi_n + 1;
    } while (gcd(*e, phi_n) != 1);
    // Extended Euclid's algorithm to calculate modular multiplicative inverse
    int a = *e, b = phi_n, x = 1, y = 0, temp;
    while (b > 0) {
        int quotient = a / b;
        temp = b;
        b = a % b;
        a = temp;
        temp = y;
        y = x - quotient * y;
        x = temp;
    }
    if (x < 0)
        *d = x + phi_n;
    else
        *d = x;
}

// Function to encrypt the message using public key
long long int encrypt(int message, int e, int n) {
    long long int result = message;
    int i;
    for (i = 1; i < e; i++) {
        result = (result * message) % n;
    }
    return result;
}

// Function to decrypt the message using private key
long long int decrypt(long long int message, int d, int n) {
    long long int result = message;
    int i;
    for (i = 1; i < d; i++) {
        result = (result * message) % n;
    }
    return result;
}

// Main function to demonstrate the usage of public-key algorithm
int main() {
    int p, q, n, e, d;
    int message;
    printf("Enter a message to encrypt: ");
    scanf("%d", &message);
    generate_key_pairs(&p, &q, &n, &e, &d);
    printf("p = %d, q = %d, n = %d, e = %d, d = %d\n", p, q, n, e, d);
    long long int encrypted_message = encrypt(message, e, n);
    printf("Encrypted message: %lld\n", encrypted_message);
    long long int decrypted_message = decrypt(encrypted_message, d, n);
    printf("Decrypted message: %lld\n", decrypted_message);
    return 0;
}