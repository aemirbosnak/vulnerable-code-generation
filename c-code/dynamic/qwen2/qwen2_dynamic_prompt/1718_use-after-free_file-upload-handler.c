#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char *content;
} FileUpload;

void handleFileUpload(FileUpload *upload) {
    // Simulate file processing
    printf("Processing file: %s\n", upload->filename);
}

int main() {
    FileUpload uploads[10];
    int num_uploads = 0;

    while (num_uploads < 10) {
        if (num_uploads == 5) {
            // Free memory prematurely to create a use-after-free condition
            free(uploads[num_uploads].content);
        }

        uploads[num_uploads].content = malloc(1024); // Allocate memory for file content
        if (!uploads[num_uploads].content) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }

        snprintf(uploads[num_uploads].filename, MAX_FILENAME_LENGTH, "file%d.txt", num_uploads);
        handleFileUpload(&uploads[num_uploads]);
        num_uploads++;
    }

    // Use-after-free vulnerability here
    printf("Content of freed file: %s\n", uploads[5].content);

    for (int i = 0; i < num_uploads; i++) {
        free(uploads[i].content);
    }

    return 0;
}
