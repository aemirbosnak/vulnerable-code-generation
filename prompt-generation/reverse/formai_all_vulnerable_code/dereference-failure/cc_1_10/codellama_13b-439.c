//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: introspective
/*
 * File Encryptor
 *
 * This program takes a file as input, encrypts it using a simple
 * substitution cipher, and then writes the encrypted file to disk.
 *
 * The key used for encryption is a randomly generated sequence
 * of ASCII characters.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random key
char* generate_key(int size) {
    char* key = malloc(size * sizeof(char));
    for (int i = 0; i < size; i++) {
        key[i] = (char) (rand() % 255);
    }
    return key;
}

// Function to encrypt a file using a substitution cipher
void encrypt_file(FILE* input, FILE* output, char* key, int size) {
    int c;
    while ((c = fgetc(input)) != EOF) {
        int index = c % size;
        c = key[index];
        fputc(c, output);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    // Generate a random key
    int key_size = 10;
    char* key = generate_key(key_size);

    // Open the input and output files
    FILE* input = fopen(argv[1], "rb");
    FILE* output = fopen(argv[2], "wb");

    // Encrypt the file
    encrypt_file(input, output, key, key_size);

    // Close the input and output files
    fclose(input);
    fclose(output);

    // Free the key
    free(key);

    return 0;
}