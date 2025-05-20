//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h>

// Define the hash function
void hash(const char* input, unsigned char* output) {
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, input, strlen(input));
    SHA256_Final(output, &ctx);
}

// Define the encryption function
void encrypt(const char* input, unsigned char* output) {
    hash(input, output);
}

// Define the decryption function
void decrypt(const unsigned char* input, char* output) {
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, input, SHA256_DIGEST_LENGTH);
    SHA256_Final(output, &ctx);
}

// Define the main function
int main() {
    char input[100];
    unsigned char output[SHA256_DIGEST_LENGTH];
    char decrypted[SHA256_DIGEST_LENGTH];

    // Prompt the user for input
    printf("Enter a message to encrypt: ");
    scanf("%s", input);

    // Encrypt the input message
    encrypt(input, output);

    // Print the encrypted message
    printf("Encrypted message: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02X", output[i]);
    }
    printf("\n");

    // Decrypt the encrypted message
    decrypt(output, decrypted);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}