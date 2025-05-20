//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_BACKUP_DIR_LEN 100
#define MAX_BACKUP_FILES 100

struct backup_file {
    char file_name[MAX_FILE_NAME_LEN];
    time_t backup_time;
};

void backup_file(char *file_name, char *backup_dir) {
    struct backup_file backup_file;
    strcpy(backup_file.file_name, file_name);
    time(&backup_file.backup_time);

    FILE *fp = fopen(backup_dir, "a");
    if (fp == NULL) {
        printf("Error: Unable to open backup directory.\n");
        exit(1);
    }

    fprintf(fp, "%s %ld\n", backup_file.file_name, backup_file.backup_time);
    fclose(fp);
}

void list_backups(char *backup_dir) {
    FILE *fp = fopen(backup_dir, "r");
    if (fp == NULL) {
        printf("Error: Unable to open backup directory.\n");
        exit(1);
    }

    char line[MAX_FILE_NAME_LEN + 20];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        printf("%s", line);
    }

    fclose(fp);
}

void restore_file(char *backup_dir, char *file_name) {
    char backup_file_name[MAX_FILE_NAME_LEN];
    sprintf(backup_file_name, "%s/%s", backup_dir, file_name);

    FILE *fp = fopen(backup_file_name, "r");
    if (fp == NULL) {
        printf("Error: Backup file not found.\n");
        exit(1);
    }

    char line[MAX_FILE_NAME_LEN + 20];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        printf("%s", line);
    }

    fclose(fp);
}

int main() {
    char backup_dir[MAX_BACKUP_DIR_LEN];
    printf("Enter backup directory: ");
    scanf("%s", backup_dir);

    char file_name[MAX_FILE_NAME_LEN];
    printf("Enter file name to backup: ");
    scanf("%s", file_name);

    backup_file(file_name, backup_dir);
    printf("File backed up successfully.\n");

    list_backups(backup_dir);

    char restore_file_name[MAX_FILE_NAME_LEN];
    printf("Enter file name to restore: ");
    scanf("%s", restore_file_name);

    restore_file(backup_dir, restore_file_name);

    return 0;
}