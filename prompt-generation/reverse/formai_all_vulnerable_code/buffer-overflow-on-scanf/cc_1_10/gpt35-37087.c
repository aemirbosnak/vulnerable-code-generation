//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// structure to store file details
struct file_info {
    char* name;
    off_t size;
};

int compare(const void* first, const void* second) {
    // typecasting the void* to file_info* for accessing the size field
    struct file_info* f = *(struct file_info**) first;
    struct file_info* s = *(struct file_info**) second;
    // sorting based on file size in descending order
    return s->size - f->size;
}

void analyze_disk_space(char* path) {

    DIR* directory = opendir(path);
    if (!directory) {
        printf("Error: Unable to open directory %s\n", path);
        return;
    }

    printf("Analyzing disk space for directory %s...\n", path);

    // to store file details
    struct file_info** files = (struct file_info**) malloc(sizeof(struct file_info*) * 1000);

    struct dirent* dir_entry;
    int file_count = 0;
    while ((dir_entry = readdir(directory))) {
        if (dir_entry->d_type == DT_REG) {
            char* file_path = (char*) malloc(strlen(path) + strlen(dir_entry->d_name) + 2);
            sprintf(file_path, "%s/%s", path, dir_entry->d_name);
            struct stat file_stat;
            if (stat(file_path, &file_stat) == -1) {
                printf("Error: Unable to stat file %s\n", file_path);
                continue;
            }
            // storing file details
            struct file_info* file = (struct file_info*) malloc(sizeof(struct file_info));
            file->name = dir_entry->d_name;
            file->size = file_stat.st_size;
            files[file_count++] = file;
            free(file_path);
        }
    }
    closedir(directory);

    // sorting files based on their size
    qsort(files, file_count, sizeof(struct file_info*), compare);
    
    printf("\nLargest files:\n");
    for (int i = 0; i < 10 && i < file_count; i++) {
        float size_in_kb = files[i]->size / 1024.0;
        printf("%d. %s (%.2f KB)\n", i + 1, files[i]->name, size_in_kb);
    }

    // to calculate total disk space occupied by files
    off_t total_size = 0;
    for (int i = 0; i < file_count; i++) {
        total_size += files[i]->size;
    }
    printf("\nTotal disk space occupied by files in %s: %.2f MB\n", path, total_size / 1024.0 / 1024);

    // freeing allocated memory
    for (int i = 0; i < file_count; i++) {
        free(files[i]);
    }
    free(files);
}

int main() {
    char path[1000];
    printf("Enter the path to analyze: ");
    scanf("%s", path);
    analyze_disk_space(path);
    return 0;
}