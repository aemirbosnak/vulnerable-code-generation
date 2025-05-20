//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHIFT 3 // Number of positions to shift for encryption

// Function to encrypt a single character
char encrypt_char(char c) {
    if (c >= 'a' && c <= 'z') {
        return (c - 'a' + SHIFT) % 26 + 'a';
    } else if (c >= 'A' && c <= 'Z') {
        return (c - 'A' + SHIFT) % 26 + 'A';
    }
    return c; // Non-alphabetic characters remain unchanged
}

// Function to encrypt the contents of a file and write to a new file
void encrypt_file(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    if (!input_file) {
        perror("Could not open input file");
        return;
    }
    
    FILE *output_file = fopen(output_filename, "w");
    if (!output_file) {
        perror("Could not open output file");
        fclose(input_file);
        return;
    }

    int c;
    while ((c = fgetc(input_file)) != EOF) {
        fputc(encrypt_char(c), output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

// Recursive function to encrypt files in a directory
void encrypt_directory(const char *directory) {
    char command[256];
    snprintf(command, sizeof(command), "find %s -type f", directory);

    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("Failed to run command");
        return;
    }

    char filepath[256];
    while (fgets(filepath, sizeof(filepath), fp) != NULL) {
        // Remove newline character
        filepath[strcspn(filepath, "\n")] = 0;

        // Create a new filename for the encrypted file
        char output_filepath[256];
        snprintf(output_filepath, sizeof(output_filepath), "%s.enc", filepath);

        printf("Encrypting file: %s\n", filepath);
        encrypt_file(filepath, output_filepath);
    }

    pclose(fp);
}

// User-defined function to prompt user and handle encryption operation
void encrypt_files_recursive() {
    char directory[256];

    printf("Enter the directory to encrypt files in: ");
    scanf("%s", directory);

    encrypt_directory(directory);
}

int main() {
    encrypt_files_recursive();
    return 0;
}