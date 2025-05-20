//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char content[MAX_FILE_SIZE];
} File;

File* create_file(char* name, int size) {
    File* file = (File*) malloc(sizeof(File));
    strcpy(file->name, name);
    file->size = size;
    file->content[0] = '\0';
    return file;
}

int write_file(File* file, char* content) {
    int i = 0;
    while (i < file->size && content[i]!= '\0') {
        strcat(file->content, &content[i]);
        i++;
    }
    return i;
}

int read_file(File* file, char* content) {
    strcpy(content, file->content);
    return strlen(content);
}

void delete_file(File* file) {
    free(file);
}

void list_files(File* files[], int count) {
    printf("File Name\t\tSize\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%d\n", files[i]->name, files[i]->size);
    }
}

int main() {
    File* root = create_file("/", 0);
    File* file1 = create_file("file1.txt", 10);
    File* file2 = create_file("file2.txt", 20);
    root->content[0] = '\0';
    strcat(root->content, "file1.txt");
    strcat(root->content, "file2.txt");
    list_files(root->content, strlen(root->content));
    write_file(file1, "Hello, World!");
    read_file(file1, "");
    delete_file(file2);
    list_files(root->content, strlen(root->content));
    return 0;
}