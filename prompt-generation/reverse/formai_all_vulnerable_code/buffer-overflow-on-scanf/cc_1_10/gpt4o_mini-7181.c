//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHIFT 4
#define BUFFER_SIZE 1024

// Function to encrypt a single character
char encrypt_char(char c) {
    // Simple Caesar Cipher shifting
    return c + SHIFT;
}

// Function to decrypt a single character
char decrypt_char(char c) {
    return c - SHIFT;
}

// Function to encrypt a file
void encrypt_file(const char *input_file, const char *output_file) {
    FILE *fin = fopen(input_file, "r");
    FILE *fout = fopen(output_file, "w");
    if (fin == NULL || fout == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, fin) != NULL) {
        for (size_t i = 0; i < strlen(buffer); i++) {
            buffer[i] = encrypt_char(buffer[i]);
        }
        fputs(buffer, fout);
    }

    fclose(fin);
    fclose(fout);
}

// Function to decrypt a file
void decrypt_file(const char *input_file, const char *output_file) {
    FILE *fin = fopen(input_file, "r");
    FILE *fout = fopen(output_file, "w");
    if (fin == NULL || fout == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, fin) != NULL) {
        for (size_t i = 0; i < strlen(buffer); i++) {
            buffer[i] = decrypt_char(buffer[i]);
        }
        fputs(buffer, fout);
    }

    fclose(fin);
    fclose(fout);
}

// Function to display the menu
void display_menu() {
    printf("**************************************************\n");
    printf("*                File Encryptor                  *\n");
    printf("**************************************************\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("**************************************************\n");
}

// Main function
int main() {
    while (1) {
        display_menu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        if (choice == 1) {
            char input_file[256];
            char output_file[256];
            printf("Enter the name of the file to encrypt: ");
            fgets(input_file, sizeof(input_file), stdin);
            input_file[strcspn(input_file, "\n")] = '\0'; // remove newline

            printf("Enter the name of the output file: ");
            fgets(output_file, sizeof(output_file), stdin);
            output_file[strcspn(output_file, "\n")] = '\0'; // remove newline

            encrypt_file(input_file, output_file);
            printf("File encrypted successfully!\n");
        } else if (choice == 2) {
            char input_file[256];
            char output_file[256];
            printf("Enter the name of the file to decrypt: ");
            fgets(input_file, sizeof(input_file), stdin);
            input_file[strcspn(input_file, "\n")] = '\0'; // remove newline

            printf("Enter the name of the output file: ");
            fgets(output_file, sizeof(output_file), stdin);
            output_file[strcspn(output_file, "\n")] = '\0'; // remove newline

            decrypt_file(input_file, output_file);
            printf("File decrypted successfully!\n");
        } else if (choice == 3) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}