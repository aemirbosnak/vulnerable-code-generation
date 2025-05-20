//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }

    char path[1024];
    strcpy(path, argv[1]);
    struct stat st;

    if (stat(path, &st)!= 0) {
        fprintf(stderr, "Could not stat %s: %s\n", path, strerror(errno));
        return 1;
    }

    DIR *dir = opendir(path);
    if (dir == NULL) {
        fprintf(stderr, "Could not open directory %s: %s\n", path, strerror(errno));
        return 1;
    }

    char buffer[1024];
    struct dirent *entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;

            strcat(buffer, " ");
            strcat(buffer, entry->d_name);
        }
    }

    closedir(dir);

    printf("Total size: %ld bytes\n", st.st_size);
    printf("Total files: %d\n", (int)st.st_nlink);
    printf("Total directories: %d\n", (int)st.st_blksize);
    printf("Free space: %ld bytes\n", (st.st_size - st.st_blocks * st.st_blksize));

    return 0;
}