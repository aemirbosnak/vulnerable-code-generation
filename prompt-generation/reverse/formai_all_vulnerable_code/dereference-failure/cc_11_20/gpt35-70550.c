//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

// Function to synchronize files in two directories
int sync_files(char *dir1, char *dir2) {
    struct dirent *entry;
    DIR *dir = opendir(dir1);
    if(!dir) {
        printf("Error: %s\n", strerror(errno));
        return -1;
    }
    
    while(entry = readdir(dir)) {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char path1[100], path2[100];
        sprintf(path1, "%s/%s", dir1, entry->d_name);
        sprintf(path2, "%s/%s", dir2, entry->d_name);
        
        struct stat stat1, stat2;
        if(stat(path1, &stat1) < 0) {
            printf("Error: %s\n", strerror(errno));
            return -1;
        }
        if(stat(path2, &stat2) < 0) {
            printf("Error: %s\n", strerror(errno));
            return -1;
        }
        
        if((stat1.st_mode & S_IFMT) != (stat2.st_mode & S_IFMT)) {
            // If file type is different, remove the old file and copy the new one
            if(remove(path2) != 0) {
                printf("Error: %s\n", strerror(errno));
                return -1;
            }
            if((stat1.st_mode & S_IFMT) == S_IFDIR) {
                if(mkdir(path2, stat1.st_mode) != 0) {
                    printf("Error: %s\n", strerror(errno));
                    return -1;
                }
            }
            else {
                FILE *fp1 = fopen(path1, "rb"), *fp2 = fopen(path2, "wb");
                if(fp1 == NULL || fp2 == NULL) {
                    printf("Error: %s\n", strerror(errno));
                    return -1;
                }
                char buf[1024];
                int n = 0;
                while((n = fread(buf, 1, sizeof(buf), fp1)) > 0) {
                    if(fwrite(buf, 1, n, fp2) != n) {
                        printf("Error: %s\n", strerror(errno));
                        return -1;
                    }
                }
                fclose(fp1); fclose(fp2);
            }
        }
        else {
            // If file is the same, check if it's a directory
            if((stat1.st_mode & S_IFMT) == S_IFDIR) {
                // Recursively sync the directories
                if(sync_files(path1, path2) != 0) {
                    return -1;
                }
            }
            else {
                // If file is different, copy over the new version
                FILE *fp1 = fopen(path1, "rb"), *fp2 = fopen(path2, "wb");
                if(fp1 == NULL || fp2 == NULL) {
                    printf("Error: %s\n", strerror(errno));
                    return -1;
                }
                char buf[1024];
                int n = 0;
                while((n = fread(buf, 1, sizeof(buf), fp1)) > 0) {
                    if(fwrite(buf, 1, n, fp2) != n) {
                        printf("Error: %s\n", strerror(errno));
                        return -1;
                    }
                }
                fclose(fp1); fclose(fp2);
            }
        }
    }
    closedir(dir);
    return 0;
}

int main() {
    // Example usage
    sync_files("directory1", "directory2");
    return 0;
}