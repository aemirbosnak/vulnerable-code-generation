//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "MySecretKey"
#define BLOCK_SIZE 16

// Function to encrypt a block of data using the XOR cipher
void encrypt_block(char* block, int size) {
    int i;
    for(i = 0; i < size; i++) {
        block[i] ^= KEY[i % strlen(KEY)];
    }
}

// Function to decrypt a block of data using the XOR cipher
void decrypt_block(char* block, int size) {
    int i;
    for(i = 0; i < size; i++) {
        block[i] ^= KEY[i % strlen(KEY)];
    }
}

int main() {
    FILE* input_file;
    FILE* output_file;
    char input_filename[100];
    char output_filename[100];
    char buffer[BLOCK_SIZE];
    int bytes_read, bytes_written;

    // Get input and output filenames from user
    printf("Enter input filename: ");
    scanf("%s", input_filename);
    printf("Enter output filename: ");
    scanf("%s", output_filename);

    // Open input and output files
    input_file = fopen(input_filename, "rb");
    output_file = fopen(output_filename, "wb");
    if(input_file == NULL || output_file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    // Read input file in blocks and encrypt each block
    while((bytes_read = fread(buffer, sizeof(char), BLOCK_SIZE, input_file)) > 0) {
        encrypt_block(buffer, bytes_read);
        fwrite(buffer, sizeof(char), bytes_read, output_file);
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully!\n");
    return 0;
}