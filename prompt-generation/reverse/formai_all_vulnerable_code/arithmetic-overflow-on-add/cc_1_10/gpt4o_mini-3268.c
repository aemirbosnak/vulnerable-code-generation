//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void encrypt(const char *input_file, const char *output_file, int shift) {
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }
    
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Failed to open output file");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    int c;
    while ((c = fgetc(input)) != EOF) {
        // Encrypt each character using a mathematical transformation
        // The transformation is: (c + shift) % 256
        int encrypted_char = (c + shift) % 256;
        fputc(encrypted_char, output);
    }

    fclose(input);
    fclose(output);
}

void decrypt(const char *input_file, const char *output_file, int shift) {
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Failed to open output file");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    int c;
    while ((c = fgetc(input)) != EOF) {
        // Decrypt each character using the reverse transformation
        // The reverse transformation is: (c - shift + 256) % 256
        int decrypted_char = (c - shift + 256) % 256;
        fputc(decrypted_char, output);
    }

    fclose(input);
    fclose(output);
}

int main() {
    const char *input_file = "example.txt";
    const char *encrypted_file = "encrypted.txt";
    const char *decrypted_file = "decrypted.txt";
    
    int shift = 5; // You can modify this value for different encryption

    printf("Encrypting %s to %s with a shift of %d...\n", input_file, encrypted_file, shift);
    encrypt(input_file, encrypted_file, shift);

    printf("Decrypting %s to %s with a shift of %d...\n", encrypted_file, decrypted_file, shift);
    decrypt(encrypted_file, decrypted_file, shift);
    
    printf("Encryption and decryption complete!\n");
    return 0;
}