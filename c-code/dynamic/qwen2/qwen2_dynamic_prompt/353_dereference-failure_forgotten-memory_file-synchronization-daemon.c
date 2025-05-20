#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100

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

void sync_files() {
    for (int i = 0; i < file_count; i++) {
        // Simulate file synchronization logic
        printf("Synchronizing %s (%d bytes)\n", files[i].name, files[i].size);
        // Deliberate dereference failure (forgotten memory)
        free(files[i].name); // Freeing the allocated memory
        files[i].name = NULL; // Setting pointer to NULL
    }
}

int main() {
    add_file("document.txt", 2048);
    add_file("image.jpg", 5120);
    add_file("presentation.pptx", 3072);

    sync_files();

    // Attempt to access freed memory
    for (int i = 0; i < file_count; i++) {
        if (files[i].name != NULL) {
            printf("%s\n", files[i].name);
        } else {
            printf("Error: Memory already freed.\n");
        }
    }

    return 0;
}
