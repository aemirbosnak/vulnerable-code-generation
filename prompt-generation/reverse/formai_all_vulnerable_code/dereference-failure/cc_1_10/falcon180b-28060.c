//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 256
#define MAX_FILE_NAME_LENGTH 1024

typedef struct {
    char key[MAX_KEY_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];
} FileEncryptor;

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <key> <file_name>\n", argv[0]);
        return 1;
    }

    FileEncryptor encryptor;
    strcpy(encryptor.key, argv[1]);
    strcpy(encryptor.file_name, argv[2]);

    FILE *file = fopen(encryptor.file_name, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", encryptor.file_name);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char *buffer = (unsigned char *) malloc(file_size);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        fclose(file);
        return 1;
    }

    fread(buffer, file_size, 1, file);
    fclose(file);

    unsigned char *encrypted_buffer = (unsigned char *) malloc(file_size + 1);
    if (encrypted_buffer == NULL) {
        printf("Error allocating memory\n");
        free(buffer);
        return 1;
    }

    int key_length = strlen(encryptor.key);
    int i, j;
    for (i = 0; i < file_size; i++) {
        encrypted_buffer[i] = buffer[i] ^ encryptor.key[i % key_length];
    }

    encrypted_buffer[file_size] = '\0';

    FILE *encrypted_file = fopen("encrypted_file.bin", "wb");
    if (encrypted_file == NULL) {
        printf("Error creating encrypted file\n");
        free(buffer);
        free(encrypted_buffer);
        return 1;
    }

    fwrite(encrypted_buffer, file_size + 1, 1, encrypted_file);
    fclose(encrypted_file);

    printf("File encrypted successfully\n");

    free(buffer);
    free(encrypted_buffer);

    return 0;
}