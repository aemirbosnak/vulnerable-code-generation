//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 256
#define MAX_FILE_SIZE 1000000

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
    char file_path[MAX_FILE_SIZE];
} Encryptor;

void generate_key(Encryptor* encryptor) {
    int i;
    for (i = 0; i < MAX_KEY_SIZE; i++) {
        encryptor->key[i] = rand() % 26 + 'a';
    }
    encryptor->key_size = MAX_KEY_SIZE;
}

void encrypt_file(Encryptor* encryptor) {
    FILE* input_file;
    FILE* output_file;
    char input_buffer[MAX_FILE_SIZE];
    char output_buffer[MAX_FILE_SIZE];
    int input_size;
    int output_size;
    int i;

    input_file = fopen(encryptor->file_path, "rb");
    if (input_file == NULL) {
        printf("Error: file not found.\n");
        exit(1);
    }

    output_file = fopen("encrypted.bin", "wb");
    if (output_file == NULL) {
        printf("Error: could not create output file.\n");
        exit(1);
    }

    while ((input_size = fread(input_buffer, sizeof(char), MAX_FILE_SIZE, input_file)) > 0) {
        for (i = 0; i < input_size; i++) {
            if (isalpha(input_buffer[i])) {
                output_buffer[i] = input_buffer[i] + encryptor->key[i % encryptor->key_size];
            } else {
                output_buffer[i] = input_buffer[i];
            }
        }
        fwrite(output_buffer, sizeof(char), input_size, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    Encryptor encryptor;
    char file_path[MAX_FILE_SIZE];
    printf("Enter file path:\n");
    scanf("%s", file_path);
    strcpy(encryptor.file_path, file_path);
    generate_key(&encryptor);
    encrypt_file(&encryptor);
    printf("File encrypted successfully!\n");
    return 0;
}