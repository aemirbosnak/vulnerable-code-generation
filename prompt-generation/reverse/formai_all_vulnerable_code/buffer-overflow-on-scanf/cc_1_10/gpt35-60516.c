//FormAI DATASET v1.0 Category: File Backup System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_NUM_FILES 10

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    time_t timestamp;
} File;

typedef struct {
    File files[MAX_NUM_FILES];
    int numFiles;
} FileList;

void displayFileList(FileList* fileList)
{
    printf("File List:\n");
    printf("==========================================\n");
    for(int i = 0; i < fileList->numFiles; i++)
    {
        printf("%d. %s\t\tModified: %s", i+1, fileList->files[i].name, ctime(&(fileList->files[i].timestamp)));
    }
    printf("\n");
}

void backupFiles(FileList* fileList, char* backupDir)
{
    for(int i = 0; i < fileList->numFiles; i++)
    {
        char copyCommand[100];
        sprintf(copyCommand, "cp %s/%s %s/%s.%ld", backupDir, fileList->files[i].name, backupDir, fileList->files[i].name, fileList->files[i].timestamp);
        system(copyCommand);
    }
}

void addFile(FileList* fileList)
{
    File newFile;
    printf("Enter filename (max %d characters): ", MAX_FILENAME_LENGTH-1);
    scanf("%s", newFile.name);
    newFile.timestamp = time(NULL);
    fileList->files[fileList->numFiles] = newFile;
    fileList->numFiles++;
}

void removeFile(FileList* fileList)
{
    int fileNum;
    printf("Enter the number of the file you want to remove: ");
    scanf("%d", &fileNum);
    if(fileNum <= fileList->numFiles && fileNum > 0)
    {
        printf("Removing file %s\n", fileList->files[fileNum-1].name);
        for(int i = fileNum-1; i < fileList->numFiles-1; i++)
        {
            fileList->files[i] = fileList->files[i+1];
        }
        fileList->numFiles--;
    }
    else
    {
        printf("Invalid file number.\n");
    }
}

int main()
{
    char backupDir[50];
    printf("Welcome to C File Backup System!\n");
    printf("Please enter the path to your backup directory: ");
    scanf("%s", backupDir);

    FileList fileList;
    fileList.numFiles = 0;

    while(1)
    {
        int choice;
        printf("\n\nPlease choose an option:\n");
        printf("1. Display file list\n");
        printf("2. Add file\n");
        printf("3. Remove file\n");
        printf("4. Backup files\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayFileList(&fileList);
                break;
            case 2:
                addFile(&fileList);
                break;
            case 3:
                removeFile(&fileList);
                break;
            case 4:
                backupFiles(&fileList, backupDir);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}