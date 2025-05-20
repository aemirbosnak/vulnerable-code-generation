//FormAI DATASET v1.0 Category: Image Editor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int red;
    int green;
    int blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel **pixels;
} Image;

// Function prototypes
Image *create_image(int width, int height);
void free_image(Image *image);
void set_pixel(Image *image, int x, int y, Pixel pixel);
Pixel get_pixel(Image *image, int x, int y);
void invert_colors(Image *image);
void grayscale(Image *image);
void brightness(Image *image, int value);
void contrast(Image *image, float value);
void blur(Image *image, int radius);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: image_editor FILE\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Unable to open file: %s\n", argv[1]);
        return 1;
    }

    int width, height;
    fscanf(file, "%d %d", &width, &height);

    Image *image = create_image(width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int red, green, blue;
            fscanf(file, "%d %d %d", &red, &green, &blue);
            Pixel pixel = {red, green, blue};
            set_pixel(image, x, y, pixel);
        }
    }

    fclose(file);

    // Apply image filters
    invert_colors(image);
    grayscale(image);
    brightness(image, 50);
    contrast(image, 1.5);
    blur(image, 3);

    // Save the edited image to a file
    file = fopen("edited_image.ppm", "w");
    if (!file) {
        printf("Unable to create file: edited_image.ppm\n");
        return 1;
    }

    fprintf(file, "P3\n%d %d\n255\n", image->width, image->height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Pixel pixel = get_pixel(image, x, y);
            fprintf(file, "%d %d %d ", pixel.red, pixel.green, pixel.blue);
        }
        fprintf(file, "\n");
    }

    fclose(file);

    free_image(image);

    return 0;
}

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(Pixel *) * height);
    for (int y = 0; y < height; y++) {
        image->pixels[y] = malloc(sizeof(Pixel) * width);
        for (int x = 0; x < width; x++) {
            Pixel pixel = {0, 0, 0};
            set_pixel(image, x, y, pixel);
        }
    }
    return image;
}

void free_image(Image *image) {
    for (int y = 0; y < image->height; y++) {
        free(image->pixels[y]);
    }
    free(image->pixels);
    free(image);
}

void set_pixel(Image *image, int x, int y, Pixel pixel) {
    image->pixels[y][x] = pixel;
}

Pixel get_pixel(Image *image, int x, int y) {
    return image->pixels[y][x];
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

void grayscale(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel pixel = get_pixel(image, x, y);
            int gray = (pixel.red + pixel.green + pixel.blue) / 3;
            pixel.red = gray;
            pixel.green = gray;
            pixel.blue = gray;
            set_pixel(image, x, y, pixel);
        }
    }
}

void brightness(Image *image, int value) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel pixel = get_pixel(image, x, y);
            pixel.red += value;
            pixel.green += value;
            pixel.blue += value;
            set_pixel(image, x, y, pixel);
        }
    }
}

void contrast(Image *image, float value) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel pixel = get_pixel(image, x, y);
            pixel.red = (int)(((pixel.red / 255.0) - 0.5) * value + 0.5) * 255;
            pixel.green = (int)(((pixel.green / 255.0) - 0.5) * value + 0.5) * 255;
            pixel.blue = (int)(((pixel.blue / 255.0) - 0.5) * value + 0.5) * 255;
            set_pixel(image, x, y, pixel);
        }
    }
}

void blur(Image *image, int radius) {
    Pixel **temp = malloc(sizeof(Pixel *) * image->height);
    for (int y = 0; y < image->height; y++) {
        temp[y] = malloc(sizeof(Pixel) * image->width);
        for (int x = 0; x < image->width; x++) {
            temp[y][x] = get_pixel(image, x, y);
        }
    }

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int red = 0, green = 0, blue = 0;
            int count = 0;
            for (int dy = -radius; dy <= radius; dy++) {
                for (int dx = -radius; dx <= radius; dx++) {
                    if (x + dx >= 0 && x + dx < image->width && y + dy >= 0 && y + dy < image->height) {
                        Pixel pixel = temp[y + dy][x + dx];
                        red += pixel.red;
                        green += pixel.green;
                        blue += pixel.blue;
                        count++;
                    }
                }
            }
            Pixel pixel = {red / count, green / count, blue / count};
            set_pixel(image, x, y, pixel);
        }
    }

    for (int y = 0; y < image->height; y++) {
        free(temp[y]);
    }
    free(temp);
}