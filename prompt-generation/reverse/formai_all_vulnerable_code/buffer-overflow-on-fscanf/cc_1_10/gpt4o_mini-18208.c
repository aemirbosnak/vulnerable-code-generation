//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define ASCII_CHARS " .:-=+*%@#"

typedef struct {
    unsigned char r, g, b;
} Pixel;

Pixel image[MAX_HEIGHT][MAX_WIDTH];
int width, height;

void readPPM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    char format[3];
    fscanf(file, "%s\n%d %d\n255\n", format, &width, &height);
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(&image[i][j], sizeof(Pixel), 1, file);
        }
    }
    
    fclose(file);
}

char getASCIIChar(Pixel pixel) {
    int gray = (pixel.r + pixel.g + pixel.b) / 3;
    int index = (gray * (strlen(ASCII_CHARS) - 1)) / 255;
    return ASCII_CHARS[index];
}

void printASCIIArt() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            putchar(getASCIIChar(image[i][j]));
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        exit(1);
    }

    readPPM(argv[1]);
    
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Image dimensions exceed allowed limits (%dx%d)\n",
                MAX_WIDTH, MAX_HEIGHT);
        exit(1);
    }

    printASCIIArt();

    return 0;
}