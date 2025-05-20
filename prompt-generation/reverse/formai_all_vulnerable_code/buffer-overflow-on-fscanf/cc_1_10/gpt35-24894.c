//FormAI DATASET v1.0 Category: Image Editor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_FILENAME_LENGTH 50

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    Pixel *data;
    int width;
    int height;
} Image;

Image *load_image(char *filename) {
    FILE *input_file = fopen(filename, "rb");
    if (input_file == NULL) {
        printf("Failed to open file!\n");
        return NULL;
    }

    char magic_number[3];
    fscanf(input_file, "%s", magic_number);
    if (strcmp(magic_number, "P6") != 0) {
        printf("Input file must be a P6 PPM image!\n");
        fclose(input_file);
        return NULL;
    }

    int width, height, max_color_value;
    fscanf(input_file, "%d %d %d", &width, &height, &max_color_value);
    if (max_color_value != 255) {
        printf("Max color value must be 255!\n");
        fclose(input_file);
        return NULL;
    }

    Image *image = (Image*) malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = (Pixel*) malloc(width * height * sizeof(Pixel));

    fread(image->data, sizeof(Pixel), width * height, input_file);
    fclose(input_file);

    return image;
}

void save_image(Image *image, char *filename) {
    FILE *output_file = fopen(filename, "wb");
    if (output_file == NULL) {
        printf("Failed to open file!\n");
        return;
    }

    fprintf(output_file, "P6\n%d %d\n%d\n", image->width, image->height, 255);
    fwrite(image->data, sizeof(Pixel), image->width * image->height, output_file);
    fclose(output_file);
}

Image *create_image(int width, int height) {
    Image *image = (Image*) malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = (Pixel*) malloc(width * height * sizeof(Pixel));

    for (int i = 0; i < width * height; i++) {
        image->data[i].red = 255;
        image->data[i].green = 255;
        image->data[i].blue = 255;
    }

    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void set_pixel(Image *image, int x, int y, Pixel pixel) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        return;
    }

    image->data[y * image->width + x] = pixel;
}

Pixel get_pixel(Image *image, int x, int y) {
    if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
        Pixel pixel;
        pixel.red = 0;
        pixel.green = 0;
        pixel.blue = 0;
        return pixel;
    }

    return image->data[y * image->width + x];
}

Image *copy_image(Image *image) {
    Image *copy = create_image(image->width, image->height);
    memcpy(copy->data, image->data, image->width * image->height * sizeof(Pixel));
    return copy;
}

Image *invert_image(Image *image) {
    Image *copy = copy_image(image);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel pixel = get_pixel(copy, x, y);
            pixel.red = 255 - pixel.red;
            pixel.green = 255 - pixel.green;
            pixel.blue = 255 - pixel.blue;
            set_pixel(copy, x, y, pixel);
        }
    }

    return copy;
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    Image *image = load_image(filename);
    if (image == NULL) {
        return 1;
    }

    printf("Loaded image with dimensions %d x %d\n", image->width, image->height);

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Invert colors\n");
        printf("2. Save image\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Image *inverted_image = invert_image(image);
                free_image(image);
                image = inverted_image;
                printf("Image colors inverted!\n");
                break;
            }
            case 2: {
                char output_filename[MAX_FILENAME_LENGTH];
                printf("Enter output filename: ");
                scanf("%s", output_filename);
                save_image(image, output_filename);
                printf("Image saved!\n");
                break;
            }
            case 3: {
                printf("Goodbye!\n");
                free_image(image);
                return 0;
            }
            default: {
                printf("Invalid choice!\n");
                break;
            }
        }
    }

    return 0;
}