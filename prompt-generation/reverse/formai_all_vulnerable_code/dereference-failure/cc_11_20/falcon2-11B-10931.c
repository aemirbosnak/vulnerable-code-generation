//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

struct file_info {
    char* filename;
    struct stat stat_info;
};

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <source_dir> <target_dir> <file_to_check>\n", argv[0]);
        return 1;
    }

    char* source_dir = argv[1];
    char* target_dir = argv[2];
    char* file_to_check = argv[3];

    struct file_info source_info, target_info;

    DIR* dir = opendir(source_dir);
    if (!dir) {
        printf("Failed to open source directory: %s\n", source_dir);
        return 1;
    }

    struct dirent* ent;
    while ((ent = readdir(dir))) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
            continue;

        char filename[256];
        strcpy(filename, source_dir);
        strcat(filename, "/");
        strcat(filename, ent->d_name);

        source_info.filename = filename;

        if (stat(filename, &source_info.stat_info)!= 0) {
            printf("Failed to get source file information: %s\n", filename);
            continue;
        }
    }

    closedir(dir);

    DIR* target_dir_dir = opendir(target_dir);
    if (!target_dir_dir) {
        printf("Failed to open target directory: %s\n", target_dir);
        return 1;
    }

    struct dirent* target_ent;
    while ((target_ent = readdir(target_dir_dir))) {
        if (strcmp(target_ent->d_name, ".") == 0 || strcmp(target_ent->d_name, "..") == 0)
            continue;

        char target_filename[256];
        strcpy(target_filename, target_dir);
        strcat(target_filename, "/");
        strcat(target_filename, target_ent->d_name);

        target_info.filename = target_filename;

        if (stat(target_filename, &target_info.stat_info)!= 0) {
            printf("Failed to get target file information: %s\n", target_filename);
            continue;
        }
    }

    closedir(target_dir_dir);

    int file_found = 0;
    for (int i = 0; i < 1024; i++) {
        if (strcmp(source_info.filename, target_info.filename) == 0) {
            file_found = 1;
            break;
        }
    }

    if (!file_found) {
        printf("%s is not found in the target directory.\n", file_to_check);
        return 0;
    }

    printf("%s is found in the target directory.\n", file_to_check);

    return 0;
}