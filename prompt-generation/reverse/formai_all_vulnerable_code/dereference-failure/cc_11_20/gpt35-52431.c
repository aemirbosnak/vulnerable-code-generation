//FormAI DATASET v1.0 Category: File Synchronizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>

#define MAX_PATH_LENGTH 1000 // maximum path size

// Function to synchronize files between directories
void sync_files(char *dir1_path, char *dir2_path)
{
    DIR *dir1, *dir2;
    struct dirent *entry1, *entry2;
    struct stat st1, st2;
    char file1_path[MAX_PATH_LENGTH], file2_path[MAX_PATH_LENGTH];
    int fd1, fd2;
    char buf[BUFSIZ];
    ssize_t nbytes;

    // Open the directories for reading
    dir1 = opendir(dir1_path);
    if (dir1 == NULL) {
        printf("Error opening directory %s: %s\n", dir1_path, strerror(errno));
        exit(1);
    }

    dir2 = opendir(dir2_path);
    if (dir2 == NULL) {
        printf("Error opening directory %s: %s\n", dir2_path, strerror(errno));
        exit(1);
    }

    // Loop over all files in the first directory
    while ((entry1 = readdir(dir1)) != NULL) {
        // Ignore . and .. entries
        if (strcmp(entry1->d_name, ".") == 0 || strcmp(entry1->d_name, "..") == 0) {
            continue;
        }

        // Construct the full path of the file in the first directory
        snprintf(file1_path, MAX_PATH_LENGTH, "%s/%s", dir1_path, entry1->d_name);

        // Get the file status information
        if (lstat(file1_path, &st1) == -1) {
            printf("Error retrieving file status for %s: %s\n", file1_path, strerror(errno));
            continue;
        }

        // Construct the full path of the file in the second directory
        snprintf(file2_path, MAX_PATH_LENGTH, "%s/%s", dir2_path, entry1->d_name);

        // Check if the file exists in the second directory
        if (lstat(file2_path, &st2) == -1) {
            // If the file exists only in the first directory, copy it over to the second directory
            fd1 = open(file1_path, O_RDONLY);
            if (fd1 == -1) {
                printf("Error opening file %s: %s\n", file1_path, strerror(errno));
                continue;
            }

            fd2 = open(file2_path, O_WRONLY | O_CREAT | O_TRUNC, st1.st_mode);
            if (fd2 == -1) {
                printf("Error creating file %s: %s\n", file2_path, strerror(errno));
                continue;
            }

            while ((nbytes = read(fd1, buf, BUFSIZ)) > 0) {
                if (write(fd2, buf, nbytes) != nbytes) {
                    printf("Error writing to file %s: %s\n", file2_path, strerror(errno));
                    continue;
                }
            }

            close(fd1);
            close(fd2);

        } else {
            // If the file exists in both directories, check if they are the same
            if (st1.st_mtime > st2.st_mtime) {
                // If the file in the first directory is newer, copy it over to the second directory
                fd1 = open(file1_path, O_RDONLY);
                if (fd1 == -1) {
                    printf("Error opening file %s: %s\n", file1_path, strerror(errno));
                    continue;
                }

                fd2 = open(file2_path, O_WRONLY | O_TRUNC);
                if (fd2 == -1) {
                    printf("Error opening file %s: %s\n", file2_path, strerror(errno));
                    continue;
                }

                while ((nbytes = read(fd1, buf, BUFSIZ)) > 0) {
                    if (write(fd2, buf, nbytes) != nbytes) {
                        printf("Error writing to file %s: %s\n", file2_path, strerror(errno));
                        continue;
                    }
                }

                close(fd1);
                close(fd2);

            } else if (st1.st_mtime < st2.st_mtime) {
                // If the file in the second directory is newer, copy it over to the first directory
                fd2 = open(file2_path, O_RDONLY);
                if (fd2 == -1) {
                    printf("Error opening file %s: %s\n", file2_path, strerror(errno));
                    continue;
                }

                fd1 = open(file1_path, O_WRONLY | O_TRUNC);
                if (fd1 == -1) {
                    printf("Error opening file %s: %s\n", file1_path, strerror(errno));
                    continue;
                }

                while ((nbytes = read(fd2, buf, BUFSIZ)) > 0) {
                    if (write(fd1, buf, nbytes) != nbytes) {
                        printf("Error writing to file %s: %s\n", file1_path, strerror(errno));
                        continue;
                    }
                }

                close(fd1);
                close(fd2);
            }
        }
    }

    // Close the directories
    closedir(dir1);
    closedir(dir2);
}

int main(int argc, char *argv[])
{
    char *dir1_path, *dir2_path;

    // Make sure the user has provided two directory paths as command line arguments
    if (argc != 3) {
        printf("Usage: %s <dir1> <dir2>\n", argv[0]);
        exit(1);
    }

    dir1_path = argv[1];
    dir2_path = argv[2];

    // Synchronize the files between the two directories
    sync_files(dir1_path, dir2_path);

    printf("Files synchronized successfully!\n");

    return 0;
}