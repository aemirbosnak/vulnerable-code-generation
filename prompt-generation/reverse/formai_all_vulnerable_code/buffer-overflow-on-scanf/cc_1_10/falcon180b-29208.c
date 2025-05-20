//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char file_name[MAX_FILE_NAME];
    int file_size;
    char data[MAX_FILE_SIZE];
} File;

void save_file(File *file) {
    FILE *fp = fopen(file->file_name, "wb");
    if (fp == NULL) {
        printf("Error: could not open file %s for writing\n", file->file_name);
        exit(1);
    }
    fwrite(file->data, file->file_size, 1, fp);
    fclose(fp);
}

void recover_file(char *file_name) {
    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s for reading\n", file_name);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);
    char data[MAX_FILE_SIZE];
    fread(data, file_size, 1, fp);
    fclose(fp);

    printf("Recovered file: %s\n", file_name);
    printf("Size: %d bytes\n", file_size);

    printf("Data:\n");
    for (int i = 0; i < file_size; i++) {
        printf("%02X ", (unsigned char)data[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    File file;
    printf("Enter the name of the file to recover: ");
    scanf("%s", file.file_name);

    printf("Enter the size of the file in bytes: ");
    scanf("%d", &file.file_size);

    printf("Enter the data to recover (in hexadecimal):\n");
    for (int i = 0; i < file.file_size; i++) {
        scanf("%02X", &file.data[i]);
    }

    save_file(&file);
    recover_file(file.file_name);

    return 0;
}