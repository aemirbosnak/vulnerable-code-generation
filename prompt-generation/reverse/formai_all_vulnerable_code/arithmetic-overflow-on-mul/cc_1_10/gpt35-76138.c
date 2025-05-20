//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BLOCK_SIZE 4096

void print_size(long long size) {
    if (size < 1024) {
        printf("%lld B\n", size);
        return;
    }

    int exp = 0;
    double d_size = (double)size;
    while (d_size >= 1024 && exp < 5) {
        d_size /= 1024;
        ++exp;
    }

    char *unit;
    switch (exp) {
        case 0:
            unit = "B";
            break;
        case 1:
            unit = "KB";
            break;
        case 2:
            unit = "MB";
            break;
        case 3:
            unit = "GB";
            break;
        default:
            unit = "TB";
    }

    printf("%.2f %s\n", d_size, unit);
}

long long get_size(const char *path) {
    struct stat st;
    if (stat(path, &st) == -1) {
        printf("Could not get info for %s.\n", path);
        return 0;
    }

    if (S_ISDIR(st.st_mode)) {
        DIR *dir;
        struct dirent *dp;
        long long size = 0;

        dir = opendir(path);
        if (dir == NULL) {
            printf("Could not open directory %s.\n", path);
            return 0;
        }

        while ((dp = readdir(dir)) != NULL) {
            if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
                continue;
            }

            char file_path[1024];
            sprintf(file_path, "%s/%s", path, dp->d_name);

            size += get_size(file_path);
        }

        closedir(dir);
        return size;
    } else if (S_ISREG(st.st_mode)) {
        long long file_size = st.st_size;
        return file_size % BLOCK_SIZE == 0 ? file_size : ((file_size / BLOCK_SIZE) + 1) * BLOCK_SIZE;
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Insufficient arguments. Usage: %s <path>.\n", argv[0]);
        return 1;
    }

    long long total_size = 0;
    for (int i = 1; i < argc; ++i) {
        total_size += get_size(argv[i]);
    }

    printf("Total disk space: ");
    print_size(total_size);

    return 0;
}