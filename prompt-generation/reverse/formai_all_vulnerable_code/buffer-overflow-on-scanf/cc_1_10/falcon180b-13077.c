//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_LENGTH 100
#define MAX_BACKUP_DIR_LENGTH 200
#define MAX_BACKUP_FILES 100

typedef struct {
    char file_name[MAX_FILE_LENGTH];
    char backup_dir[MAX_BACKUP_DIR_LENGTH];
    int num_backups;
} BackupFile;

void backup_file(char *file_path, char *backup_dir, int num_backups) {
    FILE *file, *backup_file;
    char backup_file_path[MAX_FILE_LENGTH];
    int i;

    strcpy(backup_file_path, backup_dir);
    strcat(backup_file_path, "/");
    strcat(backup_file_path, file_path);

    for (i = 0; i < num_backups; i++) {
        strcat(backup_file_path, ".bak");
        backup_file = fopen(backup_file_path, "w");
        if (backup_file == NULL) {
            printf("Error creating backup file: %s\n", backup_file_path);
            exit(1);
        }
        file = fopen(file_path, "r");
        if (file == NULL) {
            printf("Error opening file: %s\n", file_path);
            exit(1);
        }
        while ((fgetc(file))!= EOF) {
            fputc(fgetc(file), backup_file);
        }
        fclose(file);
        fclose(backup_file);
    }
}

int main() {
    BackupFile backup_files[MAX_BACKUP_FILES];
    int num_files, i;

    printf("Enter the number of files to backup: ");
    scanf("%d", &num_files);

    for (i = 0; i < num_files; i++) {
        printf("Enter the file path for file %d: ", i+1);
        scanf("%s", backup_files[i].file_name);
        printf("Enter the backup directory for file %d: ", i+1);
        scanf("%s", backup_files[i].backup_dir);
        printf("Enter the number of backups for file %d: ", i+1);
        scanf("%d", &backup_files[i].num_backups);
    }

    for (i = 0; i < num_files; i++) {
        backup_file(backup_files[i].file_name, backup_files[i].backup_dir, backup_files[i].num_backups);
    }

    return 0;
}