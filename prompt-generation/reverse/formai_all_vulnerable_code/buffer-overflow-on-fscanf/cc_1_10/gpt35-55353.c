//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1024
#define MAX_COLOR_VALUE 255

typedef struct {
    int width;
    int height;
    int pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
} Image;

/**
 * Load the image from the text file
 */
void load_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open %s.\n", filename);
        exit(1);
    }
    fscanf(fp, "%d %d", &image->width, &image->height);
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fscanf(fp, "%d", &image->pixels[i][j]);
        }
    }
    fclose(fp);
}

/**
 * Write the image to the text file
 */
void write_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "%d %d\n", image->width, image->height);
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fprintf(fp, "%d ", image->pixels[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

/**
 * Flip the image horizontally
 */
void flip_horizontal(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            int temp = image->pixels[i][j];
            image->pixels[i][j] = image->pixels[i][image->width - j - 1];
            image->pixels[i][image->width - j - 1] = temp;
        }
    }
}

/**
 * Change the brightness of the image
 */
void change_brightness(Image *image, int delta) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            image->pixels[i][j] = image->pixels[i][j] + delta;
            if (image->pixels[i][j] > MAX_COLOR_VALUE) {
                image->pixels[i][j] = MAX_COLOR_VALUE;
            }
            else if (image->pixels[i][j] < 0) {
                image->pixels[i][j] = 0;
            }
        }
    }
}

/**
 * Change the contrast of the image
 */
void change_contrast(Image *image, float alpha) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            image->pixels[i][j] = (int)(alpha * (image->pixels[i][j] - MAX_COLOR_VALUE / 2) + MAX_COLOR_VALUE / 2);
            if (image->pixels[i][j] > MAX_COLOR_VALUE) {
                image->pixels[i][j] = MAX_COLOR_VALUE;
            }
            else if (image->pixels[i][j] < 0) {
                image->pixels[i][j] = 0;
            }
        }
    }
}

int main() {
    Image image;
    char filename[100];
    int choice;
    int delta;
    float alpha;

    printf("Enter the filename of the image to load: ");
    scanf("%s", filename);
    load_image(&image, filename);

    printf("1. Flip the image horizontally\n");
    printf("2. Change the brightness of the image\n");
    printf("3. Change the contrast of the image\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            flip_horizontal(&image);
            break;
        case 2:
            printf("Enter the delta: ");
            scanf("%d", &delta);
            change_brightness(&image, delta);
            break;
        case 3:
            printf("Enter the alpha: ");
            scanf("%f", &alpha);
            change_contrast(&image, alpha);
            break;
        default:
            printf("Invalid choice.\n");
            exit(1);
    }

    printf("Enter the filename of the image to write: ");
    scanf("%s", filename);
    write_image(&image, filename);

    return 0;
}