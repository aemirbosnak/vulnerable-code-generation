//FormAI DATASET v1.0 Category: File Synchronizer ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

bool sync_directory(char *dir1, char *dir2) {
    DIR *dirp1, *dirp2;
    struct dirent *dp1, *dp2;
    char path1[512], path2[512];

    if ((dirp1 = opendir(dir1)) == NULL) {
        printf("Cannot open directory: %s", dir1);
        return false;
    }

    if ((dirp2 = opendir(dir2)) == NULL) {
        printf("Cannot open directory: %s", dir2);
        return false;
    }

    while ((dp1 = readdir(dirp1)) != NULL) {
        if (strcmp(dp1->d_name, ".") == 0 || strcmp(dp1->d_name, "..") == 0) {
            continue;
        }
        snprintf(path2, sizeof(path2), "%s/%s", dir2, dp1->d_name);
        snprintf(path1, sizeof(path1), "%s/%s", dir1, dp1->d_name);

        struct stat statbuf;
        if (lstat(path1, &statbuf) != 0) {
            printf("lstat error\n");
            return false;
        }
        if (S_ISDIR(statbuf.st_mode)) {
            if (mkdir(path2, statbuf.st_mode) != 0) {
                printf("Cannot create directory: %s", path2);
                return false;
            }
            sync_directory(path1, path2);
        } else {
            int file1 = open(path1, O_RDONLY);
            int file2 = open(path2, O_RDONLY);
            if (file2 == -1) {
                // file2 does not exist, create a new file by copying file1 to file2
                file2 = open(path2, O_WRONLY | O_CREAT | O_TRUNC, statbuf.st_mode);
                if (file2 == -1) {
                    printf("Cannot create file: %s\n", path2);
                    return false;
                }
                char buffer[BUFFER_SIZE];
                size_t bytes_read = 0;
                while ((bytes_read = read(file1, buffer, BUFFER_SIZE)) > 0) {
                    if (write(file2, buffer, bytes_read) == -1) {
                        printf("Write Error\n");
                        return false;
                    }
                }
                close(file2);
            } else {
                // file2 exists, compare and synchronize if necessary
                struct stat statbuf2;
                lstat(path2, &statbuf2);
                if (statbuf.st_mtime > statbuf2.st_mtime) {
                    // file1 is more recent, overwrite file2 by copying file1 to file2
                    file2 = open(path2, O_WRONLY | O_CREAT | O_TRUNC, statbuf.st_mode);
                    if (file2 == -1) {
                        printf("Cannot create file: %s\n", path2);
                        return false;
                    }
                    char buffer[BUFFER_SIZE];
                    size_t bytes_read = 0;
                    while ((bytes_read = read(file1, buffer, BUFFER_SIZE)) > 0) {
                        if (write(file2, buffer, bytes_read) == -1) {
                            printf("Write Error\n");
                            return false;
                        }
                    }
                    close(file2);
                } else if (statbuf.st_mtime < statbuf2.st_mtime) {
                    // file2 is more recent, overwrite file1 by copying file2 to file1
                    file1 = open(path1, O_WRONLY | O_CREAT | O_TRUNC, statbuf2.st_mode);
                    if (file1 == -1) {
                        printf("Cannot create file: %s\n", path1);
                        return false;
                    }
                    char buffer[BUFFER_SIZE];
                    size_t bytes_read = 0;
                    while ((bytes_read = read(file2, buffer, BUFFER_SIZE)) > 0) {
                        if (write(file1, buffer, bytes_read) == -1) {
                            printf("Write Error\n");
                            return false;
                        }
                    }
                    close(file1);
                }
                close(file2);
            }
        }
    }
    closedir(dirp1);
    closedir(dirp2);
    return true;
}

int main() {
    char dir1[256], dir2[256];
    printf("Enter the two directories you want to synchronize: ");
    scanf("%s %s", dir1, dir2);
    if (!sync_directory(dir1, dir2)) {
        printf("Error: Synchronization failed\n");
        return 1;
    }
    printf("Synchronized Successfully!\n");
    return 0;
}