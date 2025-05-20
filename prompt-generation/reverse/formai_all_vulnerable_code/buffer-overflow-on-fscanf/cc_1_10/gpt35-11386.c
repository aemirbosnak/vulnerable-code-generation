//FormAI DATASET v1.0 Category: File Backup System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_SIZE 256

// Defining our structure for backup files
typedef struct BackupFile {
    char filename[MAX_FILENAME_SIZE];
    time_t timestamp;
} BackupFile;

int main() {
    // Create an array of BackupFile structs
    BackupFile backupFiles[10];

    // Create a file pointer and open the file for reading
    FILE *fp;
    fp = fopen("file.txt", "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("File could not be opened.\n");
        exit(EXIT_FAILURE);
    }

    // Read the filenames and timestamps from the file and store them in our BackupFile array
    int i = 0;
    while (!feof(fp)) {
        fscanf(fp, "%[^,],%ld\n", backupFiles[i].filename, &backupFiles[i].timestamp);
        i++;
    }

    // Print the backup file list
    printf("Backup File List:\n");
    for (int j = 0; j < i; j++) {
        printf("%s (%ld)\n", backupFiles[j].filename, backupFiles[j].timestamp);
    }

    // Close the file
    fclose(fp);

    // Create a file pointer and open the file for writing
    fp = fopen("file.txt", "a");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("File could not be opened.\n");
        exit(EXIT_FAILURE);
    }

    // Get the current time and store it in a variable
    time_t currentTime;
    time(&currentTime);

    // Create a new BackupFile struct for the backup file we are about to create
    BackupFile newBackupFile;

    // Ask the user for the filename to backup and store it in our new BackupFile struct
    printf("\nEnter the filename to backup: ");
    scanf("%s", newBackupFile.filename);

    // Store the current time in our new BackupFile struct
    newBackupFile.timestamp = currentTime;

    // Write the new backup file information to the file
    fprintf(fp, "%s,%ld\n", newBackupFile.filename, newBackupFile.timestamp);

    // Print a message to let the user know the backup was successful
    printf("\nBackup successful.\n");

    // Close the file
    fclose(fp);

    // Exit the program
    return 0;
}