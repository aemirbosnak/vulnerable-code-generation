//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to perform XOR encryption/decryption
void xor_encrypt_decrypt(FILE *input, FILE *output, char *key, size_t key_len) {
    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;
    size_t key_index = 0;
    
    // Read from input file and write to output file
    while ((bytesRead = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, input)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key[key_index]; // XOR with the key
            key_index = (key_index + 1) % key_len; // Cycle through key
        }
        fwrite(buffer, sizeof(unsigned char), bytesRead, output);
    }
}

// Function to get user input for the key
void get_key(char *key, size_t max_length) {
    printf("Enter encryption key (max %zu characters): ", max_length - 1);
    fgets(key, max_length, stdin);
    key[strcspn(key, "\n")] = 0; // Strip newline character
}

// Main function to process file encryption/decryption
int main() {
    char key[100];
    char input_filename[256], output_filename[256];
    int choice;
    
    printf("Welcome to the Mind-Bending File Encryptor!\n");
    printf("Choose an option:\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    getchar(); // consume newline after choice
    
    // Get the encryption key
    get_key(key, sizeof(key));
    size_t key_length = strlen(key);
    
    if (key_length == 0) {
        fprintf(stderr, "Error: Key cannot be empty!\n");
        return EXIT_FAILURE;
    }

    // Get the input and output files from the user
    printf("Enter input filename: ");
    fgets(input_filename, sizeof(input_filename), stdin);
    input_filename[strcspn(input_filename, "\n")] = 0; // Strip newline character

    printf("Enter output filename: ");
    fgets(output_filename, sizeof(output_filename), stdin);
    output_filename[strcspn(output_filename, "\n")] = 0; // Strip newline character
    
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        fprintf(stderr, "Error: Cannot open input file '%s'\n", input_filename);
        return EXIT_FAILURE;
    }
    
    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        fclose(input_file);
        fprintf(stderr, "Error: Cannot open output file '%s'\n", output_filename);
        return EXIT_FAILURE;
    }

    // Encrypt or Decrypt based on user's choice
    if (choice == 1) {
        printf("Encrypting file...\n");
        xor_encrypt_decrypt(input_file, output_file, key, key_length);
        printf("File encrypted successfully!\n");
    } else if (choice == 2) {
        printf("Decrypting file...\n");
        xor_encrypt_decrypt(input_file, output_file, key, key_length);
        printf("File decrypted successfully!\n");
    } else {
        fprintf(stderr, "Error: Invalid choice!\n");
    }

    // Clean up and close files
    fclose(input_file);
    fclose(output_file);
    
    return EXIT_SUCCESS;
}