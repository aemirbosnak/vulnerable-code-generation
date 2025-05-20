//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NUM 10000
#define PRIME_NUM 101

// Function to generate two prime numbers
int generate_primes(int *num1, int *num2) {
    int i, j;
    srand(time(NULL));
    for (i = 2; i <= MAX_NUM; i++) {
        if (isprime(i)) {
            *num1 = i;
            break;
        }
    }
    for (j = i + 1; j <= MAX_NUM; j++) {
        if (isprime(j)) {
            *num2 = j;
            break;
        }
    }
    return 0;
}

// Function to check if a number is prime or not
int isprime(int n) {
    if (n <= 1)
        return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

// Function to encrypt the message using public key
void encrypt(int *message, int *public_key, int *encrypted_message, int n) {
    int i;
    for (i = 0; i < n; i++) {
        encrypted_message[i] = (message[i] * public_key[i]) % MAX_NUM;
    }
}

// Function to decrypt the message using private key
void decrypt(int *encrypted_message, int *private_key, int *decrypted_message, int n) {
    int i;
    for (i = 0; i < n; i++) {
        decrypted_message[i] = (encrypted_message[i] * private_key[i]) % MAX_NUM;
    }
}

// Main function to run the program
int main() {
    int message[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int public_key[10], private_key[10], encrypted_message[10], decrypted_message[10];
    int n = sizeof(message) / sizeof(message[0]);
    generate_primes(&public_key[0], &private_key[0]);
    printf("Public Key: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", public_key[i]);
    }
    printf("\nPrivate Key: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", private_key[i]);
    }
    printf("\nMessage: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", message[i]);
    }
    encrypt(message, public_key, encrypted_message, n);
    printf("\nEncrypted Message: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", encrypted_message[i]);
    }
    decrypt(encrypted_message, private_key, decrypted_message, n);
    printf("\nDecrypted Message: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", decrypted_message[i]);
    }
    return 0;
}