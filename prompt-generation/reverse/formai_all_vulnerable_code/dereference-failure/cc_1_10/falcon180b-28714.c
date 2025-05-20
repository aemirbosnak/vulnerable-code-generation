//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME 100
#define MAX_FILE_SIZE 1000

typedef struct {
    char name[MAX_FILE_NAME];
    char content[MAX_FILE_SIZE];
    int size;
} File;

File* files[MAX_FILES];
int num_files = 0;

void create_file(char* name, char* content) {
    if (num_files >= MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }

    File* new_file = (File*)malloc(sizeof(File));
    strcpy(new_file->name, name);
    strcpy(new_file->content, content);
    new_file->size = strlen(content);

    files[num_files++] = new_file;
}

void delete_file(char* name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i]->name, name) == 0) {
            free(files[i]);
            files[i] = NULL;
            num_files--;
            return;
        }
    }

    printf("Error: File not found.\n");
}

void rename_file(char* old_name, char* new_name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i]->name, old_name) == 0) {
            strcpy(files[i]->name, new_name);
            return;
        }
    }

    printf("Error: File not found.\n");
}

void read_file(char* name, char* content) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i]->name, name) == 0) {
            strcpy(content, files[i]->content);
            return;
        }
    }

    printf("Error: File not found.\n");
}

void write_file(char* name, char* content) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i]->name, name) == 0) {
            strcpy(files[i]->content, content);
            return;
        }
    }

    printf("Error: File not found.\n");
}

int main() {
    create_file("test.txt", "Hello, world!");
    read_file("test.txt", "content");
    printf("%s\n", "content");

    return 0;
}