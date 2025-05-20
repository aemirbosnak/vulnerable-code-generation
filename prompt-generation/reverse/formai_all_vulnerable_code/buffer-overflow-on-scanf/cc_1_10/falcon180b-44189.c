//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define prime numbers
#define PRIME_1 17
#define PRIME_2 23

// Define the public key
int public_key[2] = {PRIME_1, PRIME_2};

// Define the private key
int private_key[2];

// Define the number of elements in the key
#define KEY_SIZE 2

// Define the maximum value of the input
#define MAX_VALUE 1000000

// Define the buffer size for reading input
#define BUFFER_SIZE 1000000

// Define the function prototypes
void generate_keys();
int encrypt(int input);
int decrypt(int input);

int main() {
    generate_keys();
    int input;
    printf("Enter a message to encrypt: ");
    scanf("%d", &input);
    int encrypted_input = encrypt(input);
    printf("Encrypted message: %d\n", encrypted_input);
    int decrypted_input = decrypt(encrypted_input);
    printf("Decrypted message: %d\n", decrypted_input);
    return 0;
}

// Generate the public and private keys
void generate_keys() {
    int temp_key[KEY_SIZE];
    for (int i = 0; i < KEY_SIZE; i++) {
        private_key[i] = public_key[i] = rand() % MAX_VALUE + 1;
    }
    for (int i = 0; i < KEY_SIZE; i++) {
        temp_key[i] = public_key[i];
        public_key[i] = private_key[i];
        private_key[i] = temp_key[i];
    }
}

// Encrypt the input using the public key
int encrypt(int input) {
    int encrypted_input = 1;
    for (int i = 0; i < KEY_SIZE; i++) {
        encrypted_input = (encrypted_input * public_key[i]) % MAX_VALUE;
    }
    return encrypted_input;
}

// Decrypt the input using the private key
int decrypt(int input) {
    int decrypted_input = 1;
    for (int i = 0; i < KEY_SIZE; i++) {
        decrypted_input = (decrypted_input * private_key[i]) % MAX_VALUE;
    }
    return decrypted_input;
}