//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_BACKUP_DIR_LENGTH 256
#define MAX_FILES_TO_BACKUP 100

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_dir[MAX_BACKUP_DIR_LENGTH];
    int priority;
} FileBackup;

void read_files_to_backup(FileBackup *files_to_backup, int num_files) {
    for (int i = 0; i < num_files; i++) {
        printf("Enter file name for backup #%d: ", i+1);
        scanf("%s", files_to_backup[i].file_name);

        printf("Enter backup directory for %s: ", files_to_backup[i].file_name);
        scanf("%s", files_to_backup[i].backup_dir);

        printf("Enter priority for %s (1-10): ", files_to_backup[i].file_name);
        scanf("%d", &files_to_backup[i].priority);
    }
}

void backup_files(FileBackup *files_to_backup, int num_files) {
    for (int i = 0; i < num_files; i++) {
        char backup_path[MAX_BACKUP_DIR_LENGTH + strlen(files_to_backup[i].file_name) + 2];
        strcpy(backup_path, files_to_backup[i].backup_dir);
        strcat(backup_path, "/");
        strcat(backup_path, files_to_backup[i].file_name);

        printf("Backing up %s to %s\n", files_to_backup[i].file_name, backup_path);
    }
}

int main() {
    int num_files;

    printf("Enter number of files to backup: ");
    scanf("%d", &num_files);

    FileBackup files_to_backup[MAX_FILES_TO_BACKUP];
    read_files_to_backup(files_to_backup, num_files);

    backup_files(files_to_backup, num_files);

    return 0;
}