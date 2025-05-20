#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

void handleFileUpload(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Vulnerability: Integer overflow
    char *buffer = (char *)malloc((MAX_FILE_SIZE + fileSize) * sizeof(char));
    if (!buffer) {
        perror("Failed to allocate memory");
        fclose(file);
        return;
    }

    size_t bytesRead = fread(buffer, 1, fileSize, file);
    if (bytesRead != fileSize) {
        perror("Failed to read file");
        free(buffer);
        fclose(file);
        return;
    }

    // Process the file data here
    printf("File uploaded successfully\n");

    free(buffer);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    handleFileUpload(argv[1]);

    return 0;
}
