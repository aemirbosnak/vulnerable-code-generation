//FormAI DATASET v1.0 Category: File Backup System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024

/* Function declaration */
void backupFile(char *fileName);

int main()
{
    /* File name */
    char fileName[BUFFER_SIZE];

    printf("Enter file name: ");
    scanf("%s", fileName);

    /* Call backup function */
    backupFile(fileName);

    printf("File backup is complete.\n");

    return 0;
}

/*
 * This function takes a file name as argument, opens the file in read mode,
 * creates a new file with the original file name and timestamp appended to it,
 * and copies the content of the original file into the new file.
 */
void backupFile(char *fileName)
{
    FILE *fpOriginalFile, *fpBackupFile;
    char backupFileName[BUFFER_SIZE], buffer[BUFFER_SIZE], dateAndTime[BUFFER_SIZE];
    time_t rawTime;
    struct tm *timeInfo;

    /* Open original file in read mode */
    fpOriginalFile = fopen(fileName, "r");

    if (fpOriginalFile == NULL)
    {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    /* Get current time */
    time(&rawTime);
    timeInfo = localtime(&rawTime);

    /* Format timestamp */
    strftime(dateAndTime, BUFFER_SIZE, "_%Y%m%d%H%M%S", timeInfo);

    /* Create backup file name */
    snprintf(backupFileName, BUFFER_SIZE, "%s%s", fileName, dateAndTime);

    /* Open backup file in write mode */
    fpBackupFile = fopen(backupFileName, "w");

    if (fpBackupFile == NULL)
    {
        printf("Error creating backup file.\n");
        fclose(fpOriginalFile);
        exit(EXIT_FAILURE);
    }

    /* Copy content of original file to backup file */
    while (fgets(buffer, BUFFER_SIZE, fpOriginalFile) != NULL)
    {
        fputs(buffer, fpBackupFile);
    }

    /* Close files */
    fclose(fpOriginalFile);
    fclose(fpBackupFile);

    printf("Backup of %s has been created.\n", fileName);
}