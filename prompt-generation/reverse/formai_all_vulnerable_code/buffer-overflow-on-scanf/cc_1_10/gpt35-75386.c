//FormAI DATASET v1.0 Category: File Backup System ; Style: peaceful
/* This is an example C File Backup System program.
   It allows users to backup their files in a chosen directory
   and keep track of all the backups. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 255
#define MAX_BACKUPS_PER_FILE 10
#define MAX_BACKUP_SIZE 1024

/* Struct to represent a single backup */
typedef struct {
    time_t timestamp;
    char contents[MAX_BACKUP_SIZE];
} backup_t;

/* Struct to represent a file and all its backups */
typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int num_backups;
    backup_t backups[MAX_BACKUPS_PER_FILE];
} file_t;

/* Function to create a backup for a given file */
void create_backup(file_t* file) {
    if (file->num_backups == MAX_BACKUPS_PER_FILE) {
        printf("Maximum number of backups reached for file %s\n", file->filename);
        return;
    }

    backup_t backup;
    backup.timestamp = time(NULL);
    memcpy(backup.contents, file->filename, strlen(file->filename));
    file->backups[file->num_backups++] = backup;

    printf("Backup created for file %s at %s", file->filename, ctime(&backup.timestamp));
}

/* Function to display all the backups for a given file */
void display_backups(file_t* file) {
    printf("Backups for file %s:\n", file->filename);
    for (int i = 0; i < file->num_backups; i++) {
        printf("%d. %s", i+1, ctime(&file->backups[i].timestamp));
    }
}

int main() {
    /* Create a list to hold all the files */
    file_t files[MAX_BACKUPS_PER_FILE];
    int num_files = 0;

    /* Infinite loop until user chooses to quit */
    while (1) {
        printf("1. Add a file\n2. Create backup\n3. Display backups\n4. Quit\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            /* Add a new file to the list */
            printf("Enter file name: ");
            char filename[MAX_FILENAME_LENGTH];
            scanf("%s", filename);

            /* Check if file already exists */
            int file_index = -1;
            for (int i = 0; i < num_files; i++) {
                if (strcmp(files[i].filename, filename) == 0) {
                    file_index = i;
                    break;
                }
            }

            if (file_index == -1) {
                /* File does not exist, create it */
                file_t new_file;
                strcpy(new_file.filename, filename);
                new_file.num_backups = 0;
                files[num_files++] = new_file;

                printf("File %s added successfully\n", filename);
            }
            else {
                /* File already exists */
                printf("File %s already exists\n", filename);
            }
        }
        else if (choice == 2) {
            /* Create a backup for a selected file */
            printf("Files available for backup:\n");
            for (int i = 0; i < num_files; i++) {
                printf("%d. %s\n", i+1, files[i].filename);
            }

            int file_choice;
            scanf("%d", &file_choice);
            if (file_choice <= 0 || file_choice > num_files) {
                printf("Invalid file choice\n");
                continue;
            }

            create_backup(&files[file_choice-1]);
        }
        else if (choice == 3) {
            /* Display all backups for a selected file */
            printf("Files available for display:\n");
            for (int i = 0; i < num_files; i++) {
                printf("%d. %s\n", i+1, files[i].filename);
            }

            int file_choice;
            scanf("%d", &file_choice);
            if (file_choice <= 0 || file_choice > num_files) {
                printf("Invalid file choice\n");
                continue;
            }

            display_backups(&files[file_choice-1]);
        }
        else if (choice == 4) {
            /* Quit the program */
            printf("Goodbye!\n");
            break;
        }
        else {
            /* Invalid choice */
            printf("Invalid choice\n");
        }
    }

    return 0;
}