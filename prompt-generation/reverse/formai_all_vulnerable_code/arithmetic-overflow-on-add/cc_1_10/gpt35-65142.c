//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

void generate_key(int *e, int *d, int *n);
long int encrypt(int msg, int e, int n);
long int decrypt(int cypher, int d, int n);
int gcd(int a, int b);
int is_prime(int num);

int main() {
    int e, d, n, i;
    int msg[MAX_SIZE], cypher[MAX_SIZE], decrypted[MAX_SIZE];
    int len;

    // Generate public-private key pair
    generate_key(&e, &d, &n);
    printf("Public key: e = %d, n = %d\n", e, n);
    printf("Private key: d = %d, n = %d\n", d, n);

    // Get message to be encrypted
    printf("Enter message to be encrypted: ");
    fgets(msg, MAX_SIZE, stdin);

    // Remove newline character from message
    len = strlen(msg);
    if (msg[len-1] == '\n') {
        msg[len-1] = '\0';
        len--;
    }

    // Encrypt message
    for (i = 0; i < len; i++) {
        cypher[i] = encrypt(msg[i], e, n);
    }

    // Print encrypted message
    printf("Encrypted message: ");
    for (i = 0; i < len; i++) {
        printf("%ld ", cypher[i]);
    }
    printf("\n");

    // Decrypt message
    for (i = 0; i < len; i++) {
        decrypted[i] = decrypt(cypher[i], d, n);
    }

    // Print decrypted message
    printf("Decrypted message: ");
    for (i = 0; i < len; i++) {
        printf("%c", decrypted[i]);
    }
    printf("\n");

    return 0;
}

void generate_key(int *e, int *d, int *n) {
    int p, q;

    // Generate two random prime numbers
    do {
        p = rand() % 100 + 1;
    } while (!is_prime(p));
    do {
        q = rand() % 100 + 1;
    } while (!is_prime(q));

    *n = p * q;
    int phi = (p - 1) * (q - 1);

    // Choose random public key e such that gcd(e, phi) = 1
    do {
        *e = rand() % (phi - 1) + 1;
    } while (gcd(*e, phi) != 1);

    // Calculate private key d such that d*e = 1 (mod phi)
    int k = 1;
    do {
        *d = (k * phi + 1) / *e;
        k++;
    } while ((*d) * (*e) % phi != 1);
}

long int encrypt(int msg, int e, int n) {
    long int cypher = 1;
    for (int i = 0; i < e; i++) {
        cypher = (cypher * msg) % n;
    }
    return cypher;
}

long int decrypt(int cypher, int d, int n) {
    long int msg = 1;
    for (int i = 0; i < d; i++) {
        msg = (msg * cypher) % n;
    }
    return msg;
}

int gcd(int a, int b) {
    int temp;
    while (b > 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}