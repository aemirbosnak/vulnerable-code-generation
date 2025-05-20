//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME 100
#define MAX_FILE_SIZE 1000

typedef struct {
    char name[MAX_FILE_NAME];
    int size;
    char content[MAX_FILE_SIZE];
} File;

void create_file(File *file, char *name, int size) {
    strcpy(file->name, name);
    file->size = size;
    memset(file->content, 0, sizeof(file->content));
}

void write_to_file(File *file, char *content) {
    strcat(file->content, content);
}

void read_from_file(File *file) {
    printf("File name: %s\n", file->name);
    printf("File size: %d\n", file->size);
    printf("File content:\n%s\n", file->content);
}

int main() {
    File files[MAX_FILES];
    int num_files = 0;

    while (num_files < MAX_FILES) {
        printf("Enter file name: ");
        scanf("%s", files[num_files].name);

        printf("Enter file size: ");
        scanf("%d", &files[num_files].size);

        printf("Enter file content: ");
        scanf("%s", files[num_files].content);

        num_files++;
    }

    printf("List of files:\n");
    for (int i = 0; i < num_files; i++) {
        read_from_file(&files[i]);
    }

    return 0;
}