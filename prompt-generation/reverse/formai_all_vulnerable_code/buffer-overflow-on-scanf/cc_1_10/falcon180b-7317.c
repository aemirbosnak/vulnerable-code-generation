//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

typedef struct {
    char filename[100];
    char key[100];
    char encrypted_filename[200];
    FILE *file;
    FILE *encrypted_file;
} File;

void encrypt_file(File *file) {
    int i, j, k = 0;
    char ch;

    rewind(file->file);
    fseek(file->encrypted_file, 0, SEEK_SET);

    while ((ch = fgetc(file->file))!= EOF) {
        i = ch + k;
        j = i % 26 + 65;

        if (isalpha(ch)) {
            fprintf(file->encrypted_file, "%c", j);
        } else {
            fprintf(file->encrypted_file, "%c", ch);
        }

        k = i % 26;
    }

    fclose(file->file);
    fclose(file->encrypted_file);
}

int main() {
    int i, n;
    char filename[100];
    char key[100];
    File files[SIZE];

    printf("Enter the number of files to encrypt: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the filename for file %d: ", i + 1);
        scanf("%s", filename);

        printf("Enter the encryption key for file %s: ", filename);
        scanf("%s", key);

        strcpy(files[i].filename, filename);
        strcpy(files[i].key, key);

        strcat(files[i].encrypted_filename, filename);
        strcat(files[i].encrypted_filename, ".enc");

        files[i].file = fopen(files[i].filename, "rb");
        files[i].encrypted_file = fopen(files[i].encrypted_filename, "wb");
    }

    for (i = 0; i < n; i++) {
        encrypt_file(&files[i]);
    }

    return 0;
}