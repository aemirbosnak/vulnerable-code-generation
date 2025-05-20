//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];
} encryption_info;

void encrypt_file(encryption_info* info) {
    FILE* input_file = fopen(info->file_name, "r");
    FILE* output_file = fopen(info->file_name, "w");

    char c;
    while ((c = fgetc(input_file)) != EOF) {
        c = (char)((int)c + (int)info->key[0]);
        fputc(c, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

void decrypt_file(encryption_info* info) {
    FILE* input_file = fopen(info->file_name, "r");
    FILE* output_file = fopen(info->file_name, "w");

    char c;
    while ((c = fgetc(input_file)) != EOF) {
        c = (char)((int)c - (int)info->key[0]);
        fputc(c, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    encryption_info info;
    printf("Enter key: ");
    scanf("%s", info.key);
    printf("Enter file name: ");
    scanf("%s", info.file_name);

    encrypt_file(&info);
    decrypt_file(&info);

    return 0;
}