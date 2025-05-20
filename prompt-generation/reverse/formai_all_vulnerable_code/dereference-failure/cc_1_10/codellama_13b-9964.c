//Code Llama-13B DATASET v1.0 Category: Cryptography Implementation ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define BUF_SIZE 1024
#define KEY_SIZE 16

// Custom error handling
#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

// Custom function to generate a random key
void generate_key(char *key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = (char)rand();
    }
}

// Custom function to encrypt a string using a key
void encrypt_string(char *str, char *key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(str); i++, j++) {
        if (j == KEY_SIZE) j = 0;
        str[i] = str[i] + key[j];
    }
}

// Custom function to decrypt a string using a key
void decrypt_string(char *str, char *key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(str); i++, j++) {
        if (j == KEY_SIZE) j = 0;
        str[i] = str[i] - key[j];
    }
}

int main() {
    // Generate a random key
    char key[KEY_SIZE];
    generate_key(key);

    // Encrypt a string using the key
    char *str = "Hello, World!";
    encrypt_string(str, key);

    // Print the encrypted string
    printf("Encrypted string: %s\n", str);

    // Decrypt the encrypted string using the same key
    decrypt_string(str, key);

    // Print the decrypted string
    printf("Decrypted string: %s\n", str);

    return 0;
}