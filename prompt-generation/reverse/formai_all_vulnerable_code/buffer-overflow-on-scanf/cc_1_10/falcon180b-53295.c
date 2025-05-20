//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "secret_key"
#define KEY_LENGTH 9

// Function to encrypt the file
void encrypt_file(FILE *input_file, FILE *output_file) {
    char buffer[1024];
    int bytes_read, bytes_written;

    // Read the input file in chunks
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
        // Encrypt the buffer using the key
        for (int i = 0; i < bytes_read; i++) {
            char c = buffer[i];
            c ^= KEY[i % KEY_LENGTH];
            buffer[i] = c;
        }

        // Write the encrypted buffer to the output file
        bytes_written = fwrite(buffer, 1, bytes_read, output_file);
        if (bytes_written!= bytes_read) {
            printf("Error writing to output file\n");
            exit(1);
        }
    }
}

// Function to decrypt the file
void decrypt_file(FILE *input_file, FILE *output_file) {
    char buffer[1024];
    int bytes_read, bytes_written;

    // Read the input file in chunks
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
        // Decrypt the buffer using the key
        for (int i = 0; i < bytes_read; i++) {
            char c = buffer[i];
            c ^= KEY[i % KEY_LENGTH];
            buffer[i] = c;
        }

        // Write the decrypted buffer to the output file
        bytes_written = fwrite(buffer, 1, bytes_read, output_file);
        if (bytes_written!= bytes_read) {
            printf("Error writing to output file\n");
            exit(1);
        }
    }
}

// Function to prompt the user for a file name
char *prompt_file_name(char *prompt) {
    char *filename = malloc(1024);
    printf("%s", prompt);
    scanf("%s", filename);
    return filename;
}

int main() {
    FILE *input_file, *output_file;
    char *input_filename, *output_filename;

    // Prompt the user for the input file name
    input_filename = prompt_file_name("Enter input file name: ");

    // Open the input file
    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    // Prompt the user for the output file name
    output_filename = prompt_file_name("Enter output file name: ");

    // Open the output file
    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    // Prompt the user for the operation to perform
    char *operation = prompt_file_name("Enter operation (encrypt/decrypt): ");

    // Perform the operation
    if (strcmp(operation, "encrypt") == 0) {
        encrypt_file(input_file, output_file);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt_file(input_file, output_file);
    } else {
        printf("Invalid operation\n");
        exit(1);
    }

    // Close the files
    fclose(input_file);
    fclose(output_file);

    return 0;
}