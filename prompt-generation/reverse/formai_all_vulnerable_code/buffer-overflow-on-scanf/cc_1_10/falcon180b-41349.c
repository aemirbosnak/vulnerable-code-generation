//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_KEY_LENGTH 16
#define MAX_BLOCK_SIZE 64

typedef struct {
    char key[MAX_KEY_LENGTH + 1];
    int key_length;
    int num_blocks;
    char *input_file;
    char *output_file;
} encryption_params;

void read_key(encryption_params *params) {
    printf("Enter encryption key: ");
    scanf("%s", params->key);
    params->key_length = strlen(params->key);
}

void read_input_file(encryption_params *params) {
    printf("Enter input file name: ");
    scanf("%s", params->input_file);
}

void read_output_file(encryption_params *params) {
    printf("Enter output file name: ");
    scanf("%s", params->output_file);
}

void set_num_blocks(encryption_params *params) {
    printf("Enter number of blocks: ");
    scanf("%d", &params->num_blocks);
}

void encrypt(encryption_params *params) {
    FILE *input_file = fopen(params->input_file, "rb");
    FILE *output_file = fopen(params->output_file, "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files\n");
        exit(1);
    }

    char buffer[MAX_BLOCK_SIZE];
    int block_size = params->num_blocks * MAX_BLOCK_SIZE;

    while (fread(buffer, sizeof(char), MAX_BLOCK_SIZE, input_file) == MAX_BLOCK_SIZE) {
        for (int i = 0; i < params->key_length; i++) {
            char key_char = params->key[i];
            for (int j = 0; j < MAX_BLOCK_SIZE; j++) {
                char input_char = buffer[j];
                char output_char = input_char ^ key_char;
                buffer[j] = output_char;
            }
        }
        fwrite(buffer, sizeof(char), MAX_BLOCK_SIZE, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    encryption_params params;

    printf("Enter encryption parameters:\n");
    read_key(&params);
    read_input_file(&params);
    read_output_file(&params);
    set_num_blocks(&params);

    encrypt(&params);

    return 0;
}