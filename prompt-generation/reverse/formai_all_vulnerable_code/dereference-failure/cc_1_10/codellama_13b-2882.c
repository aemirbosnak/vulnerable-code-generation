//Code Llama-13B DATASET v1.0 Category: Disk space analyzer ; Style: decentralized
// Decentralized disk space analyzer
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>

struct file_info {
    char *name;
    off_t size;
};

void print_file_info(struct file_info *file) {
    printf("%s\t%ld\n", file->name, file->size);
}

void print_directory_info(char *path, struct file_info *file_list, int file_list_size) {
    DIR *dir;
    struct dirent *entry;
    int i;

    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL) {
        char full_path[PATH_MAX];
        struct stat statbuf;
        struct file_info file;

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, PATH_MAX, "%s/%s", path, entry->d_name);
        if (lstat(full_path, &statbuf) == -1) {
            perror("lstat");
            exit(1);
        }

        if (S_ISDIR(statbuf.st_mode)) {
            print_directory_info(full_path, file_list, file_list_size);
        } else {
            file.name = strdup(entry->d_name);
            file.size = statbuf.st_size;
            file_list[file_list_size++] = file;
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    char *path = argv[1];
    int file_list_size = 0;
    struct file_info *file_list;

    file_list = malloc(1024 * sizeof(struct file_info));
    if (file_list == NULL) {
        perror("malloc");
        exit(1);
    }

    print_directory_info(path, file_list, file_list_size);

    for (int i = 0; i < file_list_size; i++) {
        print_file_info(&file_list[i]);
    }

    free(file_list);
    return 0;
}