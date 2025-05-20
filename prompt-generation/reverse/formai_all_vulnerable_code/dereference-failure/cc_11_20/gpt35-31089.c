//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char** argv) {

    if (argc < 2) {
        printf("Error: Please provide the directory path\n");
        return 1;
    }

    DIR* dir;
    struct dirent* ent;
    struct stat st;
    char* path = argv[1];

    if ((dir = opendir(path)) == NULL) {
        printf("Error: Failed to open directory\n");
        return 1;
    }

    int totalSize = 0;

    while ((ent = readdir(dir)) != NULL) {
        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, ent->d_name);

        if (stat(fullPath, &st) == -1) {
            printf("Error: Failed to get file info\n");
            return 1;
        }

        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            printf("%s [DIR]\n", ent->d_name);

            int dirSize = 0;

            DIR* dir2 = opendir(fullPath);
            if (dir2 != NULL) {
                struct dirent* ent2;
                struct stat st2;

                while ((ent2 = readdir(dir2)) != NULL) {
                    if (strcmp(ent2->d_name, ".") == 0 || strcmp(ent2->d_name, "..") == 0) {
                        continue;
                    }

                    char fullPath2[1024];
                    snprintf(fullPath2, sizeof(fullPath2), "%s/%s", fullPath, ent2->d_name);

                    if (stat(fullPath2, &st2) == -1) {
                        printf("Error: Failed to get file info\n");
                        return 1;
                    }

                    dirSize += st2.st_size;
                }

                closedir(dir2);
            }

            printf("    Total Size: %d\n", dirSize);

            totalSize += dirSize;
        } else {
            printf("%s %llu bytes\n", ent->d_name, st.st_size);

            totalSize += st.st_size;
        }
    }

    closedir(dir);

    printf("\nTotal Disk Space Used: %d\n", totalSize);

    return 0;
}