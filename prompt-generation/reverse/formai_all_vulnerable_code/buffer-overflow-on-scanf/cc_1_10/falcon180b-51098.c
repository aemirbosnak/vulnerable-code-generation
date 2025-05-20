//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000

typedef struct {
    char name[30];
    int size;
    char content[MAX_FILE_SIZE];
} File;

void create_file(File* file_system, int num_files, char* file_name, int file_size) {
    int i;
    for (i = 0; i < num_files; i++) {
        strcpy(file_system[i].name, file_name);
        file_system[i].size = file_size;
        strcpy(file_system[i].content, "");
    }
}

void write_to_file(File* file_system, int file_index, char* content) {
    int content_length = strlen(content);
    if (content_length > file_system[file_index].size) {
        printf("Error: File is too small to hold the content.\n");
        return;
    }
    strcpy(file_system[file_index].content, content);
}

void read_from_file(File* file_system, int file_index) {
    printf("%s\n", file_system[file_index].content);
}

int main() {
    File file_system[100];
    int num_files, i;

    printf("Enter the number of files: ");
    scanf("%d", &num_files);

    printf("Enter the file names (max 30 characters each):\n");
    for (i = 0; i < num_files; i++) {
        scanf("%s", file_system[i].name);
    }

    printf("Enter the file sizes (in bytes):\n");
    for (i = 0; i < num_files; i++) {
        scanf("%d", &file_system[i].size);
    }

    printf("Enter the content for each file:\n");
    for (i = 0; i < num_files; i++) {
        char content[MAX_FILE_SIZE];
        scanf("%s", content);
        write_to_file(file_system, i, content);
    }

    printf("Files created successfully!\n");

    return 0;
}