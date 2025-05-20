//FormAI DATASET v1.0 Category: File Encyptor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt(const char* input_filename, const char* output_filename, const char* key) {
    FILE* input_file = fopen(input_filename, "rb");
    FILE* output_file = fopen(output_filename, "wb");
    
    if (input_file == NULL) {
        printf("Error: unable to open input file.\n");
        exit(1);
    }
    if (output_file == NULL) {
        printf("Error: unable to open output file.\n");
        exit(1);
    }
    
    char buffer[BUFFER_SIZE];
    int buffer_size = 0;
    int key_index = 0;
    int key_length = strlen(key);
    
    while ((buffer_size = fread(buffer, sizeof(char), BUFFER_SIZE, input_file)) > 0) {
        for (int i = 0; i < buffer_size; i++) {
            buffer[i] ^= key[key_index];
            key_index = (key_index + 1) % key_length;
        }
        fwrite(buffer, sizeof(char), buffer_size, output_file);
    }
    
    fclose(input_file);
    fclose(output_file);
}

void decrypt(const char* input_filename, const char* output_filename, const char* key) {
    encrypt(input_filename, output_filename, key);
}

int main() {
    char input_filename[256];
    char output_filename[256];
    char key[256];

    printf("Enter input filename: ");
    scanf("%s", input_filename);

    printf("Enter output filename: ");
    scanf("%s", output_filename);

    printf("Enter encryption/decryption key: ");
    scanf("%s", key);

    encrypt(input_filename, output_filename, key);
    printf("File encrypted successfully.\n");

    return 0;
}