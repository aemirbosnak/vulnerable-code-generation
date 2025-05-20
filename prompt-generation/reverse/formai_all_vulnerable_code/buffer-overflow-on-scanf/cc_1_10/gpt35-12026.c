//FormAI DATASET v1.0 Category: File Backup System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_BACKUP_FILES 10

int main()
{
    char originalFileName[MAX_FILENAME_LENGTH];
    char backupFileName[MAX_FILENAME_LENGTH];
    char backupFileExtension[] = ".bak";

    printf("Enter the name of the file to backup: ");
    scanf("%s", originalFileName);

    //Create the backup file name
    strcpy(backupFileName, originalFileName);
    strcat(backupFileName, backupFileExtension);

    //Open the files
    FILE *originalFile = fopen(originalFileName, "r");
    FILE *backupFile = fopen(backupFileName, "w");

    //Check if files were opened successfully
    if(originalFile == NULL || backupFile == NULL)
    {
        printf("Error opening files!\n");
        exit(1);
    }

    //Read from original file and write to backup file
    char ch;
    while((ch = fgetc(originalFile)) != EOF)
    {
        fputc(ch, backupFile);
    }

    //Close the files
    fclose(originalFile);
    fclose(backupFile);

    //List all backup files
    printf("All backup files:\n");
    int backupFileCount = 0;
    for(int i = 0; i < MAX_BACKUP_FILES; i++)
    {
        char tempFileName[MAX_FILENAME_LENGTH];
        strcpy(tempFileName, originalFileName);
        char backupNumber[3];
        sprintf(backupNumber, "%d", i);
        strcat(tempFileName, backupNumber);
        strcat(tempFileName, backupFileExtension);
        FILE *tempFile = fopen(tempFileName, "r");

        if(tempFile != NULL)
        {
            printf("- %s\n", tempFileName);
            backupFileCount++;
            fclose(tempFile);
        }
    }

    if(backupFileCount == 0)
    {
        printf("No backup files found!\n");
    }

    return 0;
}