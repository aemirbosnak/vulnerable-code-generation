#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_image(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    int width, height, channel;
    fscanf(file, "%d %d %d\n", &width, &height, &channel);

    char *image = malloc(width * height * channel);
    fread(image, 1, width * height * channel, file);
    fclose(file);

    // Image processing logic

    // Write the manipulated image to stdout
    fprintf(stdout, "P5\n%d %d\n255\n", width, height);
    for (int i = 0; i < width * height * channel; ++i) {
        fprintf(stdout, "%02X ", image[i]);
        if ((i + 1) % (width * channel) == 0) {
            fprintf(stdout, "\n");
        }
    }

    free(image);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    process_image(argv[1]);
    return 0;
}
