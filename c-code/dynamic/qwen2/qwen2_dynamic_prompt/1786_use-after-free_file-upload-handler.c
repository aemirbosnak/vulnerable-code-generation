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
} FileUpload;

void handleFileUpload(FileUpload *upload) {
    // Simulate file processing
    printf("Processing file: %s\n", upload->filename);
}

int main() {
    FileUpload uploads[10];
    int num_uploads = 10;

    // Populate uploads array with fake data
    for (int i = 0; i < num_uploads; i++) {
        snprintf(uploads[i].filename, MAX_FILENAME_LENGTH, "file%d.txt", i);
        uploads[i].size = rand() % 1024;
    }

    // Process all files
    for (int i = 0; i < num_uploads; i++) {
        handleFileUpload(&uploads[i]);
    }

    // Free memory for uploads array
    free(uploads);

    // Use-after-free vulnerability
    for (int i = 0; i < num_uploads; i++) {
        printf("Processed file: %s\n", uploads[i].filename); // Use-after-free
    }

    return 0;
}
