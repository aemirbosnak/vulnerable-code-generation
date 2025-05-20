//FormAI DATASET v1.0 Category: File Backup System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILE_LENGTH 100

int main()
{
    // Initialize variables
    char filename[MAX_FILE_LENGTH];
    char backupFilename[MAX_FILE_LENGTH + 4]; // Add space for ".bak"
    char fileContent[100000];
    char c;
    int i = 0, backup = 0;
    FILE *fp, *bp;

    // Prompt user for filename
    printf("Enter filename: ");
    fgets(filename, MAX_FILE_LENGTH, stdin);
    strtok(filename, "\n"); // Remove newline character

    // Check if file exists
    fp = fopen(filename, "r");
    if (!fp) {
        printf("File does not exist!\n");
        return 0;
    }

    // Copy file contents to buffer
    while ((c = fgetc(fp)) != EOF) {
        fileContent[i++] = c;
    }
    fileContent[i] = '\0';

    // Prompt user for backup option
    printf("Create backup file? (0=no, 1=yes): ");
    scanf("%d", &backup);

    // Create backup filename
    if (backup) {
        strcpy(backupFilename, filename);
        strcat(backupFilename, ".bak");
        bp = fopen(backupFilename, "w");
        fprintf(bp, "%s", fileContent);
        fclose(bp);
        printf("Backup file created: %s\n", backupFilename);
    }

    // Display file contents
    printf("\nFile contents:\n%s", fileContent);

    // Close file
    fclose(fp);

    return 0;
}