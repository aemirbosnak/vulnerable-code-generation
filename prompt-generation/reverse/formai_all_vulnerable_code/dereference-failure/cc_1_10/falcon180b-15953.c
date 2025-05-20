//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10 MB

typedef struct {
    char key[16];
    int key_length;
    FILE *input_file;
    FILE *output_file;
} Encryptor;

void generate_key(char key[16]) {
    for (int i = 0; i < 16; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[15] = '\0';
}

void encrypt(Encryptor *encryptor) {
    char input_buffer[1024];
    char output_buffer[1024];
    int input_buffer_length = 0;
    int output_buffer_length = 0;

    while (fread(input_buffer, 1, sizeof(input_buffer), encryptor->input_file) > 0) {
        for (int i = 0; i < strlen(input_buffer); i++) {
            if (isalpha(input_buffer[i])) {
                char key_index = tolower(encryptor->key[i % encryptor->key_length]) - 'a';
                output_buffer[output_buffer_length++] = (key_index + (input_buffer[i] - 'a')) % 26 + 'a';
            } else {
                output_buffer[output_buffer_length++] = input_buffer[i];
            }
        }

        fwrite(output_buffer, 1, output_buffer_length, encryptor->output_file);
        output_buffer_length = 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }

    Encryptor encryptor;
    encryptor.input_file = fopen(argv[1], "rb");
    encryptor.output_file = fopen(argv[2], "wb");
    if (encryptor.input_file == NULL || encryptor.output_file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    strcpy(encryptor.key, argv[3]);
    encryptor.key_length = strlen(encryptor.key);

    encrypt(&encryptor);

    fclose(encryptor.input_file);
    fclose(encryptor.output_file);

    return 0;
}