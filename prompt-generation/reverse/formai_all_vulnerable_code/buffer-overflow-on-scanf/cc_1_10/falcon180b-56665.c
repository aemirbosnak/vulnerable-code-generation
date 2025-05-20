//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_FILE_SIZE 1000000
#define BACKUP_DIR "backup"

struct file_backup {
    char file_name[MAX_FILE_NAME];
    char backup_name[MAX_FILE_NAME];
    char backup_dir[MAX_FILE_NAME];
    int file_size;
};

int main() {
    char file_path[MAX_FILE_NAME];
    printf("Enter the file path: ");
    scanf("%s", file_path);

    struct file_backup file_backup;

    strcpy(file_backup.file_name, file_path);
    strcpy(file_backup.backup_name, "backup_");
    strcat(file_backup.backup_name, file_backup.file_name);
    strcpy(file_backup.backup_dir, BACKUP_DIR);

    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    file_backup.file_size = ftell(file);
    rewind(file);

    char backup_path[MAX_FILE_NAME];
    strcpy(backup_path, file_backup.backup_dir);
    strcat(backup_path, "/");
    strcat(backup_path, file_backup.backup_name);

    FILE *backup_file = fopen(backup_path, "w");
    if (backup_file == NULL) {
        printf("Backup directory not found.\n");
        exit(1);
    }

    char buffer[MAX_FILE_SIZE];
    int bytes_read = 0;

    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    fclose(file);
    fclose(backup_file);

    printf("File backup successful.\n");
    return 0;
}