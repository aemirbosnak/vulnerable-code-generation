#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 256

typedef struct {
    char *path;
} FileEntry;

void synchronize_files(FileEntry *entries, int count) {
    for (int i = 0; i < count; i++) {
        if (entries[i].path == NULL) {
            printf("Error: Null path entry found.\n");
            continue;
        }
        FILE *source = fopen(entries[i].path, "r");
        if (source == NULL) {
            perror("Failed to open source file");
            continue;
        }

        char target_path[MAX_PATH_LENGTH];
        snprintf(target_path, sizeof(target_path), "/synced/%s", entries[i].path);

        FILE *target = fopen(target_path, "w");
        if (target == NULL) {
            perror("Failed to open target file");
            fclose(source);
            continue;
        }

        char buffer[1024];
        size_t bytes_read;
        while ((bytes_read = fread(buffer, 1, sizeof(buffer), source)) > 0) {
            fwrite(buffer, 1, bytes_read, target);
        }

        fclose(source);
        fclose(target);
    }
}

int main() {
    FileEntry files[] = {
        {"file1.txt"},
        {NULL},
        {"file3.txt"}
    };

    synchronize_files(files, 3);

    return 0;
}
