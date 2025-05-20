//Code Llama-13B DATASET v1.0 Category: File system simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_FILE_SIZE 1000

typedef struct {
    char name[MAX_FILENAME_LEN];
    char contents[MAX_FILE_SIZE];
} File;

typedef struct {
    char name[MAX_FILENAME_LEN];
    int num_files;
    File* files;
} Directory;

void create_file(Directory* dir, const char* filename, const char* contents) {
    int i;
    for (i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, filename) == 0) {
            printf("File already exists!\n");
            return;
        }
    }
    File* file = malloc(sizeof(File));
    strcpy(file->name, filename);
    strcpy(file->contents, contents);
    dir->files = realloc(dir->files, (dir->num_files + 1) * sizeof(File));
    dir->files[dir->num_files] = *file;
    dir->num_files++;
    free(file);
}

void delete_file(Directory* dir, const char* filename) {
    int i;
    for (i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, filename) == 0) {
            memmove(dir->files + i, dir->files + i + 1, (dir->num_files - i - 1) * sizeof(File));
            dir->num_files--;
            return;
        }
    }
    printf("File not found!\n");
}

void list_files(Directory* dir) {
    int i;
    for (i = 0; i < dir->num_files; i++) {
        printf("%s\n", dir->files[i].name);
    }
}

int main() {
    Directory* dir = malloc(sizeof(Directory));
    strcpy(dir->name, "root");
    dir->num_files = 0;
    dir->files = NULL;

    create_file(dir, "hello.txt", "Hello, world!");
    create_file(dir, "goodbye.txt", "Goodbye, cruel world!");
    delete_file(dir, "goodbye.txt");
    list_files(dir);

    free(dir);
    return 0;
}