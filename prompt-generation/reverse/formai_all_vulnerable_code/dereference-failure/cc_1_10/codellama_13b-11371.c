//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: happy
// Happy File Encryptor
// Usage: ./happy_encryptor <file_to_encrypt> <encryption_key>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define the encryption function
void encrypt(uint8_t* data, uint8_t key) {
    for (int i = 0; i < strlen(data); i++) {
        data[i] = (data[i] + key) % 256;
    }
}

// Define the decryption function
void decrypt(uint8_t* data, uint8_t key) {
    for (int i = 0; i < strlen(data); i++) {
        data[i] = (data[i] - key) % 256;
    }
}

// Main function
int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: ./happy_encryptor <file_to_encrypt> <encryption_key>\n");
        return 1;
    }

    // Open the file to encrypt
    FILE* file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error: Unable to open file %s\n", argv[1]);
        return 1;
    }

    // Read the file into memory
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    uint8_t* file_data = malloc(file_size);
    fseek(file, 0, SEEK_SET);
    fread(file_data, file_size, 1, file);
    fclose(file);

    // Encrypt the file
    encrypt(file_data, atoi(argv[2]));

    // Save the encrypted file
    char* encrypted_file = "encrypted_file.txt";
    FILE* encrypted_file_ptr = fopen(encrypted_file, "wb");
    fwrite(file_data, file_size, 1, encrypted_file_ptr);
    fclose(encrypted_file_ptr);

    // Free the file data
    free(file_data);

    return 0;
}