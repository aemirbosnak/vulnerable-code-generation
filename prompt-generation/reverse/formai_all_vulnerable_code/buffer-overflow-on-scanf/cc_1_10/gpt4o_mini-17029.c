//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define KEY "my_secret_key"

// Function to encrypt the data using XOR operation
void encrypt_decrypt(FILE *input, FILE *output) {
    char ch;
    size_t key_len = strlen(KEY);
    size_t i = 0;

    while ((ch = fgetc(input)) != EOF) {
        // XOR the character with the corresponding character from the key
        fputc(ch ^ KEY[i % key_len], output);
        i++;
    }
}

// Function to display the menu
void display_menu() {
    printf("File Encryptor/Decryptor\n");
    printf("-------------------------\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

// Function to handle file encryption/decryption prompt
void handle_file(const char *mode) {
    char input_file[BUFFER_SIZE];
    char output_file[BUFFER_SIZE];

    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        return;
    }

    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        fclose(input);
        return;
    }

    encrypt_decrypt(input, output);

    fclose(input);
    fclose(output);

    printf("%s operation completed: %s -> %s\n", 
           strcmp(mode, "encrypt") == 0 ? "Encryption" : "Decryption", input_file, output_file);
}

// Main function
int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                handle_file("encrypt");
                break;
            case 2:
                handle_file("decrypt");
                break;
            case 3:
                printf("Exiting the program... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}