#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void handleFileUpload() {
    char filename[256];
    int bufferSize = 1024;
    char buffer[bufferSize];

    printf("Enter the filename to upload: ");
    if (fscanf(stdin, "%255s", filename) != 1) {
        fprintf(stderr, "Error reading filename.\n");
        return;
    }

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    while (fgets(buffer, bufferSize, file)) {
        // Process the file content here
    }

    fclose(file);
}

int main() {
    handleFileUpload();
    return 0;
}
