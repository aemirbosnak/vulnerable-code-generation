//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 50

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s image.pgm\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *f = fopen(argv[1], "rb");
    if (f == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char header[256];
    if (fgets(header, sizeof(header), f) == NULL) {
        perror("fgets");
        fclose(f);
        return EXIT_FAILURE;
    }

    if (strncmp(header, "P5", 2) != 0) {
        fprintf(stderr, "Invalid image format: %s\n", header);
        fclose(f);
        return EXIT_FAILURE;
    }

    int width, height, maxval;
    if (fscanf(f, "%d %d %d", &width, &height, &maxval) != 3) {
        perror("fscanf");
        fclose(f);
        return EXIT_FAILURE;
    }

    if (width != WIDTH || height != HEIGHT) {
        fprintf(stderr, "Invalid image size: %dx%d\n", width, height);
        fclose(f);
        return EXIT_FAILURE;
    }

    unsigned char pixels[WIDTH * HEIGHT];
    if (fread(pixels, sizeof(pixels), 1, f) != 1) {
        perror("fread");
        fclose(f);
        return EXIT_FAILURE;
    }

    fclose(f);

    char output[WIDTH * HEIGHT * 2];
    int index = 0;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int value = pixels[y * WIDTH + x];
            char c = ".";
            if (value >= maxval / 2) {
                c = "#";
            }
            output[index++] = c;
            output[index++] = ' ';
        }
        output[index++] = '\n';
    }

    printf("%s", output);

    return EXIT_SUCCESS;
}