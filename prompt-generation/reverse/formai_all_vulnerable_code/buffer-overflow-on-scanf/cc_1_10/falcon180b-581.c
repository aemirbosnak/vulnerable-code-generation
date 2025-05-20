//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 256
#define MAX_FILE_SIZE 1024*1024*1024 // 1 GB

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
    int mode;
} Encryptor;

Encryptor* create_encryptor(char* key, int key_size, int mode) {
    Encryptor* encryptor = (Encryptor*)malloc(sizeof(Encryptor));
    if (encryptor == NULL) {
        printf("Error: Failed to allocate memory\n");
        exit(1);
    }

    strncpy(encryptor->key, key, MAX_KEY_SIZE);
    encryptor->key_size = key_size;
    encryptor->mode = mode;

    return encryptor;
}

int encrypt_file(Encryptor* encryptor, char* input_file, char* output_file) {
    FILE* input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error: Failed to open input file\n");
        return 1;
    }

    FILE* output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error: Failed to open output file\n");
        return 1;
    }

    char buffer[1024];
    int buffer_size;

    while ((buffer_size = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        for (int i = 0; i < buffer_size; i++) {
            buffer[i] ^= encryptor->key[i % encryptor->key_size];
        }

        fwrite(buffer, 1, buffer_size, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}

int main() {
    char key[MAX_KEY_SIZE];
    int key_size;
    int mode;

    printf("Enter key: ");
    fgets(key, MAX_KEY_SIZE, stdin);
    key_size = strlen(key);

    printf("Enter encryption mode (0: ECB, 1: CBC): ");
    scanf("%d", &mode);

    Encryptor* encryptor = create_encryptor(key, key_size, mode);

    char input_file[256];
    char output_file[256];

    printf("Enter input file: ");
    fgets(input_file, 256, stdin);

    strcat(output_file, input_file);
    strcat(output_file, ".enc");

    encrypt_file(encryptor, input_file, output_file);

    printf("Encryption completed successfully\n");

    return 0;
}