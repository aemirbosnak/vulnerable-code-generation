//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_SIZE 1024

typedef struct {
    char *name;
    long long size;
} file_t;

void add_file(file_t *files, int *count, char *name, long long size) {
    if (*count >= MAX_SIZE) {
        printf("Error: Too many files.\n");
        exit(1);
    }
    files[*count].name = strdup(name);
    files[*count].size = size;
    (*count)++;
}

int compare_files(const void *a, const void *b) {
    file_t *file1 = (file_t *)a;
    file_t *file2 = (file_t *)b;
    return (int)(file2->size - file1->size);
}

void print_files(file_t *files, int count) {
    qsort(files, count, sizeof(file_t), compare_files);
    for (int i = 0; i < count; i++) {
        printf("%s (%lld bytes)\n", files[i].name, files[i].size);
    }
}

void analyze_directory(char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Error: Could not open directory.\n");
        exit(1);
    }
    struct dirent *ent;
    file_t files[MAX_SIZE];
    int count = 0;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            char *name = ent->d_name;
            struct stat st;
            if (stat(name, &st) == -1) {
                printf("Error: Could not stat file.\n");
                exit(1);
            }
            long long size = st.st_size;
            add_file(files, &count, name, size);
        }
    }
    closedir(dir);
    print_files(files, count);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }
    analyze_directory(argv[1]);
    return 0;
}