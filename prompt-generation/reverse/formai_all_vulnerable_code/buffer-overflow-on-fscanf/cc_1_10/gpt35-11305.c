//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

typedef struct {
    int width;
    int height;
    unsigned char* data;
} Image;

// function prototype
Image* read_image(char* filename);
void write_image(char* filename, Image* image);
void flip_image(Image* image);
void adjust_brightness(Image* image, int brightness);
void adjust_contrast(Image* image, float contrast);

int main(void)
{
    char filename[MAX_FILENAME_LENGTH];
    int brightness;
    float contrast;
    Image* image;

    printf("Enter image filename: ");
    scanf("%s", filename);

    image = read_image(filename);

    if (image == NULL) {
        printf("Error: Failed to read image\n");
        return 1;
    }

    // Flip image horizontally
    flip_image(image);

    // Adjust brightness
    printf("Enter brightness adjustment value (-255 to 255): ");
    scanf("%d", &brightness);
    adjust_brightness(image, brightness);

    // Adjust contrast
    printf("Enter contrast adjustment value (0.1 to 10.0): ");
    scanf("%f", &contrast);
    adjust_contrast(image, contrast);

    // Write output image
    write_image("output.pgm", image);

    free(image->data);
    free(image);

    printf("Done!\n");

    return 0;
}

Image* read_image(char* filename)
{
    FILE* file = fopen(filename, "rb");
    char magic_number[3];
    int width, height, max_val;
    Image* image;

    if (!file) {
        printf("Error: Could not open image file\n");
        return NULL;
    }

    // Read image header
    fscanf(file, "%s\n%d %d\n%d\n", magic_number, &width, &height, &max_val);

    if (strcmp(magic_number, "P5") != 0) {
        printf("Error: Invalid image format, only .PGM files accepted\n");
        fclose(file);
        return NULL;
    }

    image = (Image*) malloc(sizeof(Image));

    if (!image) {
        printf("Error: Could not allocate memory for image\n");
        fclose(file);
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->data = (unsigned char*) malloc(width * height);

    // Read image data
    fread(image->data, 1, width * height, file);

    fclose(file);

    return image;
}

void write_image(char* filename, Image* image)
{
    FILE* file = fopen(filename, "wb");

    fprintf(file, "P5\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, 1, image->width * image->height, file);

    fclose(file);
}

void flip_image(Image* image)
{
    int i, j;
    unsigned char temp;

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width / 2; j++) {
            temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[i * image->width + (image->width - j - 1)];
            image->data[i * image->width + (image->width - j - 1)] = temp;
        }
    }
}

void adjust_brightness(Image* image, int brightness)
{
    int i, j;
    int val;

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            val = image->data[i * image->width + j] + brightness;

            if (val < 0) {
                image->data[i * image->width + j] = 0;
            } else if (val > 255) {
                image->data[i * image->width + j] = 255;
            } else {
                image->data[i * image->width + j] = (unsigned char) val;
            }
        }
    }
}

void adjust_contrast(Image* image, float contrast)
{
    int i, j;
    float val;

    contrast = (100.0 + contrast) / 100.0;

    contrast *= contrast;

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            val = (((float) image->data[i * image->width + j] / 255.0) - 0.5) * contrast + 0.5;
            val *= 255;

            if (val < 0) {
                image->data[i * image->width + j] = 0;
            } else if (val > 255) {
                image->data[i * image->width + j] = 255;
            } else {
                image->data[i * image->width + j] = (unsigned char) val;
            }
        }
    }
}