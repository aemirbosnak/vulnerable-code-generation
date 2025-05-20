//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PATH 1024

struct file_info {
    char name[MAX_PATH];
    long size;
};

void get_file_info(const char *path, struct file_info *file_info) {
    struct stat stat_buf;
    if (stat(path, &stat_buf) == 0) {
        file_info->size = stat_buf.st_size;
        strcpy(file_info->name, path);
    }
}

void print_file_info(const struct file_info *file_info) {
    printf("%-20s %10ld\n", file_info->name, file_info->size);
}

int compare_file_info(const void *a, const void *b) {
    const struct file_info *file_info_a = (const struct file_info *)a;
    const struct file_info *file_info_b = (const struct file_info *)b;

    if (file_info_a->size > file_info_b->size) {
        return -1;
    } else if (file_info_a->size < file_info_b->size) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(argv[1]))!= NULL) {
        struct file_info *file_info_list = malloc(sizeof(struct file_info));
        int file_count = 0;

        while ((ent = readdir(dir))!= NULL) {
            char path[MAX_PATH];
            sprintf(path, "%s/%s", argv[1], ent->d_name);

            get_file_info(path, &file_info_list[file_count]);
            file_count++;
        }

        closedir(dir);

        qsort(file_info_list, file_count, sizeof(struct file_info), compare_file_info);

        for (int i = 0; i < file_count; i++) {
            print_file_info(&file_info_list[i]);
        }

        free(file_info_list);
    }

    return 0;
}