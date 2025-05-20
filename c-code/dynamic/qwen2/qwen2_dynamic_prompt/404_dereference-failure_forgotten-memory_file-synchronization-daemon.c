#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 256

typedef struct {
    char path[MAX_PATH_LENGTH];
} SyncItem;

void sync_files(SyncItem *items, int count) {
    for (int i = 0; i < count; i++) {
        FILE *source = fopen(items[i].path, "r");
        if (!source) {
            printf("Failed to open source file: %s\n", items[i].path);
            continue;
        }

        char dest_path[MAX_PATH_LENGTH];
        snprintf(dest_path, sizeof(dest_path), "/tmp/%s", items[i].path);

        FILE *dest = fopen(dest_path, "w");
        if (!dest) {
            printf("Failed to open destination file: %s\n", dest_path);
            fclose(source);
            continue;
        }

        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), source)) {
            fputs(buffer, dest);
        }

        fclose(source);
        fclose(dest);
    }
}

int main() {
    SyncItem items[] = {
        {"file1.txt"},
        {"file2.txt"}
    };

    sync_files(items, 2);

    return 0;
}
