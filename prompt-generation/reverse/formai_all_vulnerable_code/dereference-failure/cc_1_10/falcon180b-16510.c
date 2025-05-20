//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_LINE_LEN 1000
#define MAX_BACKUP_FILES 10

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    FILE *file;
} File;

typedef struct {
    File *files[MAX_BACKUP_FILES];
    int num_files;
} Backup;

void backup_file(char *file_name, Backup *backup) {
    int i;
    for (i = 0; i < backup->num_files; i++) {
        if (strcmp(backup->files[i]->file_name, file_name) == 0) {
            return;
        }
    }
    if (backup->num_files >= MAX_BACKUP_FILES) {
        printf("Error: Maximum number of backup files reached.\n");
        return;
    }
    File *new_file = malloc(sizeof(File));
    strcpy(new_file->file_name, file_name);
    new_file->file = fopen(file_name, "r");
    if (new_file->file == NULL) {
        printf("Error: Could not open file for backup.\n");
        free(new_file);
        return;
    }
    backup->files[backup->num_files] = new_file;
    backup->num_files++;
}

void restore_file(char *file_name, Backup *backup) {
    int i;
    for (i = 0; i < backup->num_files; i++) {
        if (strcmp(backup->files[i]->file_name, file_name) == 0) {
            char line[MAX_LINE_LEN];
            while (fgets(line, MAX_LINE_LEN, backup->files[i]->file)!= NULL) {
                printf("%s", line);
            }
            fclose(backup->files[i]->file);
            free(backup->files[i]);
            backup->files[i] = NULL;
            backup->num_files--;
            return;
        }
    }
    printf("Error: File not found in backup.\n");
}

void list_files(Backup *backup) {
    int i;
    for (i = 0; i < backup->num_files; i++) {
        printf("%s\n", backup->files[i]->file_name);
    }
}

int main() {
    Backup backup;
    backup.num_files = 0;
    backup_file("example.txt", &backup);
    backup_file("example2.txt", &backup);
    list_files(&backup);
    restore_file("example.txt", &backup);
    list_files(&backup);
    return 0;
}