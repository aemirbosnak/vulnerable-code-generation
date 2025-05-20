//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1024
#define PRIME_NUMBER 31

// Function to generate a random prime number
int generate_prime() {
    int n, i, is_prime = 1;
    srand(time(NULL));
    n = rand() % MAX_SIZE + 1;

    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            is_prime = 0;
            break;
        }
    }

    if (is_prime) {
        return n;
    } else {
        return generate_prime();
    }
}

// Function to generate public and private keys
void generate_keys(int key_size, int *public_key, int *private_key) {
    int i, j, temp;

    // Generate a random prime number
    int prime = generate_prime();

    // Generate public key
    for (i = 0; i < key_size; i++) {
        public_key[i] = rand() % prime;
    }

    // Generate private key
    for (i = 0; i < key_size; i++) {
        private_key[i] = rand() % prime;
    }
}

// Function to encrypt the message using public key
void encrypt(int message[], int public_key[], int key_size) {
    int i, j, remainder;

    for (i = 0; i < key_size; i++) {
        remainder = message[i] % public_key[i];
        if (remainder!= 0) {
            message[i] = (message[i] - remainder + public_key[i]) % public_key[i];
        }
    }
}

// Function to decrypt the message using private key
void decrypt(int message[], int private_key[], int key_size) {
    int i, j, remainder;

    for (i = 0; i < key_size; i++) {
        remainder = message[i] % private_key[i];
        if (remainder!= 0) {
            message[i] = (message[i] - remainder + private_key[i]) % private_key[i];
        }
    }
}

int main() {
    int key_size, message_size, i, j, choice;
    int public_key[MAX_SIZE], private_key[MAX_SIZE];
    char message[MAX_SIZE];

    // Get key size from user
    printf("Enter key size (between 1 and %d): ", MAX_SIZE);
    scanf("%d", &key_size);

    // Generate public and private keys
    generate_keys(key_size, public_key, private_key);

    // Get message size from user
    printf("Enter message size (between 1 and %d): ", MAX_SIZE);
    scanf("%d", &message_size);

    // Get message from user
    printf("Enter message: ");
    scanf("%s", message);

    // Encrypt message
    encrypt(message, public_key, key_size);

    // Print encrypted message
    printf("Encrypted message: ");
    for (i = 0; i < message_size; i++) {
        printf("%d ", message[i]);
    }
    printf("\n");

    // Decrypt message
    decrypt(message, private_key, key_size);

    // Print decrypted message
    printf("Decrypted message: ");
    for (i = 0; i < message_size; i++) {
        printf("%d ", message[i]);
    }
    printf("\n");

    return 0;
}