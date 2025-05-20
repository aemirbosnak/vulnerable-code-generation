//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH 1024
#define MAX_FILES 100000

typedef struct {
    char path[MAX_PATH];
    size_t size;
} FileInfo;

int compare_size(const void *a, const void *b) {
    const FileInfo *file_a = (const FileInfo *)a;
    const FileInfo *file_b = (const FileInfo *)b;

    if (file_a->size > file_b->size) {
        return -1;
    } else if (file_a->size < file_b->size) {
        return 1;
    } else {
        return 0;
    }
}

void print_files(FileInfo files[], int count) {
    qsort(files, count, sizeof(FileInfo), compare_size);

    for (int i = 0; i < count; i++) {
        printf("%s (%zu bytes)\n", files[i].path, files[i].size);
    }
}

int main() {
    char path[MAX_PATH];
    DIR *dir;
    struct dirent *ent;
    FileInfo files[MAX_FILES];
    int count = 0;

    printf("Enter the directory to analyze: ");
    scanf("%s", path);

    dir = opendir(path);

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_REG) {
                snprintf(files[count].path, MAX_PATH, "%s/%s", path, ent->d_name);
                files[count].size = ent->d_reclen;
                count++;
            }
        }

        closedir(dir);

        print_files(files, count);
    } else {
        perror("");
    }

    return 0;
}