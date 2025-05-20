//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILE_NAME_LENGTH 1024

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    size_t size;
} file_t;

void print_files(file_t* files, int count) {
    printf("Files:\n");
    for (int i = 0; i < count; i++) {
        printf("%s (%zu bytes)\n", files[i].name, files[i].size);
    }
}

void print_bar(size_t size, size_t total) {
    int bar_width = 50;
    int filled_width = (int)((double)bar_width * (double)size / (double)total);
    for (int i = 0; i < bar_width; i++) {
        if (i < filled_width) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

void print_progress(size_t processed, size_t total) {
    printf("Progress: ");
    print_bar(processed, total);
}

void count_files(const char* directory, file_t* files, int* count) {
    DIR* dir = opendir(directory);
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            files[*count] = (file_t){
               .name = ent->d_name,
               .size = ent->d_reclen,
            };
            (*count)++;
        }
    }

    closedir(dir);
}

void analyze_disk_space(const char* directory) {
    file_t files[1024];
    int count = 0;

    count_files(directory, files, &count);

    size_t total_size = 0;
    for (int i = 0; i < count; i++) {
        total_size += files[i].size;
    }

    printf("Directory: %s\n", directory);
    printf("Total files: %d\n", count);
    printf("Total size: %zu bytes\n", total_size);

    print_files(files, count);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    analyze_disk_space(argv[1]);

    return 0;
}