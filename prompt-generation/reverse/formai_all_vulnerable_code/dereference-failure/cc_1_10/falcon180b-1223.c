//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

typedef struct {
    char key[KEY_SIZE];
    int rounds;
} RC4_ctx;

void generate_key(char* key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 256;
    }
}

void rc4_encrypt(char* input_file, char* output_file, char* key, int rounds) {
    FILE* input = fopen(input_file, "rb");
    FILE* output = fopen(output_file, "wb");

    if (input == NULL || output == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    RC4_ctx ctx;
    strcpy(ctx.key, key);
    ctx.rounds = rounds;

    char buffer[BLOCK_SIZE];
    char state[256];
    int i, j;

    for (i = 0; i < 256; i++) {
        state[i] = i;
    }

    for (i = 0; i < ctx.rounds; i++) {
        for (j = 0; j < 256; j++) {
            state[j] += state[(state[j] + i) % 256];
        }
    }

    int len = 0;
    while ((len = fread(buffer, 1, BLOCK_SIZE, input)) > 0) {
        for (i = 0; i < len; i++) {
            buffer[i] ^= state[(state[buffer[i]] + ctx.rounds) % 256];
        }
        fwrite(buffer, 1, len, output);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char* argv[]) {
    if (argc!= 5) {
        printf("Usage: %s input_file output_file key rounds\n", argv[0]);
        exit(1);
    }

    char* input_file = argv[1];
    char* output_file = argv[2];
    char* key = argv[3];
    int rounds = atoi(argv[4]);

    generate_key(key, KEY_SIZE);

    rc4_encrypt(input_file, output_file, key, rounds);

    printf("Encryption complete.\n");

    return 0;
}