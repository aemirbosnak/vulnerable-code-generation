//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define Q 101
#define P 1000000007
#define G 2

// Function to calculate gcd of two numbers
int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to calculate modular exponentiation
int mod_exp(int base, int exponent, int modulus) {
    int result = 1;
    while(exponent > 0) {
        if(exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

// Function to generate random prime number
int generate_prime() {
    int num;
    while(1) {
        num = rand() % N + 2;
        if(gcd(num, P) == 1) {
            break;
        }
    }
    return num;
}

// Function to generate public and private keys
void generate_keys(int *public_key, int *private_key) {
    *public_key = generate_prime();
    *private_key = generate_prime();
}

// Function to encrypt message
void encrypt(int message, int public_key, int *encrypted_message) {
    int n = 0, e = 0;
    int d = mod_exp(public_key, P - 1, P);
    while(e == 0) {
        e = rand() % (P - 1);
        if(gcd(e, P - 1) == 1) {
            n = mod_exp(G, e, P);
        }
    }
    *encrypted_message = mod_exp(message, n, P);
}

// Function to decrypt message
int decrypt(int encrypted_message, int private_key) {
    int m = mod_exp(encrypted_message, private_key, P);
    return m;
}

// Main function
int main() {
    int public_key, private_key, message, encrypted_message, decrypted_message;
    generate_keys(&public_key, &private_key);
    printf("Public Key: %d\n", public_key);
    printf("Private Key: %d\n", private_key);
    printf("Enter message to encrypt: ");
    scanf("%d", &message);
    encrypt(message, public_key, &encrypted_message);
    printf("Encrypted message: %d\n", encrypted_message);
    decrypted_message = decrypt(encrypted_message, private_key);
    printf("Decrypted message: %d\n", decrypted_message);
    return 0;
}