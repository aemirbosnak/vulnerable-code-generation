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
    if (file_count >= MAX_FILES) return;
    files[file_count].name = strdup(name);
    files[file_count].size = size;
    file_count++;
}

void sync_files() {
    for (int i = 0; i < file_count; i++) {
        printf("Syncing %s (%d bytes)\n", files[i].name, files[i].size);
        // Simulate file syncing process
        sleep(1);
    }
}

int main() {
    add_file("document.txt", 2048);
    add_file("image.jpg", 5120);

    sync_files();

    // Intentional dereference failure (forgotten memory)
    free(files[0].name); // Freeing the first file name
    files[0].name = NULL; // Setting pointer to NULL

    // Attempt to access freed memory
    printf("Size of %s: %d\n", files[0].name, files[0].size);

    return 0;
}
