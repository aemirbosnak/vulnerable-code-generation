//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to generate public and private key pairs
void generate_keys(int p, int q, int *public_key, int *private_key)
{
    int n = p * q; // calculate the value of n
    int phi = (p - 1) * (q - 1); // calculate the value of phi(n)
    int e, d; // variables to hold the public and private keys

    // find a value for e such that 1 < e < phi(n) and e is co-prime to phi(n)
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1) {
            break;
        }
    }

    // calculate the value of d such that d is the multiplicative inverse of e (mod phi(n))
    d = multiplicative_inverse(e, phi);

    // set the values of the public and private keys
    *public_key = e;
    *private_key = d;
}

// function to encrypt a message using the public key
void encrypt(int plaintext, int public_key, int n, int *ciphertext)
{
    *ciphertext = mod_pow(plaintext, public_key, n);
}

// function to decrypt a ciphertext using the private key
void decrypt(int ciphertext, int private_key, int n, int *plaintext)
{
    *plaintext = mod_pow(ciphertext, private_key, n);
}

// main function
int main()
{
    int p, q; // variables to hold the prime numbers
    int public_key, private_key; // variables to hold the public and private keys
    int plaintext; // variable to hold the plaintext
    int ciphertext; // variable to hold the ciphertext

    // get input from the user
    printf("Enter two prime numbers: ");
    scanf("%d %d", &p, &q);

    // generate the public and private key pairs
    generate_keys(p, q, &public_key, &private_key);

    // print the public and private keys
    printf("Public key: %d\n", public_key);
    printf("Private key: %d\n", private_key);

    // get input from the user
    printf("Enter the plaintext message: ");
    scanf("%d", &plaintext);

    // encrypt the message using the public key
    encrypt(plaintext, public_key, p*q, &ciphertext);

    // print the ciphertext
    printf("Ciphertext: %d\n", ciphertext);

    // decrypt the ciphertext using the private key
    decrypt(ciphertext, private_key, p*q, &plaintext);

    // print the decrypted plaintext
    printf("Decrypted plaintext: %d\n", plaintext);

    return 0;
}

// function to calculate the greatest common divisor of two numbers
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

// function to calculate the multiplicative inverse of a number (mod n)
int multiplicative_inverse(int a, int n)
{
    int t = 0;
    int new_t = 1;
    int r = n;
    int new_r = a;

    while (new_r != 0) {
        int quotient = r / new_r;

        int tmp_t = new_t;
        new_t = t - quotient * new_t;
        t = tmp_t;

        int tmp_r = new_r;
        new_r = r - quotient * new_r;
        r = tmp_r;
    }

    if (r > 1)
        return -1;

    if (t < 0)
        t = t + n;

    return t;
}

// function to calculate a number raised to a power (mod n)
int mod_pow(int base, int exponent, int n)
{
    int result = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % n;
        }

        base = (base * base) % n;
        exponent = exponent / 2;
    }

    return result;
}