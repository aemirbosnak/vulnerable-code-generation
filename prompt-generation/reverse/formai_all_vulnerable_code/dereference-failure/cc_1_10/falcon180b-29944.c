//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    size_t size;
} FileInfo;

void get_file_info(const char *path, FileInfo *info) {
    struct statvfs buf;
    if (statvfs(path, &buf) == 0) {
        info->size = buf.f_blocks * buf.f_frsize;
        strncpy(info->path, path, MAX_PATH);
    } else {
        info->size = 0;
        strcpy(info->path, "Error");
    }
}

int compare_files(const void *a, const void *b) {
    const FileInfo *file_a = (const FileInfo *)a;
    const FileInfo *file_b = (const FileInfo *)b;
    return (int)(file_b->size - file_a->size);
}

void print_files(FileInfo *files, int count) {
    qsort(files, count, sizeof(FileInfo), compare_files);
    for (int i = 0; i < count; i++) {
        printf("%-40s %10zu\n", files[i].path, files[i].size);
    }
}

void analyze_directory(const char *path) {
    DIR *dir;
    struct dirent *ent;
    FileInfo files[1024];
    int count = 0;

    if ((dir = opendir(path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_REG || ent->d_type == DT_LNK) {
                char file_path[MAX_PATH];
                snprintf(file_path, MAX_PATH, "%s/%s", path, ent->d_name);
                get_file_info(file_path, &files[count]);
                count++;
            }
        }
        closedir(dir);
    }

    print_files(files, count);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s directory\n", argv[0]);
        return 1;
    }

    analyze_directory(argv[1]);

    return 0;
}