//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 32
#define MAX_FILE_SYSTEM_SIZE 1024 * 1024 * 10 // 10 MB

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    int size;
    int offset;
} file_t;

file_t* files = NULL;
int num_files = 0;
int total_size = 0;

void create_file(char* filename, int size) {
    if (num_files >= MAX_FILE_SYSTEM_SIZE) {
        printf("Error: File system is full.\n");
        return;
    }

    file_t* new_file = (file_t*)malloc(sizeof(file_t));
    strncpy(new_file->filename, filename, MAX_FILE_NAME_LENGTH);
    new_file->size = size;
    new_file->offset = total_size;
    total_size += size;

    files = (file_t*)realloc(files, sizeof(file_t) * ++num_files);
    files[num_files - 1] = *new_file;
}

void delete_file(char* filename) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            total_size -= files[i].size;

            files = (file_t*)realloc(files, sizeof(file_t) * --num_files);

            break;
        }
    }
}

void list_files() {
    int i;
    for (i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].filename, files[i].size);
    }
}

int main() {
    create_file("test.txt", 10);
    create_file("hello.txt", 5);
    create_file("world.txt", 7);

    list_files();

    delete_file("test.txt");

    list_files();

    return 0;
}