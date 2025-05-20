//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME 100

typedef struct {
    char name[MAX_FILE_NAME];
    int size;
    char content[MAX_FILE_NAME];
} file_t;

int num_files = 0;
file_t *files = NULL;

void create_file(char *name, int size, char *content) {
    if (num_files >= MAX_FILES) {
        printf("Error: Too many files!\n");
        return;
    }

    file_t *new_file = malloc(sizeof(file_t));
    strcpy(new_file->name, name);
    new_file->size = size;
    strcpy(new_file->content, content);

    files = realloc(files, sizeof(file_t) * ++num_files);
    files[num_files - 1] = *new_file;
}

void delete_file(char *name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            free(files[i].content);
            free(files[i].name);
            free(files[i].content);
            files[i] = files[num_files - 1];
            num_files--;
            files = realloc(files, sizeof(file_t) * num_files);
            return;
        }
    }

    printf("Error: File not found!\n");
}

void rename_file(char *old_name, char *new_name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, old_name) == 0) {
            strcpy(files[i].name, new_name);
            return;
        }
    }

    printf("Error: File not found!\n");
}

void read_file(char *name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("File name: %s\n", files[i].name);
            printf("File size: %d\n", files[i].size);
            printf("File content:\n%s", files[i].content);
            return;
        }
    }

    printf("Error: File not found!\n");
}

void write_file(char *name, int size, char *content) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(files[i].content, content);
            files[i].size = size;
            printf("File updated!\n");
            return;
        }
    }

    printf("Error: File not found!\n");
}

int main() {
    create_file("test.txt", 10, "Hello, world!");
    read_file("test.txt");
    rename_file("test.txt", "hello.txt");
    read_file("hello.txt");
    write_file("hello.txt", 15, "Hello, C programming!");
    read_file("hello.txt");

    for (int i = 0; i < num_files; i++) {
        free(files[i].content);
        free(files[i].name);
    }
    free(files);

    return 0;
}