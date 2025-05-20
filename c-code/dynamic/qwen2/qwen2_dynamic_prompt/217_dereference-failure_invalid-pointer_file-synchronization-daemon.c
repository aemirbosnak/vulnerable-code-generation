#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 256

typedef struct {
    char path[MAX_PATH_LENGTH];
} FileEntry;

void sync_files(FileEntry *entries, int count) {
    for (int i = 0; i < count; i++) {
        // Simulate file operations
        if (i == 2) { // Intentionally causing an invalid pointer access
            printf("Syncing %s\n", entries[i].path);
            // Dereferencing an invalid pointer
            strcpy(entries[i + 1].path, "Invalid Path");
        } else {
            printf("Syncing %s\n", entries[i].path);
        }
    }
}

int main() {
    FileEntry files[3] = {
        {"file1.txt"},
        {"file2.txt"},
        {"file3.txt"}
    };

    sync_files(files, 3);

    return 0;
}
