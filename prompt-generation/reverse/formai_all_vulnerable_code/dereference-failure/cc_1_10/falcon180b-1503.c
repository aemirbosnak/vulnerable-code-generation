//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 1000
#define MAX_FILE_NAME_SIZE 100

typedef struct {
    char name[MAX_FILE_NAME_SIZE];
    int size;
    int is_deleted;
} file_t;

int num_files = 0;
file_t *files = NULL;

void init() {
    num_files = 0;
    files = malloc(MAX_FILES * sizeof(file_t));
    memset(files, 0, MAX_FILES * sizeof(file_t));
}

void add_file(char *name, int size) {
    if (num_files >= MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }

    strncpy(files[num_files].name, name, MAX_FILE_NAME_SIZE);
    files[num_files].size = size;
    files[num_files].is_deleted = 0;

    num_files++;
}

void delete_file(char *name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            files[i].is_deleted = 1;
            printf("File '%s' deleted.\n", name);
            return;
        }
    }

    printf("File '%s' not found.\n", name);
}

void list_files() {
    int i;

    for (i = 0; i < num_files; i++) {
        if (files[i].is_deleted == 0) {
            printf("%s (%d bytes)\n", files[i].name, files[i].size);
        }
    }
}

int main() {
    init();

    add_file("boot.c", 1000);
    add_file("main.c", 2000);

    list_files();

    delete_file("boot.c");

    list_files();

    return 0;
}