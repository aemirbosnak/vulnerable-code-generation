//FormAI DATASET v1.0 Category: Image Editor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char red, green, blue;
} pixel;

void grayscale(pixel *, int, int);
void invert(pixel *, int, int);
void flip_horizontal(pixel *, int, int);
void flip_vertical(pixel *, int, int);

int main() {
    FILE *input_file, *output_file;
    char input_filename[50], output_filename[50];
    int width, height;
    pixel *image;

    printf("Enter the input image filename: ");
    scanf("%s", input_filename);

    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(input_file, "P6\n%d %d\n255\n", &width, &height);

    image = (pixel *) malloc(width * height * sizeof(pixel));

    fread(image, sizeof(pixel), width * height, input_file);

    printf("What do you want to do with the image? (g for grayscale, i for invert, fh for flip horizontally, fv for flip vertically): ");
    char selected_option[2];
    scanf("%s", selected_option);

    switch (selected_option[0]) {
        case 'g':
            grayscale(image, width, height);
            sprintf(output_filename, "grayscale_%s", input_filename);
            break;
        case 'i':
            invert(image, width, height);
            sprintf(output_filename, "invert_%s", input_filename);
            break;
        case 'fh':
            flip_horizontal(image, width, height);
            sprintf(output_filename, "flip_horizontal_%s", input_filename);
            break;
        case 'fv':
            flip_vertical(image, width, height);
            sprintf(output_filename, "flip_vertical_%s", input_filename);
            break;
        default:
            printf("Invalid option.\n");
            return 1;
    }

    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(output_file, "P6\n%d %d\n255\n", width, height);

    fwrite(image, sizeof(pixel), width * height, output_file);

    free(image);

    fclose(input_file);
    fclose(output_file);

    printf("Image processed successfully and saved as %s.\n", output_filename);

    return 0;
}

void grayscale(pixel *image, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        unsigned char gray_value = (image[i].red + image[i].green + image[i].blue) / 3;
        image[i].red = gray_value;
        image[i].green = gray_value;
        image[i].blue = gray_value;
    }
}

void invert(pixel *image, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        image[i].red = 255 - image[i].red;
        image[i].green = 255 - image[i].green;
        image[i].blue = 255 - image[i].blue;
    }
}

void flip_horizontal(pixel *image, int width, int height) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width / 2; col++) {
            pixel temp = image[row * width + col];
            image[row * width + col] = image[row * width + (width - 1 - col)];
            image[row * width + (width - 1 - col)] = temp;
        }
    }
}

void flip_vertical(pixel *image, int width, int height) {
    for (int col = 0; col < width; col++) {
        for (int row = 0; row < height / 2; row++) {
            pixel temp = image[row * width + col];
            image[row * width + col] = image[(height - 1 - row) * width + col];
            image[(height - 1 - row) * width + col] = temp;
        }
    }
}