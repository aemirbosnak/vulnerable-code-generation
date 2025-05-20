//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/statvfs.h>

#define MAX_FILE_NAME_SIZE 1024
#define MAX_NUM_FILES 1000

typedef struct {
    char name[MAX_FILE_NAME_SIZE];
    unsigned long long size;
} FileInfo;

void print_file_info(FileInfo* file_info, int num_files) {
    printf("File Name\tSize\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s\t%llu\n", file_info[i].name, file_info[i].size);
    }
}

int get_file_info(const char* path, FileInfo* file_info, int num_files) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        return -1;
    }

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            if (num_files >= MAX_NUM_FILES) {
                closedir(dir);
                return num_files;
            }

            char file_path[MAX_FILE_NAME_SIZE];
            sprintf(file_path, "%s/%s", path, ent->d_name);

            struct statvfs statvfs_buf;
            if (statvfs(file_path, &statvfs_buf)!= 0) {
                closedir(dir);
                return -1;
            }

            strncpy(file_info[num_files].name, ent->d_name, MAX_FILE_NAME_SIZE - 1);
            file_info[num_files].size = statvfs_buf.f_blocks * statvfs_buf.f_frsize;
            num_files++;
        }
    }

    closedir(dir);
    return num_files;
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return -1;
    }

    char path[MAX_FILE_NAME_SIZE];
    strcpy(path, argv[1]);

    FileInfo file_info[MAX_NUM_FILES];
    int num_files = get_file_info(path, file_info, 0);

    if (num_files <= 0) {
        return -1;
    }

    print_file_info(file_info, num_files);

    return 0;
}