//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH  80
#define MAX_HEIGHT 25

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image *create_image(int width, int height)
{
    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->data = malloc(width * height);
    if (image->data == NULL) {
        free(image);
        return NULL;
    }

    return image;
}

void destroy_image(Image *image)
{
    free(image->data);
    free(image);
}

int load_image(Image *image, char *filename)
{
    FILE *fp;
    int i, j;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    fscanf(fp, "%d %d\n", &image->width, &image->height);

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            fscanf(fp, "%c", &image->data[i * image->width + j]);
        }
        fscanf(fp, "\n");
    }

    fclose(fp);

    return 0;
}

void save_image(Image *image, char *filename)
{
    FILE *fp;
    int i, j;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        return;
    }

    fprintf(fp, "%d %d\n", image->width, image->height);

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            fprintf(fp, "%c", image->data[i * image->width + j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void convert_image_to_ascii(Image *image, char *output)
{
    int i, j;
    char *ascii_table = ".`',:;!i?!"";~^()[]{}<>";

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            output[i * image->width + j] = ascii_table[(int)((image->data[i * image->width + j] - 32) / 8.0 * strlen(ascii_table))];
        }
    }
}

int main(int argc, char **argv)
{
    Image *image;
    char *output;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input image> <output text>\n", argv[0]);
        return 1;
    }

    image = create_image(MAX_WIDTH, MAX_HEIGHT);
    if (image == NULL) {
        fprintf(stderr, "Error: could not create image\n");
        return 1;
    }

    if (load_image(image, argv[1]) != 0) {
        fprintf(stderr, "Error: could not load image\n");
        destroy_image(image);
        return 1;
    }

    output = malloc(image->width * image->height);
    if (output == NULL) {
        fprintf(stderr, "Error: could not allocate memory for output\n");
        destroy_image(image);
        return 1;
    }

    convert_image_to_ascii(image, output);

    save_image(image, argv[2]);

    destroy_image(image);
    free(output);

    return 0;
}