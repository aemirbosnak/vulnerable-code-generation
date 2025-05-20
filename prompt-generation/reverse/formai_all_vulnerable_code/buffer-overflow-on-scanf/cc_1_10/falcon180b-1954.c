//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 16
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char key[MAX_KEY_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];
} file_info_t;

void generate_key(char* key) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int key_length = strlen(charset);

    for (int i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = charset[rand() % key_length];
    }

    key[MAX_KEY_LENGTH - 1] = '\0';
}

void encrypt_file(file_info_t* file_info) {
    FILE* input_file = fopen(file_info->file_name, "rb");
    FILE* output_file = fopen(file_info->file_name, "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char key[MAX_KEY_LENGTH];
    generate_key(key);

    char buffer[1024];
    int buffer_size = 0;

    while (fread(buffer + buffer_size, 1, 1024 - buffer_size, input_file) > 0) {
        buffer_size += fread(buffer + buffer_size, 1, 1024 - buffer_size, input_file);

        for (int i = 0; i < buffer_size; i++) {
            buffer[i] ^= key[i % MAX_KEY_LENGTH];
        }

        fwrite(buffer, 1, buffer_size, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    file_info_t file_info;

    printf("Enter file name: ");
    scanf("%s", file_info.file_name);

    printf("Enter encryption key (leave blank for random key): ");
    scanf("%s", file_info.key);

    if (strlen(file_info.key) == 0) {
        generate_key(file_info.key);
        printf("Generated key: %s\n", file_info.key);
    }

    encrypt_file(&file_info);

    printf("File encrypted successfully.\n");

    return 0;
}