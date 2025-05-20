//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_SIZE 100
#define MAX_BACKUP_DIR_SIZE 100
#define MAX_BACKUP_FILE_SIZE 100

typedef struct backup_file {
    char file_name[MAX_FILE_NAME_SIZE];
    char backup_dir[MAX_BACKUP_DIR_SIZE];
    char backup_file_name[MAX_BACKUP_FILE_SIZE];
    time_t backup_time;
} BackupFile;

void backup_file(char *file_name, char *backup_dir) {
    BackupFile backup_file;
    strcpy(backup_file.file_name, file_name);
    strcpy(backup_file.backup_dir, backup_dir);

    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    sprintf(backup_file.backup_file_name, "%s/%04d%02d%02d_%02d%02d%02d_%s.bak",
            backup_file.backup_dir,
            tm_now->tm_year + 1900,
            tm_now->tm_mon + 1,
            tm_now->tm_mday,
            tm_now->tm_hour,
            tm_now->tm_min,
            tm_now->tm_sec,
            backup_file.file_name);

    FILE *backup_file_ptr = fopen(backup_file.backup_file_name, "wb");
    if (backup_file_ptr == NULL) {
        printf("Error: could not create backup file '%s'\n", backup_file.backup_file_name);
        exit(1);
    }

    FILE *original_file_ptr = fopen(file_name, "rb");
    if (original_file_ptr == NULL) {
        printf("Error: could not open original file '%s'\n", file_name);
        fclose(backup_file_ptr);
        exit(1);
    }

    char buffer[1024];
    while (fread(buffer, sizeof(char), sizeof(buffer), original_file_ptr) > 0) {
        fwrite(buffer, sizeof(char), sizeof(buffer), backup_file_ptr);
    }

    fclose(original_file_ptr);
    fclose(backup_file_ptr);

    printf("Backup of '%s' created: '%s'\n", file_name, backup_file.backup_file_name);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <file_name> <backup_dir>\n", argv[0]);
        return 1;
    }

    backup_file(argv[1], argv[2]);

    return 0;
}