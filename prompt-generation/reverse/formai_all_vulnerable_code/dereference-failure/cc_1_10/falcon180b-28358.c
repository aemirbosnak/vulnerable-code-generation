//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>

#define MAX_PATH 256
#define MAX_FILES 100
#define MAX_NAME 32
#define MAX_SIZE 1024

typedef struct {
    char name[MAX_NAME];
    int size;
} File;

typedef struct {
    char path[MAX_PATH];
    int num_files;
    File *files;
} Directory;

Directory *create_directory(char *path) {
    Directory *dir = malloc(sizeof(Directory));
    strcpy(dir->path, path);
    dir->num_files = 0;
    dir->files = NULL;
    return dir;
}

int add_file(Directory *dir, char *name, int size) {
    if (dir->num_files >= MAX_FILES) {
        printf("Directory is full.\n");
        return -1;
    }
    File *file = malloc(sizeof(File));
    strcpy(file->name, name);
    file->size = size;
    dir->files = realloc(dir->files, sizeof(File) * (dir->num_files + 1));
    dir->files[dir->num_files] = *file;
    dir->num_files++;
    return 0;
}

int remove_file(Directory *dir, char *name) {
    int i;
    for (i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            free(dir->files[i].name);
            free(dir->files[i].name);
            dir->files = realloc(dir->files, sizeof(File) * (dir->num_files - 1));
            memmove(&dir->files[i], &dir->files[i+1], sizeof(File) * (dir->num_files - i - 1));
            dir->num_files--;
            return 0;
        }
    }
    printf("File not found.\n");
    return -1;
}

int list_files(Directory *dir) {
    int i;
    for (i = 0; i < dir->num_files; i++) {
        printf("%s (%d bytes)\n", dir->files[i].name, dir->files[i].size);
    }
}

int main() {
    Directory *root = create_directory("/");
    add_file(root, "file1.txt", 10);
    add_file(root, "file2.txt", 20);
    add_file(root, "file3.txt", 30);
    list_files(root);
    remove_file(root, "file2.txt");
    list_files(root);
    return 0;
}