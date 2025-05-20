//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    int free_space;
    char data[MAX_FILES * 100];
} FileSystem;

void init(FileSystem *fs) {
    memset(fs, 0, sizeof(FileSystem));
    fs->size = MAX_FILES * 100;
    fs->free_space = fs->size;
}

int create(FileSystem *fs, char *name, int size) {
    int i;
    for (i = 0; i < fs->size; i++) {
        if (fs->data[i] == 0) {
            fs->data[i] = 1;
            fs->free_space -= size;
            strcpy(fs->name[i], name);
            return i;
        }
    }
    printf("Error: No free space.\n");
    return -1;
}

int delete(FileSystem *fs, int index) {
    fs->data[index] = 0;
    fs->free_space += fs->size;
    return 0;
}

int read(FileSystem *fs, int index) {
    printf("File name: %s\n", fs->name[index]);
    printf("File size: %d bytes\n", fs->size);
    printf("Free space: %d bytes\n", fs->free_space);
    return 0;
}

int write(FileSystem *fs, int index, char *data) {
    strcpy(fs->data[index], data);
    return 0;
}

int main() {
    FileSystem fs;
    init(&fs);
    create(&fs, "test.txt", 10);
    read(&fs, 0);
    write(&fs, 0, "Hello, world!");
    read(&fs, 0);
    delete(&fs, 0);
    read(&fs, 0);
    return 0;
}