//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: puzzling
// Example of a unique C File Encryptor program in a puzzling style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to encrypt a file
void encrypt_file(char *file_name, int key) {
    // Open the file in binary mode for reading and writing
    FILE *fp = fopen(file_name, "r+b");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    // Get the size of the file
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);

    // Go back to the beginning of the file
    rewind(fp);

    // Encrypt the file contents
    char *file_contents = malloc(file_size);
    fread(file_contents, file_size, 1, fp);
    for (int i = 0; i < file_size; i++) {
        file_contents[i] = (char)((int)file_contents[i] + key);
    }

    // Write the encrypted file contents back to the file
    fseek(fp, 0, SEEK_SET);
    fwrite(file_contents, file_size, 1, fp);

    // Clean up memory
    free(file_contents);

    // Close the file
    fclose(fp);
}

// Function to decrypt a file
void decrypt_file(char *file_name, int key) {
    // Open the file in binary mode for reading and writing
    FILE *fp = fopen(file_name, "r+b");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    // Get the size of the file
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);

    // Go back to the beginning of the file
    rewind(fp);

    // Decrypt the file contents
    char *file_contents = malloc(file_size);
    fread(file_contents, file_size, 1, fp);
    for (int i = 0; i < file_size; i++) {
        file_contents[i] = (char)((int)file_contents[i] - key);
    }

    // Write the decrypted file contents back to the file
    fseek(fp, 0, SEEK_SET);
    fwrite(file_contents, file_size, 1, fp);

    // Clean up memory
    free(file_contents);

    // Close the file
    fclose(fp);
}

int main() {
    // Encrypt a file
    encrypt_file("example.txt", 5);

    // Decrypt the file
    decrypt_file("example.txt", 5);

    return 0;
}