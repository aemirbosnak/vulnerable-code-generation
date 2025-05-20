//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_BACKUP_DIR_LEN 256

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    char backup_dir[MAX_BACKUP_DIR_LEN];
} FileBackup;

int main() {
    int num_files;
    FileBackup *files;

    // Get number of files to backup
    printf("Enter number of files to backup: ");
    scanf("%d", &num_files);

    // Allocate memory for file backup structs
    files = (FileBackup *)malloc(num_files * sizeof(FileBackup));

    // Get file names and backup directory
    for (int i = 0; i < num_files; i++) {
        printf("Enter file name for file %d: ", i + 1);
        scanf("%s", files[i].file_name);

        printf("Enter backup directory for file %s: ", files[i].file_name);
        scanf("%s", files[i].backup_dir);
    }

    // Backup files
    for (int i = 0; i < num_files; i++) {
        char backup_file_path[MAX_BACKUP_DIR_LEN + strlen(files[i].file_name) + 2];
        strcpy(backup_file_path, files[i].backup_dir);
        strcat(backup_file_path, "/");
        strcat(backup_file_path, files[i].file_name);

        FILE *backup_file = fopen(backup_file_path, "w");

        if (backup_file == NULL) {
            printf("Error: Could not create backup file %s\n", backup_file_path);
            continue;
        }

        FILE *input_file = fopen(files[i].file_name, "r");

        if (input_file == NULL) {
            printf("Error: Could not open input file %s\n", files[i].file_name);
            fclose(backup_file);
            continue;
        }

        char buffer[4096];
        int bytes_read;

        while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), input_file)) > 0) {
            fwrite(buffer, sizeof(char), bytes_read, backup_file);
        }

        fclose(input_file);
        fclose(backup_file);

        printf("File %s backed up to %s\n", files[i].file_name, backup_file_path);
    }

    free(files);

    return 0;
}