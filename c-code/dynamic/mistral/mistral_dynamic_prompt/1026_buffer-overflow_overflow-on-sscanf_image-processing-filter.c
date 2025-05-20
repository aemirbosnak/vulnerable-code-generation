#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void processImage(char *filename) {
    int width, height;
    char buffer[BUFFER_SIZE];

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file.\n");
        return;
    }

    fgets(buffer, BUFFER_SIZE, file); // Read the first line containing the image dimensions
    sscanf(buffer, "%d %d", &width, &height);

    // Buffer overflow vulnerability
    char pixels[width * height];

    fgets(pixels, sizeof(pixels), file); // Read the image data, overwriting the memory beyond width * height bytes

    // Perform image processing, filtering, or other operations here (not shown)

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: filter <image_file>\n");
        return 1;
    }

    processImage(argv[1]);

    return 0;
}
