#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void handleFileUpload() {
    char filename[256];
    int fileSize;
    FILE *file;

    printf("Enter the filename: ");
    if (fscanf(stdin, "%s", filename) != 1) {
        fprintf(stderr, "Error reading filename.\n");
        return;
    }

    printf("Enter the file size: ");
    if (fscanf(stdin, "%d", &fileSize) != 1) {
        fprintf(stderr, "Error reading file size.\n");
        return;
    }

    // Vulnerability: No bounds checking on fileSize
    char *buffer = malloc(fileSize);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    printf("Uploading file...\n");
    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open file.\n");
        free(buffer);
        return;
    }

    fread(buffer, 1, fileSize, file);
    fclose(file);

    printf("File uploaded successfully.\n");
    free(buffer);
}

int main() {
    handleFileUpload();
    return 0;
}
