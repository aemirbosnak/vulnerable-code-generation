//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "MY_SECRET_KEY"

// Function to encrypt a file
void encrypt_file(char *filename) {
    // Open the file in read mode
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Allocate memory for the encrypted file
    char *encrypted_file = malloc(file_size);
    if (!encrypted_file) {
        printf("Error allocating memory for encrypted file\n");
        fclose(file);
        return;
    }

    // Read the file into a buffer
    char *buffer = malloc(file_size);
    if (!buffer) {
        printf("Error allocating memory for buffer\n");
        fclose(file);
        free(encrypted_file);
        return;
    }
    fread(buffer, 1, file_size, file);
    fclose(file);

    // Encrypt the buffer
    for (int i = 0; i < file_size; i++) {
        buffer[i] ^= KEY[i % strlen(KEY)];
    }

    // Write the encrypted buffer to the encrypted file
    FILE *encrypted_file_ptr = fopen("encrypted.txt", "wb");
    if (!encrypted_file_ptr) {
        printf("Error opening encrypted file\n");
        free(buffer);
        free(encrypted_file);
        return;
    }
    fwrite(buffer, 1, file_size, encrypted_file_ptr);
    fclose(encrypted_file_ptr);

    // Free the allocated memory
    free(buffer);
    free(encrypted_file);

    // Print a success message
    printf("File %s encrypted successfully\n", filename);
}

// Function to decrypt a file
void decrypt_file(char *filename) {
    // Open the file in read mode
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Allocate memory for the decrypted file
    char *decrypted_file = malloc(file_size);
    if (!decrypted_file) {
        printf("Error allocating memory for decrypted file\n");
        fclose(file);
        return;
    }

    // Read the file into a buffer
    char *buffer = malloc(file_size);
    if (!buffer) {
        printf("Error allocating memory for buffer\n");
        fclose(file);
        free(decrypted_file);
        return;
    }
    fread(buffer, 1, file_size, file);
    fclose(file);

    // Decrypt the buffer
    for (int i = 0; i < file_size; i++) {
        buffer[i] ^= KEY[i % strlen(KEY)];
    }

    // Write the decrypted buffer to the decrypted file
    FILE *decrypted_file_ptr = fopen("decrypted.txt", "wb");
    if (!decrypted_file_ptr) {
        printf("Error opening decrypted file\n");
        free(buffer);
        free(decrypted_file);
        return;
    }
    fwrite(buffer, 1, file_size, decrypted_file_ptr);
    fclose(decrypted_file_ptr);

    // Free the allocated memory
    free(buffer);
    free(decrypted_file);

    // Print a success message
    printf("File %s decrypted successfully\n", filename);
}

int main() {
    // Get the file name from the user
    char filename[256];
    printf("Enter the file name to encrypt: ");
    scanf("%s", filename);

    // Encrypt the file
    encrypt_file(filename);

    // Decrypt the file
    decrypt_file("encrypted.txt");

    return 0;
}