//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to handle file opening with error checking
FILE* open_file(const char *filename, const char *mode) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    return file;
}

// Function to encrypt the content of the file
void encrypt_file(const char *input_filename, const char *output_filename, int key) {
    FILE *input_file = open_file(input_filename, "rb");
    FILE *output_file = open_file(output_filename, "wb");

    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    // Read the input file in chunks and encrypt
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key; // Simple XOR encryption
        }
        fwrite(buffer, 1, bytes_read, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

// Function to decrypt the content of the file
void decrypt_file(const char *input_filename, const char *output_filename, int key) {
    // Decryption is the same as encryption in XOR
    encrypt_file(input_filename, output_filename, key);
}

// Function to display menu options
void display_menu() {
    printf("File Encryptor\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

// Main function
int main() {
    int choice, key;
    char input_filename[256];
    char output_filename[256];

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the file to encrypt: ");
                scanf("%s", input_filename);
                printf("Enter the name of the output file: ");
                scanf("%s", output_filename);
                printf("Enter the encryption key (integer): ");
                scanf("%d", &key);
                encrypt_file(input_filename, output_filename, key);
                printf("File encrypted successfully!\n");
                break;

            case 2:
                printf("Enter the name of the file to decrypt: ");
                scanf("%s", input_filename);
                printf("Enter the name of the output file: ");
                scanf("%s", output_filename);
                printf("Enter the decryption key (integer): ");
                scanf("%d", &key);
                decrypt_file(input_filename, output_filename, key);
                printf("File decrypted successfully!\n");
                break;

            case 3:
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}