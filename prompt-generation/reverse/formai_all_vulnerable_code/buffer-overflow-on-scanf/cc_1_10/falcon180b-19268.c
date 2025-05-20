//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024 // Maximum size of a message

typedef struct {
    int public_key;
    int private_key;
} KeyPair;

// Function to generate a random prime number
int generate_prime() {
    int num = rand() % 100 + 1;
    while (!is_prime(num)) {
        num = rand() % 100 + 1;
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

// Function to generate a key pair
void generate_key_pair(KeyPair* key_pair) {
    key_pair->public_key = generate_prime();
    key_pair->private_key = generate_prime();
}

// Function to encrypt a message using the public key
void encrypt(char* message, int public_key, char* encrypted_message) {
    int message_length = strlen(message);
    int encrypted_length = message_length * 2;
    char* buffer = malloc(encrypted_length + 1);
    memset(buffer, 0, encrypted_length + 1);
    int i = 0;
    int j = 0;
    while (i < message_length) {
        int char_value = message[i] - 'a';
        int encrypted_char_value = (char_value * public_key) % 26 + 'a';
        buffer[j++] = encrypted_char_value;
        i++;
    }
    strcpy(encrypted_message, buffer);
    free(buffer);
}

// Function to decrypt a message using the private key
void decrypt(char* encrypted_message, int private_key, char* decrypted_message) {
    int encrypted_length = strlen(encrypted_message);
    int decrypted_length = encrypted_length / 2;
    char* buffer = malloc(decrypted_length + 1);
    memset(buffer, 0, decrypted_length + 1);
    int i = 0;
    int j = 0;
    while (i < encrypted_length) {
        int char_value = encrypted_message[i] - 'a';
        int decrypted_char_value = (char_value - private_key + 26) % 26 + 'a';
        buffer[j++] = decrypted_char_value;
        i++;
    }
    strcpy(decrypted_message, buffer);
    free(buffer);
}

int main() {
    KeyPair key_pair;
    generate_key_pair(&key_pair);
    char message[MAX_SIZE];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    char encrypted_message[MAX_SIZE];
    encrypt(message, key_pair.public_key, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);
    char decrypted_message[MAX_SIZE];
    decrypt(encrypted_message, key_pair.private_key, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);
    return 0;
}