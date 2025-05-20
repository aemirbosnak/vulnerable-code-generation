//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define KEY_SIZE 16

// Function to encrypt the file
void encrypt_file(FILE *file, char *key) {
    char buffer[1024];
    int buffer_size = 0;
    FILE *output_file = fopen("encrypted_file.txt", "wb");

    while ((buffer_size = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < buffer_size; i++) {
            buffer[i] ^= key[i % KEY_SIZE];
        }
        fwrite(buffer, 1, buffer_size, output_file);
    }

    fclose(file);
    fclose(output_file);
}

// Function to decrypt the file
void decrypt_file(FILE *file, char *key) {
    char buffer[1024];
    int buffer_size = 0;
    FILE *output_file = fopen("decrypted_file.txt", "wb");

    while ((buffer_size = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < buffer_size; i++) {
            buffer[i] ^= key[i % KEY_SIZE];
        }
        fwrite(buffer, 1, buffer_size, output_file);
    }

    fclose(file);
    fclose(output_file);
}

// Function to generate a random key
void generate_key(char *key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

int main() {
    char input_file[100], output_file[100], key[KEY_SIZE];
    FILE *file;

    // Get the input file name from the user
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    // Open the input file for reading
    file = fopen(input_file, "rb");
    if (file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Get the output file name from the user
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    // Generate a random key
    generate_key(key);

    // Encrypt the file
    encrypt_file(file, key);

    // Decrypt the file
    decrypt_file(output_file, key);

    printf("File encryption/decryption complete.\n");

    return 0;
}