//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_DIR_DEPTH 100

// Function to print the disk usage of a directory
void print_disk_usage(char* path, int depth) {
    DIR *dir;
    struct dirent *ent;
    char subpath[MAX_DIR_DEPTH];
    int total_size = 0;
    int num_files = 0;

    dir = opendir(path);

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (strcmp(ent->d_name, ".")!= 0 && strcmp(ent->d_name, "..")!= 0) {
                strcpy(subpath, path);
                strcat(subpath, "/");
                strcat(subpath, ent->d_name);

                if (ent->d_type == DT_DIR) {
                    for (int i = 0; i < depth; i++) {
                        strcat(subpath, "../");
                    }
                    print_disk_usage(subpath, depth + 1);
                } else {
                    struct stat file_stat;
                    if (stat(subpath, &file_stat) == 0) {
                        total_size += file_stat.st_size;
                        num_files++;
                    }
                }
            }
        }
        closedir(dir);

        printf("Directory: ");
        for (int i = 0; i < depth; i++) {
            printf("../");
        }
        printf("%s\n", path);
        printf("Total size: %d bytes\n", total_size);
        printf("Number of files: %d\n\n", num_files);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    char* path = argv[1];
    print_disk_usage(path, 0);

    return 0;
}