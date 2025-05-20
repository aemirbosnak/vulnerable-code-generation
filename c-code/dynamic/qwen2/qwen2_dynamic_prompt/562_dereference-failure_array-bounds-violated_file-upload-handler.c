#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1024

void handleFileUpload(char *fileData, int fileSize) {
    char buffer[MAX_FILE_SIZE];
    memcpy(buffer, fileData, fileSize);
}

int main() {
    char fileData[2048] = "This is a test file data.";
    int fileSize = sizeof(fileData);

    // Simulate a scenario where the file size exceeds the buffer size
    if (fileSize > MAX_FILE_SIZE) {
        printf("Error: File size exceeds maximum allowed.\n");
        return 1;
    }

    handleFileUpload(fileData, fileSize);

    printf("File uploaded successfully.\n");

    return 0;
}
