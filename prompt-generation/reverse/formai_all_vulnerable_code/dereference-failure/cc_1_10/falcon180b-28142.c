//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 50

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char *content;
} File;

File *files[MAX_FILES];
int num_files;

int add_file(char *name, int size, char *content) {
    if (num_files >= MAX_FILES) {
        printf("Error: Maximum number of files reached\n");
        return -1;
    }

    File *file = (File *) malloc(sizeof(File));
    strncpy(file->name, name, MAX_FILE_NAME_LENGTH);
    file->size = size;
    file->content = (char *) malloc(size * sizeof(char));
    memcpy(file->content, content, size);

    files[num_files++] = file;

    return 0;
}

int remove_file(char *name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i]->name, name) == 0) {
            free(files[i]->content);
            free(files[i]);
            memmove(files + i, files + i + 1, (num_files - i - 1) * sizeof(File));
            num_files--;
            return 0;
        }
    }

    printf("Error: File not found\n");
    return -1;
}

int list_files() {
    int i;
    for (i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i]->name, files[i]->size);
    }

    return 0;
}

int main() {
    add_file("test.txt", 10, "Hello, world!");
    add_file("test2.txt", 20, "Lorem ipsum dolor sit amet.");

    list_files();

    remove_file("test.txt");

    list_files();

    return 0;
}