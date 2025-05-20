//FormAI DATASET v1.0 Category: Image Editor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_PIXEL_VALUE 255

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel** pixels;
} Image;

void free_image(Image* image)
{
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

Image* read_image(char* file_name)
{
    Image* image = malloc(sizeof(Image));
    FILE* fp = fopen(file_name, "rb");
    char format[3];
    int max_pixel_value;
    fscanf(fp, "%s\n", format);
    fscanf(fp, "%d %d\n", &image->width, &image->height);
    fscanf(fp, "%d\n", &max_pixel_value);

    if (strcmp(format, "P6") != 0 || max_pixel_value != MAX_PIXEL_VALUE) {
        printf("Invalid image format\n");
        return NULL;
    }

    image->pixels = malloc(sizeof(Pixel*) * image->height);
    for (int i = 0; i < image->height; i++) {
        image->pixels[i] = malloc(sizeof(Pixel) * image->width);
        fread(image->pixels[i], sizeof(Pixel), image->width, fp);
    }

    fclose(fp);
    return image;
}

void write_image(char* file_name, Image* image)
{
    FILE* fp = fopen(file_name, "wb");
    fprintf(fp, "P6\n%d %d\n%d\n", image->width, image->height, MAX_PIXEL_VALUE);

    for (int i = 0; i < image->height; i++) {
        fwrite(image->pixels[i], sizeof(Pixel), image->width, fp);
    }

    fclose(fp);
}

void invert_colors(Image* image)
{
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            image->pixels[i][j].red = MAX_PIXEL_VALUE - image->pixels[i][j].red;
            image->pixels[i][j].green = MAX_PIXEL_VALUE - image->pixels[i][j].green;
            image->pixels[i][j].blue = MAX_PIXEL_VALUE - image->pixels[i][j].blue;
        }
    }
}

int main()
{
    char file_name[MAX_FILE_NAME_LENGTH];

    // Read input image file
    printf("Enter input image file name: ");
    scanf("%s", file_name);

    Image* image = read_image(file_name);
    if (image == NULL) {
        return EXIT_FAILURE;
    }

    // Invert colors
    printf("Inverting colors...\n");
    invert_colors(image);

    // Write output image file
    printf("Enter output image file name: ");
    scanf("%s", file_name);

    write_image(file_name, image);
    free_image(image);

    return EXIT_SUCCESS;
}