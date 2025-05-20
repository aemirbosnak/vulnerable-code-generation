//FormAI DATASET v1.0 Category: File Encyptor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16 // size of encryption key
#define BUFFER_SIZE 1024 // size of buffer used to read/write file data

// the encryption key, you can replace it with your own key
static const unsigned char key[KEY_SIZE] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,0x10};

// XOR function used for encryption and decryption
void xor_cipher(unsigned char *data, size_t data_size, const unsigned char *key, size_t key_size) {
    for (size_t i = 0; i < data_size; i++) {
        data[i] ^= key[i % key_size];
    }
}

// encrypts/decrypts the file at the given path using the given key
void encrypt_file(const char *file_path, const unsigned char *key, size_t key_size) {
    size_t read_size;
    unsigned char buffer[BUFFER_SIZE];

    // Open the input file
    FILE *file_in = fopen(file_path, "rb");
    if (!file_in) {
        printf("Failed to open input file.\n");
        return;
    }

    // Generate output file name
    char file_out_path[strlen(file_path) + 5];
    strcpy(file_out_path, file_path);
    strcat(file_out_path, ".enc");

    // Open the output file
    FILE *file_out = fopen(file_out_path, "wb");
    if (!file_out) {
        printf("Failed to open output file.\n");
        fclose(file_in);
        return;
    }

    // Read the file in blocks and write each block encrypted to the output file
    while ((read_size = fread(buffer, 1, BUFFER_SIZE, file_in)) > 0) {
        xor_cipher(buffer, read_size, key, key_size);
        fwrite(buffer, 1, read_size, file_out);
    }

    // Close files
    fclose(file_in);
    fclose(file_out);

    // Replace the original file with the encrypted one
    if (remove(file_path) != 0 || rename(file_out_path, file_path) != 0) {
        printf("Failed to replace the original file with the encrypted one.\n");
    }
}

int main(int argc, char *argv[]) {
    printf("Enter the path to the file to be encrypted: ");
    char file_path[1024];
    scanf("%s", file_path);

    encrypt_file(file_path, key, KEY_SIZE);

    printf("The file has been encrypted successfully.\n");

    return 0;
}