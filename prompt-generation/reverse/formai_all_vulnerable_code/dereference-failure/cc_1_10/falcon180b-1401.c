//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LEN 50
#define MAX_FILE_CONTENT_LEN 1000

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    char content[MAX_FILE_CONTENT_LEN];
    int size;
} File;

int num_files = 0;
File files[MAX_FILES];

void create_file(char* name, char* content) {
    if (num_files >= MAX_FILES) {
        printf("Error: Maximum number of files reached\n");
        return;
    }

    strcpy(files[num_files].name, name);
    strcpy(files[num_files].content, content);
    files[num_files].size = strlen(content);

    num_files++;
}

void delete_file(char* name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(files[i].content, 0, sizeof(files[i].content));
            num_files--;
            return;
        }
    }

    printf("Error: File not found\n");
}

void list_files() {
    int i;

    for (i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

void read_file(char* name, char* buffer, int max_size) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strncpy(buffer, files[i].content, max_size);
            return;
        }
    }

    printf("Error: File not found\n");
}

void write_file(char* name, char* content) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(files[i].content, content);
            return;
        }
    }

    printf("Error: File not found\n");
}

int main() {
    create_file("test.txt", "Hello, World!");
    list_files();
    read_file("test.txt", "buffer", 50);
    printf("%s\n", "buffer");
    write_file("test.txt", "Hello, C Programming!");
    list_files();

    return 0;
}