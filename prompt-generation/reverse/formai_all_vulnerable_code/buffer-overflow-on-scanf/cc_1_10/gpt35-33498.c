//FormAI DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The maximum number of files that can be backed up */
#define MAX_FILES 100

/* The maximum length of a file name */
#define MAX_FILENAME_LEN 100

/* The maximum length of a file path */
#define MAX_PATH_LEN 500

/* The backup folder path */
#define BACKUP_FOLDER "C:/backup/"

/* The main function */
int main(void) {
    // Declare variables
    char filenames[MAX_FILES][MAX_FILENAME_LEN];
    char filepath[MAX_FILES][MAX_PATH_LEN];
    char backupfilepath[MAX_FILES][MAX_PATH_LEN];
    int num_files = 0;
    char input[MAX_PATH_LEN];
    char backupcmd[MAX_PATH_LEN];

    printf("C File Backup System\n");

    // Get input from user
    do {
        printf("Enter file path to backup (or 'done' to finish): ");
        scanf("%s", input);

        // Check if user is finished entering files
        if(strcmp(input, "done") == 0) {
            break;
        }

        // Copy input to filepath array
        strncpy(filepath[num_files], input, MAX_PATH_LEN);

        // Extract filename from input
        char *last_slash = strrchr(input, '/');
        if(last_slash == NULL) {
            last_slash = strrchr(input, '\\');
        }
        if(last_slash == NULL) {
            strcpy(filenames[num_files], input);
        }
        else {
            strcpy(filenames[num_files], last_slash+1);
        }

        // Create backupfilepath by appending filename to BACKUP_FOLDER
        strncpy(backupfilepath[num_files], BACKUP_FOLDER, MAX_PATH_LEN);
        strncat(backupfilepath[num_files], filenames[num_files], MAX_FILENAME_LEN);

        // Create backup command
        snprintf(backupcmd, MAX_PATH_LEN, "cp %s %s", filepath[num_files], backupfilepath[num_files]);

        // Execute backup command
        if(system(backupcmd) == -1) {
            printf("Error: could not backup file %s\n", filepath[num_files]);
        }
        else {
            printf("Successfully backed up file %s to %s\n", filepath[num_files], backupfilepath[num_files]);
            num_files++;
        }

        // Check if we have reached the maximum number of files
        if(num_files == MAX_FILES) {
            printf("Error: cannot backup more than %d files.\n", MAX_FILES);
            break;
        }

    } while(1);

    printf("Backing up complete. %d files were backed up.\n", num_files);

    return 0;
}