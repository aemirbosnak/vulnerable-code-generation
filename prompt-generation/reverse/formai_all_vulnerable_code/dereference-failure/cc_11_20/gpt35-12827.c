//FormAI DATASET v1.0 Category: File Synchronizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

void syncFiles(char *dir1, char *dir2) {
    DIR *dp1, *dp2;
    struct dirent *entry1, *entry2;
    struct stat statbuf1, statbuf2;
    char path1[256], path2[256];
    int isEqual = 0;

    // Open both directories
    if ((dp1 = opendir(dir1)) == NULL || (dp2 = opendir(dir2)) == NULL) {
        printf("Failed to open directory\n");
        return;
    }

    chdir(dir1);

    // Iterate through first directory
    while ((entry1 = readdir(dp1)) != NULL) {
        if (strcmp(entry1->d_name, ".") == 0 || strcmp(entry1->d_name, "..") == 0) {
            continue;
        }

        sprintf(path1, "%s/%s", dir1, entry1->d_name);
        lstat(path1, &statbuf1);

        // Check if path exists in second directory
        chdir(dir2);
        if (access(entry1->d_name, F_OK) == 0) {
            // Path exists in second directory, check if it's a file or directory
            lstat(entry1->d_name, &statbuf2);
            if (S_ISREG(statbuf1.st_mode) && S_ISREG(statbuf2.st_mode)) {
                // If both are files, check if they are equal
                FILE *fp1 = fopen(path1, "r");
                FILE *fp2 = fopen(entry1->d_name, "r");
                if (fp1 && fp2) {
                    isEqual = 1;
                    char c1 = fgetc(fp1);
                    char c2 = fgetc(fp2);
                    while (c1 != EOF && c2 != EOF) {
                        if (c1 != c2) {
                            isEqual = 0;
                            break;
                        }
                        c1 = fgetc(fp1);
                        c2 = fgetc(fp2);
                    }
                    if (c1 != c2) {
                        isEqual = 0;
                    }
                    fclose(fp1);
                    fclose(fp2);
                }
                if (!isEqual) {
                    // If files are not equal, copy file from first directory to second directory
                    chdir(dir1);
                    sprintf(path1, "%s/%s", dir1, entry1->d_name);
                    sprintf(path2, "%s/%s", dir2, entry1->d_name);
                    FILE *file1 = fopen(path1, "rb");
                    FILE *file2 = fopen(path2, "wb");
                    if (file1 && file2) {
                        char buffer[1024];
                        size_t bytes;
                        while ((bytes = fread(buffer, 1, sizeof(buffer), file1)) > 0) {
                            fwrite(buffer, 1, bytes, file2);
                        }
                        fclose(file1);
                        fclose(file2);
                    }
                    chdir(dir2);
                }
            } else if (S_ISDIR(statbuf1.st_mode) && S_ISDIR(statbuf2.st_mode)) {
                // If both are directories, recursively call syncFiles function
                syncFiles(path1, entry1->d_name);
            }
        } else {
            // Path does not exist in second directory, copy path from first directory to second directory
            chdir(dir1);
            sprintf(path1, "%s/%s", dir1, entry1->d_name);
            sprintf(path2, "%s/%s", dir2, entry1->d_name);
            if (S_ISREG(statbuf1.st_mode)) {
                // If path is a file, copy file from first directory to second directory
                FILE *file1 = fopen(path1, "rb");
                FILE *file2 = fopen(path2, "wb");
                if (file1 && file2) {
                    char buffer[1024];
                    size_t bytes;
                    while ((bytes = fread(buffer, 1, sizeof(buffer), file1)) > 0) {
                        fwrite(buffer, 1, bytes, file2);
                    }
                    fclose(file1);
                    fclose(file2);
                }
            } else if (S_ISDIR(statbuf1.st_mode)) {
                // If path is a directory, create directory in second directory
                mkdir(entry1->d_name, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
                syncFiles(path1, entry1->d_name);
            }
            chdir(dir2);
        }
    }

    // Iterate through second directory
    chdir(dir2);
    while ((entry2 = readdir(dp2)) != NULL) {
        if (strcmp(entry2->d_name, ".") == 0 || strcmp(entry2->d_name, "..") == 0) {
            continue;
        }

        sprintf(path2, "%s/%s", dir2, entry2->d_name);
        lstat(path2, &statbuf2);

        // Check if path exists in first directory
        chdir(dir1);
        if (access(entry2->d_name, F_OK) == -1) {
            // Path only exists in second directory, copy path from second directory to first directory
            chdir(dir2);
            sprintf(path1, "%s/%s", dir1, entry2->d_name);
            sprintf(path2, "%s/%s", dir2, entry2->d_name);
            if (S_ISREG(statbuf2.st_mode)) {
                // If path is a file, copy file from second directory to first directory
                FILE *file1 = fopen(path1, "wb");
                FILE *file2 = fopen(path2, "rb");
                if (file1 && file2) {
                    char buffer[1024];
                    size_t bytes;
                    while ((bytes = fread(buffer, 1, sizeof(buffer), file2)) > 0) {
                        fwrite(buffer, 1, bytes, file1);
                    }
                    fclose(file1);
                    fclose(file2);
                }
            } else if (S_ISDIR(statbuf2.st_mode)) {
                // If path is a directory, create directory in first directory
                mkdir(entry2->d_name, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
                syncFiles(entry2->d_name, path1);
            }
            chdir(dir1);
        }
    }

    closedir(dp1);
    closedir(dp2);
}

int main() {
    syncFiles("directory1", "directory2");
    return 0;
}