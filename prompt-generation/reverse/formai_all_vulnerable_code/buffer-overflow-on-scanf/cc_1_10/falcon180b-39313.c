//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 100
#define BACKUP_DIR "backup"
#define FILE_EXTENSION ".bak"

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    time_t last_modified;
} BackupFile;

void create_backup_dir() {
    char backup_dir_path[100];
    strcpy(backup_dir_path, BACKUP_DIR);
    mkdir(backup_dir_path, 0777);
}

void backup_file(const char *file_path) {
    BackupFile backup_file;
    strcpy(backup_file.file_name, file_path);
    backup_file.last_modified = time(NULL);

    char backup_file_path[200];
    strcpy(backup_file_path, BACKUP_DIR);
    strcat(backup_file_path, "/");
    strcat(backup_file_path, backup_file.file_name);
    strcat(backup_file_path, FILE_EXTENSION);

    FILE *backup_file_ptr = fopen(backup_file_path, "w");
    if (backup_file_ptr == NULL) {
        printf("Error creating backup file\n");
        return;
    }

    FILE *file_ptr = fopen(file_path, "r");
    if (file_ptr == NULL) {
        printf("Error opening file\n");
        fclose(backup_file_ptr);
        return;
    }

    char buffer[1000];
    while (fgets(buffer, sizeof(buffer), file_ptr)!= NULL) {
        fputs(buffer, backup_file_ptr);
    }

    fclose(file_ptr);
    fclose(backup_file_ptr);
}

int main() {
    create_backup_dir();

    char file_path[100];
    printf("Enter file path to backup: ");
    scanf("%s", file_path);

    backup_file(file_path);

    printf("Backup complete!\n");

    return 0;
}