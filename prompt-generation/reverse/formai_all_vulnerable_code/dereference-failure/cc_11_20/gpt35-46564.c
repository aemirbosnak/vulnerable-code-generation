//FormAI DATASET v1.0 Category: File Synchronizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

//Define maximum buffer size
#define MAX_BUFFER_SIZE 1024

//Function to synchronise files
void syncFiles(char* sourceDirectory, char* destinationDirectory)
{
    DIR* sourceDir;
    DIR* destinationDir;
    struct dirent* sourceDirent;
    struct dirent* destinationDirent;
    struct stat sourceStat;
    struct stat destinationStat;
    char sourcePath[MAX_BUFFER_SIZE];
    char destinationPath[MAX_BUFFER_SIZE];
    int sourceFD;
    int destinationFD;
    char buffer[MAX_BUFFER_SIZE];
    ssize_t bytesRead;
    int error;

    //Open the source directory and check for errors
    sourceDir = opendir(sourceDirectory);
    if(sourceDir == NULL)
    {
        perror("Error opening source directory");
        exit(EXIT_FAILURE);
    }

    //Open the destination directory and check for errors
    destinationDir = opendir(destinationDirectory);
    if(destinationDir == NULL)
    {
        perror("Error opening destination directory");
        exit(EXIT_FAILURE);
    }

    //Iterate through all entries in source directory
    while((sourceDirent = readdir(sourceDir)) != NULL)
    {
        //Skip '.' and '..' entries
        if(strcmp(sourceDirent->d_name, ".") == 0 || strcmp(sourceDirent->d_name, "..") == 0)
	    {
            continue;   
	    }

        //Build full path of source file
        snprintf(sourcePath, MAX_BUFFER_SIZE, "%s/%s", sourceDirectory, sourceDirent->d_name);
        //Get the stat of the file
        if(stat(sourcePath, &sourceStat))
        {
            perror("Error getting file stat");
        }
        
        //Iterate through all entries in destination directory
        rewinddir(destinationDir);
        error = 1;
        while((destinationDirent = readdir(destinationDir)) != NULL)
        {
            //Skip '.' and '..' entries
            if(strcmp(destinationDirent->d_name, ".") == 0 || strcmp(destinationDirent->d_name, "..") == 0)
	        {
                continue;   
	        }

            //Build full path of destination file
            snprintf(destinationPath, MAX_BUFFER_SIZE, "%s/%s", destinationDirectory, destinationDirent->d_name);
            //Get the stat of the file
            if(stat(destinationPath, &destinationStat))
            {
                perror("Error getting file stat");
            }

            //Compare source and destination file names
            if(strcmp(sourceDirent->d_name, destinationDirent->d_name) == 0)
            {
                //If files have different sizes, overwrite destination file
                if(sourceStat.st_size != destinationStat.st_size)
                {
                    //Open source file for reading and check for errors
                    sourceFD = open(sourcePath, O_RDONLY);
                    if(sourceFD == -1)
                    {
                        perror("Error opening source file");
                        exit(EXIT_FAILURE);
                    }

                    //Open destination file for writing and check for errors
                    destinationFD = open(destinationPath, O_WRONLY | O_TRUNC);
                    if(destinationFD == -1)
                    {
                        perror("Error opening destination file");
                        exit(EXIT_FAILURE);
                    }

                    //Copy file contents from source to destination
                    while((bytesRead = read(sourceFD, buffer, MAX_BUFFER_SIZE)) > 0)
                    {
                        if(write(destinationFD, buffer, bytesRead) != bytesRead)
                        {
                            perror("Error writing to destination file");
                            exit(EXIT_FAILURE);
                        }
                    }

                    //Close file descriptors
                    close(sourceFD);
                    close(destinationFD);
                }
                else
                {
                    error = 0;
                    break;   
                }
            }
	    }

        //If file not found in destination, create file and copy contents from source
        if(error)
        {
            snprintf(destinationPath, MAX_BUFFER_SIZE, "%s/%s", destinationDirectory, sourceDirent->d_name);
            //Open source file for reading and check for errors
            sourceFD = open(sourcePath, O_RDONLY);
            if(sourceFD == -1)
            {
                perror("Error opening source file");
                exit(EXIT_FAILURE);
            }

            //Open destination file for writing and check for errors
            destinationFD = open(destinationPath, O_WRONLY | O_CREAT, sourceStat.st_mode);
            if(destinationFD == -1)
            {
                perror("Error opening destination file");
                exit(EXIT_FAILURE);
            }

            //Copy file contents from source to destination
            while((bytesRead = read(sourceFD, buffer, MAX_BUFFER_SIZE)) > 0)
            {
                if(write(destinationFD, buffer, bytesRead) != bytesRead)
                {
                    perror("Error writing to destination file");
                    exit(EXIT_FAILURE);
                }
            }

            //Close file descriptors
            close(sourceFD);
            close(destinationFD);
        }       
    }

    //Close directory streams
    closedir(sourceDir);
    closedir(destinationDir);
}

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    //Synchronize files
    syncFiles(argv[1], argv[2]);

    return 0;
}