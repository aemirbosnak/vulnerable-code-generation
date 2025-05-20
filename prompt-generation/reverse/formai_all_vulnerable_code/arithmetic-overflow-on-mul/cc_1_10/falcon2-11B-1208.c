//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

void read_dir_info(const char* dirname, struct dirent** result) {
    DIR* d = opendir(dirname);
    struct stat st;
    if (d!= NULL) {
        while ((*result = readdir(d))!= NULL) {
            stat(dirname, &st);
            if (strcmp((*result)->d_name, ".")!= 0 && strcmp((*result)->d_name, "..")!= 0) {
                (*result)->d_type = DT_UNKNOWN;
            } else {
                (*result)->d_type = DT_DIR;
            }
        }
        closedir(d);
    } else {
        perror("opendir");
    }
}

long disk_usage(const char* path) {
    struct stat st;
    stat(path, &st);
    return st.st_blocks * st.st_blksize;
}

int main() {
    char dirname[100];
    printf("Enter a directory to analyze:\n");
    scanf("%s", dirname);

    struct dirent** entries;
    read_dir_info(dirname, entries);

    long total_usage = 0;
    for (struct dirent* entry = entries[0]; entry!= NULL; entry = entries[1]) {
        if (entry->d_type == DT_DIR) {
            total_usage += disk_usage(dirname);
            continue;
        }
        total_usage += disk_usage(dirname);
    }

    printf("Total disk usage of '%s': %ld bytes\n", dirname, total_usage);

    closedir(entries);
    free(entries);

    return 0;
}