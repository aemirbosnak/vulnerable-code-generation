//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_BACKUP_DIR_LEN 100
#define MAX_BACKUP_FILE_NAME_LEN 200

typedef struct backup_file {
    char file_name[MAX_FILE_NAME_LEN];
    time_t file_time;
    struct backup_file *next;
} BackupFile;

typedef struct backup_dir {
    char dir_name[MAX_BACKUP_DIR_LEN];
    BackupFile *file_list;
} BackupDir;

void add_backup_file(BackupDir *dir, char *file_name) {
    BackupFile *file = (BackupFile *)malloc(sizeof(BackupFile));
    strcpy(file->file_name, file_name);
    file->file_time = time(NULL);
    file->next = NULL;

    if (dir->file_list == NULL) {
        dir->file_list = file;
    } else {
        BackupFile *last_file = dir->file_list;
        while (last_file->next!= NULL) {
            last_file = last_file->next;
        }
        last_file->next = file;
    }
}

void print_backup_files(BackupDir *dir) {
    BackupFile *file = dir->file_list;
    while (file!= NULL) {
        printf("%s (%ld)\n", file->file_name, file->file_time);
        file = file->next;
    }
}

int main() {
    BackupDir backup_dir;
    strcpy(backup_dir.dir_name, "backup_dir");

    add_backup_file(&backup_dir, "file1.txt");
    add_backup_file(&backup_dir, "file2.txt");

    print_backup_files(&backup_dir);

    return 0;
}