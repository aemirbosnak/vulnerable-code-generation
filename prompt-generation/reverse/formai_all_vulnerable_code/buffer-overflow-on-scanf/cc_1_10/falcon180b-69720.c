//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

typedef struct {
    char path[1000];
    long long size;
} File;

void get_files(const char *dir, File files[], int *count) {
    DIR *d;
    struct dirent *dirp;
    d = opendir(dir);
    if (d) {
        while ((dirp = readdir(d))!= NULL) {
            if (dirp->d_type == DT_REG || dirp->d_type == DT_LNK) {
                sprintf(files[*count].path, "%s/%s", dir, dirp->d_name);
                files[*count].size = 0;
                (*count)++;
            }
        }
        closedir(d);
    }
}

void get_file_size(const char *path, long long *size) {
    struct statvfs buf;
    if (statvfs(path, &buf) == 0) {
        *size = buf.f_blocks * buf.f_frsize;
    }
}

int main() {
    int count = 0;
    File files[10000];

    char path[1000];
    printf("Enter the path: ");
    scanf("%s", path);

    get_files(path, files, &count);

    printf("\nFile\t\tSize\n");
    for (int i = 0; i < count; i++) {
        get_file_size(files[i].path, &files[i].size);
        printf("%-40s%lld\n", files[i].path, files[i].size);
    }

    return 0;
}