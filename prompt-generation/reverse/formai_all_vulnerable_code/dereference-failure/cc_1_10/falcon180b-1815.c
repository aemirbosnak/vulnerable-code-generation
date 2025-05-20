//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_DIR_LEN 1024
#define MAX_FILE_LEN 1024

typedef struct _dir_info {
    char dir_name[MAX_DIR_LEN];
    unsigned long long total_size;
    unsigned long long num_files;
} DirInfo;

typedef struct _file_info {
    char file_name[MAX_FILE_LEN];
    unsigned long long file_size;
} FileInfo;

void print_dir_info(DirInfo *dir_info) {
    printf("Directory Name: %s\n", dir_info->dir_name);
    printf("Total Size: %llu bytes\n", dir_info->total_size);
    printf("Number of Files: %llu\n\n", dir_info->num_files);
}

void print_file_info(FileInfo *file_info) {
    printf("File Name: %s\n", file_info->file_name);
    printf("File Size: %llu bytes\n\n", file_info->file_size);
}

unsigned long long get_dir_size(char *dir_path) {
    DIR *dir = opendir(dir_path);
    struct dirent *ent;
    unsigned long long total_size = 0;
    int num_files = 0;

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_REG || ent->d_type == DT_LNK) {
                total_size += ent->d_off;
                num_files++;
            }
        }

        closedir(dir);
    }

    return total_size;
}

void analyze_dir(char *dir_path, int depth) {
    char full_path[MAX_DIR_LEN];
    DIR *dir;
    struct dirent *ent;

    sprintf(full_path, "%s/%s", dir_path, "");
    dir = opendir(full_path);

    if (dir!= NULL) {
        DirInfo dir_info;
        strcpy(dir_info.dir_name, dir_path);
        dir_info.total_size = get_dir_size(dir_path);
        dir_info.num_files = 0;

        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                if (strcmp(ent->d_name, ".")!= 0 && strcmp(ent->d_name, "..")!= 0) {
                    sprintf(full_path, "%s/%s", dir_path, ent->d_name);
                    analyze_dir(full_path, depth + 1);
                    dir_info.num_files++;
                }
            } else if (ent->d_type == DT_REG || ent->d_type == DT_LNK) {
                FileInfo file_info;
                strcpy(file_info.file_name, ent->d_name);
                file_info.file_size = ent->d_off;
                print_file_info(&file_info);
                dir_info.total_size += ent->d_off;
                dir_info.num_files++;
            }
        }

        closedir(dir);
        print_dir_info(&dir_info);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    analyze_dir(argv[1], 0);
    return 0;
}