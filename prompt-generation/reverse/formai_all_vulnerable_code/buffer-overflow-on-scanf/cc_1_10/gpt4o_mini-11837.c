//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void print_menu() {
    printf("File Encryptor/Decryptor\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

void xor_encrypt_decrypt(FILE *input_file, FILE *output_file, char key) {
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, input_file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key; // XOR operation
        }
        fwrite(buffer, sizeof(char), bytes_read, output_file);
    }
}

int main() {
    int option;
    char key;
    char input_filename[256];
    char output_filename[256];
    
    while (1) {
        print_menu();
        scanf("%d", &option);

        switch (option) {
            case 1: // Encrypt a file
                printf("Enter input file name to encrypt: ");
                scanf("%s", input_filename);
                printf("Enter output file name for encrypted data: ");
                scanf("%s", output_filename);
                printf("Enter encryption key (single character): ");
                scanf(" %c", &key);
                
                {
                    FILE *input_file = fopen(input_filename, "rb");
                    if (input_file == NULL) {
                        perror("Error opening input file");
                        break;
                    }
                    
                    FILE *output_file = fopen(output_filename, "wb");
                    if (output_file == NULL) {
                        perror("Error opening output file");
                        fclose(input_file);
                        break;
                    }

                    xor_encrypt_decrypt(input_file, output_file, key);
                    printf("File encrypted successfully.\n");

                    fclose(input_file);
                    fclose(output_file);
                }
                break;

            case 2: // Decrypt a file
                printf("Enter input file name to decrypt: ");
                scanf("%s", input_filename);
                printf("Enter output file name for decrypted data: ");
                scanf("%s", output_filename);
                printf("Enter decryption key (same as the one used to encrypt): ");
                scanf(" %c", &key);
                
                {
                    FILE *input_file = fopen(input_filename, "rb");
                    if (input_file == NULL) {
                        perror("Error opening input file");
                        break;
                    }

                    FILE *output_file = fopen(output_filename, "wb");
                    if (output_file == NULL) {
                        perror("Error opening output file");
                        fclose(input_file);
                        break;
                    }

                    xor_encrypt_decrypt(input_file, output_file, key);
                    printf("File decrypted successfully.\n");

                    fclose(input_file);
                    fclose(output_file);
                }
                break;

            case 3: // Exit
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}