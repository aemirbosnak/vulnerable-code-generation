//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 10
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char encrypted_file_name[MAX_FILE_NAME_LENGTH];
    char key[MAX_KEY_LENGTH];
    int encrypted;
} FileInfo;

void encrypt_file(FileInfo* file_info) {
    FILE* input_file = fopen(file_info->file_name, "rb");
    FILE* output_file = fopen(file_info->encrypted_file_name, "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char buffer[1024];
    int buffer_size = 0;

    while ((buffer_size = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
        for (int i = 0; i < buffer_size; i++) {
            char c = buffer[i];
            if (isalpha(c)) {
                c = (c - 'A' + file_info->key[i % strlen(file_info->key)] - 'A') % 26 + 'A';
            }
            fwrite(&c, 1, 1, output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);
}

void decrypt_file(FileInfo* file_info) {
    FILE* input_file = fopen(file_info->encrypted_file_name, "rb");
    FILE* output_file = fopen(file_info->file_name, "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char buffer[1024];
    int buffer_size = 0;

    while ((buffer_size = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
        for (int i = 0; i < buffer_size; i++) {
            char c = buffer[i];
            if (isalpha(c)) {
                c = (c - 'A' + 'A' - file_info->key[i % strlen(file_info->key)]) % 26 + 'A';
            }
            fwrite(&c, 1, 1, output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    FileInfo file_info;
    printf("Enter file name: ");
    scanf("%s", file_info.file_name);

    printf("Enter encrypted file name: ");
    scanf("%s", file_info.encrypted_file_name);

    printf("Enter key: ");
    scanf("%s", file_info.key);

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            file_info.encrypted = 1;
            encrypt_file(&file_info);
            printf("File encrypted successfully.\n");
            break;
        case 2:
            file_info.encrypted = 0;
            decrypt_file(&file_info);
            printf("File decrypted successfully.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}