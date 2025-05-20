//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // 1 MB
#define BUFFER_SIZE 1024 // 1 KB

typedef struct {
    char filename[100];
    int filesize;
    char *data;
} File;

void read_file(FILE *fp, File *file) {
    fseek(fp, 0, SEEK_END);
    file->filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    file->data = (char*) malloc(file->filesize + 1);
    if (file->data == NULL) {
        printf("Error: Failed to allocate memory for file data.\n");
        exit(1);
    }

    fread(file->data, file->filesize, 1, fp);
    file->data[file->filesize] = '\0';
}

void write_file(FILE *fp, File *file) {
    fwrite(file->data, file->filesize, 1, fp);
}

void backup_file(char *filename, char *backup_dir) {
    FILE *fp, *bfp;
    File file;
    char backup_filename[200];

    strcpy(backup_filename, backup_dir);
    strcat(backup_filename, "/");
    strcat(backup_filename, filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Failed to open file for reading.\n");
        exit(1);
    }

    read_file(fp, &file);
    fclose(fp);

    strcat(backup_filename, ".bak");
    bfp = fopen(backup_filename, "wb");
    if (bfp == NULL) {
        printf("Error: Failed to open backup file for writing.\n");
        exit(1);
    }

    write_file(bfp, &file);
    fclose(bfp);

    printf("File backed up successfully.\n");
}

int main() {
    char filename[100];
    char backup_dir[100];

    printf("Enter the file name to backup: ");
    scanf("%s", filename);

    printf("Enter the backup directory: ");
    scanf("%s", backup_dir);

    backup_file(filename, backup_dir);

    return 0;
}