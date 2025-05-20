//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_SIZE 30

typedef struct {
    char name[MAX_FILE_NAME_SIZE];
    int size;
    char data[MAX_FILE_NAME_SIZE];
} File;

int num_files = 0;
File files[MAX_FILES];

void create_file(char* name, int size) {
    if (num_files >= MAX_FILES) {
        printf("Error: Too many files.\n");
        exit(1);
    }

    strcpy(files[num_files].name, name);
    files[num_files].size = size;
    memset(files[num_files].data, '\0', size);

    num_files++;
}

void delete_file(char* name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            free(files[i].data);
            memset(files[i].data, '\0', files[i].size);
            strcpy(files[i].name, "");
            num_files--;
            return;
        }
    }

    printf("Error: File not found.\n");
}

void write_to_file(char* name, char* data) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(files[i].data, data);
            return;
        }
    }

    printf("Error: File not found.\n");
}

void read_from_file(char* name, char* data) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(data, files[i].data);
            return;
        }
    }

    printf("Error: File not found.\n");
}

int main() {
    create_file("test.txt", 10);
    write_to_file("test.txt", "Hello, world!");
    read_from_file("test.txt", "test");
    printf("%s\n", "test");
    delete_file("test.txt");
    return 0;
}