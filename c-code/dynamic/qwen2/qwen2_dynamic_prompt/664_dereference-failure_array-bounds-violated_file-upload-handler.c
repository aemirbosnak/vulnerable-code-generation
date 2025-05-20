#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void handleFileUpload(char *filename, char *data, size_t length) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    // Simulate a buffer overflow by writing more data than allocated
    fwrite(data, 1, length + BUFFER_SIZE, file);

    fclose(file);
}

int main() {
    char filename[] = "upload.txt";
    char data[BUFFER_SIZE] = "This is a test file upload.\n";

    // Intentionally create an array bounds violation
    handleFileUpload(filename, data, sizeof(data));

    printf("File uploaded successfully.\n");

    return 0;
}
