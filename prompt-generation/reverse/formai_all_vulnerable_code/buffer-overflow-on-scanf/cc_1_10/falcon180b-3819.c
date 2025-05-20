//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILE_NAME 1024

typedef struct {
    char* name;
    long long size;
} file_info;

int compare_file_info(const void* a, const void* b) {
    const file_info* fa = a;
    const file_info* fb = b;

    if (fa->size > fb->size) {
        return -1;
    } else if (fa->size < fb->size) {
        return 1;
    } else {
        return 0;
    }
}

void get_file_info(const char* dir_path, file_info* file_array, int* num_files) {
    DIR* dir = opendir(dir_path);
    struct dirent* entry;

    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_REG || entry->d_type == DT_LNK) {
            char file_path[MAX_FILE_NAME];
            sprintf(file_path, "%s/%s", dir_path, entry->d_name);

            struct stat stat_buf;
            stat(file_path, &stat_buf);

            file_info file_info = {
               .name = strdup(entry->d_name),
               .size = stat_buf.st_size
            };

            file_array[*num_files] = file_info;
            (*num_files)++;
        }
    }

    closedir(dir);
}

void print_file_info(file_info* file_array, int num_files) {
    printf("File Name\tSize\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s\t%lld\n", file_array[i].name, file_array[i].size);
    }
}

void main() {
    char dir_path[MAX_FILE_NAME];
    printf("Enter directory path: ");
    scanf("%s", dir_path);

    file_info* file_array = malloc(MAX_FILE_NAME * sizeof(file_info));
    int num_files = 0;

    get_file_info(dir_path, file_array, &num_files);

    printf("Before sorting:\n");
    print_file_info(file_array, num_files);

    qsort(file_array, num_files, sizeof(file_info), compare_file_info);

    printf("After sorting by file size (descending order):\n");
    print_file_info(file_array, num_files);

    free(file_array);
}