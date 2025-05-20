//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 100
#define BACKUP_DIR "backup/"
#define BACKUP_EXT ".bak"

typedef struct {
    char original_file_name[MAX_FILE_NAME_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];
} BackupFile;

void create_backup_dir() {
    char command[100];
    sprintf(command, "mkdir -p %s", BACKUP_DIR);
    system(command);
}

void create_backup_file_name(char* original_file_name, char* backup_file_name) {
    strcpy(backup_file_name, BACKUP_DIR);
    strcat(backup_file_name, original_file_name);
    strcat(backup_file_name, BACKUP_EXT);
}

int main() {
    create_backup_dir();

    BackupFile backup_file;
    printf("Enter the name of the file to backup: ");
    scanf("%s", backup_file.original_file_name);

    create_backup_file_name(backup_file.original_file_name, backup_file.backup_file_name);

    FILE* original_file = fopen(backup_file.original_file_name, "r");
    if (original_file == NULL) {
        printf("Error: Original file not found.\n");
        return 1;
    }

    FILE* backup_file_ptr = fopen(backup_file.backup_file_name, "w");
    if (backup_file_ptr == NULL) {
        printf("Error: Failed to create backup file.\n");
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), original_file)!= NULL) {
        fputs(buffer, backup_file_ptr);
    }

    fclose(original_file);
    fclose(backup_file_ptr);

    printf("Backup completed successfully.\n");

    return 0;
}