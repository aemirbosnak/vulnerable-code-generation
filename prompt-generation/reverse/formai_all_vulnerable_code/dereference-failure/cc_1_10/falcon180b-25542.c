//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BLOCK_SIZE 64
#define KEY_SIZE 64

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_SIZE] = '\0';
}

void encrypt_file(FILE *input_file, FILE *output_file, char *key) {
    char input_buffer[BLOCK_SIZE];
    char output_buffer[BLOCK_SIZE + 1];
    int i, j;
    for (i = 0; i < BLOCK_SIZE; i++) {
        input_buffer[i] = fgetc(input_file);
    }
    for (i = 0; i < BLOCK_SIZE; i++) {
        output_buffer[i] = input_buffer[i] ^ key[i % KEY_SIZE];
    }
    output_buffer[BLOCK_SIZE] = '\0';
    fwrite(output_buffer, BLOCK_SIZE + 1, 1, output_file);
}

void decrypt_file(FILE *input_file, FILE *output_file, char *key) {
    char input_buffer[BLOCK_SIZE + 1];
    char output_buffer[BLOCK_SIZE];
    int i, j;
    fread(input_buffer, BLOCK_SIZE + 1, 1, input_file);
    for (i = 0; i < BLOCK_SIZE; i++) {
        output_buffer[i] = input_buffer[i] ^ key[i % KEY_SIZE];
    }
    fwrite(output_buffer, BLOCK_SIZE, 1, output_file);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }
    FILE *input_file = fopen(argv[1], "rb");
    FILE *output_file = fopen(argv[2], "wb");
    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    char key[KEY_SIZE + 1];
    generate_key(key);
    encrypt_file(input_file, output_file, key);
    fclose(input_file);
    fclose(output_file);
    return 0;
}