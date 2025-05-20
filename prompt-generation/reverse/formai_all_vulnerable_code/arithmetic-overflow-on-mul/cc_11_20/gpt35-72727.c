//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLOR 255

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    FILE *f = fopen(filename, "rb");
    if(!f) {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }

    // Read image header
    char header[54];
    fread(header, sizeof(char), 54, f);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bpp = *(int*)&header[28];

    if(bpp != 24) {
        printf("Only 24-bit images supported\n");
        exit(1);
    }

    // Allocate memory for image data
    int padding = (4 - (width * 3) % 4) % 4;
    int size = width * height * 3 + height * padding;
    unsigned char *data = (unsigned char *)malloc(size);

    // Read image data
    fread(data, sizeof(unsigned char), size, f);
    fclose(f);

    // Flip image vertically
    for(int i = 0; i < height / 2; i++) {
        for(int j = 0; j < width * 3; j++) {
            unsigned char tmp = data[i * (width * 3 + padding) + j];
            data[i * (width * 3 + padding) + j] = data[(height - i - 1) * (width * 3 + padding) + j];
            data[(height - i - 1) * (width * 3 + padding) + j] = tmp;
        }
    }

    // Adjust brightness and contrast
    float alpha = 1.0, beta = 0.0;
    printf("Enter new brightness (-255 to 255): ");
    scanf("%f", &beta);
    beta = beta > 255 ? 255 : (beta < -255 ? -255 : beta);
    printf("Enter new contrast (0 to 10): ");
    scanf("%f", &alpha);
    alpha = alpha < 0 ? 0 : (alpha > 10 ? 10 : alpha);

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width * 3; j++) {
            float tmp = data[i * (width * 3 + padding) + j] * alpha + beta;
            data[i * (width * 3 + padding) + j] = tmp > MAX_COLOR ? MAX_COLOR : (tmp < 0 ? 0 : tmp);
        }
    }

    // Write output image to file
    char *out_filename = "output.bmp";
    f = fopen(out_filename, "wb");
    fwrite(header, sizeof(char), 54, f);
    fwrite(data, sizeof(unsigned char), size, f);
    fclose(f);
    printf("Done. Output saved to %s\n", out_filename);

    free(data);
    return 0;
}