//FormAI DATASET v1.0 Category: File Encyptor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_BUFFER_SIZE 1024

/* Function to encrypt a file and save it with a new name */
void encrypt_file(char *filename, char *newFilename, char *password) {

    FILE *file1, *file2;
    char buffer[MAX_BUFFER_SIZE];
    int read_len, i;

    // Open the input file
    file1 = fopen(filename, "rb");
    if (file1 == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Open the output file
    file2 = fopen(newFilename, "wb");
    if (file2 == NULL) {
        printf("Error opening file!\n");
        fclose(file1);
        exit(1);
    }

    // Write the password as the first 10 bytes of the output file
    fwrite(password, sizeof(char), 10, file2);
    
    // Encrypt the remaining file data and write to output file
    while ((read_len = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, file1))) {
        for (i = 0; i < read_len; i++) {
            buffer[i] = buffer[i] ^ password[i % 10];
        }
        fwrite(buffer, sizeof(char), read_len, file2);
    }

    // Close both files
    fclose(file1);
    fclose(file2);
}

/* Function to decrypt an encrypted file and save it with a new name */
void decrypt_file(char *filename, char *newFilename, char *password) {

    FILE *file1, *file2;
    char buffer[MAX_BUFFER_SIZE];
    int read_len, i;

    // Open the input file
    file1 = fopen(filename, "rb");
    if (file1 == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Open the output file
    file2 = fopen(newFilename, "wb");
    if (file2 == NULL) {
        printf("Error opening file!\n");
        fclose(file1);
        exit(1);
    }

    // Read the password from the first 10 bytes of the input file
    char read_password[10];
    fread(read_password, sizeof(char), 10, file1);
    if (strcmp(read_password, password) != 0) {
        printf("Invalid password! File cannot be decrypted.\n");
        fclose(file1);
        fclose(file2);
        exit(1);
    }

    // Decrypt the remaining file data and write to output file
    while ((read_len = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, file1))) {
        for (i = 0; i < read_len; i++) {
            buffer[i] = buffer[i] ^ password[i % 10];
        }
        fwrite(buffer, sizeof(char), read_len, file2);
    }

    // Close both files
    fclose(file1);
    fclose(file2);
}

/* Main function */
int main() {

    char filename[MAX_FILE_NAME], newFilename[MAX_FILE_NAME], password[10];
    int choice;

    printf("Choose an option:\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    scanf("%d", &choice);

    printf("Enter the file name (with extension): ");
    scanf("%s", filename);

    printf("Enter the new file name (with extension): ");
    scanf("%s", newFilename);

    printf("Enter the password (maximum 10 characters): ");
    scanf("%s", password);

    switch (choice) {
        case 1:
            encrypt_file(filename, newFilename, password);
            printf("File encrypted successfully!\n");
            break;
        case 2:
            decrypt_file(filename, newFilename, password);
            printf("File decrypted successfully!\n");
            break;
        default:
            printf("Invalid choice!\n");
            exit(1);
    }

    return 0;
}