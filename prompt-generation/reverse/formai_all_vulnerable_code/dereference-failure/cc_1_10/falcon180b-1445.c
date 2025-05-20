//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_SIZE 1000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char data[MAX_FILE_SIZE];
} File;

File* files;
int num_files;

void init() {
    files = (File*)malloc(MAX_FILES * sizeof(File));
    num_files = 0;
}

void create_file(char* name, int size) {
    if (num_files >= MAX_FILES) {
        printf("ERROR: Maximum number of files reached.\n");
        return;
    }

    strcpy(files[num_files].name, name);
    files[num_files].size = size;
    num_files++;
}

void write_file(char* name, char* data) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(files[i].data, data);
            break;
        }
    }
}

void read_file(char* name, char* data) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(data, files[i].data);
            break;
        }
    }
}

void delete_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(files[i].name, 0, MAX_FILE_NAME_LENGTH);
            memset(files[i].data, 0, MAX_FILE_SIZE);
            break;
        }
    }
}

int main() {
    init();

    create_file("cyberpunk.txt", 5);
    write_file("cyberpunk.txt", "Neo-Tokyo");
    read_file("cyberpunk.txt", "data");
    printf("%s\n", "data");
    delete_file("cyberpunk.txt");

    return 0;
}