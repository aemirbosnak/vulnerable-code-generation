//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>

#define MAX_FILE_NAME_LENGTH 1024
#define MAX_FILE_SIZE (1024 * 1024 * 1024)

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    off_t size;
} FileInfo;

int compare_files(const void *a, const void *b) {
    const FileInfo *file_a = (const FileInfo *) a;
    const FileInfo *file_b = (const FileInfo *) b;
    return strcmp(file_a->name, file_b->name);
}

void print_files(FileInfo *files, int count) {
    printf("Files sorted by size:\n");
    for (int i = 0; i < count; i++) {
        printf("%-30s %10ld bytes\n", files[i].name, files[i].size);
    }
}

void analyze_disk_space(const char *path) {
    DIR *dir;
    struct dirent *ent;
    FileInfo files[MAX_FILE_NAME_LENGTH];
    int count = 0;
    off_t total_size = 0;

    if ((dir = opendir(path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_REG || ent->d_type == DT_LNK) {
                if (count >= MAX_FILE_NAME_LENGTH) {
                    printf("Error: Too many files!\n");
                    exit(1);
                }
                strcpy(files[count].name, ent->d_name);
                if (stat(ent->d_name, &files[count].size) == -1) {
                    printf("Error: %s\n", strerror(errno));
                    exit(1);
                }
                total_size += files[count].size;
                count++;
            }
        }
        closedir(dir);
    } else {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    qsort(files, count, sizeof(FileInfo), compare_files);
    print_files(files, count);

    printf("\nTotal disk space used: %ld bytes\n", total_size);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    analyze_disk_space(argv[1]);

    return 0;
}