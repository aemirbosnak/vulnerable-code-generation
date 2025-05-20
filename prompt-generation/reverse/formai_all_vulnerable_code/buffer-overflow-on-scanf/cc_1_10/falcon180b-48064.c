//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_BACKUP_FILES 10

struct backup_file {
    char file_name[MAX_FILE_NAME_LENGTH];
    time_t backup_time;
    struct backup_file *next;
};

struct backup_file *backup_files = NULL;

void add_backup_file(char *file_name) {
    struct backup_file *new_backup_file = (struct backup_file *)malloc(sizeof(struct backup_file));
    strncpy(new_backup_file->file_name, file_name, MAX_FILE_NAME_LENGTH);
    new_backup_file->backup_time = time(NULL);
    new_backup_file->next = NULL;

    if (backup_files == NULL) {
        backup_files = new_backup_file;
    } else {
        struct backup_file *current_backup_file = backup_files;
        while (current_backup_file->next!= NULL) {
            current_backup_file = current_backup_file->next;
        }
        current_backup_file->next = new_backup_file;
    }
}

void print_backup_files() {
    struct backup_file *current_backup_file = backup_files;
    while (current_backup_file!= NULL) {
        printf("File name: %s\n", current_backup_file->file_name);
        printf("Backup time: %s\n", ctime(&current_backup_file->backup_time));
        printf("\n");
        current_backup_file = current_backup_file->next;
    }
}

int main() {
    int i, choice;

    do {
        printf("\n1. Add backup file\n");
        printf("2. Print backup files\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", backup_files->file_name);
                break;
            case 2:
                print_backup_files();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}