//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 32
#define MAX_FILE_SIZE 1000000

typedef struct {
    char key[MAX_KEY_LENGTH];
    FILE *file;
    int mode;
} Encryptor;

void encrypt_file(Encryptor *encryptor) {
    char buffer[1024];
    int buffer_length = 0;
    int key_length = strlen(encryptor->key);
    int i = 0;

    while ((buffer_length = fread(buffer, 1, 1024, encryptor->file)) > 0) {
        for (i = 0; i < buffer_length; i++) {
            buffer[i] ^= encryptor->key[i % key_length];
        }
        fwrite(buffer, 1, buffer_length, encryptor->file);
    }

    fclose(encryptor->file);
}

void decrypt_file(Encryptor *encryptor) {
    char buffer[1024];
    int buffer_length = 0;
    int key_length = strlen(encryptor->key);
    int i = 0;

    while ((buffer_length = fread(buffer, 1, 1024, encryptor->file)) > 0) {
        for (i = 0; i < buffer_length; i++) {
            buffer[i] ^= encryptor->key[i % key_length];
        }
        fwrite(buffer, 1, buffer_length, encryptor->file);
    }

    fclose(encryptor->file);
}

void open_file(Encryptor *encryptor) {
    if (encryptor->mode == 0) {
        encryptor->file = fopen(encryptor->key, "wb");
    } else {
        encryptor->file = fopen(encryptor->key, "rb");
    }
}

int main(int argc, char **argv) {
    Encryptor encryptor;

    if (argc < 3) {
        printf("Usage: %s [encrypt|decrypt] <file> <key>\n", argv[0]);
        return 1;
    }

    strcpy(encryptor.key, argv[2]);
    strcpy(encryptor.file, argv[3]);
    encryptor.mode = (strcmp(argv[1], "encrypt") == 0)? 0 : 1;

    open_file(&encryptor);

    if (encryptor.mode == 0) {
        encrypt_file(&encryptor);
    } else {
        decrypt_file(&encryptor);
    }

    return 0;
}