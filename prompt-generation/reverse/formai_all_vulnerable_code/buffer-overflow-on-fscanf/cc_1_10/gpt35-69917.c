//FormAI DATASET v1.0 Category: Image Editor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Image structure
typedef struct Image {
    char magic_number[3];
    int width;
    int height;
    int max_value;
    unsigned char *pixels;
} Image;

// Function to allocate memory for an image
Image* create_image() {
    Image *img = malloc(sizeof(Image));
    if (img == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for image!\n");
        exit(1);
    }
    return img;
}

// Function to read a PGM file and store it as an image
Image* read_pgm_file(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open file '%s' for reading!\n", filename);
        exit(1);
    }

    char header[3];
    int width, height, max_value;

    fscanf(fp, "%s\n%d %d\n%d\n", header, &width, &height, &max_value);

    if (strcmp(header, "P5") != 0) {
        fprintf(stderr, "Error: Invalid file format! Only P5 PGM files are supported!\n");
        fclose(fp);
        exit(1);
    }

    Image *img = create_image();
    img->magic_number[0] = header[0];
    img->magic_number[1] = header[1];
    img->magic_number[2] = '\0';
    img->width = width;
    img->height = height;
    img->max_value = max_value;
    img->pixels = (unsigned char*) malloc(sizeof(unsigned char) * width * height);
    if (img->pixels == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for image pixels!\n");
        fclose(fp);
        exit(1);
    }

    fread(img->pixels, sizeof(unsigned char), width * height, fp);
    if (feof(fp) == 0) {
        fprintf(stderr, "Error: Unable to read image data from file!\n");
        fclose(fp);
        exit(1);
    }

    fclose(fp);
    return img;
}

// Function to write an image as a PGM file
void write_pgm_file(char *filename, Image *img) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open file '%s' for writing!\n", filename);
        exit(1);
    }

    fprintf(fp, "%s\n%d %d\n%d\n", img->magic_number, img->width, img->height, img->max_value);

    fwrite(img->pixels, sizeof(unsigned char), img->width * img->height, fp);
    if (ferror(fp) != 0) {
        fprintf(stderr, "Error: Unable to write image data to file!\n");
        fclose(fp);
        exit(1);
    }

    fclose(fp);
}

// Function to copy an image
Image* copy_image(Image *img) {
    Image *new_img = create_image();
    new_img->magic_number[0] = img->magic_number[0];
    new_img->magic_number[1] = img->magic_number[1];
    new_img->magic_number[2] = '\0';
    new_img->width = img->width;
    new_img->height = img->height;
    new_img->max_value = img->max_value;
    new_img->pixels = (unsigned char*) malloc(sizeof(unsigned char) * img->width * img->height);
    if (new_img->pixels == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for image pixels!\n");
        exit(1);
    }
    memcpy(new_img->pixels, img->pixels, sizeof(unsigned char) * img->width * img->height);
    return new_img;
}

// Function to invert the colors of an image
void invert_image(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i] = img->max_value - img->pixels[i];
    }
}

// Function to convert an image to grayscale
void grayscale_image(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char pixel_value = img->pixels[i];
        unsigned char grayscale_value = (unsigned char) (0.3 * (double) ((pixel_value >> 16) & 0xff) + 0.59 * (double) ((pixel_value >> 8) & 0xff) + 0.11 * (double) (pixel_value & 0xff));
        img->pixels[i] = grayscale_value;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [input_file.pgm] [output_file.pgm]\n", argv[0]);
        exit(1);
    }

    Image *img = read_pgm_file(argv[1]);

    // Create a copy of the original image
    Image *copy = copy_image(img);

    // Invert the colors of the image
    invert_image(img);

    // Convert the image to grayscale
    grayscale_image(copy);

    // Write the inverted image to disk
    write_pgm_file("inverted.pgm", img);

    // Write the grayscale image to disk
    write_pgm_file("grayscale.pgm", copy);

    printf("Image processing complete!\n");

    // Free memory
    free(img->pixels);
    free(img);
    free(copy->pixels);
    free(copy);

    return 0;
}