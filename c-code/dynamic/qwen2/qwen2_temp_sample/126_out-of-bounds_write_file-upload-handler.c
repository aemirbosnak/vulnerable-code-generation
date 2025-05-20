#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void handle_file_upload(const char* filename, const unsigned char* data, size_t length) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Failed to open file\n");
        return;
    }

    // Simulate an out-of-bounds write by writing more data than the buffer can hold
    fwrite(data, 1, length * 2, file); // Writing twice the intended amount

    fclose(file);
}

int main() {
    const char* filename = "uploaded_file.bin";
    unsigned char data[MAX_BUFFER_SIZE] = {0};

    // Populate data array with some values
    for (size_t i = 0; i < MAX_BUFFER_SIZE; i++) {
        data[i] = i % 256;
    }

    handle_file_upload(filename, data, sizeof(data));

    printf("File uploaded successfully\n");

    return 0;
}
