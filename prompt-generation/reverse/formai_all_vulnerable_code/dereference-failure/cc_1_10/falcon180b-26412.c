//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_FILE_NAME 1024
#define MAX_PATH 4096

typedef struct {
    char file_name[MAX_FILE_NAME];
    unsigned long long file_size;
} file_info_t;

void get_file_info(const char *path, file_info_t *file_info) {
    struct stat file_stat;
    if (stat(path, &file_stat)!= 0) {
        fprintf(stderr, "Error getting file info for %s\n", path);
        exit(1);
    }

    strncpy(file_info->file_name, path, MAX_FILE_NAME - 1);
    file_info->file_name[MAX_FILE_NAME - 1] = '\0';

    file_info->file_size = file_stat.st_size;
}

void print_file_info(const file_info_t *file_info) {
    printf("%-40s %10llu bytes\n", file_info->file_name, file_info->file_size);
}

void print_folder_info(const char *folder_path) {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(folder_path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            char path[MAX_PATH];
            snprintf(path, MAX_PATH, "%s/%s", folder_path, ent->d_name);

            if (ent->d_type == DT_DIR) {
                printf("Folder: %s\n", ent->d_name);
            } else {
                file_info_t file_info;
                get_file_info(path, &file_info);
                print_file_info(&file_info);
            }
        }
        closedir(dir);
    } else {
        perror("");
        exit(1);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [folder_path]\n", argv[0]);
        exit(1);
    }

    char folder_path[MAX_PATH];
    snprintf(folder_path, MAX_PATH, "%s", argv[1]);

    print_folder_info(folder_path);

    return 0;
}