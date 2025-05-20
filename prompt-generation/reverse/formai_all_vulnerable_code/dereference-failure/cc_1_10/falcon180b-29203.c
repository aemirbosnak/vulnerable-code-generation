//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 8

typedef struct {
    char key[KEY_LENGTH];
    int rounds;
} encryption_params;

void generate_key(char *key) {
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt_file(FILE *input, FILE *output, encryption_params *params) {
    char buffer[BLOCK_SIZE];
    char iv[BLOCK_SIZE];
    fseek(input, 0, SEEK_SET);
    fread(iv, 1, BLOCK_SIZE, input);
    for (int i = 0; i < BLOCK_SIZE; i++) {
        iv[i] ^= params->key[i % KEY_LENGTH];
    }
    while (fread(buffer, 1, BLOCK_SIZE, input)!= 0) {
        for (int i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] ^= iv[i % BLOCK_SIZE];
        }
        for (int j = 0; j < params->rounds; j++) {
            for (int i = 0; i < BLOCK_SIZE; i++) {
                buffer[i] = (buffer[i] + params->key[(i + j) % KEY_LENGTH]) % 26 + 'a';
            }
        }
        fwrite(buffer, 1, BLOCK_SIZE, output);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <input_file> <output_file> <key_length>\n", argv[0]);
        return 1;
    }
    int key_length = atoi(argv[3]);
    if (key_length < 1 || key_length > 32) {
        printf("Invalid key length.\n");
        return 1;
    }
    encryption_params params;
    generate_key(params.key);
    params.rounds = rand() % 10 + 1;
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    FILE *output = fopen(argv[2], "wb");
    if (output == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }
    encrypt_file(input, output, &params);
    fclose(input);
    fclose(output);
    return 0;
}