#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Unsafely large buffer for input and output data
#define BUFFER_SIZE 100000

typedef uint8_t byte;

// Encrypt function with C-style buffer overflow vulnerability
void encrypt(byte* plaintext, byte* ciphertext, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        ciphertext[i] = plaintext[i] * 2 + 3; // Simulate encryption operation leading to overflow
    }
    // Overwrite stack frame data after the end of ciphertext buffer
    ciphertext[length] = 'S'; // Set a sentinel value for demonstration
}

// Decrypt function with buffer overflow vulnerability
void decrypt(byte* ciphertext, byte* plaintext, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        plaintext[i] = ciphertext[i] / 2 - 3; // Simulate decryption operation leading to overflow
    }
}

// Usage example
int main() {
    const char plaintext[] = "SECRET";
    const size_t plaintext_len = sizeof(plaintext) - 1;

    byte ciphertext[BUFFER_SIZE];
    byte plaintext_out[BUFFER_SIZE];

    encrypt((byte*)plaintext, ciphertext, plaintext_len);
    decrypt(ciphertext, plaintext_out, plaintext_len);

    printf("Decrypted plaintext: %s\n", plaintext_out);

    return 0;
}
