//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/statvfs.h>

#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_SIZE];
    int size;
} File;

void read_directory(const char* path, int level) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Failed to open directory %s\n", path);
        return;
    }

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            char new_path[strlen(path) + strlen(ent->d_name) + 2];
            strcpy(new_path, path);
            strcat(new_path, "/");
            strcat(new_path, ent->d_name);
            read_directory(new_path, level + 1);
        } else {
            File file;
            strcpy(file.name, ent->d_name);
            file.size = ent->d_reclen;
            printf("%*s %10d bytes\n", level * 4, "", file.size);
        }
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s directory\n", argv[0]);
        return 1;
    }

    char path[strlen(argv[1]) + 1];
    strcpy(path, argv[1]);

    read_directory(path, 0);

    return 0;
}