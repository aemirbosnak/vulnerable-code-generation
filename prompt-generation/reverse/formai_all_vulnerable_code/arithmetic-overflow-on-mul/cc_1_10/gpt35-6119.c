//FormAI DATASET v1.0 Category: Image Editor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255

int main(int argc, char **argv) {
    // Read input image file
    FILE *infile = fopen(argv[1], "rb");

    if (infile == NULL) {
        printf("Error opening input file!\n");
        exit(1);
    }

    // Read image dimensions
    int width, height, channels;
    fscanf(infile, "P6\n%d %d\n%d\n", &width, &height, &channels);

    // Allocate memory for image data
    unsigned char *data = malloc(width * height * channels * sizeof(unsigned char));

    // Read image data
    fread(data, sizeof(unsigned char), width * height * channels, infile);

    // Image editing code
    for (int i = 0; i < width * height * channels; i++) {
        int pixel = data[i];
        data[i] = MAX_PIXEL_VALUE - pixel;
    }

    // Write output image file
    FILE *outfile = fopen(argv[2], "wb");

    if (outfile == NULL) {
        printf("Error opening output file!\n");
        exit(1);
    }

    // Write image dimensions
    fprintf(outfile, "P6\n%d %d\n%d\n", width, height, channels);

    // Write image data
    fwrite(data, sizeof(unsigned char), width * height * channels, outfile);

    // Cleanup
    free(data);
    fclose(infile);
    fclose(outfile);

    return 0;
}