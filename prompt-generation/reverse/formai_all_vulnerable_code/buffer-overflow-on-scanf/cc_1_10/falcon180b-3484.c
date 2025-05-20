//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_LENGTH 1000

void encrypt_file(char *file_path, char *key) {
    FILE *file;
    char buffer[MAX_FILE_LENGTH];
    char encrypted_buffer[MAX_FILE_LENGTH];
    int buffer_length, encrypted_buffer_length;
    int key_index;

    file = fopen(file_path, "rb");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    buffer_length = fread(buffer, sizeof(char), MAX_FILE_LENGTH, file);
    if (buffer_length < 0) {
        printf("Error: could not read file.\n");
        exit(1);
    }

    for (key_index = 0; key_index < strlen(key); key_index++) {
        char key_char = key[key_index];
        encrypted_buffer_length = 0;

        while (buffer_length > 0) {
            char buffer_char = buffer[--buffer_length];
            char encrypted_char;

            if (isalpha(buffer_char)) {
                if (isupper(buffer_char)) {
                    encrypted_char = (buffer_char - 'A' + key_char - 'A') % 26 + 'A';
                } else {
                    encrypted_char = (buffer_char - 'a' + key_char - 'a') % 26 + 'a';
                }
            } else {
                encrypted_char = buffer_char;
            }

            encrypted_buffer[encrypted_buffer_length++] = encrypted_char;
        }

        buffer_length = encrypted_buffer_length;
        memcpy(buffer, encrypted_buffer, buffer_length);
    }

    fclose(file);

    file = fopen(file_path, "wb");
    if (file == NULL) {
        printf("Error: could not open file for writing.\n");
        exit(1);
    }

    fwrite(buffer, sizeof(char), buffer_length, file);
    fclose(file);

    printf("File encrypted successfully.\n");
}

int main() {
    char file_path[MAX_FILE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter file path: ");
    scanf("%s", file_path);

    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt_file(file_path, key);

    return 0;
}