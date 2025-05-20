//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define PRIME_NUMBER 31

// Function to generate a random prime number
int generate_prime() {
    int num = rand() % MAX_SIZE + 2;
    while (!is_prime(num)) {
        num = rand() % MAX_SIZE + 2;
    }
    return num;
}

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate public and private keys
void generate_keys(int *public_key, int *private_key) {
    *public_key = generate_prime();
    *private_key = generate_prime();
}

// Function to encrypt a message using the public key
void encrypt(int public_key, char *message) {
    int len = strlen(message);
    char encrypted_message[len + 1];
    encrypted_message[len] = '\0';

    for (int i = 0; i < len; i++) {
        encrypted_message[i] = message[i] ^ (public_key % PRIME_NUMBER);
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt an encrypted message using the private key
void decrypt(int private_key, char *encrypted_message) {
    int len = strlen(encrypted_message);
    char decrypted_message[len + 1];
    decrypted_message[len] = '\0';

    for (int i = 0; i < len; i++) {
        decrypted_message[i] = encrypted_message[i] ^ (private_key % PRIME_NUMBER);
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    int public_key, private_key;
    generate_keys(&public_key, &private_key);

    char message[MAX_SIZE];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    encrypt(public_key, message);

    return 0;
}