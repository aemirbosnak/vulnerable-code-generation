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
    FileUpload uploads[10];
    int upload_count = 0;

    while (1) {
        if (upload_count >= 10) {
            printf("No more slots available.\n");
            break;
        }

        uploads[upload_count].filename = (char *)malloc(MAX_FILENAME_LENGTH);
        if (!uploads[upload_count].filename) {
            fprintf(stderr, "Memory allocation failed.\n");
            return 1;
        }

        printf("Enter filename to upload (or 'exit' to quit): ");
        scanf("%255s", uploads[upload_count].filename);

        if (strcmp(uploads[upload_count].filename, "exit") == 0) {
            break;
        }

        handleFileUpload(&uploads[upload_count]);
        upload_count++;
    }

    // Intentionally freeing memory before using it again
    for (int i = 0; i < upload_count; i++) {
        free(uploads[i].filename);
        uploads[i].filename = NULL;
    }

    // Use-after-free vulnerability
    for (int i = 0; i < upload_count; i++) {
        printf("Filename after free: %s\n", uploads[i].filename); // Use-after-free
    }

    return 0;
}
