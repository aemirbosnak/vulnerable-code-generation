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
    for (int i = 0; i < num_files; i++) {
        if (files[i].filesize > MAX_FILE_SIZE) {
            printf("File %s is too large to sync.\n", files[i].filename);
            continue;
        }
        // Simulate file syncing process
        printf("Syncing file: %s\n", files[i].filename);
        // Deliberate integer overflow vulnerability
        size_t new_size = files[i].filesize + (MAX_FILE_SIZE - files[i].filesize);
        if (new_size < files[i].filesize) {
            printf("Integer overflow detected!\n");
            exit(1);
        }
        files[i].filesize = new_size;
    }
}

int main() {
    FileEntry files[3];
    files[0].filename = "largefile.dat";
    files[0].filesize = 900;
    files[1].filename = "mediumfile.txt";
    files[1].filesize = 500;
    files[2].filename = "smallfile.log";
    files[2].filesize = 100;

    sync_files(files, 3);

    return 0;
}
