//FormAI DATASET v1.0 Category: File Backup System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for file names and directories
#define MAX_FILENAME_LENGTH 50
#define MAX_DIR_LENGTH 100

// Define struct for storing file information
typedef struct file {
    char name[MAX_FILENAME_LENGTH];
    char directory[MAX_DIR_LENGTH];
} File;

// Function to prompt user for file information
File getFileInformation() {
    File newFile;

    printf("Enter the file name: ");
    scanf("%s", newFile.name);

    printf("Enter the directory path: ");
    scanf("%s", newFile.directory);

    return newFile;
}

// Function to create a backup of a file
void createBackup(File file) {
    char backupFilename[MAX_FILENAME_LENGTH + 7];
    sprintf(backupFilename, "backup_%s", file.name);

    char copyCommand[MAX_DIR_LENGTH + 20];
    sprintf(copyCommand, "cp %s/%s ./%s", file.directory, file.name, backupFilename);

    system(copyCommand);

    printf("Backup of %s created successfully!\n", file.name);
}

int main() {
    int option;

    while(option != 3) {
        printf("\nSelect an option: \n");
        printf("1. Create a backup of a file\n");
        printf("2. Restore a file from backup\n");
        printf("3. Exit\n");

        scanf("%d", &option);

        switch(option) {
            case 1:
                createBackup(getFileInformation());
                break;
            case 2:
                printf("Not yet implemented.\n");
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Please select again.\n");
                break;
        }
    }

    return 0;
}