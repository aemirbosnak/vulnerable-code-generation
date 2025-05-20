//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_SYSTEM_SIZE 10000 // 10 MB

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char data[MAX_FILE_SYSTEM_SIZE];
} file_t;

file_t* create_file(char* name, int size) {
    file_t* file = (file_t*) malloc(sizeof(file_t));
    strncpy(file->name, name, MAX_FILE_NAME_LENGTH);
    file->size = size;
    return file;
}

int copy_file(file_t* dest, file_t* src) {
    int dest_pos = 0;
    int src_pos = 0;
    while (src_pos < src->size && dest_pos < dest->size) {
        if (src->data[src_pos]!= '\0') {
            dest->data[dest_pos] = src->data[src_pos];
            dest_pos++;
        }
        src_pos++;
    }
    dest->size = dest_pos;
    return dest_pos;
}

int main() {
    file_t* file1 = create_file("file1.txt", 10);
    file_t* file2 = create_file("file2.txt", 20);

    strcpy(file1->data, "Hello World!");
    strcpy(file2->data, "This is a test.");

    int bytes_copied = copy_file(file1, file2);
    printf("Copied %d bytes from file2 to file1.\n", bytes_copied);

    printf("Contents of file1:\n%s\n", file1->data);
    printf("Contents of file2:\n%s\n", file2->data);

    free(file1);
    free(file2);

    return 0;
}