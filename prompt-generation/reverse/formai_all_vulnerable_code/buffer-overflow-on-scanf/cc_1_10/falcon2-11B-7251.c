//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a function to backup a file
void backupFile(const char* fileName) {
    // Open the file for reading
    FILE* inputFile = fopen(fileName, "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Error opening input file\n");
        return;
    }

    // Create a backup file
    char* backupFileName = (char*)malloc(strlen(fileName) + 4);
    sprintf(backupFileName, "%s.bak", fileName);

    // Open the backup file for writing
    FILE* backupFile = fopen(backupFileName, "w");
    if (backupFile == NULL) {
        fprintf(stderr, "Error opening backup file\n");
        fclose(inputFile);
        free(backupFileName);
        return;
    }

    // Copy the contents of the input file to the backup file
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), inputFile)) {
        fprintf(backupFile, "%s", buffer);
    }

    // Close the files
    fclose(inputFile);
    fclose(backupFile);
    free(backupFileName);
}

int main() {
    // Get the file name from the user
    char fileName[256];
    printf("Enter the name of the file to backup: ");
    scanf("%s", fileName);

    // Backup the file
    backupFile(fileName);

    printf("Backup completed successfully\n");

    return 0;
}