#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct {
    char *filename;
} FileEntry;

FileEntry files[MAX_FILES];
int file_count = 0;

void add_file(const char *filename) {
    if (file_count >= MAX_FILES) return;
    files[file_count].filename = strdup(filename);
    file_count++;
}

void remove_file(int index) {
    if (index < 0 || index >= file_count) return;
    free(files[index].filename);
    for (int i = index; i < file_count - 1; i++) {
        files[i] = files[i + 1];
    }
    file_count--;
}

void rename_file(int index, const char *new_filename) {
    if (index < 0 || index >= file_count) return;
    free(files[index].filename);
    files[index].filename = strdup(new_filename);
}

void list_files() {
    for (int i = 0; i < file_count; i++) {
        printf("%s\n", files[i].filename);
    }
}

int main() {
    add_file("file1.txt");
    add_file("file2.txt");
    list_files();

    remove_file(0);
    list_files();

    rename_file(0, "newfile.txt");
    list_files();

    // Use-after-free vulnerability
    char *ptr = files[0].filename;
    remove_file(0);
    strcpy(ptr, "This should crash"); // This will cause a segmentation fault

    return 0;
}
