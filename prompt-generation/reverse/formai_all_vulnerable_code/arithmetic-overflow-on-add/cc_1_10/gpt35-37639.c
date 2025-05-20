//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define PRIME_MAX 10000   // the maximum value for the prime numbers generated

// function to check if a number is prime
bool is_prime(int n)
{
    int i;
    if (n <= 1) {
        return false;
    }
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// function to generate a random prime number
int generate_prime()
{
    int prime;
    do {
        prime = rand() % PRIME_MAX;
    } while (!is_prime(prime));
    return prime;
}

// function to calculate the greatest common divisor
int gcd(int a, int b)
{
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// function to calculate the public key
int generate_public_key(int phi)
{
    int e;
    do {
        e = rand() % (phi - 2) + 2;
    } while (gcd(e, phi) != 1);
    return e;
}

// function to calculate the private key
int generate_private_key(int e, int phi)
{
    int d = 0;
    while ((e * d) % phi != 1 || d == e) {
        if (d == e) {
            d++;
        }
        d++;
    }
    return d;
}

int main()
{
    // seed for random number generation
    srand(time(NULL));

    int p = generate_prime();   // generate first prime number
    int q = generate_prime();   // generate second prime number

    // calculate n and phi
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // generate public and private keys
    int e = generate_public_key(phi);
    int d = generate_private_key(e, phi);

    // display keys
    printf("Public key: (%d,%d)\n", e, n);
    printf("Private key: (%d,%d)\n", d, n);

    return 0;
}