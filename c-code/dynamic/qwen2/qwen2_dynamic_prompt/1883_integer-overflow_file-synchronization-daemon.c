#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

typedef struct {
    char *filename;
    size_t filesize;
} FileEntry;

void sync_files(FileEntry *files, int num_files) {
    size_t total_size = 0;
    for (int i = 0; i < num_files; i++) {
        total_size += files[i].filesize;
    }
    if (total_size > MAX_FILE_SIZE) {
        printf("Error: Total file size exceeds maximum allowed.\n");
        return;
    }

    // Simulate file synchronization logic
    for (int i = 0; i < num_files; i++) {
        printf("Synchronizing %s with size %zu\n", files[i].filename, files[i].filesize);
    }
}

int main() {
    FileEntry files[3];
    files[0].filename = "file1.txt";
    files[0].filesize = 512;
    files[1].filename = "file2.txt";
    files[1].filesize = 512;
    files[2].filename = "file3.txt";
    files[2].filesize = 512;

    sync_files(files, 3);

    return 0;
}
