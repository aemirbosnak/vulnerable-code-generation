//FormAI DATASET v1.0 Category: File Backup System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 100
#define MAX_BACKUPS 5

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int num_backups;
    char backups[MAX_BACKUPS][MAX_FILENAME_LENGTH];
} File;

File files[MAX_FILES];
int num_files = 0;

void backup_file(File *file) {
    if (file->num_backups == MAX_BACKUPS) {
        // remove oldest backup
        remove(file->backups[0]);
        // shift backups back
        for (int i = 1; i < MAX_BACKUPS; i++) {
            strcpy(file->backups[i-1], file->backups[i]);
        }
        // add new backup
        char backup_filename[MAX_FILENAME_LENGTH];
        sprintf(backup_filename, "%s_b%d", file->filename, file->num_backups);
        strcpy(file->backups[MAX_BACKUPS-1], backup_filename);
    } else {
        char backup_filename[MAX_FILENAME_LENGTH];
        sprintf(backup_filename, "%s_b%d", file->filename, file->num_backups);
        strcpy(file->backups[file->num_backups], backup_filename);
        file->num_backups++;
    }
    // actually backup the file
    char command[MAX_FILENAME_LENGTH + 20];
    sprintf(command, "cp %s %s", file->filename, file->backups[file->num_backups-1]);
    system(command);
}

void backup_all_files() {
    for (int i = 0; i < num_files; i++) {
        backup_file(&files[i]);
    }
}

void add_file(char *filename) {
    if (num_files == MAX_FILES) {
        printf("Error: maximum number of files exceeded.\n");
        return;
    }
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            printf("Error: file %s already added.\n", filename);
            return;
        }
    }
    File new_file;
    strcpy(new_file.filename, filename);
    new_file.num_backups = 0;
    files[num_files] = new_file;
    num_files++;
}

int main() {
    char input[MAX_FILENAME_LENGTH];
    while (1) {
        printf("Enter command: ");
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            printf("Enter filename: ");
            scanf("%s", input);
            add_file(input);
        } else if (strcmp(input, "backup") == 0) {
            backup_all_files();
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Error: invalid command.\n");
        }
    }
    return 0;
}