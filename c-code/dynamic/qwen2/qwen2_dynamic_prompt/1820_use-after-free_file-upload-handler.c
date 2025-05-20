#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char *data;
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
        uploads[i].data = malloc(1024); // Allocate memory for file data
        memset(uploads[i].data, 'A', 1023);
        uploads[i].data[1023] = '\0';
    }

    // Process all uploads
    for (int i = 0; i < num_uploads; i++) {
        handleFileUpload(&uploads[i]);
    }

    // Free allocated memory
    for (int i = 0; i < num_uploads; i++) {
        free(uploads[i].data);
    }

    // Use-after-free vulnerability
    for (int i = 0; i < num_uploads; i++) {
        printf("%s\n", uploads[i].filename); // Access freed memory
    }

    return 0;
}
