//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define MAX_FILES 1024

typedef struct {
    char path[MAX_PATH];
    off_t size;
} File;

int compare_files(const void *a, const void *b) {
    const File *file_a = a;
    const File *file_b = b;

    return (int) (file_a->size - file_b->size);
}

void get_files(const char *path, File files[], int *num_files) {
    DIR *dir = opendir(path);

    if (dir == NULL) {
        return;
    }

    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            if (*num_files >= MAX_FILES) {
                break;
            }

            File file;
            strcpy(file.path, path);
            strcat(file.path, "/");
            strcat(file.path, ent->d_name);

            file.size = ent->d_reclen;
            files[*num_files] = file;
            (*num_files)++;
        }
    }

    closedir(dir);
}

void analyze_disk_space(const char *path) {
    File files[MAX_FILES];
    int num_files = 0;

    get_files(path, files, &num_files);

    if (num_files == 0) {
        printf("No files found.\n");
        return;
    }

    qsort(files, num_files, sizeof(File), compare_files);

    printf("Largest files:\n");
    for (int i = 0; i < num_files && i < 10; i++) {
        printf("%-40s %10ld bytes\n", files[i].path, files[i].size);
    }

    off_t total_size = 0;
    for (int i = 0; i < num_files; i++) {
        total_size += files[i].size;
    }

    printf("\nTotal disk space used: %ld bytes\n", total_size);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    analyze_disk_space(argv[1]);

    return 0;
}