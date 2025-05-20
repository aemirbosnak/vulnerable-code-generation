//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    int size;
    char *data;
} file_t;

file_t *create_file(char *filename, int size) {
    file_t *file = (file_t *) malloc(sizeof(file_t));
    strcpy(file->filename, filename);
    file->size = size;
    file->data = (char *) malloc(size);
    return file;
}

void delete_file(file_t *file) {
    free(file->data);
    free(file);
}

void backup_file(file_t *file, char *backup_dir) {
    char backup_filename[MAX_FILE_NAME_LENGTH];
    strcpy(backup_filename, file->filename);
    strcat(backup_filename, ".bak");
    FILE *backup_file = fopen(backup_filename, "wb");
    if (backup_file == NULL) {
        printf("Error: Failed to create backup file %s\n", backup_filename);
        return;
    }
    fwrite(file->data, file->size, 1, backup_file);
    fclose(backup_file);
    printf("Backup created: %s\n", backup_filename);
}

int main() {
    char filename[MAX_FILE_NAME_LENGTH];
    char backup_dir[MAX_FILE_NAME_LENGTH];
    printf("Enter the name of the file to backup: ");
    scanf("%s", filename);
    printf("Enter the backup directory: ");
    scanf("%s", backup_dir);

    file_t *file = create_file(filename, 0);
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Failed to open file %s\n", filename);
        delete_file(file);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp);
    rewind(fp);

    file->data = (char *) malloc(file->size);
    if (file->data == NULL) {
        printf("Error: Failed to allocate memory for file %s\n", filename);
        fclose(fp);
        delete_file(file);
        return 1;
    }

    fread(file->data, file->size, 1, fp);
    fclose(fp);

    backup_file(file, backup_dir);

    delete_file(file);

    return 0;
}