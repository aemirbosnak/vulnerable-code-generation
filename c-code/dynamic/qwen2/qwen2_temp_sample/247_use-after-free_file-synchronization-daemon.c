#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *data;
} FileData;

void simulateFileSync(FileData *file) {
    // Simulate file data processing
    printf("Processing file: %s\n", file->data);
}

void freeFileData(FileData *file) {
    if (file != NULL && file->data != NULL) {
        free(file->data);
        file->data = NULL; // Prevent dangling pointer
    }
}

int main() {
    FileData file;
    file.data = (char *)malloc(BUFFER_SIZE);
    if (file.data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    strcpy(file.data, "Sample file content");

    simulateFileSync(&file);

    // Free the allocated memory
    freeFileData(&file);

    // Use after free vulnerability
    simulateFileSync(&file); // Dereferencing freed memory

    return 0;
}
