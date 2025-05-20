//FormAI DATASET v1.0 Category: File Synchronizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PATH_LENGTH 256
#define BUFFER_SIZE 1024

// Function to check if path exists and is a directory
int isDirectory(const char *path)
{
    struct stat statbuf;
    if (stat(path, &statbuf) != 0)
    {
        return 0;
    }
    return S_ISDIR(statbuf.st_mode);
}

// Function to sync files between source and destination directories
void syncFiles(char *sourcePath, char *destinationPath)
{
    DIR *dir;
    struct dirent *entry;
    char source[MAX_PATH_LENGTH], destination[MAX_PATH_LENGTH];
    strcpy(source, sourcePath);
    strcpy(destination, destinationPath);

    // Open source directory
    if ((dir = opendir(source)) == NULL)
    {
        printf("Could not open source directory.");
        exit(EXIT_FAILURE);
    }

    // Read each file and sub-directory in source directory
    while ((entry = readdir(dir)) != NULL)
    {
        char subSource[MAX_PATH_LENGTH], subDestination[MAX_PATH_LENGTH];
        strcpy(subSource, source);
        strcpy(subDestination, destination);

        // Ignoring the "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        strcat(subSource, "/");
        strcat(subSource, entry->d_name);
        strcat(subDestination, "/");
        strcat(subDestination, entry->d_name);

        // Check if entry is a directory
        if (isDirectory(subSource))
        {
            // Recursively sync sub-directory
            syncFiles(subSource, subDestination);
        }
        else
        {
            // If file exists in destination, check for modifications
            if (access(subDestination, F_OK) == 0)
            {
                int sourceFd, destFd, bytesRead;
                char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
                int sourceBytes = 0, destBytes = 0;

                sourceFd = open(subSource, O_RDONLY);
                destFd = open(subDestination, O_RDONLY);
                while ((bytesRead = read(sourceFd, &buf1, BUFFER_SIZE)) > 0)
                {
                    sourceBytes += bytesRead;
                }
                close(sourceFd);
                sourceFd = open(subSource, O_RDONLY);
                while ((bytesRead = read(destFd, &buf2, BUFFER_SIZE)) > 0)
                {
                    destBytes += bytesRead;
                }
                close(destFd);
                destFd = open(subDestination, O_RDONLY);

                // If source and destination files are same size
                if (sourceBytes == destBytes)
                {
                    int flag = 0;
                    while ((bytesRead = read(sourceFd, &buf1, BUFFER_SIZE)) > 0)
                    {
                        if (read(destFd, &buf2, bytesRead) != bytesRead || memcmp(&buf1, &buf2, bytesRead) != 0)
                        {
                            flag = 1;
                            break;
                        }
                    }

                    // If file content is not same, update destination
                    if (flag)
                    {
                        close(destFd);
                        destFd = open(subDestination, O_WRONLY | O_TRUNC);
                        while ((bytesRead = read(sourceFd, &buf1, BUFFER_SIZE)) > 0)
                        {
                            write(destFd, &buf1, bytesRead);
                        }
                    }
                }
                // If source and destination files are different size, update destination
                else
                {
                    close(destFd);
                    destFd = open(subDestination, O_WRONLY | O_TRUNC);
                    while ((bytesRead = read(sourceFd, &buf1, BUFFER_SIZE)) > 0)
                    {
                        write(destFd, &buf1, bytesRead);
                    }
                }
                close(sourceFd);
                close(destFd);
            }
            else
            {
                // If file does not exist in destination, copy it over
                int sourceFd, destFd, bytesRead;
                char buf[BUFFER_SIZE];

                sourceFd = open(subSource, O_RDONLY);
                destFd = open(subDestination, O_WRONLY | O_CREAT, 0666);
                while ((bytesRead = read(sourceFd, &buf, BUFFER_SIZE)) > 0)
                {
                    write(destFd, &buf, bytesRead);
                }
                close(sourceFd);
                close(destFd);
            }
        }
    }
    closedir(dir);
    return;
}

int main()
{
    char sourcePath[MAX_PATH_LENGTH], destinationPath[MAX_PATH_LENGTH];
    printf("Enter the source path: ");
    scanf("%s", sourcePath);
    printf("Enter the destination path: ");
    scanf("%s", destinationPath);
    syncFiles(sourcePath, destinationPath);
    printf("File sync complete!");
    return 0;
}