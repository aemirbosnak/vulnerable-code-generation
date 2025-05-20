#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

void handleFileUpload(char *filename) {
    FILE *file;
    char buffer[MAX_FILE_SIZE];
    size_t fileSize;

    // Simulate file opening
    if ((file = fopen(filename, "r")) == NULL) {
        perror("Error opening file");
        return;
    }

    // Simulate reading file content into buffer
    fileSize = fread(buffer, 1, sizeof(buffer), file);
    fclose(file);

    // Integer overflow vulnerability
    int bufferSize = (int)fileSize; // Potential overflow here
    if (bufferSize > MAX_FILE_SIZE) {
        printf("File too large\n");
        return;
    }

    // Process the file content
    for (int i = 0; i < bufferSize; i++) {
        putchar(buffer[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    handleFileUpload(argv[1]);

    return 0;
}
