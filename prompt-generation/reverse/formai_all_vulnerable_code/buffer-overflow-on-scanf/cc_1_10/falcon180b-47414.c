//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 8
#define BLOCK_SIZE 64

void encrypt(char* input_file, char* output_file, char* key) {
    FILE* input = fopen(input_file, "rb");
    FILE* output = fopen(output_file, "wb");

    if (!input ||!output) {
        printf("Error: Could not open file(s)\n");
        exit(1);
    }

    char key_buffer[KEY_SIZE + 1] = {0};
    strncpy(key_buffer, key, KEY_SIZE);

    char buffer[BLOCK_SIZE + 1] = {0};
    int buffer_index = 0;

    while (fread(buffer, sizeof(char), BLOCK_SIZE, input) == BLOCK_SIZE) {
        for (int i = 0; i < BLOCK_SIZE; i++) {
            char c = toupper(buffer[i]);
            if (isalpha(c)) {
                c = ((c - 'A' + 13) % 26) + 'A';
            } else {
                c = buffer[i];
            }

            int key_index = (i % KEY_SIZE);
            c ^= key_buffer[key_index];

            fwrite(&c, sizeof(char), 1, output);
        }

        buffer_index += BLOCK_SIZE;
    }

    if (buffer_index % BLOCK_SIZE!= 0) {
        for (int i = 0; i < buffer_index % BLOCK_SIZE; i++) {
            char c = toupper(buffer[i]);
            if (isalpha(c)) {
                c = ((c - 'A' + 13) % 26) + 'A';
            } else {
                c = buffer[i];
            }

            int key_index = (i % KEY_SIZE);
            c ^= key_buffer[key_index];

            fwrite(&c, sizeof(char), 1, output);
        }
    }

    fclose(input);
    fclose(output);
}

int main() {
    char input_file[100] = {0};
    char output_file[100] = {0};
    char key[KEY_SIZE + 1] = {0};

    printf("Enter input file name: ");
    scanf("%s", input_file);

    printf("Enter output file name: ");
    scanf("%s", output_file);

    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt(input_file, output_file, key);

    printf("Encryption complete!\n");

    return 0;
}