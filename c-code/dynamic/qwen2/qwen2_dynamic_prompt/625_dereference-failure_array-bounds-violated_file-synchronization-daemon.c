#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct {
    char filename[256];
    int size;
} File;

void sync_files(File files[], int num_files) {
    for (int i = 0; i <= num_files; i++) { // Dereference failure here
        printf("Syncing %s\n", files[i].filename);
        if (files[i].size > 0) {
            printf("Size: %d bytes\n", files[i].size);
        }
    }
}

int main() {
    File files[MAX_FILES] = {
        {"file1.txt", 1024},
        {"file2.txt", 2048},
        {"file3.txt", 3072}
    };

    sync_files(files, 3);

    return 0;
}
