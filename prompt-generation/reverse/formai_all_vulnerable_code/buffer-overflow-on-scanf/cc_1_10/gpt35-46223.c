//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: funny
// Welcome to the world of public-key cryptography!
// This program implements a top-secret algorithm known as Chuck Norris' Beard.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define some constants for the algorithm
#define NUMBER_OF_BEARD_HAIRS 100
#define BEARD_HAIR_LENGTH 10

// Function to generate a random prime number
int generate_random_prime(int min, int max) {
    int num;
    srand(time(NULL));
    num = (rand() % (max - min + 1)) + min;
    for(int i=2; i<num; i++) {
        if(num % i == 0) {
            num = generate_random_prime(min, max);
            break;
        }
    }
    return num;
}

// Function to calculate modular exponentiation
int modular_exponentiation(int base, int exponent, int modulus) {
    int result = 1;
    while(exponent > 0) {
        if(exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

int main() {
    int beard_hairs[NUMBER_OF_BEARD_HAIRS];
    int public_key, private_key, p, q, n, t;
    char message[100];

    // Get the message to encrypt from the user
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Generate two random prime numbers
    p = generate_random_prime(100, 999);
    q = generate_random_prime(100, 999);

    // Calculate n and t
    n = p * q;
    t = (p-1) * (q-1);

    // Generate a public key e
    public_key = generate_random_prime(2, t-1);

    // Calculate a private key d
    for(int i=1; i<t; i++) {
        if(((public_key*i) % t) == 1) {
            private_key = i;
            break;
        }
    }

    // Grow a beard!
    printf("\nGrowing a beard...\n");
    for(int i=0; i<NUMBER_OF_BEARD_HAIRS; i++) {
        beard_hairs[i] = generate_random_prime(100000, 999999);
    }

    // Encrypt the message using Chuck Norris' Beard algorithm
    printf("\nEncrypting the message with Chuck Norris' Beard algorithm...\n");
    for(int i=0; i<strlen(message); i++) {
        int c = message[i];
        int encrypted = modular_exponentiation(c, public_key, n);
        message[i] = encrypted;
    }

    // Print out the encrypted message and keys
    printf("\nEncrypted message: %s", message);
    printf("\nPublic key: %d", public_key);
    printf("\nPrivate key: %d", private_key);

    // Shave the beard and decrypt the message
    printf("\n\nShaving the beard...\n");
    for(int i=0; i<NUMBER_OF_BEARD_HAIRS; i++) {
        beard_hairs[i] = 0;
    }
    printf("\nDecrypting the message with Chuck Norris' Beard algorithm...\n");
    for(int i=0; i<strlen(message); i++) {
        int c = message[i];
        int decrypted = modular_exponentiation(c, private_key, n);
        message[i] = decrypted;
    }

    // Print out the decrypted message
    printf("\nDecrypted message: %s\n", message);

    return 0;
}