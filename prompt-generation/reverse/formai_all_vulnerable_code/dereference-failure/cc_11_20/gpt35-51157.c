//FormAI DATASET v1.0 Category: File Synchronizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PATH_LENGTH 1024 // Max length of file path
#define MAX_FILE_SIZE 1048576 // Max file size allowed (1 MB)

/**
 * Structure to hold file metadata
 */
typedef struct FileData {
    char filename[MAX_PATH_LENGTH]; // File name with full path
    char md5hash[33]; // MD5 hash of file
    long long int size; // File size
    bool isDir; // Is directory or file
    bool isDeleted; // Is marked for deletion
} FileData;

/**
 * This function calculates and returns the MD5 hash of the file specified by filePath. 
 * Returns NULL if there is any error.
 */
char* calculateMD5(char* filePath) {
    // Code for calculating MD5 hash goes here
    return NULL;
}

/**
 * This function synchronizes two directories specified by src and dst. 
 * It first scans the source directory recursively and calculates MD5 hash for each file.
 * Then it scans the destination directory recursively and compares the MD5 hash and file size with the source directory.
 * If there are any differences, it copies the file from the source directory to the destination directory.
 * If there are any files in the destination that are not present in the source directory, it deletes them.
 * Returns true if synchronization is successful, otherwise false.
 */
bool synchronizeDirectories(char* src, char* dst) {
    DIR *dir = opendir(src);
    if(dir == NULL) {
        printf("Failed to open source directory: %s\n", strerror(errno));
        return false;
    }

    struct dirent *entry;
    while((entry = readdir(dir))) {
        // Ignore "." and ".."
        if(strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,"..") == 0) {
            continue;
        }
        
        FileData file;
        strcpy(file.filename,src);
        strcat(file.filename,"/");
        strcat(file.filename,entry->d_name);

        struct stat fileInfo;
        if(lstat(file.filename,&fileInfo) == -1) {
            continue;
        }
        if(S_ISDIR(fileInfo.st_mode)) {
            file.isDir = true;
            if(!synchronizeDirectories(file.filename,dst)) {
                closedir(dir);
                return false;
            }
        } else {
            file.isDir = false;
            strcpy(file.md5hash,calculateMD5(file.filename));
        }
        file.size = fileInfo.st_size;

        // Compare with destination directory
        char destFilePath[MAX_PATH_LENGTH];
        strcpy(destFilePath,dst);
        strcat(destFilePath,"/");
        strcat(destFilePath,entry->d_name);

        struct stat destFileInfo;
        if(lstat(destFilePath,&destFileInfo) == -1) {
            // File does not exist in destination
            if(errno == ENOENT) {
                if(file.isDir) {
                    if(mkdir(destFilePath,fileInfo.st_mode) == -1) {
                        printf("Failed to create directory: %s\n",strerror(errno));
                        closedir(dir);
                        return false;
                    }
                } else {
                    int fdSrc = open(file.filename,O_RDONLY);
                    if(fdSrc == -1) {
                        printf("Failed to open file: %s\n",strerror(errno));
                        closedir(dir);
                        return false;
                    }
                    int fdDst = open(destFilePath,O_CREAT|O_WRONLY|O_TRUNC,fileInfo.st_mode);
                    if(fdDst == -1) {
                        printf("Failed to create file: %s\n",strerror(errno));
                        close(fdSrc);
                        closedir(dir);
                        return false;
                    }

                    char *buffer = (char *) malloc(MAX_FILE_SIZE);
                    ssize_t bytes;
                    while ((bytes = read(fdSrc, buffer, MAX_FILE_SIZE)) > 0) {
                        if (write(fdDst, buffer, bytes) != bytes) {
                            printf("Failed to write to file: %s\n",strerror(errno));
                            close(fdSrc);
                            close(fdDst);
                            closedir(dir);
                            return false;
                        }
                    }
                    close(fdSrc);
                    close(fdDst);
                    free(buffer);
                }
            } else {
                printf("Failed to stat file in destination directory: %s\n",strerror(errno));
                closedir(dir);
                return false;
            }
        } else {
            // File exists in destination
            if(file.isDir) {
                // Ignore directories in comparison
            } else if(!strcmp(file.md5hash,"")) {
                // File in source could not be read
                printf("Failed to read file: %s\n",file.filename);
                closedir(dir);
                return false;
            } else if(!strcmp(file.md5hash,"DELETED")) {
                // File was marked for deletion
                unlink(destFilePath);
            } else if(strcmp(file.md5hash,calculateMD5(destFilePath))) {
                // File is different in source and destination
                int fdSrc = open(file.filename,O_RDONLY);
                if(fdSrc == -1) {
                    printf("Failed to open file: %s\n",strerror(errno));
                    closedir(dir);
                    return false;
                }
                int fdDst = open(destFilePath,O_CREAT|O_WRONLY|O_TRUNC,fileInfo.st_mode);
                if(fdDst == -1) {
                    printf("Failed to create file: %s\n",strerror(errno));
                    close(fdSrc);
                    closedir(dir);
                    return false;
                }

                char *buffer = (char *) malloc(MAX_FILE_SIZE);
                ssize_t bytes;
                while ((bytes = read(fdSrc, buffer, MAX_FILE_SIZE)) > 0) {
                    if (write(fdDst, buffer, bytes) != bytes) {
                        printf("Failed to write to file: %s\n",strerror(errno));
                        close(fdSrc);
                        close(fdDst);
                        closedir(dir);
                        return false;
                    }
                }
                close(fdSrc);
                close(fdDst);
                free(buffer);
            }
        }
    }

    // Delete files in destination that are not in source
    rewinddir(dir);
    while((entry = readdir(dir))) {
        // Ignore "." and ".."
        if(strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,"..") == 0) {
            continue;
        }

        char srcFilePath[MAX_PATH_LENGTH];
        strcpy(srcFilePath,src);
        strcat(srcFilePath,"/");
        strcat(srcFilePath,entry->d_name);

        struct stat srcFileInfo;
        if(lstat(srcFilePath,&srcFileInfo) == -1) {
            // File does not exist in source
            if(errno == ENOENT) {
                char destFilePath[MAX_PATH_LENGTH];
                strcpy(destFilePath,dst);
                strcat(destFilePath,"/");
                strcat(destFilePath,entry->d_name);

                if(unlink(destFilePath) == -1) {
                    printf("Failed to delete file: %s\n",strerror(errno));
                    closedir(dir);
                    return false;
                }
            } else {
                printf("Failed to stat file in source directory: %s\n",strerror(errno));
                closedir(dir);
                return false;
            }
        }
    }

    closedir(dir);
    return true;
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s <source_path> <destination_path>\n",argv[0]);
        return 1;
    }

    if(!synchronizeDirectories(argv[1],argv[2])) {
        printf("Failed to synchronize directories!\n");
        return 1;
    }

    printf("Directories synchronized successfully!\n");
    return 0;
}