//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SYSTEM_SIZE 1000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
} File;

typedef struct {
    File *files[MAX_FILE_SYSTEM_SIZE];
    int num_files;
} FileSystem;

void create_file(FileSystem *fs, char *name, int size) {
    File *file = malloc(sizeof(File));
    strcpy(file->name, name);
    file->size = size;
    fs->files[fs->num_files++] = file;
}

void delete_file(FileSystem *fs, char *name) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            free(fs->files[i]);
            fs->files[i] = fs->files[--fs->num_files];
            break;
        }
    }
}

void list_files(FileSystem *fs) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        printf("%s (%d bytes)\n", fs->files[i]->name, fs->files[i]->size);
    }
}

int main() {
    FileSystem fs;
    fs.num_files = 0;

    create_file(&fs, "test.txt", 10);
    create_file(&fs, "example.txt", 20);

    list_files(&fs);

    delete_file(&fs, "test.txt");

    list_files(&fs);

    return 0;
}