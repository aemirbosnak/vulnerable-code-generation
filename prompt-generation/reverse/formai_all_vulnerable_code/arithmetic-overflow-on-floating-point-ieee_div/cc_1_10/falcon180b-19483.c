//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <unistd.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    unsigned long long total_size;
    unsigned long long used_size;
    float percentage;
} FileSystem;

void get_filesystem_info(const char* path, FileSystem* fs) {
    struct statvfs buf;
    if (statvfs(path, &buf) == -1) {
        perror("statvfs");
        exit(1);
    }

    fs->total_size = buf.f_blocks * buf.f_frsize;
    fs->used_size = buf.f_blocks - buf.f_bfree;
    fs->percentage = (float)((fs->used_size * 100.0) / fs->total_size);
}

void scan_directory(const char* path, FileSystem* fs, int depth) {
    DIR* dir;
    struct dirent* ent;
    if ((dir = opendir(path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            char child_path[MAX_PATH];
            sprintf(child_path, "%s/%s", path, ent->d_name);

            if (ent->d_type == DT_DIR) {
                FileSystem child_fs;
                scan_directory(child_path, &child_fs, depth + 1);
                fs->total_size += child_fs.total_size;
                fs->used_size += child_fs.used_size;
            } else {
                fs->total_size += ent->d_reclen;
                fs->used_size += ent->d_reclen;
            }
        }
        closedir(dir);
    }
}

void print_filesystem_info(const FileSystem* fs, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%s:\n", fs->path);
    printf("  Total size: %lld bytes\n", fs->total_size);
    printf("  Used size: %lld bytes\n", fs->used_size);
    printf("  Percentage: %.2f%%\n", fs->percentage);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    FileSystem fs;
    get_filesystem_info(argv[1], &fs);

    scan_directory(argv[1], &fs, 0);

    print_filesystem_info(&fs, 0);

    return 0;
}