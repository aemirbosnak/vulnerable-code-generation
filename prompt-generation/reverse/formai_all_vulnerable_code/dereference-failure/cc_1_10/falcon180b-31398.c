//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LEN 50
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    char data[MAX_FILE_SIZE];
    int size;
} file_t;

file_t* create_file(char* name) {
    file_t* file = (file_t*)malloc(sizeof(file_t));
    strcpy(file->name, name);
    file->size = 0;
    return file;
}

int read_file(file_t* file, char* buffer, int count) {
    int bytes_read = 0;
    if (file->size > 0) {
        if (count > file->size) {
            count = file->size;
        }
        strncpy(buffer, file->data, count);
        bytes_read = count;
    }
    return bytes_read;
}

int write_file(file_t* file, char* buffer, int count) {
    int bytes_written = 0;
    if (count > MAX_FILE_SIZE) {
        count = MAX_FILE_SIZE;
    }
    strncpy(file->data + file->size, buffer, count);
    file->size += count;
    bytes_written = count;
    return bytes_written;
}

int main() {
    file_t* file1 = create_file("file1.txt");
    file_t* file2 = create_file("file2.txt");
    write_file(file1, "Hello, world!", strlen("Hello, world!"));
    write_file(file2, "This is a test.", strlen("This is a test."));
    char buffer[MAX_FILE_SIZE];
    read_file(file1, buffer, MAX_FILE_SIZE);
    printf("File1 contents: %s\n", buffer);
    read_file(file2, buffer, MAX_FILE_SIZE);
    printf("File2 contents: %s\n", buffer);
    free(file1);
    free(file2);
    return 0;
}