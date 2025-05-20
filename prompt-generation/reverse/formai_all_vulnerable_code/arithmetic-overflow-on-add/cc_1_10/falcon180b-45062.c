//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PRIME 1000
#define MAX_KEY_SIZE 1024

// Function to generate prime number
int is_prime(int n) {
    if (n <= 1)
        return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

// Function to generate public and private keys
void generate_keys(int *public_key, int *private_key, int key_size) {
    int prime = 0;
    int j = 0;
    while (j < key_size) {
        while (!is_prime(prime)) {
            prime = rand() % MAX_PRIME;
        }
        public_key[j] = prime;
        private_key[j] = (prime - 1) % MAX_PRIME;
        j++;
    }
}

// Function to encrypt the message
void encrypt(char *message, int public_key[], int key_size) {
    int i = 0;
    while (message[i]!= '\0') {
        message[i] = (message[i] + public_key[i % key_size]) % 256;
        i++;
    }
}

// Function to decrypt the message
void decrypt(char *message, int private_key[], int key_size) {
    int i = 0;
    while (message[i]!= '\0') {
        message[i] = (message[i] - private_key[i % key_size] + 256) % 256;
        i++;
    }
}

int main() {
    int key_size;
    printf("Enter the key size (max %d): ", MAX_KEY_SIZE);
    scanf("%d", &key_size);

    int public_key[key_size], private_key[key_size];
    generate_keys(public_key, private_key, key_size);

    char message[MAX_KEY_SIZE];
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    encrypt(message, public_key, key_size);
    printf("Encrypted message: %s\n", message);

    decrypt(message, private_key, key_size);
    printf("Decrypted message: %s\n", message);

    return 0;
}