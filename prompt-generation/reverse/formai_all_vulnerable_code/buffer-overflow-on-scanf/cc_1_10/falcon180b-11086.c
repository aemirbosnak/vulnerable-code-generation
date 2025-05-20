//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 256

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    char backup_file_name[MAX_FILE_NAME_LEN];
    FILE *fp;
    FILE *backup_fp;
} FileBackup;

void init_file_backup(FileBackup *fb, char *file_name) {
    strcpy(fb->file_name, file_name);
    strcat(fb->backup_file_name, ".bak");
    fb->fp = fopen(file_name, "r+");
    if (fb->fp == NULL) {
        printf("Error opening file: %s\n", file_name);
        exit(1);
    }
    fb->backup_fp = fopen(fb->backup_file_name, "w+");
    if (fb->backup_fp == NULL) {
        printf("Error opening backup file: %s\n", fb->backup_file_name);
        exit(1);
    }
    fb->backup_fp = freopen(fb->backup_file_name, "w+", fb->backup_fp);
}

void backup_file(FileBackup *fb) {
    char ch;
    rewind(fb->fp);
    rewind(fb->backup_fp);
    while ((ch = fgetc(fb->fp))!= EOF) {
        fputc(ch, fb->backup_fp);
    }
}

void restore_file(FileBackup *fb) {
    char ch;
    rewind(fb->fp);
    rewind(fb->backup_fp);
    while ((ch = fgetc(fb->backup_fp))!= EOF) {
        fputc(ch, fb->fp);
    }
}

int main() {
    char file_name[MAX_FILE_NAME_LEN];
    printf("Enter file name: ");
    scanf("%s", file_name);
    FileBackup fb;
    init_file_backup(&fb, file_name);
    while (1) {
        printf("1. Backup file\n2. Restore file\n3. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                backup_file(&fb);
                printf("File backed up successfully!\n");
                break;
            case 2:
                restore_file(&fb);
                printf("File restored successfully!\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}