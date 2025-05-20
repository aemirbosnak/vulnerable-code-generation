//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <sys/stat.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    long long size;
} FileInfo;

void get_file_info(const char* path, FileInfo* file_info) {
    struct stat stat_buf;
    stat(path, &stat_buf);
    file_info->size = stat_buf.st_size;
    strncpy(file_info->path, path, MAX_PATH);
}

void print_file_info(const FileInfo* file_info) {
    printf("%s - %lld bytes\n", file_info->path, file_info->size);
}

int compare_file_info(const void* a, const void* b) {
    const FileInfo* file_info_a = (const FileInfo*)a;
    const FileInfo* file_info_b = (const FileInfo*)b;
    return strcmp(file_info_a->path, file_info_b->path);
}

void sort_file_info(FileInfo* file_info, int count) {
    qsort(file_info, count, sizeof(FileInfo), compare_file_info);
}

void get_directory_size(const char* path, long long* size) {
    struct statvfs statvfs_buf;
    statvfs(path, &statvfs_buf);
    *size = statvfs_buf.f_blocks * statvfs_buf.f_frsize;
}

void analyze_disk_space(const char* path) {
    DIR* dir;
    struct dirent* dirent;
    FileInfo file_info[1024];
    int count = 0;
    long long total_size = 0;

    dir = opendir(path);
    if (dir == NULL) {
        printf("Error: could not open directory '%s'\n", path);
        return;
    }

    while ((dirent = readdir(dir))!= NULL) {
        if (dirent->d_type == DT_DIR) {
            char subdir_path[MAX_PATH];
            snprintf(subdir_path, MAX_PATH, "%s/%s", path, dirent->d_name);
            get_directory_size(subdir_path, &total_size);
        } else {
            FileInfo* file_info_ptr = &file_info[count];
            get_file_info(dirent->d_name, file_info_ptr);
            total_size += file_info_ptr->size;
            count++;
        }
    }

    closedir(dir);

    sort_file_info(file_info, count);

    printf("Total size of '%s': %lld bytes\n", path, total_size);
    printf("Largest files:\n");
    for (int i = 0; i < count; i++) {
        print_file_info(&file_info[i]);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    analyze_disk_space(argv[1]);

    return 0;
}