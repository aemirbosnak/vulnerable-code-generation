//Falcon2-11B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for modulus and exponent
#define MODULUS 65537
#define PUBLIC_EXPONENT 65537

// Function to generate public and private keys
void generate_keys(int* public_key, int* private_key) {
    // Choose two random primes for modulus and exponent
    int modulus_1 = rand() % MODULUS;
    int modulus_2 = rand() % MODULUS;
    int exponent_1 = rand() % MODULUS;
    int exponent_2 = rand() % MODULUS;

    // Calculate the public and private keys
    int public_key_1 = (modulus_1 * exponent_1) % MODULUS;
    int public_key_2 = (modulus_2 * exponent_2) % MODULUS;
    int private_key_1 = (modulus_1 * exponent_2) % MODULUS;
    int private_key_2 = (modulus_2 * exponent_1) % MODULUS;

    // Store the keys in the given arrays
    public_key[0] = public_key_1;
    public_key[1] = public_key_2;
    private_key[0] = private_key_1;
    private_key[1] = private_key_2;
}

// Function to encrypt a message using the public key
void encrypt(int* public_key, char* message, char* ciphertext) {
    // Perform modular exponentiation to encrypt the message
    int message_value = (int) message[0];
    int exponent = (int) public_key[0];
    int modulus = MODULUS;
    int encrypted_value = 1;

    for (int i = 0; i < strlen(message); i++) {
        int char_value = (int) message[i];
        encrypted_value *= (char_value % modulus);
        encrypted_value %= modulus;
    }

    // Convert the encrypted value to a character and store it in the ciphertext array
    ciphertext[0] = (char) (encrypted_value % 256);
}

// Function to decrypt a ciphertext using the private key
void decrypt(int* private_key, char* ciphertext, char* message) {
    // Perform modular exponentiation to decrypt the ciphertext
    int ciphertext_value = (int) ciphertext[0];
    int exponent = (int) private_key[0];
    int modulus = MODULUS;
    int decrypted_value = 1;

    for (int i = 0; i < strlen(ciphertext); i++) {
        int char_value = (int) ciphertext[i];
        decrypted_value *= (char_value % modulus);
        decrypted_value %= modulus;
    }

    // Convert the decrypted value to a character and store it in the message array
    message[0] = (char) (decrypted_value % 256);
}

int main() {
    // Generate the public and private keys
    int public_key[2], private_key[2];
    generate_keys(&public_key[0], &private_key[0]);

    // Encrypt a message using the public key
    char message[] = "Hello, world!";
    char ciphertext[2];
    encrypt(public_key, message, ciphertext);

    // Decrypt the ciphertext using the private key
    char decrypted_message[2];
    decrypt(private_key, ciphertext, decrypted_message);

    // Print the results
    printf("Encrypted message: %s\n", ciphertext);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}