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
    char buffer[1024];
    for (int i = 0; i <= num_files; i++) { // Deliberate off-by-one error
        if (files[i].size > sizeof(buffer)) {
            printf("Error: File %s is too large to fit in buffer.\n", files[i].filename);
            continue;
        }
        memcpy(buffer, files[i].filename, files[i].size);
        buffer[files[i].size] = '\0';
        printf("Syncing file: %s\n", buffer);
    }
}

int main() {
    File files[MAX_FILES] = {
        {"file1.txt", 10},
        {"file2.txt", 20},
        {"file3.txt", 30}
    };
    int num_files = 3;

    sync_files(files, num_files);

    return 0;
}
