//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME 100

struct File {
    char name[MAX_FILE_NAME];
    FILE *fp;
};

void backup_files(struct File *files, int count) {
    char backup_dir[MAX_FILE_NAME];
    strcpy(backup_dir, "backup/");
    mkdir(backup_dir, 0777);

    for (int i = 0; i < count; i++) {
        char backup_file[MAX_FILE_NAME];
        sprintf(backup_file, "%s%s", backup_dir, files[i].name);

        if (strcmp(files[i].name, backup_file)!= 0) {
            FILE *backup_fp = fopen(backup_file, "w");

            if (backup_fp == NULL) {
                printf("Error creating backup file: %s\n", backup_file);
                exit(1);
            }

            char buffer[1024];
            while (fgets(buffer, sizeof(buffer), files[i].fp)!= NULL) {
                fputs(buffer, backup_fp);
            }

            fclose(backup_fp);
        }
    }
}

int main() {
    struct File files[MAX_FILES];
    int count = 0;

    printf("Enter the file names to be backed up (enter 'done' when finished):\n");

    while (count < MAX_FILES && scanf("%s", files[count].name)!= EOF) {
        if (strcmp(files[count].name, "done") == 0) {
            break;
        }

        files[count].fp = fopen(files[count].name, "r");

        if (files[count].fp == NULL) {
            printf("Error opening file: %s\n", files[count].name);
            exit(1);
        }

        count++;
    }

    backup_files(files, count);

    for (int i = 0; i < count; i++) {
        fclose(files[i].fp);
    }

    return 0;
}