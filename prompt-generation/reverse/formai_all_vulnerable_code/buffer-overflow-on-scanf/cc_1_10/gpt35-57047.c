//FormAI DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <string.h>

/* Function to backup a file */
void backupFile(char fileName[]) {

    // Create a new filename for the backup
    char backupName[strlen(fileName) + 5];
    strcpy(backupName, fileName);
    strcat(backupName, ".bak");

    // Create file pointers for the original and backup files
    FILE *originalFile, *backupFile;

    // Open the original file for reading and check if it exists
    originalFile = fopen(fileName, "r");
    if (originalFile == NULL) {
        printf("Error: File does not exist.\n");
        return;
    }

    // Open the backup file for writing and check if it was successfully created
    backupFile = fopen(backupName, "w");
    if (backupFile == NULL) {
        printf("Error: Unable to create backup file.\n");
        return;
    }

    // Copy the contents of the original file to the backup file
    char c;
    do {
        c = fgetc(originalFile);
        fputc(c, backupFile);
    } while (c != EOF);

    // Close the files
    fclose(originalFile);
    fclose(backupFile);

    printf("File backup successful.\n");
}

int main() {

    // Prompt the user to enter the name of the file to backup
    char fileName[50];
    printf("Enter the name of the file to backup: ");
    scanf("%s", fileName);

    // Call the backup file function
    backupFile(fileName);

    return 0;
}