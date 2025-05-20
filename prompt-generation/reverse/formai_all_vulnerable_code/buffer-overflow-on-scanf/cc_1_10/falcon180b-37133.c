//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LEN 100
#define MAX_FILE_PATH_LEN 256

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    char file_path[MAX_FILE_PATH_LEN];
    time_t last_backup_time;
} FileBackup;

FileBackup backups[MAX_FILES];
int num_backups = 0;

void add_backup(const char* file_name, const char* file_path) {
    if (num_backups >= MAX_FILES) {
        printf("Error: Maximum number of backups reached.\n");
        return;
    }

    strcpy(backups[num_backups].file_name, file_name);
    strcpy(backups[num_backups].file_path, file_path);
    time(&backups[num_backups].last_backup_time);

    num_backups++;
}

void list_backups() {
    printf("List of backups:\n");
    for (int i = 0; i < num_backups; i++) {
        printf("Backup #%d:\n", i+1);
        printf("File name: %s\n", backups[i].file_name);
        printf("File path: %s\n", backups[i].file_path);
        printf("Last backup time: %s\n\n", ctime(&backups[i].last_backup_time));
    }
}

void backup_file(const char* file_name, const char* file_path) {
    FILE* fp;
    char backup_path[MAX_FILE_PATH_LEN];

    sprintf(backup_path, "%s.bak", file_path);

    fp = fopen(backup_path, "w");
    if (fp == NULL) {
        printf("Error: Failed to create backup file.\n");
        return;
    }

    FILE* src_fp = fopen(file_path, "r");
    if (src_fp == NULL) {
        printf("Error: Failed to open source file.\n");
        fclose(fp);
        remove(backup_path);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), src_fp)!= NULL) {
        fputs(buffer, fp);
    }

    fclose(src_fp);
    fclose(fp);

    add_backup(file_name, backup_path);
}

int main() {
    char file_name[MAX_FILE_NAME_LEN];
    char file_path[MAX_FILE_PATH_LEN];

    printf("Enter file name: ");
    scanf("%s", file_name);

    printf("Enter file path: ");
    scanf("%s", file_path);

    backup_file(file_name, file_path);

    list_backups();

    return 0;
}