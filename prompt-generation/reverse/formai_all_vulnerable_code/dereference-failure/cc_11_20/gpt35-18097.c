//FormAI DATASET v1.0 Category: File Synchronizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

void synchronize(char *directory1, char *directory2) {
    DIR *dir1 = opendir(directory1);
    DIR *dir2 = opendir(directory2);
    struct dirent *dirEntry1, *dirEntry2;
    struct stat fileStat1, fileStat2;
    char filePath1[512], filePath2[512];

    if (dir1 == NULL || dir2 == NULL) {
        printf("Error! Unable to open the directories!\n");
        exit(1);
    }

    while ((dirEntry1 = readdir(dir1)) != NULL) {
        if (strcmp(dirEntry1->d_name, ".") == 0 ||
            strcmp(dirEntry1->d_name, "..") == 0) {
            continue;
        }

        snprintf(filePath1, 512, "%s/%s", directory1, dirEntry1->d_name);
        stat(filePath1, &fileStat1);

        while ((dirEntry2 = readdir(dir2)) != NULL) {
            if (strcmp(dirEntry2->d_name, ".") == 0 ||
                strcmp(dirEntry2->d_name, "..") == 0) {
                continue;
            }

            snprintf(filePath2, 512, "%s/%s", directory2, dirEntry2->d_name);
            stat(filePath2, &fileStat2);

            if (strcmp(dirEntry1->d_name, dirEntry2->d_name) == 0) {
                if (fileStat1.st_mtime > fileStat2.st_mtime) {
                    printf("%s has been updated in folder %s!\n", dirEntry1->d_name, directory1);
                    remove(filePath2);
                    link(filePath1, filePath2);
                } else if (fileStat1.st_mtime < fileStat2.st_mtime) {
                    printf("%s has been updated in folder %s!\n", dirEntry2->d_name, directory2);
                    remove(filePath1);
                    link(filePath2, filePath1);
                } else {
                    printf("%s is already synced across both folders.\n", dirEntry1->d_name);
                }

                break;
            } else {
                if (dirEntry2->d_type == DT_DIR) {
                    synchronize(filePath1, filePath2);
                }
            }
        }

        if (dirEntry2 == NULL) {
            printf("%s does not exist in folder %s.\n", dirEntry1->d_name, directory2);
            link(filePath1, filePath2);
        }

        rewinddir(dir2);
    }

    while ((dirEntry2 = readdir(dir2)) != NULL) {
        if (strcmp(dirEntry2->d_name, ".") == 0 ||
            strcmp(dirEntry2->d_name, "..") == 0) {
            continue;
        }

        snprintf(filePath2, 512, "%s/%s", directory2, dirEntry2->d_name);

        if (access(filePath2, F_OK) == -1) {
            printf("%s does not exist in folder %s.\n", dirEntry2->d_name, directory1);
            link(filePath2, filePath1);
        }
    }

    closedir(dir1);
    closedir(dir2);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <directory1> <directory2>\n", argv[0]);
        exit(1);
    }

    if (access(argv[1], F_OK) == -1) {
        printf("Error! %s does not exist!\n", argv[1]);
        exit(1);
    }

    if (access(argv[2], F_OK) == -1) {
        printf("Error! %s does not exist!\n", argv[2]);
        exit(1);
    }

    synchronize(argv[1], argv[2]);

    printf("Synchronization complete!\n");

    return 0;
}