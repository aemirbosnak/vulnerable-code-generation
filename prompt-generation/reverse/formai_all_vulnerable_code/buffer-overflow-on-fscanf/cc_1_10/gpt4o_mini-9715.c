//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 40
#define CHAR_SET " .:-=+*%@#"

typedef struct {
    int width;
    int height;
    unsigned char* data;
} Image;

Image* loadPGM(const char* filename);
void freeImage(Image* img);
void convertToASCII(Image* img);
void drawASCII(Image* img);
void displayUsage();

int main(int argc, char* argv[]) {
    if (argc != 2) {
        displayUsage();
        return 1;
    }
  
    Image* img = loadPGM(argv[1]);
    if (!img) {
        fprintf(stderr, "Unable to load image: %s\n", argv[1]);
        return 1;
    }

    convertToASCII(img);
    freeImage(img);

    return 0;
}

void displayUsage() {
    printf("Usage: ascii_converter <image.pgm>\n");
    printf("Convert a PGM image to ASCII art.\n");
}

Image* loadPGM(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("File opening failed");
        return NULL;
    }

    char format[3];
    fscanf(file, "%2s\n", format);
    if (strcmp(format, "P5") != 0) {
        fprintf(stderr, "Unsupported PGM format. Only binary P5 is supported.\n");
        fclose(file);
        return NULL;
    }

    int width, height, maxval;
    fscanf(file, "%d %d\n%d\n", &width, &height, &maxval);
    
    if (maxval != 255) {
        fprintf(stderr, "Only 8-bit PGM images are supported.\n");
        fclose(file);
        return NULL;
    }

    unsigned char* data = (unsigned char*)malloc(width * height);
    fread(data, sizeof(unsigned char), width * height, file);
    fclose(file);

    Image* img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = data;

    return img;
}

void freeImage(Image* img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

void convertToASCII(Image* img) {
    unsigned char* grayData = img->data;
    int newWidth = WIDTH;
    int newHeight = HEIGHT;
    int pixelWidth = img->width / newWidth;
    int pixelHeight = img->height / newHeight;

    // Prepare ASCII art buffer
    char* asciiArt = malloc(newHeight * (newWidth + 1));  // +1 for null-termination
    for (int y = 0; y < newHeight; ++y) {
        for (int x = 0; x < newWidth; ++x) {
            int sum = 0;
            for (int dy = 0; dy < pixelHeight; ++dy) {
                for (int dx = 0; dx < pixelWidth; ++dx) {
                    int pixelX = x * pixelWidth + dx;
                    int pixelY = y * pixelHeight + dy;
                    if (pixelX < img->width && pixelY < img->height) {
                        sum += grayData[pixelY * img->width + pixelX];
                    }
                }
            }
            int avg = sum / (pixelWidth * pixelHeight);
            int index = (avg * (strlen(CHAR_SET) - 1)) / 255; // Normalize into range of CHAR_SET
            asciiArt[y * (newWidth + 1) + x] = CHAR_SET[index];
        }
        asciiArt[y * (newWidth + 1) + newWidth] = '\n';
    }

    // Print the ASCII art
    printf("%s", asciiArt);
    free(asciiArt);
}