//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *filename;
    char *encrypted_filename;
} file_t;

void generate_key(char *key, int key_size) {
    srand(time(NULL));
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

void encrypt_file(file_t *file, char *key) {
    FILE *input_file = fopen(file->filename, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    FILE *output_file = fopen(file->encrypted_filename, "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    char buffer[1024];
    int buffer_size = 0;
    while ((buffer_size = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
        for (int i = 0; i < buffer_size; i++) {
            buffer[i] ^= key[i % strlen(key)];
        }
        fwrite(buffer, 1, buffer_size, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    file_t file;
    file.filename = argv[1];
    file.encrypted_filename = argv[2];

    char key[strlen(file.filename)];
    generate_key(key, strlen(file.filename));

    encrypt_file(&file, key);

    printf("File encrypted successfully.\n");
    return 0;
}