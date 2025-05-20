//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>

#define MAX_DIR_SIZE 1024
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_DIR_SIZE];
    int size;
} Directory;

typedef struct {
    char name[MAX_FILE_SIZE];
    int size;
} File;

void print_directory(Directory* dir, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }

    printf("%s (%d bytes)\n", dir->name, dir->size);

    DIR* dirp = opendir(dir->name);

    if (dirp!= NULL) {
        struct dirent* entry;
        while ((entry = readdir(dirp))!= NULL) {
            if (strcmp(entry->d_name, ".")!= 0 && strcmp(entry->d_name, "..")!= 0) {
                Directory child_dir;
                strcpy(child_dir.name, dir->name);
                strcat(child_dir.name, "/");
                strcat(child_dir.name, entry->d_name);

                statvfs(child_dir.name, &child_dir.size);

                print_directory(&child_dir, depth + 1);
            }
        }

        closedir(dirp);
    }
}

int main() {
    char path[MAX_DIR_SIZE];
    printf("Enter directory path: ");
    scanf("%s", path);

    Directory root_dir;
    statvfs(path, &root_dir.size);

    print_directory(&root_dir, 0);

    return 0;
}