//FormAI DATASET v1.0 Category: File Synchronizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
    printf("Wow! Welcome to the File Synchronizer Program!\n");

    if(argc != 3) {
        printf("Oops! Please provide two directories to synchronize.\n");
        exit(EXIT_FAILURE);
    }

    DIR* dir1 = opendir(argv[1]);
    if(dir1 == NULL) {
        printf("Oh no! Directory %s does not exist.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    DIR* dir2 = opendir(argv[2]);
    if(dir2 == NULL) {
        printf("Oh no! Directory %s does not exist.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    printf("Wow! Both directories exist. Let's start synchronizing!\n");

    struct dirent* entry1;
    struct dirent* entry2;

    while((entry1 = readdir(dir1)) && (entry2 = readdir(dir2))) {
        if(strcmp(entry1->d_name, ".") == 0 || strcmp(entry1->d_name, "..") == 0 || strcmp(entry2->d_name, ".") == 0 || strcmp(entry2->d_name, "..") == 0) {
            continue;
        }

        char path1[512];
        char path2[512];

        snprintf(path1, sizeof(path1), "%s/%s", argv[1], entry1->d_name);
        snprintf(path2, sizeof(path2), "%s/%s", argv[2], entry2->d_name);

        struct stat stat1;
        struct stat stat2;

        if(stat(path1, &stat1) == -1) {
            printf("Oops! Unable to get stat info for %s\n", path1);
            continue;
        }

        if(stat(path2, &stat2) == -1) {
            printf("Oops! Unable to get stat info for %s\n", path2);
            continue;
        }

        if(S_ISDIR(stat1.st_mode) == 1) {
            printf("Info: Directory %s found in %s\n", entry1->d_name, argv[1]);
            if(S_ISDIR(stat2.st_mode) == 1) {
                printf("Info: Directory %s found in %s\n", entry2->d_name, argv[2]);

                printf("Info: Checking if content of both directories is the same.\n");

                char new_path1[512];
                char new_path2[512];

                // Synchronizing content of both directories
                snprintf(new_path1, sizeof(new_path1), "%s/%s", path1, "");
                snprintf(new_path2, sizeof(new_path2), "%s/%s", path2, "");

                char command[1024];
                snprintf(command, sizeof(command), "rsync -av --delete %s %s", new_path1, new_path2);

                printf("Info: Running rsync command: %s\n", command);

                int result = system(command);
                if(result < 0) {
                    printf("Oops! Unable to synchronize directories %s and %s\n", argv[1], argv[2]);
                }
                else {
                    printf("Wow! Successfully synchronized directories %s and %s\n", argv[1], argv[2]);
                }
            }
            else {
                printf("Info: Directory %s not found in %s\n", entry2->d_name, argv[2]);
                printf("Info: New directory %s to be created in %s\n", entry2->d_name, argv[2]);

                int mkdir_result = mkdir(path2, S_IRWXU | S_IRWXG | S_IRWXO);
                if(mkdir_result != 0) {
                    printf("Oops! Unable to create directory %s\n", path2);
                }
                else {
                    printf("Wow! Successfully created directory %s\n", path2);
                }
            }
        }
        else {
            printf("Info: File %s found in %s\n", entry1->d_name, argv[1]);
            if(S_ISDIR(stat2.st_mode) == 1) {
                printf("Info: Directory %s not found in %s\n", entry1->d_name, argv[2]);
                printf("Info: New directory %s to be created in %s\n", entry1->d_name, argv[2]);

                char new_path[512];
                snprintf(new_path, sizeof(new_path), "%s/%s", path2, "");

                int mkdir_result = mkdir(new_path, S_IRWXU | S_IRWXG | S_IRWXO);
                if(mkdir_result != 0) {
                    printf("Oops! Unable to create directory %s\n", new_path);
                    continue;
                }
                else {
                    printf("Wow! Successfully created directory %s\n", new_path);
                }
            }

            printf("Info: Copying file %s to %s\n", entry1->d_name, argv[2]);
            char command[1024];
            snprintf(command, sizeof(command), "cp %s %s", path1, path2);

            int result = system(command);
            if(result != 0) {
                printf("Oops! Unable to copy file %s to %s\n", path1, path2);
            }
            else {
                printf("Wow! File %s successfully copied to %s\n", path1, path2);
            }
        }
    }

    closedir(dir1);
    closedir(dir2);

    return 0;
}