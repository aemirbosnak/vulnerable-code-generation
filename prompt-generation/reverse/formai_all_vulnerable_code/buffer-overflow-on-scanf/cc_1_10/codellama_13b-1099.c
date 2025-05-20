//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16
#define ENCRYPT 1
#define DECRYPT 0

// Function to generate a key
void generate_key(char *key, int size) {
    for (int i = 0; i < size; i++) {
        key[i] = rand() % 256;
    }
}

// Function to encrypt/decrypt a block of data
void crypt(char *data, char *key, int mode) {
    // Create a new block to store the encrypted/decrypted data
    char block[BLOCK_SIZE];

    // Iterate over each byte in the block
    for (int i = 0; i < BLOCK_SIZE; i++) {
        // Apply the XOR operation to the byte
        block[i] = data[i] ^ key[i];
    }

    // Copy the encrypted/decrypted data back to the original block
    memcpy(data, block, BLOCK_SIZE);
}

int main() {
    // Generate a key
    char key[KEY_SIZE];
    generate_key(key, KEY_SIZE);

    // Prompt the user for the file to encrypt/decrypt
    char filename[256];
    printf("Enter the file to encrypt/decrypt: ");
    scanf("%s", filename);

    // Open the file for reading
    FILE *file = fopen(filename, "r");

    // Create a new file to store the encrypted/decrypted data
    char new_filename[256];
    sprintf(new_filename, "%s.enc", filename);
    FILE *new_file = fopen(new_filename, "w");

    // Read the data from the original file
    char data[BLOCK_SIZE];
    while (fread(data, 1, BLOCK_SIZE, file) == BLOCK_SIZE) {
        // Encrypt/decrypt the data
        crypt(data, key, ENCRYPT);

        // Write the encrypted/decrypted data to the new file
        fwrite(data, 1, BLOCK_SIZE, new_file);
    }

    // Close the files
    fclose(file);
    fclose(new_file);

    return 0;
}