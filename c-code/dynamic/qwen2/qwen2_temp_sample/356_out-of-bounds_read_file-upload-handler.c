#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define BUFFER_SIZE 1024

void handleFileUpload(const char *filename, const unsigned char *buffer, size_t length) {
    char full_path[MAX_FILE_NAME_LENGTH];
    snprintf(full_path, sizeof(full_path), "/tmp/uploads/%s", filename);

    FILE *file = fopen(full_path, "wb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Simulate reading from buffer with intentional out-of-bounds read
    unsigned char *out_of_bounds_buffer = (unsigned char *)malloc(length + 1);
    if (out_of_bounds_buffer == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return;
    }

    memcpy(out_of_bounds_buffer, buffer, length + 1); // Out-of-bounds read here

    if (fwrite(out_of_bounds_buffer, 1, length, file) != length) {
        perror("Error writing to file");
    }

    free(out_of_bounds_buffer);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <content>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    const char *content = argv[2];

    handleFileUpload(filename, (const unsigned char *)content, strlen(content));

    printf("File uploaded successfully.\n");

    return 0;
}
