//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_BACKUP_FILES 100

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    time_t timestamp;
} backup_file_t;

backup_file_t backup_files[MAX_BACKUP_FILES];
int num_backup_files = 0;

void backup_file(char *filename) {
    backup_file_t new_backup_file;
    strcpy(new_backup_file.filename, filename);
    new_backup_file.timestamp = time(NULL);
    backup_files[num_backup_files] = new_backup_file;
    num_backup_files++;
}

int main() {
    char filename[MAX_FILE_NAME_LENGTH];
    int i, choice;

    printf("Welcome to the C File Backup System!\n");
    printf("Please enter a filename to backup: ");
    scanf("%s", filename);
    backup_file(filename);

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Backup a file\n");
        printf("2. Restore a file\n");
        printf("3. List all backup files\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Please enter a filename to backup: ");
                scanf("%s", filename);
                backup_file(filename);
                break;
            case 2:
                printf("Please enter a filename to restore: ");
                scanf("%s", filename);
                // code to restore file
                break;
            case 3:
                printf("\nList of backup files:\n");
                for (i = 0; i < num_backup_files; i++) {
                    printf("%s - %s\n", backup_files[i].filename, ctime(&backup_files[i].timestamp));
                }
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}