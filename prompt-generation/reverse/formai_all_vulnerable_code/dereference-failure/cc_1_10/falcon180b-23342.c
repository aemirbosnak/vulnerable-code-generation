//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_KEY_SIZE 1024
#define MAX_STRING_SIZE 1024

// Struct to hold public and private keys
typedef struct {
    char *public_key;
    char *private_key;
} KeyPair;

// Function to generate a random string of given length
void generate_random_string(char *string, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < length; i++) {
        string[i] = charset[rand() % strlen(charset)];
    }
    string[length] = '\0';
}

// Function to generate a key pair
KeyPair generate_key_pair() {
    KeyPair key_pair;
    generate_random_string(key_pair.public_key, MAX_KEY_SIZE);
    generate_random_string(key_pair.private_key, MAX_KEY_SIZE);
    return key_pair;
}

// Function to encrypt a message using a public key
char *encrypt_message(const char *message, const char *public_key) {
    int message_length = strlen(message);
    int public_key_length = strlen(public_key);
    char *encrypted_message = malloc(message_length + 1);
    for (int i = 0; i < message_length; i++) {
        encrypted_message[i] = message[i] ^ public_key[i % public_key_length];
    }
    encrypted_message[message_length] = '\0';
    return encrypted_message;
}

// Function to decrypt a message using a private key
char *decrypt_message(const char *encrypted_message, const char *private_key) {
    int encrypted_message_length = strlen(encrypted_message);
    int private_key_length = strlen(private_key);
    char *decrypted_message = malloc(encrypted_message_length + 1);
    for (int i = 0; i < encrypted_message_length; i++) {
        decrypted_message[i] = encrypted_message[i] ^ private_key[i % private_key_length];
    }
    decrypted_message[encrypted_message_length] = '\0';
    return decrypted_message;
}

int main() {
    srand(time(NULL));

    // Generate a key pair
    KeyPair key_pair = generate_key_pair();
    printf("Public Key: %s\n", key_pair.public_key);
    printf("Private Key: %s\n", key_pair.private_key);

    // Encrypt a message
    char *message = "Hello, world!";
    char *encrypted_message = encrypt_message(message, key_pair.public_key);
    printf("Encrypted Message: %s\n", encrypted_message);

    // Decrypt the message
    char *decrypted_message = decrypt_message(encrypted_message, key_pair.private_key);
    printf("Decrypted Message: %s\n", decrypted_message);

    return 0;
}