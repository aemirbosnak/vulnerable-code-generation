//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 32
#define MAX_FILE_LEN 1024

struct {
    char key[MAX_KEY_LEN];
    char file_name[MAX_FILE_LEN];
} config;

void set_key(char* key) {
    strncpy(config.key, key, MAX_KEY_LEN);
}

void set_file_name(char* file_name) {
    strncpy(config.file_name, file_name, MAX_FILE_LEN);
}

void encrypt_file() {
    FILE* file = fopen(config.file_name, "rb");
    if (!file) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    FILE* output_file = fopen("encrypted.bin", "wb");
    if (!output_file) {
        printf("Error: Could not create output file\n");
        exit(1);
    }

    char buffer[1024];
    int buffer_len = 0;

    while ((buffer_len = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < buffer_len; i++) {
            buffer[i] ^= config.key[i % strlen(config.key)];
        }

        fwrite(buffer, 1, buffer_len, output_file);
    }

    fclose(file);
    fclose(output_file);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <key> <file_name>\n", argv[0]);
        exit(1);
    }

    set_key(argv[1]);
    set_file_name(argv[2]);

    encrypt_file();

    printf("File encrypted successfully\n");
    return 0;
}