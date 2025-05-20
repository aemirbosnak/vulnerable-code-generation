//FormAI DATASET v1.0 Category: Image Editor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

typedef struct {
    unsigned char red, green, blue;  
} Pixel;

typedef struct {
    int width, height;  
    Pixel *data;  
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->data = malloc(sizeof(Pixel) * width * height);
    image->width = width;
    image->height = height;
    return image;
}

void destroy_image(Image *image) {
    free(image->data);
    free(image);
}

void set_pixel(Image *image, int x, int y, Pixel pixel) {
    image->data[y * image->width + x] = pixel;
}

Pixel get_pixel(Image *image, int x, int y) {
    return image->data[y * image->width + x];
}

void load_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char format[MAX_LENGTH];
    int width, height, max;
    fscanf(file, "%s\n%d %d\n%d\n", format, &width, &height, &max);

    if (strcmp(format, "P3") != 0 || max != 255) {
        printf("Error: invalid file format\n");
        exit(1);
    }

    image->width = width;
    image->height = height;
    image->data = malloc(sizeof(Pixel) * height * width);

    int red, green, blue;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fscanf(file, "%d %d %d", &red, &green, &blue);
            Pixel pixel = {red, green, blue};
            set_pixel(image, x, y, pixel);
        }
    }

    fclose(file);
}

void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fprintf(file, "P3\n%d %d\n255\n", image->width, image->height);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel pixel = get_pixel(image, x, y);
            fprintf(file, "%d %d %d ", pixel.red, pixel.green, pixel.blue);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void grayscale(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel pixel = get_pixel(image, x, y);
            unsigned char avg = (pixel.red + pixel.green + pixel.blue) / 3;
            pixel.red = avg;
            pixel.green = avg;
            pixel.blue = avg;
            set_pixel(image, x, y, pixel);
        }
    }
}

void invert_colors(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel pixel = get_pixel(image, x, y);
            pixel.red = 255 - pixel.red;
            pixel.green = 255 - pixel.green;
            pixel.blue = 255 - pixel.blue;
            set_pixel(image, x, y, pixel);
        }
    }
}

void blur(Image *image) {
    Image *temp = create_image(image->width, image->height);
    memcpy(temp->data, image->data, sizeof(Pixel) * image->width * image->height);

    int kernel[3][3] = {
        {1, 2, 1},
        {2, 4, 2},
        {1, 2, 1},
    };

    for (int y = 1; y < image->height - 1; y++) {
        for (int x = 1; x < image->width - 1; x++) {
            Pixel new_pixel = {0, 0, 0};

            for (int j = -1; j <= 1; j++) {
                for (int i = -1; i <= 1; i++) {
                    Pixel pixel = get_pixel(temp, x+i, y+j);
                    int weight = kernel[j+1][i+1];
                    new_pixel.red += weight * pixel.red;
                    new_pixel.green += weight * pixel.green;
                    new_pixel.blue += weight * pixel.blue;
                }
            }

            new_pixel.red /= 16;
            new_pixel.green /= 16;
            new_pixel.blue /= 16;

            set_pixel(image, x, y, new_pixel);
        }
    }

    destroy_image(temp);
}

int main() {
    Image *image = create_image(100, 100);
    set_pixel(image, 50, 50, (Pixel){255, 255, 255});

    printf("Image created.\n");

    load_image(image, "input.ppm");

    printf("Image loaded.\n");

    grayscale(image);

    printf("Image grayscaled.\n");

    invert_colors(image);

    printf("Colors inverted.\n");

    blur(image);

    printf("Image blurred.\n");

    save_image(image, "output.ppm");

    printf("Image saved to output.ppm.\n");

    destroy_image(image);
    return 0;
}