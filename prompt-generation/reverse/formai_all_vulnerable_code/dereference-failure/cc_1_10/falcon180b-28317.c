//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char *name;
    int size;
} File;

typedef struct {
    File *files;
    int count;
} Directory;

Directory *create_directory() {
    Directory *dir = malloc(sizeof(Directory));
    dir->files = NULL;
    dir->count = 0;
    return dir;
}

void add_file(Directory *dir, char *name, int size) {
    File *file = malloc(sizeof(File));
    file->name = strdup(name);
    file->size = size;
    dir->files = realloc(dir->files, sizeof(File) * (dir->count + 1));
    dir->files[dir->count] = *file;
    dir->count++;
}

void delete_file(Directory *dir, char *name) {
    int i;
    for (i = 0; i < dir->count; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            free(dir->files[i].name);
            dir->files = realloc(dir->files, sizeof(File) * (dir->count - 1));
            memmove(&dir->files[i], &dir->files[i + 1], sizeof(File) * (dir->count - i - 1));
            dir->count--;
            break;
        }
    }
}

void print_directory(Directory *dir) {
    int i;
    for (i = 0; i < dir->count; i++) {
        printf("%s (%d bytes)\n", dir->files[i].name, dir->files[i].size);
    }
}

int main() {
    Directory *dir = create_directory();
    add_file(dir, "file1.txt", 10);
    add_file(dir, "file2.txt", 20);
    add_file(dir, "file3.txt", 30);
    print_directory(dir);
    delete_file(dir, "file2.txt");
    print_directory(dir);
    return 0;
}