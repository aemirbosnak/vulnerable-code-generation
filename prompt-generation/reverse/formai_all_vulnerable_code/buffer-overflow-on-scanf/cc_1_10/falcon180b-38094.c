//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 8

void generate_key(char* key) {
    time_t t;
    time(&t);
    srand(t);

    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

void encrypt_block(char* plaintext, char* key) {
    char ciphertext[BLOCK_SIZE];
    for (int i = 0; i < BLOCK_SIZE; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % KEY_LENGTH];
    }
    strcpy(plaintext, ciphertext);
}

void decrypt_block(char* ciphertext, char* key) {
    char plaintext[BLOCK_SIZE];
    for (int i = 0; i < BLOCK_SIZE; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % KEY_LENGTH];
    }
    strcpy(ciphertext, plaintext);
}

void encrypt_file(FILE* input_file, FILE* output_file, char* key) {
    char plaintext[BLOCK_SIZE];
    char ciphertext[BLOCK_SIZE];

    while (fread(plaintext, sizeof(char), BLOCK_SIZE, input_file) == BLOCK_SIZE) {
        encrypt_block(plaintext, key);
        fwrite(ciphertext, sizeof(char), BLOCK_SIZE, output_file);
    }
}

void decrypt_file(FILE* input_file, FILE* output_file, char* key) {
    char ciphertext[BLOCK_SIZE];
    char plaintext[BLOCK_SIZE];

    while (fread(ciphertext, sizeof(char), BLOCK_SIZE, input_file) == BLOCK_SIZE) {
        decrypt_block(ciphertext, key);
        fwrite(plaintext, sizeof(char), BLOCK_SIZE, output_file);
    }
}

int main() {
    char input_file_path[100];
    char output_file_path[100];
    char key[KEY_LENGTH];

    printf("Enter input file path: ");
    scanf("%s", input_file_path);

    printf("Enter output file path: ");
    scanf("%s", output_file_path);

    generate_key(key);

    FILE* input_file = fopen(input_file_path, "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE* output_file = fopen(output_file_path, "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    if (strcmp(input_file_path, output_file_path) == 0) {
        printf("Input and output files cannot be the same.\n");
        exit(1);
    }

    encrypt_file(input_file, output_file, key);

    fclose(input_file);
    fclose(output_file);

    printf("File encryption completed successfully.\n");

    return 0;
}