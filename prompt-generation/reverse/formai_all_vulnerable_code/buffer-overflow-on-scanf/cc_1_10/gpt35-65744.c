//FormAI DATASET v1.0 Category: File Backup System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_COUNT 100

// function prototypes
void backup(const char* filename);
void restore(int fileIndex);

// global variables
char* files[MAX_FILE_COUNT];
int fileCount = 0;

int main()
{
    int choice;

    printf("Welcome to File Backup System\n");
    printf("-------------------------------\n");

    while (1)
    {
        printf("\n1. Backup a file\n");
        printf("2. Restore a file\n");
        printf("3. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                char filename[MAX_FILENAME_LENGTH];
                printf("\nEnter the name of the file to backup: ");
                scanf("%s", filename);
                backup(filename);
                break;
            }
            case 2:
            {
                int fileIndex;
                printf("\nFiles backed up:\n");
                for (int i = 0; i < fileCount; i++)
                {
                    printf("%d. %s\n", i + 1, files[i]);
                }
                printf("\nEnter the index of the file to restore: ");
                scanf("%d", &fileIndex);
                restore(fileIndex);
                break;
            }
            case 3:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }

    return 0;
}

void backup(const char* filename)
{
    FILE* sourceFile;
    FILE* backupFile;

    // open source file
    sourceFile = fopen(filename, "r");
    if (sourceFile == NULL)
    {
        printf("File does not exist\n");
        return;
    }

    // create backup file
    char backupFilename[MAX_FILENAME_LENGTH];
    sprintf(backupFilename, "%s.bak", filename);
    backupFile = fopen(backupFilename, "w");

    // copy contents from source file to backup file
    char buffer[1024];
    size_t readSize;
    while ((readSize = fread(buffer, 1, 1024, sourceFile)) > 0)
    {
        fwrite(buffer, 1, readSize, backupFile);
    }

    // close files
    fclose(sourceFile);
    fclose(backupFile);

    // add filename to files array
    files[fileCount] = (char*) malloc((strlen(filename) + 1) * sizeof(char));
    strcpy(files[fileCount], filename);
    fileCount++;

    printf("\nBackup successful!\n");
}

void restore(int fileIndex)
{
    if (fileIndex < 1 || fileIndex > fileCount)
    {
        printf("\nInvalid index.\n");
        return;
    }

    // get file name from files array
    char* filename = files[fileIndex - 1];

    FILE* sourceFile;
    FILE* backupFile;

    // open backup file
    char backupFilename[MAX_FILENAME_LENGTH];
    sprintf(backupFilename, "%s.bak", filename);
    backupFile = fopen(backupFilename, "r");
    if (backupFile == NULL)
    {
        printf("Backup file does not exist\n");
        return;
    }

    // open source file
    sourceFile = fopen(filename, "w");

    // copy contents from backup file to source file
    char buffer[1024];
    size_t readSize;
    while ((readSize = fread(buffer, 1, 1024, backupFile)) > 0)
    {
        fwrite(buffer, 1, readSize, sourceFile);
    }

    // close files
    fclose(sourceFile);
    fclose(backupFile);

    printf("\nRestore successful!\n");
}