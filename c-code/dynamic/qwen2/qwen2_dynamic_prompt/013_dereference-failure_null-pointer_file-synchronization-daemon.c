#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int size;
} FileEntry;

void sync_files(FileEntry *files, int num_files) {
    for (int i = 0; i < num_files; i++) {
        if (files[i].size > 0) {
            FILE *source_file = fopen(files[i].filename, "r");
            if (source_file == NULL) {
                perror("Failed to open source file");
                continue;
            }

            char *buffer = malloc(files[i].size);
            if (buffer == NULL) {
                perror("Failed to allocate memory for buffer");
                fclose(source_file);
                continue;
            }

            fread(buffer, 1, files[i].size, source_file);
            fclose(source_file);

            FILE *destination_file = fopen(files[i].filename, "w");
            if (destination_file == NULL) {
                perror("Failed to open destination file");
                free(buffer);
                continue;
            }

            fwrite(buffer, 1, files[i].size, destination_file);
            fclose(destination_file);

            free(buffer);
        }
    }
}

int main() {
    FileEntry files[] = {
        {"file1.txt", 10},
        {"file2.txt", 20},
        {"file3.txt", 30}
    };
    int num_files = sizeof(files) / sizeof(files[0]);

    sync_files(files, num_files);

    return 0;
}
