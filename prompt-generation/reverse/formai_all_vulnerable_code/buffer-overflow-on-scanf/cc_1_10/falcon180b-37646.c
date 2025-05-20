//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 //10MB
#define MAX_BACKUP_FILES 10
#define BACKUP_DIR "backup"

typedef struct backup_file {
    char name[100];
    time_t timestamp;
    FILE *fp;
} backup_file_t;

backup_file_t backup_files[MAX_BACKUP_FILES];
int num_backup_files = 0;

void create_backup_dir() {
    char cmd[100];
    sprintf(cmd, "mkdir -p %s", BACKUP_DIR);
    system(cmd);
}

int get_free_backup_file() {
    for (int i = 0; i < num_backup_files; i++) {
        if (backup_files[i].fp == NULL) {
            return i;
        }
    }
    return -1; //no free backup file found
}

void backup_file(char *filename) {
    backup_file_t *bf = &backup_files[num_backup_files++];
    strcpy(bf->name, filename);
    bf->timestamp = time(NULL);
    char backup_filename[100];
    sprintf(backup_filename, "%s/%s_%ld.bak", BACKUP_DIR, filename, bf->timestamp);
    bf->fp = fopen(backup_filename, "w");
    if (bf->fp == NULL) {
        printf("Error creating backup file %s\n", backup_filename);
        exit(1);
    }
}

void close_backup_files() {
    for (int i = 0; i < num_backup_files; i++) {
        if (backup_files[i].fp!= NULL) {
            fclose(backup_files[i].fp);
            backup_files[i].fp = NULL;
        }
    }
}

int main() {
    create_backup_dir();
    char filename[100];
    printf("Enter filename to backup: ");
    scanf("%s", filename);
    backup_file(filename);
    printf("Backup completed!\n");
    close_backup_files();
    return 0;
}