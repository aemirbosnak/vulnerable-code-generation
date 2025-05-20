//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 100
#define MAX_FILE_NAME_LEN 100

typedef struct {
    char key[MAX_KEY_LEN];
    int key_len;
    char file_name[MAX_FILE_NAME_LEN];
} file_encryptor_t;

void generate_key(char* key, int len) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < len; i++) {
        int rand_index = rand() % strlen(charset);
        key[i] = charset[rand_index];
    }
    key[len] = '\0';
}

void encrypt_file(file_encryptor_t* encryptor) {
    FILE* file = fopen(encryptor->file_name, "rb");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);

    char* file_data = malloc(file_size);
    fread(file_data, file_size, 1, file);
    fclose(file);

    for (int i = 0; i < file_size; i++) {
        char ch = file_data[i];
        if (isalpha(ch)) {
            if (isupper(ch)) {
                ch = (ch - 'A' + encryptor->key[i % encryptor->key_len] - 'A') % 26 + 'A';
            } else {
                ch = (ch - 'a' + encryptor->key[i % encryptor->key_len] - 'a') % 26 + 'a';
            }
        }
        file_data[i] = ch;
    }

    file = fopen(encryptor->file_name, "wb");
    if (file == NULL) {
        printf("Error: Failed to write file.\n");
        exit(1);
    }

    fwrite(file_data, file_size, 1, file);
    fclose(file);

    printf("File successfully encrypted.\n");
}

int main() {
    file_encryptor_t encryptor;
    encryptor.key[0] = '\0';
    printf("Enter file name to encrypt: ");
    scanf("%s", encryptor.file_name);

    printf("Enter encryption key: ");
    fgets(encryptor.key, MAX_KEY_LEN, stdin);
    encryptor.key_len = strlen(encryptor.key);

    encrypt_file(&encryptor);

    return 0;
}