//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file {
    char name[100];
    int size;
    int ref_count;
} File;

typedef struct dir {
    char name[100];
    File **files;
    int count;
} Dir;

File *create_file(const char *name, int size) {
    File *file = (File *)malloc(sizeof(File));
    strcpy(file->name, name);
    file->size = size;
    file->ref_count = 1;
    return file;
}

void open_file(File *file) {
    printf("File opened: %s\n", file->name);
    file->ref_count++;
}

void close_file(File *file) {
    if (--file->ref_count == 0) {
        free(file);
    }
}

void list_files(Dir *dir) {
    for (int i = 0; i < dir->count; i++) {
        printf("File: %s\n", dir->files[i]->name);
    }
}

void add_file(Dir *dir, const char *name, int size) {
    File *file = create_file(name, size);
    dir->files[dir->count] = file;
    dir->count++;
}

int main() {
    Dir dir;
    strcpy(dir.name, "Documents");
    add_file(&dir, "file1.txt", 100);
    add_file(&dir, "file2.txt", 200);

    list_files(&dir);

    close_file(&dir.files[0]);
    close_file(&dir.files[1]);

    return 0;
}