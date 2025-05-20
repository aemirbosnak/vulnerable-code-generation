//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100

void scanFile(char* filePath);
void scanDirectory(char* dirPath);

int isInfected(char* string);

int main()
{
    char startingPath[MAX_PATH_LENGTH];
    printf("Enter path to starting directory: ");
    scanf("%s", startingPath);

    scanDirectory(startingPath);

    return 0;
}

int isInfected(char* string)
{
    char* virusSignature = "malware";
    if(strstr(string, virusSignature) != NULL)
    {
        return 1; // file is infected
    }
    return 0; // file is clean
}

void scanFile(char* filePath)
{
    FILE* file;
    char fileContents[MAX_PATH_LENGTH];
    int result;

    printf("Scanning file: %s\n", filePath);

    file = fopen(filePath, "r");
    if(file == NULL)
    {
        printf("Could not open file: %s\n", filePath);
        return;
    }

    fgets(fileContents, MAX_PATH_LENGTH, file);
    fclose(file);

    if(isInfected(fileContents))
    {
        printf("File is infected: %s\n", filePath);
    }
    else
    {
        printf("File is clean: %s\n", filePath);
    }

    return;
}

void scanDirectory(char* dirPath)
{
    DIR* directory;
    struct dirent* dirEntry;

    directory = opendir(dirPath);
    if(directory == NULL)
    {
        printf("Could not open directory: %s\n", dirPath);
        return;
    }

    printf("Scanning directory: %s\n", dirPath);

    while((dirEntry = readdir(directory)) != NULL)
    {
        if(dirEntry->d_type == DT_DIR) // is directory
        {
            if(strcmp(dirEntry->d_name, ".") == 0 || strcmp(dirEntry->d_name, "..") == 0) // skip "." and ".."
            {
                continue;
            }

            char subDirPath[MAX_PATH_LENGTH];
            sprintf(subDirPath, "%s/%s", dirPath, dirEntry->d_name);
            scanDirectory(subDirPath);
        }
        else // is file
        {
            char filePath[MAX_PATH_LENGTH];
            sprintf(filePath, "%s/%s", dirPath, dirEntry->d_name);
            scanFile(filePath);
        }
    }

    closedir(directory);

    return;
}