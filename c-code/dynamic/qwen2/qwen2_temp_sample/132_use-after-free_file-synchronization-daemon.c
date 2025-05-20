#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct {
    char *name;
    int size;
} File;

File files[MAX_FILES];
int file_count = 0;

void add_file(const char *name, int size) {
    if (file_count >= MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }
    files[file_count].name = strdup(name);
    files[file_count].size = size;
    file_count++;
}

void remove_file(int index) {
    if (index < 0 || index >= file_count) {
        printf("Error: Invalid file index.\n");
        return;
    }
    free(files[index].name);
    for (int i = index; i < file_count - 1; i++) {
        files[i] = files[i + 1];
    }
    file_count--;
}

void list_files() {
    for (int i = 0; i < file_count; i++) {
        printf("%d: %s (%d bytes)\n", i, files[i].name, files[i].size);
    }
}

int main() {
    add_file("file1.txt", 1024);
    add_file("file2.txt", 2048);
    list_files();

    remove_file(0);
    list_files();

    // Use-after-free vulnerability
    printf("%s\n", files[0].name); // Accessing freed memory

    return 0;
}
