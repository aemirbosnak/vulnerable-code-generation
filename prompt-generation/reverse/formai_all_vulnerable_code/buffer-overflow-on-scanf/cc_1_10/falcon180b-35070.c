//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = 'a' + rand() % 26;
    }
    key[KEY_SIZE] = '\0';
}

void encrypt_block(char *block, char *key) {
    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        block[i] = block[i] ^ key[i % KEY_SIZE];
    }
}

void decrypt_block(char *block, char *key) {
    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        block[i] = block[i] ^ key[i % KEY_SIZE];
    }
}

int main() {
    char input_file[50];
    char output_file[50];
    char key[KEY_SIZE + 1];
    FILE *in, *out;
    char block[BLOCK_SIZE];
    int bytes_read, bytes_written;

    printf("Enter the name of the input file: ");
    scanf("%s", input_file);
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    generate_key(key);

    in = fopen(input_file, "rb");
    if (in == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    out = fopen(output_file, "wb");
    if (out == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while ((bytes_read = fread(block, 1, BLOCK_SIZE, in)) > 0) {
        encrypt_block(block, key);
        bytes_written = fwrite(block, 1, BLOCK_SIZE, out);
        if (bytes_written!= BLOCK_SIZE) {
            printf("Error writing to output file.\n");
            exit(1);
        }
    }

    fclose(in);
    fclose(out);

    printf("File encryption completed successfully.\n");

    return 0;
}