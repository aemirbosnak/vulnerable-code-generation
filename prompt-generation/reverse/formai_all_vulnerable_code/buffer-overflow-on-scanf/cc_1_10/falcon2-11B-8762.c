//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 80

typedef struct file_backup {
    char filename[MAX_LINE_LEN];
    struct file_backup *next;
} FileBackup;

typedef struct backup_list {
    FileBackup *first;
} BackupList;

int main() {
    BackupList backup_list;
    FileBackup *file_backup;

    printf("Enter the name of the file to be backed up: ");
    scanf("%s", file_backup->filename);

    // Create a new file backup structure and add it to the backup list
    file_backup->next = NULL;
    backup_list.first = file_backup;

    while (1) {
        // Prompt the user to create a new file backup or exit
        printf("Enter 'y' to create a new file backup or 'n' to exit: ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y') {
            // Prompt the user for the name of the file to be backed up
            printf("Enter the name of the file to be backed up: ");
            scanf("%s", file_backup->filename);

            // Create a new file backup structure and add it to the backup list
            file_backup->next = NULL;
            backup_list.first = file_backup;
        }
        else if (choice == 'n') {
            // Print out the file backups
            FileBackup *current = backup_list.first;

            while (current!= NULL) {
                printf("%s\n", current->filename);
                current = current->next;
            }

            printf("No more file backups.\n");
            exit(0);
        }
        else {
            printf("Invalid choice.\n");
        }
    }
}