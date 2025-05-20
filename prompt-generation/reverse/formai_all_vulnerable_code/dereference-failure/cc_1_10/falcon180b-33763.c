//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char content[MAX_FILE_SIZE];
} File;

File files[MAX_FILES];
int num_files;

void init() {
    num_files = 0;
}

int create_file(char* name, int size, char* content) {
    if (num_files >= MAX_FILES) {
        printf("Error: Too many files\n");
        return -1;
    }

    strcpy(files[num_files].name, name);
    files[num_files].size = size;
    strcpy(files[num_files].content, content);

    num_files++;

    return 0;
}

int read_file(char* name, char* buffer) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(buffer, files[i].content);
            return files[i].size;
        }
    }

    printf("Error: File not found\n");
    return -1;
}

int write_file(char* name, char* content) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(files[i].content, content);
            return 0;
        }
    }

    printf("Error: File not found\n");
    return -1;
}

int delete_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(&files[i], 0, sizeof(File));
            return 0;
        }
    }

    printf("Error: File not found\n");
    return -1;
}

int main() {
    init();

    create_file("test.txt", 10, "Hello World!");
    read_file("test.txt", "buffer");
    printf("%s\n", "buffer");

    write_file("test.txt", "New content");
    read_file("test.txt", "buffer");
    printf("%s\n", "buffer");

    delete_file("test.txt");

    return 0;
}