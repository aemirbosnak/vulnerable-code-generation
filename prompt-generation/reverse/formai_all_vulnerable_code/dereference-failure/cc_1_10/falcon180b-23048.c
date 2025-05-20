//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define MAX_FILE_NAME 100

typedef struct {
    char name[MAX_FILE_NAME];
    FILE *fp;
    char *buffer;
    int size;
} file_t;

void backup_file(file_t *file) {
    int bytes_read;
    char backup_name[MAX_FILE_NAME];
    strcpy(backup_name, file->name);
    strcat(backup_name, ".bak");
    FILE *backup_fp = fopen(backup_name, "wb");
    if (backup_fp == NULL) {
        printf("Error creating backup file: %s\n", backup_name);
        exit(1);
    }
    while ((bytes_read = fread(file->buffer, 1, file->size, file->fp)) > 0) {
        fwrite(file->buffer, 1, bytes_read, backup_fp);
    }
    fclose(backup_fp);
    printf("Backup created: %s\n", backup_name);
}

int main() {
    file_t file;
    char filename[MAX_FILE_NAME];
    printf("Enter the name of the file to backup: ");
    scanf("%s", filename);
    file.fp = fopen(filename, "rb");
    if (file.fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    fseek(file.fp, 0, SEEK_END);
    file.size = ftell(file.fp);
    if (file.size > MAX_FILE_SIZE) {
        printf("File too large to backup.\n");
        exit(1);
    }
    rewind(file.fp);
    file.buffer = malloc(file.size);
    if (file.buffer == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }
    fread(file.buffer, 1, file.size, file.fp);
    fclose(file.fp);
    backup_file(&file);
    free(file.buffer);
    return 0;
}