//FormAI DATASET v1.0 Category: Image Editor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declare the structure to hold the image metadata and data
typedef struct {
    char format[3];
    int width;
    int height;
    int max_val;
    unsigned char *data;
} Image;

// Function to read the image from a file
Image *read_image(char *filename) {
    FILE *fin = fopen(filename, "r");
    if (!fin) {
        fprintf(stderr, "Error: Unable to open file '%s'\n", filename);
        exit(1);
    }

    // Read the image format
    char format[3];
    fscanf(fin, "%s", format);
    
    // Check if the image format is supported
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Error: Unsupported image format '%s'\n", format);
        exit(1);
    }

    // Read the image dimensions and max value
    int width, height, max_val;
    fscanf(fin, "%d %d %d\n", &width, &height, &max_val);

    // Allocate memory for the image data array and read the pixel data
    unsigned char *data = malloc(width * height * 3 * sizeof(unsigned char));
    fread(data, sizeof(unsigned char), width * height * 3, fin);

    // Close the input file and create a new image structure to hold the data
    fclose(fin);
    Image *img = malloc(sizeof(Image));
    strcpy(img->format, format);
    img->width = width;
    img->height = height;
    img->max_val = max_val;
    img->data = data;

    return img;
}

// Function to write the image to a file
void write_image(Image *img, char *filename) {
    FILE *fout = fopen(filename, "w");
    if (!fout) {
        fprintf(stderr, "Error: Unable to open file '%s'\n", filename);
        exit(1);
    }

    // Write the image format, dimensions and max value
    fprintf(fout, "%s\n%d %d\n%d\n", img->format, img->width, img->height, img->max_val);

    // Write the pixel data array
    fwrite(img->data, sizeof(unsigned char), img->width * img->height * 3, fout);

    // Close the output file
    fclose(fout);
}

// Function to apply a simple grayscale filter to the image
void grayscale_filter(Image *img) {
    for (int i = 0; i < img->width * img->height * 3; i += 3) {
        unsigned char r = img->data[i];
        unsigned char g = img->data[i+1];
        unsigned char b = img->data[i+2];
        unsigned char gray = (r + g + b) / 3;
        img->data[i] = gray;
        img->data[i+1] = gray;
        img->data[i+2] = gray;
    }
}

// Function to apply a simple blur filter to the image
void blur_filter(Image *img) {
    unsigned char *tmp = malloc(img->width * img->height * 3 * sizeof(unsigned char));
    memcpy(tmp, img->data, img->width * img->height * 3);

    for (int i = 0; i < img->width; i++) {
        for (int j = 0; j < img->height; j++) {
            int idx = ((j * img->width) + i) * 3;

            unsigned char r = 0, g = 0, b = 0;
            int count = 0;

            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (i + x >= 0 && i + x < img->width && j + y >= 0 && j + y < img->height) {
                        int newidx = (((j+y) * img->width) + (i+x)) * 3;
                        r += tmp[newidx];
                        g += tmp[newidx+1];
                        b += tmp[newidx+2];
                        count++;
                    }
                }
            }

            img->data[idx] = r / count;
            img->data[idx+1] = g / count;
            img->data[idx+2] = b / count;
        }
    }

    free(tmp);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s infile outfile\n", argv[0]);
        return 1;
    }

    Image *img = read_image(argv[1]);
    printf("Loaded image from file '%s'\n", argv[1]);

    // Apply filters to the image
    grayscale_filter(img);
    printf("Applied grayscale filter\n");
    blur_filter(img);
    printf("Applied blur filter\n");

    write_image(img, argv[2]);
    printf("Wrote image to file '%s'\n", argv[2]);

    free(img->data);
    free(img);

    return 0;
}