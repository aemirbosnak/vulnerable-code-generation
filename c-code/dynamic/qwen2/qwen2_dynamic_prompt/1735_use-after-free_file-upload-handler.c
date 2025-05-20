#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

typedef struct {
    char *filename;
} FileUpload;

void handleFileUpload(FileUpload *upload) {
    // Simulate file processing
    printf("Processing file: %s\n", upload->filename);
}

int main() {
    FileUpload *uploads = (FileUpload *)malloc(10 * sizeof(FileUpload));
    if (!uploads) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Populate uploads array with filenames
    for (int i = 0; i < 10; i++) {
        uploads[i].filename = (char *)malloc(MAX_FILENAME_LENGTH);
        snprintf(uploads[i].filename, MAX_FILENAME_LENGTH, "file%d.txt", i);
    }

    // Process some files
    for (int i = 0; i < 5; i++) {
        handleFileUpload(&uploads[i]);
    }

    // Free allocated memory
    for (int i = 0; i < 10; i++) {
        free(uploads[i].filename);
    }
    free(uploads);

    // Use-after-free vulnerability
    handleFileUpload(&uploads[3]);

    return 0;
}
