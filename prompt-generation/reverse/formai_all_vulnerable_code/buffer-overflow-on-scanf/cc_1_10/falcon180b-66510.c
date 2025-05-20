//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME 1024
#define KEY_SIZE 16

typedef struct {
    char *filename;
    FILE *fp;
    int is_encrypted;
    int key_size;
    char key[KEY_SIZE + 1];
} File;

void generate_key(char *key, int size) {
    for (int i = 0; i < size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[size] = '\0';
}

void encrypt_file(File *file) {
    if (!file->is_encrypted) {
        file->is_encrypted = 1;
        rewind(file->fp);
        char ch;
        while ((ch = fgetc(file->fp))!= EOF) {
            if (isalpha(ch)) {
                ch = toupper(ch);
                ch = (ch - 'A' + file->key[0]) % 26 + 'A';
            }
            fputc(ch, file->fp);
        }
    }
}

void decrypt_file(File *file) {
    if (file->is_encrypted) {
        file->is_encrypted = 0;
        rewind(file->fp);
        char ch;
        while ((ch = fgetc(file->fp))!= EOF) {
            if (isalpha(ch)) {
                ch = toupper(ch);
                ch = (ch - 'A' + 'Z' - file->key[0]) % 26 + 'A';
            }
            fputc(ch, file->fp);
        }
    }
}

int main() {
    srand(time(NULL));
    int key_size = KEY_SIZE;
    char key[KEY_SIZE + 1];
    generate_key(key, key_size);
    printf("Encryption key: %s\n", key);

    char filename[MAX_FILE_NAME];
    printf("Enter file name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "rb+");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    File file = {filename, fp, 0, key_size, key};
    encrypt_file(&file);

    fclose(fp);
    return 0;
}