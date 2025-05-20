#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void handleFileUpload(char *filename, char *data, size_t dataSize) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Failed to open file for writing.\n");
        return;
    }

    fwrite(data, 1, dataSize, file);
    fclose(file);
}

int main() {
    char filename[256];
    char data[BUFFER_SIZE];

    // Simulate receiving file data from a client
    printf("Enter filename: ");
    scanf("%s", filename);

    printf("Enter file content (up to %zu bytes): ", sizeof(data));
    fgets(data, sizeof(data), stdin);

    // Remove newline character if present
    size_t len = strlen(data);
    if (len > 0 && data[len - 1] == '\n') {
        data[len - 1] = '\0';
    }

    handleFileUpload(filename, data, strlen(data));

    printf("File uploaded successfully.\n");

    return 0;
}
