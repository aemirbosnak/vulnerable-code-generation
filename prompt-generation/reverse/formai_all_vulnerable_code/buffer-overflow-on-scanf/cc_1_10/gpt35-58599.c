//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

// function to check if a number is prime or not
int is_prime(int num) {
    int i;
    for(i=2; i<=sqrt(num); i++) {
        if(num%i == 0) {
            return 0;   // not a prime
        }
    }
    return 1;   // prime
}

// function to calculate greatest common divisor
int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    else {
        return gcd(b, a%b);
    }
}

// function to generate a random prime number
int generate_prime() {
    int num;
    srand(time(NULL));  // seed for random number generation
    do {
        num = rand()%999 + 2;   // generating a random number between 2 and 1000
    } while(!is_prime(num));    // keep generating until a prime number is obtained
    return num;
}

// function to calculate private key exponent
int get_private(int e, int phi) {
    int i;
    for(i=2; i<=phi-1; i++) {
        if((e*i) % phi == 1) {
            return i;   // private key found
        }
    }
}

// function to encrypt a message using public key
int encrypt(int msg, int e, int n) {
    int i;
    int c = 1;
    for(i=1; i<=e; i++) {
        c = (c*msg) % n;
    }
    return c;
}

// function to decrypt a message using private key
int decrypt(int c, int d, int n) {
    int i;
    int m = 1;
    for(i=1; i<=d; i++) {
        m = (m*c) % n;
    }
    return m;
}

int main() {
    int p, q;   // prime numbers
    int n, phi; // public key and totient
    int e, d;   // public and private key exponents
    int msg, c, m;  // message, cipher, decrypted message
    printf("Public Key Algorithm Implementation\n\n");
    // generate two random prime numbers
    printf("Generating two random prime numbers...\n");
    p = generate_prime();
    q = generate_prime();
    printf("Prime 1: %d\nPrime 2: %d\n", p, q);

    // calculate public key and totient
    n = p*q;
    phi = (p-1)*(q-1);

    // choose public key exponent
    e = 65537;  // commonly used value for e

    // calculate private key exponent
    d = get_private(e, phi);

    printf("\nPublic key: (%d, %d)\n", n, e);
    printf("Private key: %d\n", d);

    // get message from user
    printf("\nEnter message to be encrypted: ");
    scanf("%d", &msg);

    // encrypt message using public key
    c = encrypt(msg, e, n);
    printf("Encrypted Message: %d\n", c);

    // decrypt message using private key
    m = decrypt(c, d, n);
    printf("Decrypted Message: %d\n\n", m);

    return 0;
}