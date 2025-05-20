//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 64

// Function to generate a random key
void generate_key(char *key) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }
}

// Function to encrypt the file
void encrypt_file(FILE *input, FILE *output, char *key) {
    char buffer[BLOCK_SIZE];
    char *cipher_text = malloc(BLOCK_SIZE);
    int i, j;
    for (i = 0; i < BLOCK_SIZE; i++) {
        cipher_text[i] = 0;
    }
    while (fread(buffer, 1, BLOCK_SIZE, input)!= 0) {
        for (i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] ^= key[i % KEY_SIZE];
        }
        for (j = 0; j < BLOCK_SIZE; j++) {
            cipher_text[j] = buffer[j];
        }
        fwrite(cipher_text, 1, BLOCK_SIZE, output);
    }
    free(cipher_text);
}

// Function to decrypt the file
void decrypt_file(FILE *input, FILE *output, char *key) {
    char buffer[BLOCK_SIZE];
    char *plain_text = malloc(BLOCK_SIZE);
    int i, j;
    for (i = 0; i < BLOCK_SIZE; i++) {
        plain_text[i] = 0;
    }
    while (fread(buffer, 1, BLOCK_SIZE, input)!= 0) {
        for (i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] ^= key[i % KEY_SIZE];
        }
        for (j = 0; j < BLOCK_SIZE; j++) {
            plain_text[j] = buffer[j];
        }
        fwrite(plain_text, 1, BLOCK_SIZE, output);
    }
    free(plain_text);
}

int main() {
    char input_filename[100];
    char output_filename[100];
    char key[KEY_SIZE];

    // Prompt user for input filename
    printf("Enter input filename: ");
    scanf("%s", input_filename);

    // Prompt user for output filename
    printf("Enter output filename: ");
    scanf("%s", output_filename);

    // Generate a random key
    generate_key(key);

    // Open input file
    FILE *input = fopen(input_filename, "rb");
    if (input == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open output file
    FILE *output = fopen(output_filename, "wb");
    if (output == NULL) {
        printf("Error opening output file.\n");
        fclose(input);
        return 1;
    }

    // Encrypt the file
    encrypt_file(input, output, key);

    // Close files
    fclose(input);
    fclose(output);

    printf("File encrypted successfully.\n");

    return 0;
}