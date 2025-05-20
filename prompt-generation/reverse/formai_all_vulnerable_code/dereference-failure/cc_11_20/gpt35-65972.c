//FormAI DATASET v1.0 Category: File Synchronizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

/**
 * A function to synchronize two directories
 * @param dirPath1: the path to the first directory
 * @param dirPath2: the path to the second directory
 */
void synchronizeDirs(char* dirPath1, char* dirPath2) {

    DIR* dir1 = opendir(dirPath1);
    DIR* dir2 = opendir(dirPath2);

    // check if both directory paths exist
    if (dir1 == NULL || dir2 == NULL) {
        printf("ERROR: Could not open directories.\n");
        exit(1);
    }

    struct dirent* file1 = readdir(dir1);
    struct dirent* file2 = readdir(dir2);

    // loop through files in both directories
    while (file1 != NULL && file2 != NULL) {

        // ignore "." and ".." files
        if (strcmp(file1->d_name, ".") == 0 || strcmp(file1->d_name, "..") == 0) {
            file1 = readdir(dir1);
            continue;
        }

        if (strcmp(file2->d_name, ".") == 0 || strcmp(file2->d_name, "..") == 0) {
            file2 = readdir(dir2);
            continue;
        }

        char path1[1000], path2[1000];
        strcpy(path1, dirPath1);
        strcat(path1, "/");
        strcat(path1, file1->d_name);

        strcpy(path2, dirPath2);
        strcat(path2, "/");
        strcat(path2, file2->d_name);

        struct stat stat1, stat2;
        int err1 = stat(path1, &stat1);
        int err2 = stat(path2, &stat2);

        // check if files exist in both directories
        if ((err1 == 0 && err2 != 0) || (err1 != 0 && err2 == 0)) {

            // delete file in directory where it exists
            if (err1 == 0) {
                int status = remove(path1);
                if (status != 0) {
                    printf("ERROR: %s\n", strerror(errno));
                }
            } else {
                int status = remove(path2);
                if (status != 0) {
                    printf("ERROR: %s\n", strerror(errno));
                }
            }
        }

        // check if files are different
        else if (stat1.st_size != stat2.st_size) {

            // overwrite file in directory where it exists
            if (stat1.st_mtime > stat2.st_mtime) {
                int fd1 = open(path1, O_RDONLY);
                int fd2 = open(path2, O_WRONLY | O_CREAT | O_TRUNC, stat1.st_mode);
                if (fd1 < 0 || fd2 < 0) {
                    printf("ERROR: %s\n", strerror(errno));
                } else {
                    char* buffer = malloc(stat1.st_size);
                    read(fd1, buffer, stat1.st_size);
                    write(fd2, buffer, stat1.st_size);
                    close(fd1);
                    close(fd2);
                    free(buffer);
                }
            } else {
                int fd1 = open(path2, O_RDONLY);
                int fd2 = open(path1, O_WRONLY | O_CREAT | O_TRUNC, stat2.st_mode);
                if (fd1 < 0 || fd2 < 0) {
                    printf("ERROR: %s\n", strerror(errno));
                } else {
                    char* buffer = malloc(stat2.st_size);
                    read(fd1, buffer, stat2.st_size);
                    write(fd2, buffer, stat2.st_size);
                    close(fd1);
                    close(fd2);
                    free(buffer);
                }
            }
        }

        file1 = readdir(dir1);
        file2 = readdir(dir2);
    }

    closedir(dir1);
    closedir(dir2);
}

int main() {

    char dirPath1[1000], dirPath2[1000];
    printf("Enter path to first directory: ");
    fgets(dirPath1, sizeof(dirPath1), stdin);
    dirPath1[strcspn(dirPath1, "\n")] = '\0'; // remove trailing newline
    printf("Enter path to second directory: ");
    fgets(dirPath2, sizeof(dirPath2), stdin);
    dirPath2[strcspn(dirPath2, "\n")] = '\0'; // remove trailing newline

    synchronizeDirs(dirPath1, dirPath2);

    printf("Directories synchronized successfully.\n");

    return 0;
}