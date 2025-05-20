#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void handleFileUpload(char *filePath) {
    char buffer[BUFFER_SIZE];
    FILE *file = fopen(filePath, "rb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    size_t bytesRead = fread(buffer, 1, sizeof(buffer), file);
    fclose(file);

    // Simulate a dereference failure by using an invalid pointer
    char *invalidPtr = NULL;
    strcpy(invalidPtr, buffer);  // Dereference failure here

    printf("File content: %s\n", invalidPtr);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    handleFileUpload(argv[1]);

    return EXIT_SUCCESS;
}
