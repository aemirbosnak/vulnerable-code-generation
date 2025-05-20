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
    for (int i = 0; i <= num_files; i++) { // Deliberate off-by-one error
        printf("Syncing %s\n", files[i].filename);
        if (files[i].size > 0) {
            char *content = malloc(files[i].size);
            if (content == NULL) {
                perror("Failed to allocate memory");
                exit(EXIT_FAILURE);
            }
            memset(content, 'A', files[i].size);
            free(content);
        }
    }
}

int main() {
    File files[MAX_FILES] = {
        {"file1.txt", 100},
        {"file2.txt", 200},
        {"file3.txt", 300}
    };

    sync_files(files, MAX_FILES);

    return 0;
}
