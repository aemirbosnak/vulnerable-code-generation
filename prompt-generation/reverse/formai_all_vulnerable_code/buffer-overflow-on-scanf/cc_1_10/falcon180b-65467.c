//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct {
    char filename[100];
    char backup_dir[100];
} FILE_BACKUP;

void create_backup_dir(char* dir_path) {
    mkdir(dir_path, 0777);
}

FILE_BACKUP* create_file_backup(char* filename, char* backup_dir) {
    FILE_BACKUP* file_backup = (FILE_BACKUP*)malloc(sizeof(FILE_BACKUP));
    strcpy(file_backup->filename, filename);
    strcpy(file_backup->backup_dir, backup_dir);
    return file_backup;
}

void backup_file(FILE_BACKUP* file_backup) {
    char backup_path[200];
    sprintf(backup_path, "%s/%s.%ld", file_backup->backup_dir, file_backup->filename, time(NULL));
    rename(file_backup->filename, backup_path);
}

int main() {
    FILE_BACKUP* file_backup = NULL;
    char filename[100] = {0};
    char backup_dir[100] = {0};

    printf("Enter filename: ");
    scanf("%s", filename);

    printf("Enter backup directory: ");
    scanf("%s", backup_dir);

    create_backup_dir(backup_dir);

    file_backup = create_file_backup(filename, backup_dir);

    backup_file(file_backup);

    printf("File backed up successfully!\n");

    return 0;
}