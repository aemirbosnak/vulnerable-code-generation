//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

#define BUFFER_SIZE 1024

typedef struct {
    char name[BUFFER_SIZE];
    unsigned long long size;
} File;

unsigned long long get_folder_size(const char* path) {
    unsigned long long size = 0;
    DIR* dir = opendir(path);
    if (dir!= NULL) {
        struct dirent* ent;
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_REG) {
                File file;
                snprintf(file.name, BUFFER_SIZE, "%s/%s", path, ent->d_name);
                file.size = ent->d_off;
                size += file.size;
            }
        }
        closedir(dir);
    }
    return size;
}

unsigned long long get_free_space(const char* path) {
    struct statvfs buf;
    if (statvfs(path, &buf) == 0) {
        return (unsigned long long)buf.f_bfree * buf.f_bsize;
    }
    return 0;
}

void print_files(File* files, int count) {
    printf("Files:\n");
    for (int i = 0; i < count; i++) {
        printf("%-50s %10llu bytes\n", files[i].name, files[i].size);
    }
}

int main() {
    char path[BUFFER_SIZE];
    printf("Enter directory path: ");
    scanf("%s", path);

    unsigned long long size = get_folder_size(path);
    unsigned long long free_space = get_free_space(path);

    printf("\nDirectory size: %llu bytes\n", size);
    printf("Free space: %llu bytes\n", free_space);

    File* files = malloc(sizeof(File) * size / BUFFER_SIZE);
    if (files!= NULL) {
        int count = 0;
        DIR* dir = opendir(path);
        if (dir!= NULL) {
            struct dirent* ent;
            while ((ent = readdir(dir))!= NULL) {
                if (ent->d_type == DT_REG) {
                    if (count >= size / BUFFER_SIZE) {
                        break;
                    }
                    File file;
                    snprintf(file.name, BUFFER_SIZE, "%s/%s", path, ent->d_name);
                    file.size = ent->d_off;
                    files[count++] = file;
                }
            }
            closedir(dir);
        }
        print_files(files, count);
        free(files);
    }

    return 0;
}