//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LEN 100
#define MAX_FILE_NAME_LEN 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char key[MAX_KEY_LEN];
    char file_name[MAX_FILE_NAME_LEN];
    char encrypted_file_name[MAX_FILE_NAME_LEN];
} FileEncryptor;

void generate_key(char *key) {
    srand(time(NULL));
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[i] = '\0';
}

void encrypt_file(FileEncryptor *file_encryptor) {
    FILE *input_file, *output_file;
    char input_buffer[MAX_FILE_SIZE];
    char output_buffer[MAX_FILE_SIZE];
    int input_file_size;
    int i, j;

    input_file = fopen(file_encryptor->file_name, "rb");
    if (input_file == NULL) {
        printf("Error: could not open file %s for reading\n", file_encryptor->file_name);
        exit(1);
    }

    fseek(input_file, 0, SEEK_END);
    input_file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    for (i = 0, j = 0; i < input_file_size; i++) {
        fread(&input_buffer[i], sizeof(char), 1, input_file);
        output_buffer[j++] = input_buffer[i] ^ file_encryptor->key[i % strlen(file_encryptor->key)];
    }

    output_buffer[j] = '\0';

    output_file = fopen(file_encryptor->encrypted_file_name, "wb");
    if (output_file == NULL) {
        printf("Error: could not open file %s for writing\n", file_encryptor->encrypted_file_name);
        exit(1);
    }

    fwrite(output_buffer, sizeof(char), j, output_file);

    fclose(input_file);
    fclose(output_file);
}

int main() {
    FileEncryptor file_encryptor;

    printf("Enter file name to encrypt: ");
    scanf("%s", file_encryptor.file_name);

    printf("Enter encryption key: ");
    scanf("%s", file_encryptor.key);

    strcpy(file_encryptor.encrypted_file_name, file_encryptor.file_name);
    strcat(file_encryptor.encrypted_file_name, ".enc");

    generate_key(file_encryptor.key);

    encrypt_file(&file_encryptor);

    printf("File %s encrypted successfully to %s\n", file_encryptor.file_name, file_encryptor.encrypted_file_name);

    return 0;
}