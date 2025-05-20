//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_FILE_SIZE 1000000

typedef struct {
    char *name;
    int size;
} File;

typedef struct {
    File *files;
    int count;
} FileSystem;

void initFileSystem(FileSystem *fs) {
    fs->files = NULL;
    fs->count = 0;
}

void addFile(FileSystem *fs, char *name, int size) {
    File *file = malloc(sizeof(File));
    file->name = strdup(name);
    file->size = size;
    fs->files = realloc(fs->files, sizeof(File) * ++fs->count);
    fs->files[fs->count - 1] = *file;
}

int main() {
    char input[MAX_FILE_SIZE];
    fgets(input, MAX_FILE_SIZE, stdin);
    FileSystem fs;
    initFileSystem(&fs);
    char *token = strtok(input, "\n");
    while (token!= NULL) {
        if (strlen(token) > 0) {
            char *filename = strtok(token, ":");
            int filesize = atoi(strtok(NULL, ":"));
            addFile(&fs, filename, filesize);
        }
        token = strtok(NULL, "\n");
    }
    printf("Files in the system:\n");
    for (int i = 0; i < fs.count; i++) {
        printf("%s (%d bytes)\n", fs.files[i].name, fs.files[i].size);
    }
    return 0;
}