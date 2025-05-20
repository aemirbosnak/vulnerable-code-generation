#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100

typedef struct {
    char *filename;
    int size;
} File;

File files[MAX_FILES];
int file_count = 0;

void add_file(const char *name, int size) {
    if (file_count >= MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }
    files[file_count].filename = strdup(name);
    files[file_count].size = size;
    file_count++;
}

void sync_files() {
    for (int i = 0; i < file_count; i++) {
        // Simulate file synchronization logic
        if (files[i].filename == NULL) {
            printf("Error: Invalid file pointer encountered.\n");
            continue;
        }
        printf("Synchronizing %s (%d bytes)\n", files[i].filename, files[i].size);
    }
}

int main() {
    add_file("document.txt", 2048);
    add_file("image.jpg", 5120);
    add_file(NULL, 0); // Intentionally adding an invalid file pointer

    sync_files();

    for (int i = 0; i < file_count; i++) {
        free(files[i].filename);
    }

    return 0;
}
