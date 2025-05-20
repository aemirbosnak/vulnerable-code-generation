//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000
#define MAX_BACKUP_DIR_SIZE 100
#define MAX_FILE_NAME_SIZE 100

typedef struct backup_file {
    char *file_name;
    char *backup_dir;
    char *backup_file_name;
    long long int file_size;
} BackupFile;

void backup_file(BackupFile *file) {
    FILE *fp, *bkp_fp;
    char buffer[MAX_FILE_SIZE];
    long long int bytes_read, bytes_written;

    fp = fopen(file->file_name, "rb");
    if (!fp) {
        printf("Error: Could not open file '%s' for reading.\n", file->file_name);
        exit(1);
    }

    bkp_fp = fopen(file->backup_file_name, "wb");
    if (!bkp_fp) {
        printf("Error: Could not open backup file '%s' for writing.\n", file->backup_file_name);
        exit(1);
    }

    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, fp)) > 0) {
        bytes_written = fwrite(buffer, 1, bytes_read, bkp_fp);
        if (bytes_read!= bytes_written) {
            printf("Error: Could not write to backup file '%s'.\n", file->backup_file_name);
            exit(1);
        }
    }

    fclose(fp);
    fclose(bkp_fp);
}

void create_backup_dir(char *dir) {
    char *backup_dir = malloc(MAX_BACKUP_DIR_SIZE * sizeof(char));
    strcpy(backup_dir, dir);
    strcat(backup_dir, "_backup");

    if (mkdir(backup_dir)!= 0) {
        printf("Error: Could not create backup directory '%s'.\n", backup_dir);
        exit(1);
    }

    free(backup_dir);
}

int main() {
    BackupFile file;

    printf("Enter the name of the file to backup: ");
    scanf("%s", file.file_name);

    printf("Enter the directory to backup to: ");
    scanf("%s", file.backup_dir);

    strcpy(file.backup_file_name, file.backup_dir);
    strcat(file.backup_file_name, "/");
    strcat(file.backup_file_name, file.file_name);

    create_backup_dir(file.backup_dir);

    backup_file(&file);

    printf("Backup complete.\n");

    return 0;
}