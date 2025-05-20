#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void handleFileUpload(char *filename, char *buffer) {
    FILE *file;
    int bytesRead;

    if ((file = fopen(filename, "wb")) == NULL) {
        perror("Error opening file");
        return;
    }

    // Simulate reading from an external source
    strcpy(buffer, "This is some data to write to the file.\n");

    // Deliberate out-of-bounds read vulnerability
    bytesRead = fread(buffer + BUFFER_SIZE, 1, 1, file);
    printf("Bytes read: %d\n", bytesRead);

    if (fwrite(buffer, 1, strlen(buffer), file) != strlen(buffer)) {
        perror("Error writing to file");
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <data>\n", argv[0]);
        return 1;
    }

    char filename[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];

    strncpy(filename, argv[1], sizeof(filename));
    strncpy(buffer, argv[2], sizeof(buffer));

    handleFileUpload(filename, buffer);

    return 0;
}
