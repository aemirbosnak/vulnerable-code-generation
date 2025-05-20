//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 256
#define BACKUP_DIR "backup"

typedef struct {
    char original_file_name[MAX_FILE_NAME_LENGTH];
    time_t backup_time;
} BackupFile;

int main() {
    char original_file_name[MAX_FILE_NAME_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    char backup_dir_path[MAX_FILE_NAME_LENGTH];
    BackupFile backup_file;

    printf("Enter the name of the file to backup: ");
    scanf("%s", original_file_name);

    strcpy(backup_file.original_file_name, original_file_name);
    time(&backup_file.backup_time);

    sprintf(backup_dir_path, "%s/%s", BACKUP_DIR, original_file_name);
    mkdir(backup_dir_path, 0777);

    sprintf(backup_file_name, "%s/%ld.bak", backup_dir_path, backup_file.backup_time);

    FILE *original_file = fopen(original_file_name, "rb");
    if (original_file == NULL) {
        printf("Error: Could not open the original file.\n");
        return 1;
    }

    FILE *backup_file_ptr = fopen(backup_file_name, "wb");
    if (backup_file_ptr == NULL) {
        printf("Error: Could not create the backup file.\n");
        fclose(original_file);
        return 1;
    }

    char buffer[1024];
    while (fread(buffer, sizeof(char), sizeof(buffer), original_file) > 0) {
        fwrite(buffer, sizeof(char), sizeof(buffer), backup_file_ptr);
    }

    fclose(original_file);
    fclose(backup_file_ptr);

    printf("Backup completed successfully.\n");

    return 0;
}