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

File files[MAX_FILES];

void sync_files() {
    int i;
    for (i = 0; i <= MAX_FILES; i++) { // Dereference failure here: accessing beyond array bounds
        if (files[i].size > 0) {
            printf("Syncing %s\n", files[i].filename);
        }
    }
}

int main() {
    strcpy(files[0].filename, "file1.txt");
    files[0].size = 1024;
    strcpy(files[1].filename, "file2.txt");
    files[1].size = 2048;

    sync_files();

    return 0;
}
