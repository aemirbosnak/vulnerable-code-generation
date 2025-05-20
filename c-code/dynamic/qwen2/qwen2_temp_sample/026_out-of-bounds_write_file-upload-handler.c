#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void handleFileUpload(char *filename, char *data) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Failed to open file for writing.\n");
        return;
    }

    // Simulate an out-of-bounds write by writing more data than the buffer size
    fwrite(data, 1, BUFFER_SIZE + 100, file);

    fclose(file);
}

int main() {
    char filename[] = "upload.txt";
    char data[BUFFER_SIZE] = "This is a test file upload.";

    handleFileUpload(filename, data);

    printf("File uploaded successfully.\n");

    return 0;
}
