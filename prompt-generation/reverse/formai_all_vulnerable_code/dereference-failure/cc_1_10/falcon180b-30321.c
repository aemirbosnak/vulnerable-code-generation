//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 32
#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10MB

// Function to generate a random key
void generate_key(char *key) {
    const char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = characters[rand() % strlen(characters)];
    }
}

// Function to encrypt the file
void encrypt_file(char *input_file, char *output_file, char *key) {
    FILE *in_file, *out_file;
    in_file = fopen(input_file, "rb");
    out_file = fopen(output_file, "wb");

    if (in_file == NULL || out_file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char buffer[MAX_FILE_SIZE];
    int buffer_size;
    while ((buffer_size = fread(buffer, 1, MAX_FILE_SIZE, in_file)) > 0) {
        for (int i = 0; i < buffer_size; i++) {
            buffer[i] ^= key[i % MAX_KEY_LENGTH];
        }
        fwrite(buffer, 1, buffer_size, out_file);
    }

    fclose(in_file);
    fclose(out_file);
}

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        printf("Usage:./program input_file output_file key_length key_content\n");
        exit(1);
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    int key_length = atoi(argv[3]);
    char key[MAX_KEY_LENGTH];
    if (key_length > MAX_KEY_LENGTH) {
        printf("Key length is too long\n");
        exit(1);
    }
    strncpy(key, argv[4], key_length);
    generate_key(key + key_length);

    encrypt_file(input_file, output_file, key);

    printf("File encrypted successfully\n");
    return 0;
}