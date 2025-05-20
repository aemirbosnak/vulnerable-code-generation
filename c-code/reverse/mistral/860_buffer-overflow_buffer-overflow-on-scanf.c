#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define BUFFER_SIZE 256

typedef struct File {
    char name[MAX_FILE_NAME_LENGTH];
    char content[BUFFER_SIZE];
} File;

File* create_file(const char* name) {
    File* file = (File*)malloc(sizeof(File));
    strcpy(file->name, name);
    memset(file->content, 0, BUFFER_SIZE);
    return file;
}

void write_to_file(File* file, const char* content) {
    char buffer[BUFFER_SIZE];
    printf("Enter the number of characters to write: ");
    scanf("%s", buffer);
    strncat(file->content, content, atoi(buffer));
}

void read_from_file(File* file) {
    printf("Content of %s:\n%s\n", file->name, file->content);
}

void delete_file(File* file) {
    free(file);
}

int main() {
    File* file = create_file("test.txt");
    write_to_file(file, "Hello, World!");
    read_from_file(file);

    File* file2 = create_file("another_test.txt");
    write_to_file(file2, "This is another test.");
    read_from_file(file2);

    delete_file(file);
    delete_file(file2);

    return 0;
}
