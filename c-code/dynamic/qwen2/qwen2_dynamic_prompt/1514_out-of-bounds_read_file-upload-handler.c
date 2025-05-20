#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void handleFileUpload(const char* filePath) {
    FILE* file = fopen(filePath, "rb");
    if (!file) {
        printf("Failed to open file: %s\n", filePath);
        return;
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        // Simulate processing the file data
        for (size_t i = 0; i < bytesRead; ++i) {
            // Out-of-bounds read vulnerability here
            printf("%c", buffer[i + 10]); // Accessing buffer[i + 10] after the end of the array
        }
    }

    fclose(file);
}

int main() {
    const char* filePath = "example.txt";
    handleFileUpload(filePath);
    return 0;
}
