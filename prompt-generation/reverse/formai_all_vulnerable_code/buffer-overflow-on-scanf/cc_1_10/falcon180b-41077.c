//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 256
#define BACKUP_DIR "./backup"
#define MAX_BACKUP_FILES 10

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    time_t timestamp;
} BackupFile;

void backup_file(char *file_path) {
    FILE *file;
    char backup_path[MAX_FILE_NAME_LENGTH];
    BackupFile backup_file;
    time_t current_time;

    current_time = time(NULL);
    strcpy(backup_file.file_name, file_path);
    backup_file.timestamp = current_time;

    strcpy(backup_path, BACKUP_DIR);
    strcat(backup_path, "/");
    strcat(backup_path, backup_file.file_name);
    strcat(backup_path, ".bak");

    file = fopen(backup_path, "w");
    if (file == NULL) {
        printf("Error creating backup file: %s\n", backup_path);
        return;
    }

    file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", file_path);
        fclose(file);
        remove(backup_path);
        return;
    }

    char buffer[4096];
    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        fputs(buffer, file);
    }

    fclose(file);
    fclose(file);
}

int main() {
    char file_path[MAX_FILE_NAME_LENGTH];
    printf("Enter file path: ");
    scanf("%s", file_path);

    backup_file(file_path);

    return 0;
}