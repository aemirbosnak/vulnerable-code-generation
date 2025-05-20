//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_PATH_LENGTH 1000
#define MAX_BACKUP_DIRECTORY_LENGTH 100

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char path[MAX_PATH_LENGTH];
    char backup_directory[MAX_BACKUP_DIRECTORY_LENGTH];
} File;

void backup_file(File* file) {
    char backup_path[MAX_PATH_LENGTH];
    strcpy(backup_path, file->backup_directory);
    strcat(backup_path, "/");
    strcat(backup_path, file->file_name);

    FILE* backup_file = fopen(backup_path, "w");

    if (backup_file == NULL) {
        printf("Error: Could not create backup file.\n");
        return;
    }

    FILE* original_file = fopen(file->path, "r");

    if (original_file == NULL) {
        printf("Error: Could not open original file.\n");
        fclose(backup_file);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), original_file)!= NULL) {
        fputs(buffer, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);
}

int main() {
    File file;
    printf("Enter the file name: ");
    scanf("%s", file.file_name);

    printf("Enter the file path: ");
    scanf("%s", file.path);

    printf("Enter the backup directory: ");
    scanf("%s", file.backup_directory);

    backup_file(&file);

    return 0;
}