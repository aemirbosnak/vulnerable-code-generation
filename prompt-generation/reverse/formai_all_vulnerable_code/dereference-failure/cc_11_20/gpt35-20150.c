//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

int main() {
    char* filename = "input.bmp";
    FILE* file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Unable to open file %s!", filename);
        return 1;
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    int padding = (4 - (width * sizeof(Pixel)) % 4) % 4;
    int row_size = width * sizeof(Pixel) + padding;

    Pixel** pixels = (Pixel**)malloc(height * sizeof(Pixel*));
    for (int i = 0; i < height; i++) {
        pixels[i] = (Pixel*)malloc(row_size);
        fread(pixels[i], sizeof(Pixel), width, file);
        fseek(file, padding, SEEK_CUR);
    }

    fclose(file);

    // Flipping the image vertically
    for (int i = 0; i < height / 2; i++) {
        Pixel* temp_row = pixels[i];
        pixels[i] = pixels[height - i - 1];
        pixels[height - i - 1] = temp_row;
    }

    // Changing the brightness and contrast of the image
    float brightness = 0.5;
    float contrast = 2.0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Pixel* pixel = &pixels[i][j];

            int new_r = (int)(contrast * (pixel->r - 127) + 127 + 255 * brightness);
            int new_g = (int)(contrast * (pixel->g - 127) + 127 + 255 * brightness);
            int new_b = (int)(contrast * (pixel->b - 127) + 127 + 255 * brightness);

            pixel->r = new_r > 255 ? 255 : (new_r < 0 ? 0 : new_r);
            pixel->g = new_g > 255 ? 255 : (new_g < 0 ? 0 : new_g);
            pixel->b = new_b > 255 ? 255 : (new_b < 0 ? 0 : new_b);
        }
    }

    // Writing the image to a new file
    filename = "output.bmp";
    file = fopen(filename, "wb");

    fwrite(header, sizeof(unsigned char), 54, file);

    for (int i = 0; i < height; i++) {
        fwrite(pixels[i], sizeof(Pixel), width, file);
        for (int j = 0; j < padding; j++) {
            fputc(0, file);
        }
        free(pixels[i]);
    }
    free(pixels);

    fclose(file);

    printf("The image has been processed and written to %s.\n", filename);

    return 0;
}