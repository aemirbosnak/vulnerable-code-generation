//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 1024

// Key for the cypher
unsigned char key[] = {0x55, 0xAA, 0x33, 0xCC, 0x77, 0xBB, 0x11, 0xEE};
int key_len = sizeof(key);

// Function to encrypt data
void encrypt(unsigned char *data, int data_len) {
    for (int i = 0; i < data_len; i++) {
        data[i] ^= key[i % key_len];
    }
}

// Function to decrypt data
void decrypt(unsigned char *data, int data_len) {
    for (int i = 0; i < data_len; i++) {
        data[i] ^= key[i % key_len];
    }
}

int main() {
    // Get the file name from the user
    char file_name[256];
    printf("Enter the file name: ");
    scanf("%s", file_name);

    // Open the input file
    FILE *input_file = fopen(file_name, "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Get the file size
    fseek(input_file, 0, SEEK_END);
    int file_size = ftell(input_file);
    rewind(input_file);

    // Allocate a buffer to hold the file data
    unsigned char *data = malloc(file_size);
    if (data == NULL) {
        perror("Error allocating memory");
        fclose(input_file);
        return 1;
    }

    // Read the file data into the buffer
    fread(data, 1, file_size, input_file);
    fclose(input_file);

    // Encrypt the file data
    encrypt(data, file_size);

    // Open the output file
    FILE *output_file = fopen("encrypted.bin", "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        free(data);
        return 1;
    }

    // Write the encrypted data to the output file
    fwrite(data, 1, file_size, output_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");

    // Decrypt the file data
    decrypt(data, file_size);

    // Open the decrypted output file
    output_file = fopen("decrypted.bin", "wb");
    if (output_file == NULL) {
        perror("Error opening decrypted output file");
        free(data);
        return 1;
    }

    // Write the decrypted data to the output file
    fwrite(data, 1, file_size, output_file);
    fclose(output_file);

    printf("File decrypted successfully.\n");

    // Free the allocated memory
    free(data);

    return 0;
}