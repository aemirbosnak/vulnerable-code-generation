#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1024

void handleFileUpload(int fileSize) {
    char *buffer = (char *)malloc(fileSize);
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Simulate file reading into buffer
    for (int i = 0; i < fileSize; i++) {
        buffer[i] = 'A';
    }

    printf("File uploaded successfully\n");
    free(buffer);
}

int main() {
    int fileSize;

    printf("Enter file size: ");
    scanf("%d", &fileSize);

    // Integer overflow vulnerability
    int totalSize = MAX_FILE_SIZE + fileSize;

    printf("Total size: %d\n", totalSize);

    handleFileUpload(totalSize);

    return 0;
}
