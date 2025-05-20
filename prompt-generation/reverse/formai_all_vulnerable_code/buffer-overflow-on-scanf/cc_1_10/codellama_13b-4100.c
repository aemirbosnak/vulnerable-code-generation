//Code Llama-13B DATASET v1.0 Category: File system simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

typedef struct {
    char name[100];
    int size;
} File;

typedef struct {
    File *files;
    int num_files;
} Directory;

void create_file(Directory *dir, char *name, int size) {
    // Check if the file already exists
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            printf("File already exists.\n");
            return;
        }
    }

    // Add the file to the directory
    File *new_file = (File *)malloc(sizeof(File));
    strcpy(new_file->name, name);
    new_file->size = size;
    dir->files = (File *)realloc(dir->files, (dir->num_files + 1) * sizeof(File));
    dir->files[dir->num_files++] = *new_file;
}

void delete_file(Directory *dir, char *name) {
    // Check if the file exists
    int index = -1;
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("File does not exist.\n");
        return;
    }

    // Remove the file from the directory
    for (int i = index; i < dir->num_files - 1; i++) {
        dir->files[i] = dir->files[i + 1];
    }
    dir->files = (File *)realloc(dir->files, (dir->num_files - 1) * sizeof(File));
    dir->num_files--;
}

void list_files(Directory *dir) {
    for (int i = 0; i < dir->num_files; i++) {
        printf("%s\n", dir->files[i].name);
    }
}

int main() {
    Directory dir;
    dir.num_files = 0;
    dir.files = NULL;

    char command[BUFFER_SIZE];
    while (1) {
        printf("> ");
        scanf("%s", command);
        if (strcmp(command, "create") == 0) {
            char name[100];
            int size;
            scanf("%s %d", name, &size);
            create_file(&dir, name, size);
        } else if (strcmp(command, "delete") == 0) {
            char name[100];
            scanf("%s", name);
            delete_file(&dir, name);
        } else if (strcmp(command, "list") == 0) {
            list_files(&dir);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}