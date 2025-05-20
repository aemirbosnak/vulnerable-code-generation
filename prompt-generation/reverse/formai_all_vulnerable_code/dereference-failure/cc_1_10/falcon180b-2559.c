//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_SYSTEM_SIZE 100

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
} File;

typedef struct {
    File *files;
    int num_files;
} FileSystem;

void init_filesystem(FileSystem *fs) {
    fs->files = (File *) malloc(MAX_FILE_SYSTEM_SIZE * sizeof(File));
    fs->num_files = 0;
}

int add_file(FileSystem *fs, char *name, int size) {
    if (fs->num_files >= MAX_FILE_SYSTEM_SIZE) {
        printf("Error: File system is full.\n");
        return -1;
    }

    File *file = &(fs->files[fs->num_files]);
    strcpy(file->name, name);
    file->size = size;

    fs->num_files++;

    return 0;
}

int remove_file(FileSystem *fs, char *name) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            fs->num_files--;
            return 0;
        }
    }

    printf("Error: File not found.\n");
    return -1;
}

int list_files(FileSystem *fs) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        printf("%s (%d bytes)\n", fs->files[i].name, fs->files[i].size);
    }

    return 0;
}

int main() {
    FileSystem fs;
    init_filesystem(&fs);

    add_file(&fs, "test.txt", 10);
    add_file(&fs, "example.jpg", 20);

    list_files(&fs);

    remove_file(&fs, "test.txt");

    list_files(&fs);

    return 0;
}