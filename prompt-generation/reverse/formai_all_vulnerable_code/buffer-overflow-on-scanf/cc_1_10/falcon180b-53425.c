//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_BACKUP_FILES 10

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    time_t last_modified;
} FileInfo;

void backupFile(char* file_name) {
    FILE* original_file = fopen(file_name, "rb");
    if (original_file == NULL) {
        printf("Error: Could not open file %s for backup.\n", file_name);
        return;
    }

    char backup_file_name[MAX_FILE_NAME_LENGTH];
    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, ".bak");

    FILE* backup_file = fopen(backup_file_name, "wb");
    if (backup_file == NULL) {
        printf("Error: Could not create backup file %s.\n", backup_file_name);
        fclose(original_file);
        return;
    }

    char buffer[4096];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), original_file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);

    printf("Backup of file %s created successfully.\n", file_name);
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter file name to backup: ");
    scanf("%s", file_name);

    backupFile(file_name);

    return 0;
}