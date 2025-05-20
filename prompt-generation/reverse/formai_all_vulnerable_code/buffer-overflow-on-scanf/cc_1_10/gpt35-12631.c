//FormAI DATASET v1.0 Category: File Backup System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to backup the specified file
void backupFile(char *fileName) {
    FILE *file, *backup;
    char backupFileName[100], ch;

    // Generate backup file name with time stamp
    sprintf(backupFileName, "%s_%ld.bak", fileName, time(NULL));

    // Open file for reading
    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Open backup file for writing
    backup = fopen(backupFileName, "w");
    if (backup == NULL) {
        printf("Error creating backup file.\n");
        fclose(file);
        return;
    }

    // Copy contents from file to backup file
    while ((ch = fgetc(file)) != EOF) {
        fputc(ch, backup);
    }

    // Close both files
    fclose(file);
    fclose(backup);

    printf("Backup created successfully as %s.\n", backupFileName);
}

int main() {
    char fileName[100];

    printf("Enter file name to backup: ");
    scanf("%s", fileName);

    backupFile(fileName);

    return 0;
}