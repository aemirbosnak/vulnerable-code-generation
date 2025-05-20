//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <directory1> <directory2>\n", argv[0]);
        return 1;
    }

    DIR *dir1, *dir2;
    struct dirent *ent;
    struct stat st1, st2;

    if ((dir1 = opendir(argv[1])) == NULL || (dir2 = opendir(argv[2])) == NULL) {
        perror("opendir");
        return 1;
    }

    while ((ent = readdir(dir1))!= NULL) {
        if (ent->d_type == DT_DIR) {
            if (ent->d_name[0]!= '.') {
                stat(ent->d_name, &st1);
            }
        } else if (ent->d_type == DT_REG) {
            stat(ent->d_name, &st1);
        }
    }

    while ((ent = readdir(dir2))!= NULL) {
        if (ent->d_type == DT_DIR) {
            if (ent->d_name[0]!= '.') {
                stat(ent->d_name, &st2);
            }
        } else if (ent->d_type == DT_REG) {
            stat(ent->d_name, &st2);
        }
    }

    closedir(dir1);
    closedir(dir2);

    if (stat(".", &st1) == 0) {
        stat(argv[1], &st2);
        printf("Directory %s is up to date.\n", argv[1]);
    } else {
        if (stat(argv[1], &st1)!= 0) {
            printf("Directory %s does not exist.\n", argv[1]);
        } else {
            if (st1.st_mode & S_IFDIR) {
                printf("Directory %s is newer than %s.\n", argv[1], argv[2]);
            } else {
                if (st2.st_mode & S_IFDIR) {
                    printf("Directory %s is newer than %s.\n", argv[2], argv[1]);
                } else {
                    printf("File %s is newer than %s.\n", argv[2], argv[1]);
                }
            }
        }
    }

    return 0;
}