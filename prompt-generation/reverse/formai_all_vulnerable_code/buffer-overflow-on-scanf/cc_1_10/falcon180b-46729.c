//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    char key[MAX_SIZE];
    char encrypted[MAX_SIZE];
    int flag;
} file_t;

void encrypt_file(file_t *file) {
    int i, j, k;
    char ch;
    for (i = 0; i < strlen(file->name); i++) {
        ch = file->name[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 97 + file->key[i % strlen(file->key)]) % 26 + 97;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 65 + file->key[i % strlen(file->key)]) % 26 + 65;
        }
        file->encrypted[i] = ch;
    }
    file->flag = 1;
}

void decrypt_file(file_t *file) {
    int i, j, k;
    char ch;
    for (i = 0; i < strlen(file->encrypted); i++) {
        ch = file->encrypted[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - file->key[i % strlen(file->key)] + 26) % 26 + 97;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - file->key[i % strlen(file->key)] + 26) % 26 + 65;
        }
        file->name[i] = ch;
    }
    file->flag = 0;
}

int main() {
    file_t file;
    char name[MAX_SIZE];
    char key[MAX_SIZE];
    printf("Enter file name: ");
    scanf("%s", name);
    printf("Enter encryption key: ");
    scanf("%s", key);
    strcpy(file.name, name);
    strcpy(file.key, key);
    encrypt_file(&file);
    printf("Encrypted file name: %s\n", file.encrypted);
    decrypt_file(&file);
    printf("Decrypted file name: %s\n", file.name);
    return 0;
}