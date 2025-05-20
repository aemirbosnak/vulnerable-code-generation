//Code Llama-13B DATASET v1.0 Category: File system simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_FILE_SIZE 1000000

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    int size;
    char data[MAX_FILE_SIZE];
} File;

void create_file(char *name, int size, char *data) {
    File *file = (File *) malloc(sizeof(File));
    strcpy(file->name, name);
    file->size = size;
    strcpy(file->data, data);
    printf("File %s created with size %d\n", name, size);
}

void read_file(char *name) {
    File *file = (File *) malloc(sizeof(File));
    strcpy(file->name, name);
    file->size = 0;
    strcpy(file->data, "");
    printf("File %s read with size %d\n", name, file->size);
}

void write_file(char *name, int size, char *data) {
    File *file = (File *) malloc(sizeof(File));
    strcpy(file->name, name);
    file->size = size;
    strcpy(file->data, data);
    printf("File %s written with size %d\n", name, size);
}

void delete_file(char *name) {
    File *file = (File *) malloc(sizeof(File));
    strcpy(file->name, name);
    file->size = 0;
    strcpy(file->data, "");
    printf("File %s deleted\n", name);
}

int main() {
    create_file("test.txt", 100, "This is a test file");
    read_file("test.txt");
    write_file("test.txt", 200, "This is a test file with more data");
    delete_file("test.txt");
    return 0;
}