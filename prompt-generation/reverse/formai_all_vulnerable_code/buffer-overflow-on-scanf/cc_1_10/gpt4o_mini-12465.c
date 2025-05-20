//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_menu() {
    printf("\n=== Simple C File Encryptor ===\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

void encrypt_decrypt(FILE *input, FILE *output, char key) {
    char ch;
    while ((ch = fgetc(input)) != EOF) {
        // XOR operation for encryption and decryption
        fputc(ch ^ key, output);
    }
}

int main() {
    char input_filename[100], output_filename[100];
    char key;
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the name of the file to encrypt: ");
                scanf("%s", input_filename);
                printf("Enter the name of the output encrypted file: ");
                scanf("%s", output_filename);
                printf("Enter a single character key for encryption: ");
                scanf(" %c", &key);

                FILE *input_file = fopen(input_filename, "rb");
                if (!input_file) {
                    perror("Error opening input file");
                    continue;
                }

                FILE *output_file = fopen(output_filename, "wb");
                if (!output_file) {
                    perror("Error opening output file");
                    fclose(input_file);
                    continue;
                }

                encrypt_decrypt(input_file, output_file, key);
                printf("File encrypted successfully.\n");

                fclose(input_file);
                fclose(output_file);
                break;

            case 2:
                printf("Enter the name of the file to decrypt: ");
                scanf("%s", input_filename);
                printf("Enter the name of the output decrypted file: ");
                scanf("%s", output_filename);
                printf("Enter the single character key used for encryption: ");
                scanf(" %c", &key);

                input_file = fopen(input_filename, "rb");
                if (!input_file) {
                    perror("Error opening input file");
                    continue;
                }

                output_file = fopen(output_filename, "wb");
                if (!output_file) {
                    perror("Error opening output file");
                    fclose(input_file);
                    continue;
                }

                encrypt_decrypt(input_file, output_file, key);
                printf("File decrypted successfully.\n");

                fclose(input_file);
                fclose(output_file);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option. Please select again.\n");
                break;
        }
    }
    
    return 0; // Just to satisfy the compiler; the loop never exits naturally.
}