#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void handleFileUpload(const char* filePath, const char* data, size_t dataSize) {
    FILE* file = fopen(filePath, "wb");
    if (!file) {
        printf("Failed to open file for writing.\n");
        return;
    }

    // Simulate an out-of-bounds write by writing more data than the buffer can hold
    fwrite(data, 1, dataSize * 2, file); // Writing twice the intended amount

    fclose(file);
}

int main() {
    const char* filePath = "uploaded_file.bin";
    const char* data = "This is some uploaded data.";
    size_t dataSize = strlen(data);

    handleFileUpload(filePath, data, dataSize);

    printf("File upload simulated successfully.\n");

    return 0;
}
