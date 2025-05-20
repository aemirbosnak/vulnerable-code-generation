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
    // Simulate processing the uploaded file
    printf("Processing file: %s\n", upload->filename);
}

int main() {
    FileUpload *uploads[10];
    int num_uploads = 0;

    while (num_uploads < 10) {
        uploads[num_uploads] = malloc(sizeof(FileUpload));
        if (!uploads[num_uploads]) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        uploads[num_uploads]->filename = malloc(MAX_FILENAME_LENGTH);
        if (!uploads[num_uploads]->filename) {
            fprintf(stderr, "Memory allocation failed\n");
            free(uploads[num_uploads]);
            return 1;
        }

        // Simulate receiving a file name from user input
        snprintf(uploads[num_uploads]->filename, MAX_FILENAME_LENGTH, "file%d.txt", num_uploads);

        handleFileUpload(uploads[num_uploads]);

        // Free the filename memory
        free(uploads[num_uploads]->filename);

        // Deliberate use after free vulnerability
        uploads[num_uploads]->filename[0] = 'X'; // Use freed memory

        num_uploads++;
    }

    // Clean up allocated memory
    for (int i = 0; i < num_uploads; i++) {
        free(uploads[i]->filename);
        free(uploads[i]);
    }

    return 0;
}
