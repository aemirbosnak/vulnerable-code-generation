//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 256
#define BACKUP_EXTENSION ".bak"

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    char backup_name[MAX_FILE_NAME_LEN];
} FileInfo;

void backup_file(FileInfo *file_info) {
    char backup_path[MAX_FILE_NAME_LEN];
    strcpy(backup_path, file_info->file_name);
    strcat(backup_path, BACKUP_EXTENSION);

    FILE *backup_file = fopen(backup_path, "w");
    if (backup_file == NULL) {
        printf("Error creating backup file %s\n", backup_path);
        exit(1);
    }

    FILE *original_file = fopen(file_info->file_name, "r");
    if (original_file == NULL) {
        printf("Error opening original file %s\n", file_info->file_name);
        exit(1);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), original_file)!= NULL) {
        fputs(buffer, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    FileInfo file_info;
    strcpy(file_info.file_name, argv[1]);
    strcpy(file_info.backup_name, argv[1]);
    strcat(file_info.backup_name, BACKUP_EXTENSION);

    backup_file(&file_info);

    printf("Backup of %s created as %s\n", file_info.file_name, file_info.backup_name);

    return 0;
}