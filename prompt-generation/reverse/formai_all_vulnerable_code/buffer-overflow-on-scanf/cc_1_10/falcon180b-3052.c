//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1024
#define PRIME 31

// Function to calculate GCD
int gcd(int a, int b) {
    int temp;
    while (b!= 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return abs(a);
}

// Function to generate random prime number
int generate_prime(int size) {
    int num = rand() % (MAX_SIZE - 2) + 2;
    while (num % 2 == 0) {
        num++;
    }
    return num;
}

// Function to generate public and private keys
void generate_keys(int *public_key, int *private_key, int size) {
    int g = generate_prime(size);
    int p = 0;
    int i;

    // Calculate private key
    for (i = 0; i < size; i++) {
        p = (p * g + i + 1) % (MAX_SIZE - 1);
    }

    // Calculate public key
    *public_key = g;
    *private_key = p;
}

// Function to encrypt message using public key
void encrypt(char *message, int public_key, int size) {
    int i;
    char encrypted_message[MAX_SIZE];

    for (i = 0; i < strlen(message); i++) {
        encrypted_message[i] = (message[i] * public_key) % (MAX_SIZE - 1);
    }
    encrypted_message[i] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt message using private key
void decrypt(char *encrypted_message, int private_key, int size) {
    int i;
    char decrypted_message[MAX_SIZE];

    for (i = 0; i < strlen(encrypted_message); i++) {
        decrypted_message[i] = (encrypted_message[i] * private_key - 1) % (MAX_SIZE - 1);
    }
    decrypted_message[i] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    int public_key, private_key, size;

    printf("Enter message size: ");
    scanf("%d", &size);

    generate_keys(&public_key, &private_key, size);

    printf("Public key: %d\n", public_key);
    printf("Private key: %d\n", private_key);

    char message[MAX_SIZE];
    printf("Enter message to encrypt: ");
    scanf("%s", message);

    encrypt(message, public_key, size);

    printf("Encrypted message: %s\n", message);

    return 0;
}