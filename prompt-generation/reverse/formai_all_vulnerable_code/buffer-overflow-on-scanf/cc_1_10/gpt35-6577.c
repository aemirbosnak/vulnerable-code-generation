//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Preparing for the apocalypse
#define MAX_KEY 65536
#define MAX_MSG_LEN 1024

// struct to hold keys
struct keys {
    int public_key;
    int private_key;
};

// function to check if number is prime
int is_prime(int n) {
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

// function to find greatest common divisor
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// function to find multiplicative inverse
int mult_inv(int a, int b) {
    int d0 = a, d1 = b;
    int x0 = 1, x1 = 0;
    int y0 = 0, y1 = 1;
    while (d1 > 1) {
        int q = d0 / d1;
        int d2 = d0 - q * d1;
        int x2 = x0 - q * x1;
        int y2 = y0 - q * y1;
        d0 = d1; d1 = d2;
        x0 = x1; x1 = x2;
        y0 = y1; y1 = y2;
    }
    return (y1 < 0) ? y1 + a : y1;
}

// function to generate public and private keys
struct keys gen_keys(int p, int q) {
    struct keys k;
    int n = p * q;
    int fn = (p - 1) * (q - 1);
    int e = 2;
    while (gcd(e, fn) != 1) {
        e++;
    }
    int d = mult_inv(fn, e);
    k.public_key = e;
    k.private_key = d;
    return k;
}

// function to encrypt message
int* encrypt(char* msg, int n, int e) {
    int* enc = (int*) malloc(sizeof(int) * MAX_MSG_LEN);
    for (int i = 0; i < strlen(msg); i++) {
        enc[i] = fmod(pow((int)msg[i], e), n);
    }
    return enc;
}

// function to decrypt message
char* decrypt(int* enc, int n, int d) {
    char* dec = (char*) malloc(sizeof(char) * MAX_MSG_LEN);
    for (int i = 0; enc[i] != '\0'; i++) {
        dec[i] = (char)fmod(pow(enc[i], d), n);
    }
    return dec;
}

int main() {
    // initialize variables
    int p, q;
    char msg[MAX_MSG_LEN];
    int* enc_msg;
    char* dec_msg;
    struct keys k;

    // get prime numbers from user
    printf("Enter two prime numbers (separated by a space): ");
    scanf("%d %d", &p, &q);

    // check if p and q are prime
    if (!is_prime(p) || !is_prime(q)) {
        printf("Error: p and q must be prime numbers.\n");
        return 1;
    }

    // generate public and private keys
    k = gen_keys(p, q);
    printf("\nPublic key: %d\nPrivate key: %d\n", k.public_key, k.private_key);

    // get message from user
    printf("\nEnter message: ");
    scanf(" %[^\n]s", msg);

    // encrypt message
    enc_msg = encrypt(msg, p * q, k.public_key);
    printf("\nEncrypted message: ");
    for (int i = 0; enc_msg[i] != '\0'; i++) {
        printf("%d ", enc_msg[i]);
    }

    // decrypt message
    dec_msg = decrypt(enc_msg, p * q, k.private_key);
    printf("\nDecrypted message: %s\n", dec_msg);

    // clean up memory
    free(enc_msg);
    free(dec_msg);

    return 0;
}