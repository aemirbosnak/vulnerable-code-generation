//FormAI DATASET v1.0 Category: Image Steganography ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BYTE_SIZE 256
#define MAX_FILE_NAME_SIZE 100

// Function to read the contents of a file into a buffer.
int read_file(unsigned char* buffer, char* file_name) {
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error: Failed to open file!\n");
        return -1;
    }

    fseek(file, 0L, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    int i = 0;
    while (i != file_size) {
        int read = fread(buffer+i, 1, 1, file);
        if (read < 1) {
            printf("Error: Failed to read file!\n");
            break;
        }
        i++;
    }
    fclose(file);

    return i;
}

// Function to write buffer contents to a file.
void write_file(unsigned char* buffer, int buffer_size, char* file_name) {
    FILE* file = fopen(file_name, "wb");

    size_t write_count = fwrite(buffer, 1, buffer_size, file);
    if (write_count != buffer_size) {
        printf("Error: Failed to write to file!\n");
    }
    fclose(file);
}

// Function to hide 'secret' data within the 'source' data using LSB steganography technique.
void hide_data_in_image(unsigned char* source, int source_size, unsigned char* secret, int secret_size) {
    if (source_size < secret_size*8 + 32) {
        printf("Error: Image size is too small to incorporate the secret data!\n");
        return;
    }

    // Embed secret file size in first 32 bytes.
    for (int i = 0; i < 4; i++) {
        source[i] = (secret_size >> (i*8)) & 0xFF;
    }

    int secret_bit = 0;
    for (int i = 32; i < source_size && secret_bit < secret_size*8; i++) {
        source[i] &= 0xFE;
        source[i] |= ((secret[secret_bit/8] >> (secret_bit % 8)) & 0x01);
        secret_bit++;
    }
}

// Function to extract 'secret' data from 'source' data using LSB steganography technique.
bool extract_data_from_image(unsigned char* source, int source_size, unsigned char* secret, int secret_size) {
    int extracted_size = 0;
    for (int i = 0; i < 4; i++) {
        extracted_size |= (source[i] & 0xFF) << (i*8);
    }

    if (extracted_size != secret_size) {
        printf("Error: Failed to extract the correct secret data size!\n");
        return false;
    }

    int secret_bit = 0;
    for (int i = 32; i < source_size && secret_bit < secret_size*8; i++) {
        secret[secret_bit/8] &= ~(1 << (secret_bit % 8));
        secret[secret_bit/8] |= (source[i] & 0x01) << (secret_bit % 8);
        secret_bit++;
    }

    if (secret_bit != secret_size*8) {
        printf("Error: Failed to extract the correct secret data!\n");
        return false;
    }

    return true;
}

int main() {
    char source_file[MAX_FILE_NAME_SIZE] = "source.bmp";
    char secret_file[MAX_FILE_NAME_SIZE] = "secret.txt";
    unsigned char source[MAX_BYTE_SIZE];
    unsigned char secret[MAX_BYTE_SIZE];
    unsigned char extracted_secret[MAX_BYTE_SIZE];

    int source_size = read_file(source, source_file);
    int secret_size = read_file(secret, secret_file);

    hide_data_in_image(source, source_size, secret, secret_size);

    write_file(source, source_size, "encoded.bmp");

    int encoded_size = read_file(source, "encoded.bmp");
    bool success = extract_data_from_image(source, encoded_size, extracted_secret, secret_size);

    if (success) {
        write_file(extracted_secret, secret_size, "decoded.txt");
    }

    return 0;
}