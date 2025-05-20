//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_PATH_LENGTH 1000
#define BACKUP_DIR "backups"
#define BACKUP_EXT ".bak"

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char file_path[MAX_FILE_PATH_LENGTH];
    time_t timestamp;
} BackupFile;

void create_backup_dir() {
    char backup_path[MAX_FILE_PATH_LENGTH];
    strcpy(backup_path, "./");
    strcat(backup_path, BACKUP_DIR);
    mkdir(backup_path);
}

void backup_file(char* file_path) {
    BackupFile backup_file;
    strcpy(backup_file.file_name, file_path);
    strcpy(backup_file.file_path, file_path);
    strcat(backup_file.file_path, BACKUP_EXT);
    backup_file.timestamp = time(NULL);
    FILE* backup_fp = fopen(backup_file.file_path, "w");
    if (backup_fp == NULL) {
        printf("Error: Failed to create backup file.\n");
        exit(1);
    }
    FILE* fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error: Failed to open file.\n");
        exit(1);
    }
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp)!= NULL) {
        fputs(buffer, backup_fp);
    }
    fclose(fp);
    fclose(backup_fp);
}

int main() {
    char file_path[MAX_FILE_PATH_LENGTH];
    printf("Enter file path: ");
    scanf("%s", file_path);
    create_backup_dir();
    backup_file(file_path);
    printf("Backup complete.\n");
    return 0;
}