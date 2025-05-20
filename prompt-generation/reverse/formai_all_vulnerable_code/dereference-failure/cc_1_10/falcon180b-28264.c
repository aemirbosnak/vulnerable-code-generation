//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LEN 50

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    int size;
    char content[MAX_FILE_NAME_LEN];
} File;

File files[MAX_FILES];
int num_files = 0;

void create_file(char* name, int size) {
    if (num_files >= MAX_FILES) {
        printf("Error: Too many files.\n");
        return;
    }
    
    strcpy(files[num_files].name, name);
    files[num_files].size = size;
    strcpy(files[num_files].content, "");
    
    num_files++;
}

void delete_file(char* name) {
    int i;
    
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            files[i].size = 0;
            strcpy(files[i].content, "");
            break;
        }
    }
}

void write_file(char* name, char* content) {
    int i;
    
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(files[i].content, content);
            break;
        }
    }
}

void read_file(char* name, char* content) {
    int i;
    
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(content, files[i].content);
            break;
        }
    }
}

void list_files() {
    int i;
    
    for (i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

int main() {
    create_file("test.txt", 10);
    write_file("test.txt", "Hello, world!");
    list_files();
    read_file("test.txt", "content");
    printf("%s\n", "content");
    delete_file("test.txt");
    list_files();
    
    return 0;
}