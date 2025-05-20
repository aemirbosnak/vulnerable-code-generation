//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define MAX_FILE_NAME_LEN 1024

typedef struct {
    char filename[MAX_FILE_NAME_LEN];
    long long filesize;
} FileInfo;

void print_usage() {
    printf("Usage:./program [path]\n");
}

void print_files(char* path, int depth) {
    DIR *dir;
    struct dirent *ent;
    char next_path[MAX_FILE_NAME_LEN];
    strcpy(next_path, path);
    strcat(next_path, "/");

    if ((dir = opendir(path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                strcat(next_path, ent->d_name);
                print_files(next_path, depth + 1);
            } else {
                FileInfo file_info;
                strcpy(file_info.filename, next_path);
                strcat(file_info.filename, "/");
                strcat(file_info.filename, ent->d_name);
                struct statvfs fs_info;
                statvfs(file_info.filename, &fs_info);
                file_info.filesize = fs_info.f_blocks * fs_info.f_frsize;
                printf("%*s %10lld %s\n", depth * 2, "", file_info.filesize, file_info.filename);
            }
        }
        closedir(dir);
    }
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        print_usage();
        return 1;
    }

    print_files(argv[1], 0);

    return 0;
}