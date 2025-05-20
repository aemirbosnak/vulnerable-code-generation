//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

// ascii art characters, sorted by brightness
static const char *ascii_chars = " .,:;i1tfLCG08@";

int main(int argc, char **argv) {
    // check if program is run with correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    // read image from input file
    FILE *in = fopen(input_file, "rb");
    if (!in) {
        printf("Error: Could not open input file '%s'\n", input_file);
        return 1;
    }

    unsigned char img[MAX_HEIGHT][MAX_WIDTH];
    int width, height;

    // read image header (P5)
    char magic[2];
    fscanf(in, "%s\n", magic);
    if (strcmp(magic, "P5") != 0) {
        printf("Error: Invalid PGM file format\n");
        fclose(in);
        return 1;
    }

    // read image dimensions
    fscanf(in, "%d %d\n", &width, &height);
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: Image dimensions exceed maximum allowed (%dx%d)\n", MAX_WIDTH, MAX_HEIGHT);
        fclose(in);
        return 1;
    }

    // read max brightness (it is not used in this program)
    int max_brightness;
    fscanf(in, "%d\n", &max_brightness);

    // read image data
    fread(img, sizeof(unsigned char), width*height, in);
    fclose(in);

    // convert image to ascii art
    char ascii[MAX_HEIGHT][MAX_WIDTH];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // get brightness of pixel (scaled to 0-1)
            double brightness = (double)img[y][x] / 255;

            // find closest ascii character based on brightness
            int index = (int)(brightness * strlen(ascii_chars));
            ascii[y][x] = ascii_chars[index];
        }
    }

    // write ascii art to output file
    FILE *out = fopen(output_file, "w");
    if (!out) {
        printf("Error: Could not open output file '%s'\n", output_file);
        return 1;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fprintf(out, "%c", ascii[y][x]);
        }
        fprintf(out, "\n");
    }
    fclose(out);

    printf("Done! Image converted to ASCII art and written to file '%s'.\n", output_file);
    return 0;
}