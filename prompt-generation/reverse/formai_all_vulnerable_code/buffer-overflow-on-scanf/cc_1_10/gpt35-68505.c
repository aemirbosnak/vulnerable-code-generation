//FormAI DATASET v1.0 Category: File Encyptor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_KEY_LENGTH 256
#define BUFFER_SIZE 512

void encrypt_file(const char* filename, const char* key);
void decrypt_file(const char* filename, const char* key);

int main(int argc, char* argv[]) {
    char filename[MAX_FILENAME_LENGTH];
    char key[MAX_KEY_LENGTH];
    char action;

    printf("Enter filename to encrypt/decrypt: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0;

    printf("Enter encryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key[strcspn(key, "\n")] = 0;

    printf("Do you want to encrypt or decrypt? (E/D): ");
    scanf("%c", &action);
    getchar();

    if (action == 'E' || action == 'e') {
        encrypt_file(filename, key);
        printf("Encryption successful.\n");
    } else if (action == 'D' || action == 'd') {
        decrypt_file(filename, key);
        printf("Decryption successful.\n");
    } else {
        printf("Invalid input.\n");
        return 1;
    }

    return 0;
}

void encrypt_file(const char* filename, const char* key) {
    FILE* input_file = fopen(filename, "rb");
    FILE* output_file = fopen(strcat(filename, ".enc"), "wb");

    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read = 0;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[i % strlen(key)];
        }

        fwrite(buffer, 1, bytes_read, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

void decrypt_file(const char* filename, const char* key) {
    FILE* input_file = fopen(filename, "rb");
    FILE* output_file = fopen(strcat(filename, ".dec"), "wb");

    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read = 0;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[i % strlen(key)];
        }

        fwrite(buffer, 1, bytes_read, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}