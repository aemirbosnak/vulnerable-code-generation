//FormAI DATASET v1.0 Category: File Backup System ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_BACKUP_FILES 10

typedef struct Backup_File {
    char filename[MAX_FILENAME_LENGTH];
    int version;
} Backup_File;

Backup_File backup_files[MAX_BACKUP_FILES];
int num_backup_files = 0;

void backup(char *filename) {
    int i, file_index = -1;
    // Check if file is already backed up
    for(i = 0; i < num_backup_files; i++) {
        if(strcmp(filename, backup_files[i].filename) == 0) {
            file_index = i;
            break;
        }
    }
    if(file_index == -1) {
        // File not backed up yet, add to backups array
        strncpy(backup_files[num_backup_files].filename, filename, MAX_FILENAME_LENGTH);
        backup_files[num_backup_files].version = 1;
        num_backup_files++;
    } else {
        // File already backed up, increase version and print confirmation message
        backup_files[file_index].version++;
        printf("%s backed up with version %d\n", filename, backup_files[file_index].version);
    }
}

void print_backups() {
    int i;
    printf("List of backup files:\n");
    for(i = 0; i < num_backup_files; i++) {
        printf("%s, version %d\n", backup_files[i].filename, backup_files[i].version);
    }
}

int main() {
    int choice = 0;
    char filename[MAX_FILENAME_LENGTH];
    while(choice != 3) {
        printf("1. Backup file\n");
        printf("2. View backups\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter filename to backup: ");
                scanf("%s", filename);
                backup(filename);
                break;
            case 2:
                print_backups();
                break;
            case 3:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    }
    return 0;
}