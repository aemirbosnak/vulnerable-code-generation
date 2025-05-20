//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_DEPTH 1000
#define MAX_FILE_NAME_LENGTH 1024
#define MAX_PATH_LENGTH 4096

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    long size;
    int is_file;
} FileInfo;

void print_usage() {
    printf("Usage:./disk_analyzer [path]\n");
}

void print_file_info(FileInfo* file_info, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }

    if (file_info->is_file) {
        printf("%s (%ld bytes)\n", file_info->name, file_info->size);
    } else {
        printf("%s\n", file_info->name);
    }
}

void analyze_directory(const char* path, int depth) {
    DIR* dir = opendir(path);

    if (dir == NULL) {
        printf("Error: Failed to open directory %s\n", path);
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", path, entry->d_name);

        struct stat st;
        if (stat(full_path, &st) == -1) {
            printf("Error: Failed to stat file %s\n", full_path);
            continue;
        }

        FileInfo file_info = {0};
        strncpy(file_info.name, entry->d_name, MAX_FILE_NAME_LENGTH - 1);
        file_info.size = st.st_size;
        file_info.is_file = S_ISREG(st.st_mode);

        print_file_info(&file_info, depth);
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    char path[MAX_PATH_LENGTH];
    snprintf(path, MAX_PATH_LENGTH, "%s", argv[1]);

    analyze_directory(path, 0);

    return 0;
}