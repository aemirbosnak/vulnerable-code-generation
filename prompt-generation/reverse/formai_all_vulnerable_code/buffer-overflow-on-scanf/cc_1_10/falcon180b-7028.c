//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10MB
#define BACKUP_DIR "backup"

typedef struct {
    char file_name[256];
    char backup_dir[256];
    char backup_name[256];
    char backup_ext[16];
    char backup_path[512];
    int file_size;
} file_t;

int create_backup_dir() {
    char cmd[256];
    sprintf(cmd, "mkdir -p %s", BACKUP_DIR);
    system(cmd);
    return 0;
}

int backup_file(file_t *file) {
    FILE *fp, *bfp;
    char ch;
    int count = 0;
    fp = fopen(file->file_name, "rb");
    if (fp == NULL) {
        printf("Error: Failed to open file %s\n", file->file_name);
        return 1;
    }
    sprintf(file->backup_name, "%d_%s", count, file->file_name);
    strcpy(file->backup_ext, ".bak");
    strcpy(file->backup_path, BACKUP_DIR);
    strcat(file->backup_path, "/");
    strcat(file->backup_path, file->backup_name);
    strcat(file->backup_path, file->backup_ext);
    bfp = fopen(file->backup_path, "wb");
    if (bfp == NULL) {
        printf("Error: Failed to create backup file %s\n", file->backup_path);
        fclose(fp);
        return 1;
    }
    while ((ch = fgetc(fp))!= EOF) {
        fputc(ch, bfp);
        count++;
        if (count >= MAX_FILE_SIZE) {
            printf("Warning: Backup file size limit reached for %s\n", file->file_name);
            break;
        }
    }
    fclose(fp);
    fclose(bfp);
    return 0;
}

int main() {
    file_t file;
    char file_name[256];
    printf("Enter file name: ");
    scanf("%s", file_name);
    strcpy(file.file_name, file_name);
    printf("Enter backup directory (leave blank for default): ");
    scanf("%s", file.backup_dir);
    if (file.backup_dir[0] == '\0') {
        strcpy(file.backup_dir, BACKUP_DIR);
    }
    create_backup_dir();
    backup_file(&file);
    printf("Backup completed for %s\n", file.file_name);
    return 0;
}