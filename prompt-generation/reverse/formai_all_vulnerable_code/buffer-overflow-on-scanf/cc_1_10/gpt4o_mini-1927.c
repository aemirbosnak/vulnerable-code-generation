//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

// Function to encrypt or decrypt the contents of the file
void xor_encrypt_decrypt(const char *input_file, const char *output_file, const char *key) {
    FILE *infile;
    FILE *outfile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    size_t key_length = strlen(key);
    size_t i, j;

    // Open the input file for reading
    infile = fopen(input_file, "rb");
    if (infile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open the output file for writing
    outfile = fopen(output_file, "wb");
    if (outfile == NULL) {
        perror("Error creating output file");
        fclose(infile);
        exit(EXIT_FAILURE);
    }

    // Read from the input file, encrypt/decrypt using XOR, and write to the output file
    while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, infile)) > 0) {
        for (i = 0, j = 0; i < bytesRead; i++, j++) {
            if (j >= key_length) {
                j = 0; // Loop the key
            }
            buffer[i] ^= key[j]; // XOR operation
        }
        fwrite(buffer, sizeof(char), bytesRead, outfile);
    }

    // Close the files
    fclose(infile);
    fclose(outfile);
}

// Function to display the program's menu
void display_menu() {
    printf("File Encryptor/Decryptor\n");
    printf("===========================\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("===========================\n");
}

int main() {
    char input_file[100];
    char output_file[100];
    char key[50];
    int option;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &option);
        getchar(); // To consume the newline character after the number input

        switch (option) {
            case 1:
                printf("Enter input file name to encrypt: ");
                fgets(input_file, sizeof(input_file), stdin);
                input_file[strcspn(input_file, "\n")] = 0; // Remove newline character

                printf("Enter output file name for encrypted data: ");
                fgets(output_file, sizeof(output_file), stdin);
                output_file[strcspn(output_file, "\n")] = 0; // Remove newline character

                printf("Enter encryption key: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0; // Remove newline character

                xor_encrypt_decrypt(input_file, output_file, key);
                printf("File encrypted successfully!\n");
                break;

            case 2:
                printf("Enter input file name to decrypt: ");
                fgets(input_file, sizeof(input_file), stdin);
                input_file[strcspn(input_file, "\n")] = 0; // Remove newline character

                printf("Enter output file name for decrypted data: ");
                fgets(output_file, sizeof(output_file), stdin);
                output_file[strcspn(output_file, "\n")] = 0; // Remove newline character

                printf("Enter decryption key: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = 0; // Remove newline character

                xor_encrypt_decrypt(input_file, output_file, key);
                printf("File decrypted successfully!\n");
                break;

            case 3:
                printf("Exiting the program.\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}