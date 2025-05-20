//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_BACKUP_FILES 10

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    int backup_count;
} backup_file_t;

backup_file_t backup_files[MAX_BACKUP_FILES];
int num_backup_files = 0;

void add_backup_file(char* file_name) {
    backup_file_t* backup_file = &backup_files[num_backup_files];
    strcpy(backup_file->file_name, file_name);
    sprintf(backup_file->backup_file_name, "%s.bak", file_name);
    backup_file->backup_count = 0;
    num_backup_files++;
}

void backup_file(char* file_name) {
    int i;
    for (i = 0; i < num_backup_files; i++) {
        if (strcmp(backup_files[i].file_name, file_name) == 0) {
            sprintf(backup_files[i].backup_file_name, "%s.%d.bak", file_name, backup_files[i].backup_count + 1);
            backup_files[i].backup_count++;
            return;
        }
    }
    add_backup_file(file_name);
}

void restore_file(char* file_name) {
    int i;
    for (i = 0; i < num_backup_files; i++) {
        if (strcmp(backup_files[i].file_name, file_name) == 0) {
            sprintf(backup_files[i].backup_file_name, "%s.%d.bak", file_name, backup_files[i].backup_count - 1);
            rename(backup_files[i].backup_file_name, file_name);
            return;
        }
    }
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    while (1) {
        printf("Enter file name to backup: ");
        scanf("%s", file_name);
        backup_file(file_name);
    }
    return 0;
}