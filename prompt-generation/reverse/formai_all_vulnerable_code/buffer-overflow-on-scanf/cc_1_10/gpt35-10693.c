//FormAI DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Encrypts the given file with the given key
void encrypt_file(const char* filename, const char* key) {
    FILE* input_file = fopen(filename, "rb");
    FILE* output_file = fopen(strcat(filename, ".enc"), "wb");
    int key_length = strlen(key);
    int i = 0;
    
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }
    
    // Read input file in chunks and encrypt it
    while (1) {
        char buffer[BUFFER_SIZE];
        size_t bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file);
        if (bytes_read == 0) {
            break;
        }
        for (size_t j = 0; j < bytes_read; j++) {
            buffer[j] ^= key[i];
            i = (i + 1) % key_length;
        }
        fwrite(buffer, 1, bytes_read, output_file);
    }
    
    fclose(input_file);
    fclose(output_file);
}

// Decrypts the given file with the given key
void decrypt_file(const char* filename, const char* key) {
    FILE* input_file = fopen(filename, "rb");
    FILE* output_file = fopen(strtok(filename, ".enc"), "wb");
    int key_length = strlen(key);
    int i = 0;
    
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }
    
    // Read input file in chunks and decrypt it
    while (1) {
        char buffer[BUFFER_SIZE];
        size_t bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file);
        if (bytes_read == 0) {
            break;
        }
        for (size_t j = 0; j < bytes_read; j++) {
            buffer[j] ^= key[i];
            i = (i + 1) % key_length;
        }
        fwrite(buffer, 1, bytes_read, output_file);
    }
    
    fclose(input_file);
    fclose(output_file);
}

int main() {
    char filename[256];
    char key[256];
    int choice;
    
    printf("Select an operation:\n");
    printf("1. Encrypt file\n");
    printf("2. Decrypt file\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    
    printf("Enter filename: ");
    scanf("%s", filename);
    
    printf("Enter key: ");
    scanf("%s", key);
    
    switch (choice) {
        case 1:
            encrypt_file(filename, key);
            printf("File encrypted successfully as %s.enc\n", filename);
            break;
        case 2:
            decrypt_file(filename, key);
            printf("File decrypted successfully as %s\n", strtok(filename, ".enc"));
            break;
        default:
            printf("Invalid choice.\n");
    }
    
    return 0;
}