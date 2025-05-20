//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    time_t last_modified;
    char backup_file_name[MAX_FILE_NAME_LENGTH];
} FileBackup;

void backup_file(FileBackup* file) {
    char* backup_path = malloc(strlen(file->file_name) + 5);
    strcpy(backup_path, file->file_name);
    strcat(backup_path, ".bak");

    FILE* backup_file = fopen(backup_path, "wb");
    if (backup_file == NULL) {
        printf("Error creating backup file: %s\n", backup_path);
        return;
    }

    FILE* input_file = fopen(file->file_name, "rb");
    if (input_file == NULL) {
        printf("Error opening input file: %s\n", file->file_name);
        fclose(backup_file);
        return;
    }

    char buffer[1024];
    while (fread(buffer, sizeof(char), sizeof(buffer), input_file) > 0) {
        fwrite(buffer, sizeof(char), sizeof(buffer), backup_file);
    }

    fclose(input_file);
    fclose(backup_file);
}

int main() {
    FileBackup file_backup;

    printf("Enter the file name to backup: ");
    scanf("%s", file_backup.file_name);

    file_backup.last_modified = time(NULL);

    strcpy(file_backup.backup_file_name, file_backup.file_name);
    strcat(file_backup.backup_file_name, ".bak");

    backup_file(&file_backup);

    return 0;
}