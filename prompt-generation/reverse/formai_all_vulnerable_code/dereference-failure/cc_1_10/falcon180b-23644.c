//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 10000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_SIZE];
    int size;
} File;

File* files = NULL;
int num_files = 0;

void create_file(const char* name) {
    File* new_file = malloc(sizeof(File));
    strcpy(new_file->name, name);
    new_file->size = 0;
    files = realloc(files, sizeof(File) * ++num_files);
    files[num_files - 1] = *new_file;
    free(new_file);
}

File* open_file(const char* name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            return &files[i];
        }
    }
    return NULL;
}

void write_to_file(File* file, const char* content) {
    int content_length = strlen(content);
    if (file->size + content_length > MAX_FILE_SIZE) {
        printf("Error: File is full.\n");
        return;
    }
    strcat(file->content, content);
    file->size += content_length;
}

void read_from_file(File* file) {
    printf("%s:\n%s\n", file->name, file->content);
}

void delete_file(const char* name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            free(files[i].content);
            files = realloc(files, sizeof(File) * --num_files);
            return;
        }
    }
}

int main() {
    create_file("test.txt");
    File* file = open_file("test.txt");
    write_to_file(file, "Hello, world!");
    read_from_file(file);
    delete_file("test.txt");
    return 0;
}