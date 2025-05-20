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
    FILE *source, *destination;
    char buffer[4096];
    int i = 0;

    while (i < MAX_FILES && strlen(files[i].filename) > 0) {
        source = fopen(files[i].filename, "rb");
        if (!source) {
            perror("Failed to open source file");
            continue;
        }

        destination = fopen(files[i].filename, "wb");
        if (!destination) {
            perror("Failed to open destination file");
            fclose(source);
            continue;
        }

        while ((files[i].size -= fread(buffer, 1, sizeof(buffer), source)) > 0) {
            fwrite(buffer, 1, sizeof(buffer), destination);
        }

        fclose(source);
        fclose(destination);

        i++;
    }
}

int main() {
    // Simulate adding files to the synchronization list
    strcpy(files[0].filename, "example.txt");
    files[0].size = 1024;

    strcpy(files[1].filename, "largefile.bin");
    files[1].size = 1024 * 1024 * 10; // 10 MB

    sync_files();

    return 0;
}
