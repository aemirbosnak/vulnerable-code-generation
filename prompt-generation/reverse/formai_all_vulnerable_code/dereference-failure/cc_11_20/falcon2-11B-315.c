//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char dir1[1024], dir2[1024];
    DIR *dir1p, *dir2p;
    struct dirent *entry;
    struct stat st1, st2;
    int error = 0;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <dir1> <dir2>\n", argv[0]);
        return 1;
    }

    strcpy(dir1, argv[1]);
    strcpy(dir2, argv[2]);

    if ((dir1p = opendir(dir1)) == NULL || (dir2p = opendir(dir2)) == NULL) {
        fprintf(stderr, "Error opening directories\n");
        return 1;
    }

    while ((entry = readdir(dir1p))!= NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        strcpy(dir1 + strlen(dir1), entry->d_name);

        if (stat(dir1, &st1) == -1) {
            fprintf(stderr, "Error stat()ing %s\n", dir1);
            error = 1;
            break;
        }

        if (error == 0) {
            if (stat(dir2, &st2) == -1) {
                fprintf(stderr, "Error stat()ing %s\n", dir2);
                error = 1;
                break;
            }

            if (st1.st_dev!= st2.st_dev || st1.st_ino!= st2.st_ino) {
                fprintf(stderr, "%s: Not present in %s\n", dir1, dir2);
                error = 1;
                break;
            }
        }

        strcpy(dir2 + strlen(dir2), entry->d_name);
    }

    closedir(dir1p);
    closedir(dir2p);

    if (error == 0)
        printf("No files missing from either directory\n");

    return error;
}