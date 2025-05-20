//FormAI DATASET v1.0 Category: File Encyptor ; Style: multivariable
#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_KEY_LENGTH 256
#define BUFFER_SIZE 1024

void encrypt(char *input_filename, char *output_filename, char *key) {
    // Open input and output files
    FILE *input_file = fopen(input_filename, "rb");
    FILE *output_file = fopen(output_filename, "wb");

    // Validate file pointers
    if (input_file == NULL || output_file == NULL) {
        printf("Failed to open files for encryption.\n");
        return;
    }

    // Write key to output file
    int key_length = strlen(key);
    fwrite(&key_length, sizeof(int), 1, output_file);
    fwrite(key, sizeof(char), key_length, output_file);

    // Encrypt the file
    char buffer[BUFFER_SIZE];
    int key_index = 0;
    int bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, input_file)) != 0) {
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[key_index++];
            if (key_index == key_length) {
                key_index = 0;
            }
        }
        fwrite(buffer, sizeof(char), bytes_read, output_file);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("Encryption complete.\n");
}

void decrypt(char *input_filename, char *output_filename) {
    // Open input and output files
    FILE *input_file = fopen(input_filename, "rb");
    FILE *output_file = fopen(output_filename, "wb");

    // Validate file pointers
    if (input_file == NULL || output_file == NULL) {
        printf("Failed to open files for decryption.\n");
        return;
    }

    // Read key from input file
    int key_length;
    fread(&key_length, sizeof(int), 1, input_file);
    char key[key_length + 1];
    fread(key, sizeof(char), key_length, input_file);
    key[key_length] = '\0';

    // Decrypt the file
    char buffer[BUFFER_SIZE];
    int key_index = 0;
    int bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, input_file)) != 0) {
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[key_index++];
            if (key_index == key_length) {
                key_index = 0;
            }
        }
        fwrite(buffer, sizeof(char), bytes_read, output_file);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("Decryption complete.\n");
}

int main() {
    char input_filename[MAX_FILENAME_LENGTH];
    char output_filename[MAX_FILENAME_LENGTH];
    char key[MAX_KEY_LENGTH];
    int mode;

    // Get user input
    printf("Enter the input filename: ");
    scanf("%s", input_filename);

    printf("Enter the output filename: ");
    scanf("%s", output_filename);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    printf("Enter the mode (0 for encryption, 1 for decryption): ");
    scanf("%d", &mode);

    // Encrypt or decrypt
    if (mode == 0) {
        encrypt(input_filename, output_filename, key);
    } else if (mode == 1) {
        decrypt(input_filename, output_filename);
    } else {
        printf("Invalid mode.\n");
    }

    return 0;
}