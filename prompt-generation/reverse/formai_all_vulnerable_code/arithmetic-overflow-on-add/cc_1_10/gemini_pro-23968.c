//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ENCRYPT 1
#define DECRYPT 0

// Mathematically defined encryption and decryption functions
unsigned char encrypt(unsigned char c, int k) {
    return (c + k) % 256;
}

unsigned char decrypt(unsigned char c, int k) {
    return (c - k + 256) % 256;
}

int main() {
    // Get input from user
    char *filename = malloc(sizeof(char) * 100);
    printf("Enter the file to be encrypted: ");
    scanf("%s", filename);

    int key;
    printf("Enter the encryption key (0-255): ");
    scanf("%d", &key);

    int mode;
    printf("Encrypt (1) or decrypt (0)? ");
    scanf("%d", &mode);

    // Open the file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Determine the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Create a buffer to hold the file contents
    unsigned char *buffer = malloc(sizeof(unsigned char) * file_size);
    if (buffer == NULL) {
        printf("Error allocating memory.\n");
        fclose(file);
        return 1;
    }

    // Read the file contents into the buffer
    fread(buffer, sizeof(unsigned char), file_size, file);
    fclose(file);

    // Encrypt or decrypt the file contents
    int i;
    for (i = 0; i < file_size; i++) {
        if (mode == ENCRYPT) {
            buffer[i] = encrypt(buffer[i], key);
        } else if (mode == DECRYPT) {
            buffer[i] = decrypt(buffer[i], key);
        }
    }

    // Open the output file
    char *output_filename = malloc(sizeof(char) * 100);
    sprintf(output_filename, "%s.%s", filename, mode == ENCRYPT ? "enc" : "dec");
    file = fopen(output_filename, "wb");
    if (file == NULL) {
        printf("Error opening output file.\n");
        free(buffer);
        return 1;
    }

    // Write the encrypted or decrypted file contents to the output file
    fwrite(buffer, sizeof(unsigned char), file_size, file);
    fclose(file);

    // Free the allocated memory
    free(buffer);
    free(filename);
    free(output_filename);

    printf("File %s successfully encrypted/decrypted.\n", mode == ENCRYPT ? "encrypted" : "decrypted");
    return 0;
}