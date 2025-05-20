//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    unsigned char r, g, b;
} pixel;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    char header[256];
    if (fgets(header, sizeof(header), fp) == NULL) {
        perror("fgets");
        fclose(fp);
        return 1;
    }

    int width, height;
    if (sscanf(header, "P6 %d %d", &width, &height) != 2) {
        fprintf(stderr, "Invalid header format\n");
        fclose(fp);
        return 1;
    }

    pixel *image = malloc(width * height * sizeof(pixel));
    if (image == NULL) {
        perror("malloc");
        fclose(fp);
        return 1;
    }

    if (fread(image, sizeof(pixel), width * height, fp) != width * height) {
        perror("fread");
        free(image);
        fclose(fp);
        return 1;
    }

    fclose(fp);

    char *ascii = malloc(width * height * sizeof(char));
    if (ascii == NULL) {
        perror("malloc");
        free(image);
        return 1;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixel p = image[y * width + x];
            double brightness = (p.r + p.g + p.b) / 3.0;
            ascii[y * width + x] = " .:-=+*#%@";
            ascii[y * width + x] =
                brightness < 0.25 ? ' ' :
                brightness < 0.5  ? '.' :
                brightness < 0.75 ? '-' :
                brightness < 0.85 ? '+' :
                brightness < 0.95 ? '=' :
                brightness < 0.98 ? '*' : '#';
        }
    }

    free(image);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", ascii[y * width + x]);
        }
        printf("\n");
    }

    free(ascii);

    return 0;
}