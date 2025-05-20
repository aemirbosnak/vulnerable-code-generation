//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LEN 255
#define MAX_PATH_LEN 1024
#define BUFFER_SIZE 1024

typedef struct {
    char *file_name;
    char *backup_file_name;
    FILE *file;
    FILE *backup_file;
} FileBackup;

void init_file_backup(FileBackup *fb, char *file_name, char *backup_file_name) {
    fb->file_name = file_name;
    fb->backup_file_name = backup_file_name;
    fb->file = NULL;
    fb->backup_file = NULL;
}

int create_backup_file(FileBackup *fb) {
    char *path = malloc(MAX_PATH_LEN);
    strcpy(path, fb->backup_file_name);
    char *dir = strrchr(path, '/');
    if (dir!= NULL) {
        *dir = '\0';
        mkdir(path, 0777);
        *dir = '/';
    }
    fb->backup_file = fopen(path, "w");
    if (fb->backup_file == NULL) {
        printf("Error: Failed to create backup file.\n");
        return -1;
    }
    return 0;
}

int backup_file(FileBackup *fb) {
    if (fb->file == NULL || fb->backup_file == NULL) {
        printf("Error: File or backup file not opened.\n");
        return -1;
    }
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, fb->file)!= NULL) {
        fputs(buffer, fb->backup_file);
    }
    fclose(fb->file);
    fclose(fb->backup_file);
    return 0;
}

int main() {
    char *file_name = "example.txt";
    char *backup_file_name = "example.txt.bak";
    FileBackup fb;
    init_file_backup(&fb, file_name, backup_file_name);
    fb.file = fopen(file_name, "r");
    if (fb.file == NULL) {
        printf("Error: Failed to open file.\n");
        return -1;
    }
    if (create_backup_file(&fb)!= 0) {
        return -1;
    }
    if (backup_file(&fb)!= 0) {
        return -1;
    }
    printf("File backed up successfully.\n");
    return 0;
}