//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 32
#define MAX_FILE_SIZE 1000000

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    FILE *file;
} FileEncryptor;

void encrypt_file(FileEncryptor *encryptor) {
    char buffer[1024];
    int bytes_read, bytes_written;
    char *key = encryptor->key;
    int key_length = encryptor->key_length;

    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), encryptor->file)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[i % key_length];
        }
        fwrite(buffer, sizeof(char), bytes_read, encryptor->file);
    }
}

int main() {
    char key[MAX_KEY_LENGTH];
    char input_file[MAX_FILE_SIZE];
    char output_file[MAX_FILE_SIZE];

    // Get input file name and key from user
    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);
    printf("Enter key: ");
    scanf("%s", key);

    // Validate input
    if (strlen(key) > MAX_KEY_LENGTH) {
        printf("Error: Key is too long.\n");
        return 1;
    }

    // Open input and output files
    FILE *input_fp = fopen(input_file, "rb");
    if (input_fp == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }
    FILE *output_fp = fopen(output_file, "wb");
    if (output_fp == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_fp);
        return 1;
    }

    // Create FileEncryptor object
    FileEncryptor encryptor = {
       .key = key,
       .key_length = strlen(key),
       .file = input_fp
    };

    // Encrypt input file
    encrypt_file(&encryptor);

    // Close files
    fclose(encryptor.file);
    fclose(input_fp);
    fclose(output_fp);

    printf("File encrypted successfully!\n");
    return 0;
}