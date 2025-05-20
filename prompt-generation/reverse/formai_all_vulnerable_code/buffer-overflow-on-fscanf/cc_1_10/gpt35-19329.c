//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

/* Define a structure to represent pixel color */
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

/* Define a structure to represent an image */
typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

/* Function to read an image from a file */
Image* read_image(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        return NULL;
    }

    char type[3];
    fscanf(file, "%s", type); // read image type
    if (type[0] != 'P' || type[1] != '6') {
        printf("Error: invalid image format\n");
        return NULL;
    }

    Image *image = (Image*) malloc(sizeof(Image));
    if (!image) {
        printf("Error: could not allocate memory\n");
        return NULL;   
    }

    fscanf(file, "%d %d", &image->width, &image->height); // read image dimensions
    int max_val;
    fscanf(file, "%d", &max_val); // read maximum color value
    fgetc(file); // consume newline character

    image->pixels = (Pixel*) malloc(sizeof(Pixel) * image->width * image->height);
    if (!image->pixels) {
        printf("Error: could not allocate memory\n");
        return NULL;   
    }

    fread(image->pixels, sizeof(Pixel), image->width * image->height, file); // read image data from file
    fclose(file);

    return image;
}

/* Function to write an image to a file */
void write_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    fprintf(file, "P6\n%d %d\n%d\n", image->width, image->height, 255); // write image header
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file); // write image data to file
    fclose(file);
}

/* Function to flip an image horizontally */
Image* flip_horizontal(Image *image) {
    Image *result = (Image*) malloc(sizeof(Image));
    result->width = image->width;
    result->height = image->height;
    result->pixels = (Pixel*) malloc(sizeof(Pixel) * result->width * result->height);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int index1 = y * image->width + x;
            int index2 = y * image->width + (image->width - 1 - x);
            result->pixels[index2] = image->pixels[index1];
        }
    }

    return result;
}

/* Function to change the brightness and contrast of an image */
Image* adjust_brightness_contrast(Image *image, int brightness, int contrast) {
    Image *result = (Image*) malloc(sizeof(Image));
    result->width = image->width;
    result->height = image->height;
    result->pixels = (Pixel*) malloc(sizeof(Pixel) * result->width * result->height);

    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int index = y * image->width + x;
            
            float red = image->pixels[index].red;
            float green = image->pixels[index].green;
            float blue = image->pixels[index].blue;

            red = factor * (red - 128) + 128 + brightness;
            green = factor * (green - 128) + 128 + brightness;
            blue = factor * (blue - 128) + 128 + brightness;

            if (red < 0) red = 0;
            if (red > 255) red = 255;
            if (green < 0) green = 0;
            if (green > 255) green = 255;
            if (blue < 0) blue = 0;
            if (blue > 255) blue = 255;

            result->pixels[index].red = (unsigned char) red;
            result->pixels[index].green = (unsigned char) green;
            result->pixels[index].blue = (unsigned char) blue;
        }
    }

    return result;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <inputfile> <outputfile>\n", argv[0]);
        return 0;
    }

    Image *input = read_image(argv[1]);
    if (!input) {
        return 0;
    }

    Image *output1 = flip_horizontal(input);
    if (!output1) {
        free(input->pixels);
        free(input);
        return 0;
    }

    Image *output2 = adjust_brightness_contrast(input, 50, 50);
    if (!output2) {
        free(input->pixels);
        free(input);
        free(output1->pixels);
        free(output1);
        return 0;
    }

    write_image(output1, "output1.ppm");
    write_image(output2, "output2.ppm");

    free(input->pixels);
    free(input);
    free(output1->pixels);
    free(output1);
    free(output2->pixels);
    free(output2);

    return 0;
}