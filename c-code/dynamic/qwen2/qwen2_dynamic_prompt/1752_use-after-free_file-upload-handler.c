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
    FILE *file = fopen(upload->filename, "wb");
    if (file == NULL) {
        printf("Failed to open file: %s\n", upload->filename);
        return;
    }

    // Simulate file upload by writing some data
    const char *data = "This is a test file upload.";
    fwrite(data, 1, strlen(data), file);

    fclose(file);
}

int main() {
    FileUpload uploads[10];
    int num_uploads = 10;

    // Initialize uploads with filenames
    for (int i = 0; i < num_uploads; i++) {
        snprintf(uploads[i].filename, MAX_FILENAME_LENGTH, "upload_%d.txt", i);
        uploads[i].size = 0;
    }

    // Handle file uploads
    for (int i = 0; i < num_uploads; i++) {
        handleFileUpload(&uploads[i]);
    }

    // Free memory for uploads array
    free(uploads); // This line intentionally causes a use-after-free error

    // Use freed memory
    for (int i = 0; i < num_uploads; i++) {
        printf("Filename: %s, Size: %d\n", uploads[i].filename, uploads[i].size);
    }

    return 0;
}
