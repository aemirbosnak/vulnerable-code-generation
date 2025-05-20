//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PRIME 100000
#define MAX_VALUE 100000

typedef struct {
    int public_key;
    int private_key;
} KeyPair;

// Function to generate random prime numbers
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int generate_prime(int *prime) {
    int num = rand() % MAX_PRIME + 1;
    while (!is_prime(num)) {
        num = rand() % MAX_PRIME + 1;
    }
    *prime = num;
    return 1;
}

// Function to generate key pair
void generate_key_pair(KeyPair *key_pair) {
    int prime1, prime2;
    generate_prime(&prime1);
    generate_prime(&prime2);
    key_pair->public_key = prime1 * prime2;
    key_pair->private_key = prime1 + prime2;
}

// Function to encrypt message using public key
int encrypt(int message, int public_key, int *encrypted_message) {
    int result = 1;
    int temp = message;
    while (temp!= 0) {
        *encrypted_message = *encrypted_message * public_key % MAX_VALUE;
        temp /= public_key;
    }
    return result;
}

// Function to decrypt message using private key
int decrypt(int encrypted_message, int private_key, int *decrypted_message) {
    int result = 1;
    int temp = encrypted_message;
    while (temp!= 0) {
        *decrypted_message = (*decrypted_message * private_key) % MAX_VALUE;
        temp /= private_key;
    }
    return result;
}

int main() {
    KeyPair key_pair;
    generate_key_pair(&key_pair);
    int message = 12345;
    int encrypted_message, decrypted_message;
    encrypt(message, key_pair.public_key, &encrypted_message);
    printf("Encrypted message: %d\n", encrypted_message);
    decrypt(encrypted_message, key_pair.private_key, &decrypted_message);
    printf("Decrypted message: %d\n", decrypted_message);
    return 0;
}