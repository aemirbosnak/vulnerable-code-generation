//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our secret encryption key
const char* key = "H0wD@r3Y0u!";

// Function to encrypt a file
void encrypt(char* filename) {
    // Open the file in read mode
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // Determine the file size
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    // Create a buffer to store the encrypted data
    unsigned char* buffer = malloc(file_size);
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return;
    }

    // Read the file into the buffer
    fread(buffer, 1, file_size, fp);
    fclose(fp);

    // Encrypt the buffer using the XOR operator
    for (long i = 0; i < file_size; i++) {
        buffer[i] ^= key[i % strlen(key)];
    }

    // Overwrite the original file with the encrypted data
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        free(buffer);
        return;
    }
    fwrite(buffer, 1, file_size, fp);
    fclose(fp);

    // Free the allocated memory
    free(buffer);
}

// Function to decrypt a file
void decrypt(char* filename) {
    // Open the file in read mode
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // Determine the file size
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    // Create a buffer to store the decrypted data
    unsigned char* buffer = malloc(file_size);
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return;
    }

    // Read the file into the buffer
    fread(buffer, 1, file_size, fp);
    fclose(fp);

    // Decrypt the buffer using the XOR operator
    for (long i = 0; i < file_size; i++) {
        buffer[i] ^= key[i % strlen(key)];
    }

    // Overwrite the original file with the decrypted data
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        free(buffer);
        return;
    }
    fwrite(buffer, 1, file_size, fp);
    fclose(fp);

    // Free the allocated memory
    free(buffer);
}

int main() {
    int choice;
    char filename[100];

    printf("Welcome to the File Encryption Program!\n\n");
    printf("Please select an option:\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the filename to encrypt: ");
            scanf("%s", filename);
            encrypt(filename);
            printf("File encrypted successfully!\n");
            break;
        case 2:
            printf("Enter the filename to decrypt: ");
            scanf("%s", filename);
            decrypt(filename);
            printf("File decrypted successfully!\n");
            break;
        case 3:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
    }

    return 0;
}