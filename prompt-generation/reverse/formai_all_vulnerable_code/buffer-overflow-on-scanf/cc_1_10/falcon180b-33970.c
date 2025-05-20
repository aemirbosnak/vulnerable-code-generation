//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define BACKUP_DIR "backup"

typedef struct {
    char original_file_name[MAX_FILE_NAME_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];
} file_backup_t;

int create_backup_dir() {
    char command[100] = "mkdir ";
    strcat(command, BACKUP_DIR);
    system(command);
    return 0;
}

int backup_file(char* file_name) {
    char backup_file_path[100];
    strcpy(backup_file_path, BACKUP_DIR);
    strcat(backup_file_path, "/");
    strcat(backup_file_path, file_name);

    FILE* backup_file = fopen(backup_file_path, "w");
    if (backup_file == NULL) {
        printf("Error: Could not create backup file.\n");
        return -1;
    }

    FILE* original_file = fopen(file_name, "r");
    if (original_file == NULL) {
        printf("Error: Could not open original file.\n");
        fclose(backup_file);
        remove(backup_file_path);
        return -1;
    }

    char buffer[100];
    while (fgets(buffer, 100, original_file)!= NULL) {
        fputs(buffer, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);
    return 0;
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter the name of the file to be backed up: ");
    scanf("%s", file_name);

    create_backup_dir();

    file_backup_t backup_info;
    strcpy(backup_info.original_file_name, file_name);
    strcpy(backup_info.backup_file_name, file_name);
    strcat(backup_info.backup_file_name, ".bak");

    backup_file(backup_info.original_file_name);
    printf("Backup created: %s\n", backup_info.backup_file_name);

    return 0;
}