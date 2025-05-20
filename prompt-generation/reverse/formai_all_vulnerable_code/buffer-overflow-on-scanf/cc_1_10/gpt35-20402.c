//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

// function for encrypting message
void encrypt(int msg[], int n, int e, int nModulus) {
    int i;
    for (i=0; i<n; i++) {
        msg[i] = ((int)(pow(msg[i], e))) % nModulus;
    }
}

// function for decrypting message
void decrypt(int msg[], int n, int d, int nModulus) {
    int i;
    for (i=0; i<n; i++) {
        msg[i] = ((int)(pow(msg[i], d))) % nModulus;
    }
}

// function for finding multiplicative inverse
int multiplicative_inverse(int e, int phi) {
    int d;
    int i;
    for (i=2; i<phi; i++) {
        if ((e*i) % phi == 1) {
            return i;
        }
    }
    return 0;
}

// function for checking whether a number is prime or not
int is_prime(int n) {
    int i;
    for (i=2; i<=n/2; i++) {
        if (n%i == 0) {
            return 0;
        }
    }
    return 1;
}

// function for finding a random prime number
int find_prime() {
    int p;
    do {
        p = rand() % MAX + 1;
    } while (!is_prime(p));
    return p;
}

int main() {
    // seed for random number generation
    srand(time(NULL));

    // initialize variables
    int p, q, n, phi, e, d;
    int msg[MAX];
    int i, nModulus;

    // find two random prime numbers
    p = find_prime();
    q = find_prime();

    // calculate n and phi
    n = p*q;
    phi = (p-1)*(q-1);

    // find e such that 1 < e < phi and gcd(e, phi) = 1
    i=2;
    do {
        e = i++;
    } while (i<phi && multiplicative_inverse(e, phi) != 1);

    // calculate d such that de mod phi = 1
    d = multiplicative_inverse(e, phi);

    // modulus for encryption and decryption
    nModulus = n;

    // input message to be encrypted
    printf("Enter message:\n");
    for (i=0; i<MAX; i++) {
        scanf("%d", &msg[i]);
        if (msg[i] == -1) {
            break;
        }
    }

    // encrypt message
    encrypt(msg, i, e, nModulus);

    // output encrypted message
    printf("Encrypted message:\n");
    for (int j=0; j<i; j++) {
        printf("%d ", msg[j]);
    }
    printf("\n");

    // decrypt message
    decrypt(msg, i, d, nModulus);

    // output decrypted message
    printf("Decrypted message:\n");
    for (int j=0; j<i; j++) {
        printf("%d ", msg[j]);
    }
    printf("\n");

    return 0;
}