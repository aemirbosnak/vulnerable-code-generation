//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_FILE_NAME 256
#define MAX_DIR_NAME 256

typedef struct {
    char dir_path[MAX_DIR_NAME];
    off_t total_size;
    int num_files;
} dir_info_t;

void display_usage(char *program_name) {
    printf("Usage: %s [directory]\n", program_name);
}

void process_dir(char *dir_path, dir_info_t *info) {
    DIR *d;
    struct dirent *dir;
    d = opendir(dir_path);
    if (d == NULL) {
        perror("opendir");
        exit(1);
    }
    info->num_files = 0;
    info->total_size = 0;
    while ((dir = readdir(d))!= NULL) {
        if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
            continue;
        info->num_files++;
        char file_path[MAX_FILE_NAME];
        sprintf(file_path, "%s/%s", dir_path, dir->d_name);
        struct stat st;
        stat(file_path, &st);
        info->total_size += st.st_size;
    }
    closedir(d);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        display_usage(argv[0]);
        return 1;
    }
    char dir_path[MAX_DIR_NAME];
    strcpy(dir_path, argv[1]);
    dir_info_t info;
    process_dir(dir_path, &info);
    printf("Directory: %s\n", dir_path);
    printf("Total files: %d\n", info.num_files);
    printf("Total size: %ld bytes\n", info.total_size);
    return 0;
}