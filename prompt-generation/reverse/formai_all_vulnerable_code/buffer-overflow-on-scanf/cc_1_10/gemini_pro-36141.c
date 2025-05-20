//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 10000

int main() {
    // Define the file backup system
    struct FileBackupSystem {
        char files[MAX_FILES][MAX_FILE_SIZE];
        int numFiles;
    };

    // Create a new file backup system
    struct FileBackupSystem backupSystem;
    backupSystem.numFiles = 0;

    // Ask the user for the files they want to back up
    printf("Enter the files you want to back up (separated by spaces): ");
    char files[MAX_FILES][MAX_FILE_SIZE];
    int numFiles;
    scanf("%s", files[0]);
    numFiles = 1;
    while (scanf("%s", files[numFiles]) != EOF) {
        numFiles++;
    }

    // Copy the files to the backup system
    for (int i = 0; i < numFiles; i++) {
        // Open the file
        FILE *file = fopen(files[i], "r");
        if (file == NULL) {
            printf("Error opening file %s\n", files[i]);
            continue;
        }

        // Read the file into a buffer
        char buffer[MAX_FILE_SIZE];
        fread(buffer, sizeof(char), MAX_FILE_SIZE, file);

        // Close the file
        fclose(file);

        // Copy the buffer to the backup system
        strcpy(backupSystem.files[backupSystem.numFiles], buffer);
        backupSystem.numFiles++;
    }

    // Create a backup file
    time_t now = time(NULL);
    char backupFile[MAX_FILE_SIZE];
    sprintf(backupFile, "backup-%ld.txt", now);
    FILE *backup = fopen(backupFile, "w");
    if (backup == NULL) {
        printf("Error creating backup file %s\n", backupFile);
        return 1;
    }

    // Write the backup system to the file
    fwrite(&backupSystem, sizeof(struct FileBackupSystem), 1, backup);

    // Close the backup file
    fclose(backup);

    // Print a success message
    printf("Backup successful!\n");

    return 0;
}