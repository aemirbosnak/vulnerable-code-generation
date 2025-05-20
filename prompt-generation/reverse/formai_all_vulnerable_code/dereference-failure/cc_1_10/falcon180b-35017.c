//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000
#define KEY_SIZE 16
#define BLOCK_SIZE 8

typedef struct {
    char *filename;
    FILE *file;
    int filesize;
    char *key;
} FileContext;

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_SIZE] = '\0';
}

void encrypt_file(FileContext *context) {
    int i, j;
    char block[BLOCK_SIZE];
    for (i = 0; i < context->filesize; i += BLOCK_SIZE) {
        fseek(context->file, i, SEEK_SET);
        fread(block, 1, BLOCK_SIZE, context->file);
        for (j = 0; j < BLOCK_SIZE; j++) {
            if (isalpha(block[j])) {
                block[j] = toupper(block[j]) ^ context->key[j % KEY_SIZE];
            }
        }
        fseek(context->file, i, SEEK_SET);
        fwrite(block, 1, BLOCK_SIZE, context->file);
    }
}

void decrypt_file(FileContext *context) {
    int i, j;
    char block[BLOCK_SIZE];
    for (i = 0; i < context->filesize; i += BLOCK_SIZE) {
        fseek(context->file, i, SEEK_SET);
        fread(block, 1, BLOCK_SIZE, context->file);
        for (j = 0; j < BLOCK_SIZE; j++) {
            if (isalpha(block[j])) {
                block[j] = toupper(block[j]) ^ context->key[j % KEY_SIZE];
            }
        }
        fseek(context->file, i, SEEK_SET);
        fwrite(block, 1, BLOCK_SIZE, context->file);
    }
}

int main(int argc, char *argv[]) {
    FileContext context;
    char *filename = argv[1];
    char *mode = argv[2];
    context.filename = filename;
    context.file = fopen(filename, "rb+");
    if (context.file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }
    context.filesize = 0;
    fseek(context.file, 0, SEEK_END);
    context.filesize = ftell(context.file);
    if (context.filesize > MAX_FILE_SIZE) {
        printf("Error: file %s is too large\n", filename);
        return 1;
    }
    if (strcmp(mode, "encrypt") == 0) {
        generate_key(context.key);
        encrypt_file(&context);
        printf("File %s encrypted with key %s\n", filename, context.key);
    } else if (strcmp(mode, "decrypt") == 0) {
        printf("Enter encryption key: ");
        scanf("%s", context.key);
        decrypt_file(&context);
        printf("File %s decrypted with key %s\n", filename, context.key);
    } else {
        printf("Error: invalid mode\n");
        return 1;
    }
    fclose(context.file);
    return 0;
}