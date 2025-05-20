//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 1024
#define MAX_INPUT_LENGTH 4096

// Function prototypes
void generate_key(char* key, int key_length);
int encrypt(char* input, char* key, char* output);
int decrypt(char* input, char* key, char* output);

int main() {
    char input[MAX_INPUT_LENGTH];
    char output[MAX_INPUT_LENGTH];
    char key[MAX_KEY_LENGTH];
    int key_length;
    int input_length;
    int output_length;

    // Get input
    printf("Enter input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input_length = strlen(input);

    // Generate key
    printf("Enter key length: ");
    scanf("%d", &key_length);
    generate_key(key, key_length);

    // Encrypt input
    output_length = MAX_INPUT_LENGTH;
    encrypt(input, key, output);
    printf("Encrypted output: %s\n", output);

    // Decrypt output
    decrypt(output, key, input);
    printf("Decrypted input: %s\n", input);

    return 0;
}

// Generates a random key of specified length
void generate_key(char* key, int key_length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`~";
    int i;

    for (i = 0; i < key_length; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }

    key[key_length] = '\0';
}

// Encrypts input using XOR with key
int encrypt(char* input, char* key, char* output) {
    int i;

    for (i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key[i % strlen(key)];
    }

    output[strlen(input)] = '\0';
}

// Decrypts output using XOR with key
int decrypt(char* input, char* key, char* output) {
    int i;

    for (i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key[i % strlen(key)];
    }

    output[strlen(input)] = '\0';
}