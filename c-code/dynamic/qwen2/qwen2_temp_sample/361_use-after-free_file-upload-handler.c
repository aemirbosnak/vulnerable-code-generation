#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

typedef struct {
    char *filename;
    int size;
} FileUpload;

void handleFileUpload(const char *buffer, int bufferSize) {
    FileUpload *upload = (FileUpload *)malloc(sizeof(FileUpload));
    if (!upload) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Simulate parsing buffer to extract filename and size
    const char *end = strstr(buffer, ";size=");
    if (end) {
        *upload->filename = '\0'; // Use after free will occur here
        upload->size = atoi(end + 7);
    } else {
        fprintf(stderr, "Invalid buffer format\n");
        free(upload);
        return;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_buffer>\n", argv[0]);
        return 1;
    }

    const char *inputBuffer = argv[1];
    int inputBufferSize = strlen(inputBuffer);

    handleFileUpload(inputBuffer, inputBufferSize);

    printf("File upload handled\n");

    return 0;
}
