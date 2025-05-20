//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_SIZE] = '\0';
}

void encrypt_block(char *block, char *key) {
    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        block[i] ^= key[i % KEY_SIZE];
    }
}

void decrypt_block(char *block, char *key) {
    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        block[i] ^= key[i % KEY_SIZE];
    }
}

int main() {
    char input_file[100], output_file[100];
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    char key[KEY_SIZE + 1];
    generate_key(key);

    char block[BLOCK_SIZE + 1];
    int bytes_read;
    while ((bytes_read = fread(block, 1, BLOCK_SIZE, input)) > 0) {
        encrypt_block(block, key);
        fwrite(block, 1, bytes_read, output);
    }

    fclose(input);
    fclose(output);

    printf("Encryption completed successfully.\n");

    return 0;
}