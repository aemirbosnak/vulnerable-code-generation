//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: satisfied
#include <stdio.h>

// Function to calculate greatest common divisor of two numbers
int gcd(int a, int b) {
    int temp;
    while (b > 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Function to calculate modulo inverse using extended Euclidean algorithm
int mod_inv(int e, int phi) {
    int x1 = 1, y1 = 0, x2 = 0, y2 = 1; // Initial values
    int a = phi, b = e, q, temp;
    while (b > 0) {
        q = a / b;
        temp = a - q * b;
        a = b;
        b = temp;
        temp = x1 - q * x2;
        x1 = x2;
        x2 = temp;
        temp = y1 - q * y2;
        y1 = y2;
        y2 = temp;
    }
    return x1 < 0 ? x1 + phi : x1;
}

// Function to encrypt using public key
int encrypt(int msg, int e, int n) {
    int c = 1;
    while (e > 0) {
        if (e & 1) c = (c * msg) % n;
        msg = (msg * msg) % n;
        e >>= 1;
    }
    return c;
}

// Function to decrypt using private key
int decrypt(int c, int d, int n) {
    int m = 1;
    while (d > 0) {
        if (d & 1) m = (m * c) % n;
        c = (c * c) % n;
        d >>= 1;
    }
    return m;
}

int main() {
    int p, q, n, phi, e, d, msg, c, m;
    printf("Enter two prime numbers: ");
    scanf("%d %d", &p, &q);
    n = p * q;
    phi = (p - 1) * (q - 1);
    do {
        printf("Enter a number for public key (1 < e < %d) and gcd(e, phi(n)) = 1: ", phi);
        scanf("%d", &e);
    } while (gcd(e, phi) != 1);
    d = mod_inv(e, phi); // Private key
    printf("Public key: (%d, %d)\nPrivate key: (%d, %d)\n", e, n, d, n);
    printf("Enter message to be encrypted: ");
    scanf("%d", &msg);
    c = encrypt(msg, e, n);
    printf("Encrypted message: %d\n", c);
    m = decrypt(c, d, n);
    printf("Decrypted message: %d\n", m);
    return 0;
}