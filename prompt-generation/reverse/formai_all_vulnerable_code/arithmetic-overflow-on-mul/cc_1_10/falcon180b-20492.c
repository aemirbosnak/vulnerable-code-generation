//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_CONTENT_LENGTH 1000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
} File;

File files[MAX_FILES];
int num_files;

int hash(char* name) {
    int hash_value = 0;
    while (*name) {
        hash_value = (hash_value * 31) + *name;
        name++;
    }
    return hash_value % MAX_FILES;
}

int add_file(char* name, char* content) {
    int index = hash(name);
    if (files[index].name[0] == '\0') {
        strcpy(files[index].name, name);
        strcpy(files[index].content, content);
        num_files++;
        return 0;
    } else {
        printf("File with name %s already exists.\n", name);
        return -1;
    }
}

int get_file(char* name) {
    int index = hash(name);
    if (files[index].name[0] == '\0') {
        printf("File not found.\n");
        return -1;
    } else {
        printf("File content:\n%s\n", files[index].content);
        return 0;
    }
}

int main() {
    num_files = 0;
    add_file("test1.txt", "Hello, world!");
    add_file("test2.txt", "This is a test file.");
    get_file("test1.txt");
    get_file("test2.txt");
    get_file("test3.txt");
    return 0;
}