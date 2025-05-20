#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void process_image(char *filename) {
    int width, height, channels;
    char buffer[10];

    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file '%s'\n", filename);
        return;
    }

    fscanf(file, "%s %s %s\n", "MAGIC_NUMBER", buffer, buffer); // Read and discard magic number
    sscanf(file, "%d %d %d", &width, &height, &channels);

    unsigned char *image_data = malloc(width * height * channels);
    fread(image_data, width * height * channels, 1, file);

    // Image processing code (left out for brevity)

    free(image_data);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    process_image(argv[1]);
    return 0;
}
