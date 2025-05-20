//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//image structure
typedef struct _image {
    int width;
    int height;
    int max_val;
    unsigned char *data;
} Image;

//function to read image file
Image* read_image(char* filename) {
    FILE *file;
    if (!(file = fopen(filename, "rb"))) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    //read image information and allocate memory
    Image *im = (Image*) malloc(sizeof(Image));
    char buf[1024];
    fgets(buf, 1024, file);  // P6
    fgets(buf, 1024, file);  // comment
    fscanf(file, "%d %d\n", &(im->width), &(im->height));
    fscanf(file, "%d\n", &(im->max_val));
    im->data = (unsigned char *) malloc(sizeof(unsigned char) * im->width * im->height * 3);
    //read image data
    fread(im->data, sizeof(unsigned char), im->width * im->height * 3, file);
    fclose(file);
    return im;
}

//function to write image file
void write_image(char* filename, Image* im) {
    FILE *file;
    if (!(file = fopen(filename, "wb"))) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    //write image information and data
    fprintf(file, "P6\n");
    fprintf(file, "# Created by Image Processing\n");
    fprintf(file, "%d %d\n", im->width, im->height);
    fprintf(file, "%d\n", im->max_val);
    fwrite(im->data, sizeof(unsigned char), im->width * im->height * 3, file);
    fclose(file);
}

//function to flip the image horizontally
void flip_horizontal(Image* im) {
    unsigned char *temp_data = (unsigned char *) malloc(sizeof(unsigned char) * im->width * im->height * 3);
    int i, j, k;
    for (i = 0; i < im->height; i++) {
        for (j = 0; j < im->width; j++) {
            for (k = 0; k < 3; k++) {
                temp_data[(i * im->width + j) * 3 + k] = im->data[(i * im->width + im->width - 1 - j) * 3 + k];
            }
        }
    }
    memcpy(im->data, temp_data, sizeof(unsigned char) * im->width * im->height * 3);
    free(temp_data);
}

//function to adjust the brightness and contrast of the image
void adjust_brightness_contrast(Image* im, int brightness, float contrast) {
    int i, j, k;
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (i = 0; i < im->height; i++) {
        for (j = 0; j < im->width; j++) {
            for (k = 0; k < 3; k++) {
                int value = im->data[(i * im->width + j) * 3 + k];
                value = (factor * (value - 128) + 128) + brightness;
                value = (value < 0) ? 0 : ((value > 255) ? 255 : value);
                im->data[(i * im->width + j) * 3 + k] = (unsigned char) value;
            }
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 5) {
        printf("Usage: %s input_file output_file brightness contrast\n", argv[0]);
        return 1;
    }
    //read image file
    char *input_file = argv[1];
    Image *im = read_image(input_file);
    //flip the image horizontally
    flip_horizontal(im);
    //adjust the brightness and contrast of the image
    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);
    adjust_brightness_contrast(im, brightness, contrast);
    //write the output image file
    char *output_file = argv[2];
    write_image(output_file, im);
    //free memory
    free(im->data);
    free(im);
    return 0;
}