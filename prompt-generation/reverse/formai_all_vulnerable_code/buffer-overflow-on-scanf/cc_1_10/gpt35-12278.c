//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define GREEN 1
#define BLUE 2

typedef struct pixel {
    unsigned char channels[3];
} Pixel;

Pixel **read_image_file(char *filename, int *width, int *height) {
    FILE *fp;
    Pixel **image;
    int i, j;

    fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening file");
        exit(1);
    }
    fscanf(fp, "P6\n%d %d\n255\n", width, height);

    image = (Pixel **) malloc(*height * sizeof(Pixel *));
    for (i = 0; i < *height; i++) {
        image[i] = (Pixel *) malloc(*width * sizeof(Pixel));
        for (j = 0; j < *width; j++) {
            fread(&image[i][j], sizeof(Pixel), 1, fp);
        }
    }

    fclose(fp);
    return image;
}

void write_image_file(char *filename, Pixel **image, int width, int height) {
    FILE *fp;
    int i, j;

    fp = fopen(filename, "wb");
    if (!fp) {
        perror("Error opening file");
        exit(1);
    }
    fprintf(fp, "P6\n%d %d\n255\n", width, height);

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fwrite(&image[i][j], sizeof(Pixel), 1, fp);
        }
    }

    fclose(fp);
}

void flip_image(Pixel **image, int width, int height) {
    int i, j;
    Pixel temp;

    for (i = 0; i < height / 2; i++) {
        for (j = 0; j < width; j++) {
            temp = image[i][j];
            image[i][j] = image[height - i - 1][j];
            image[height - i - 1][j] = temp;
        }
    }
}

void adjust_brightness(Pixel **image, int width, int height, int brightness) {
    int i, j, k, pixel_value;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            for (k = 0; k < 3; k++) {
                pixel_value = (int) image[i][j].channels[k] + brightness;
                if (pixel_value > 255) {
                    pixel_value = 255;
                } else if (pixel_value < 0) {
                    pixel_value = 0;
                }
                image[i][j].channels[k] = (unsigned char) pixel_value;
            }
        }
    }
}

void adjust_contrast(Pixel **image, int width, int height, float contrast) {
    int i, j, k, pixel_value;
    float factor;

    factor = (259 * (contrast + 255)) / (255 * (259 - contrast));

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            for (k = 0; k < 3; k++) {
                pixel_value = (int) (factor * (image[i][j].channels[k] - 128) + 128);
                if (pixel_value > 255) {
                    pixel_value = 255;
                } else if (pixel_value < 0) {
                    pixel_value = 0;
                }
                image[i][j].channels[k] = (unsigned char) pixel_value;
            }
        }
    }
}

int main() {
    int width, height, choice;
    Pixel **image;
    char input_filename[64], output_filename[64];
    int brightness;
    float contrast;

    printf("Enter the input file name: ");
    scanf("%s", input_filename);

    image = read_image_file(input_filename, &width, &height);

    printf("Image width: %d\n", width);
    printf("Image height: %d\n", height);

    while (1) {
        printf("\n1. Flip image\n");
        printf("2. Adjust brightness\n");
        printf("3. Adjust contrast\n");
        printf("4. Save image\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                flip_image(image, width, height);
                printf("Image flipped\n");
                break;
            case 2:
                printf("Enter brightness value (-255 to 255): ");
                scanf("%d", &brightness);
                adjust_brightness(image, width, height, brightness);
                printf("Brightness adjusted\n");
                break;
            case 3:
                printf("Enter contrast value (0.01 to 10): ");
                scanf("%f", &contrast);
                adjust_contrast(image, width, height, contrast);
                printf("Contrast adjusted\n");
                break;
            case 4:
                printf("Enter the output file name: ");
                scanf("%s", output_filename);
                write_image_file(output_filename, image, width, height);
                printf("Image saved to %s\n", output_filename);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}