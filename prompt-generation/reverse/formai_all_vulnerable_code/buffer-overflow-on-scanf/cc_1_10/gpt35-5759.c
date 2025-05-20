//FormAI DATASET v1.0 Category: Image Editor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMG_HEIGHT 100
#define IMG_WIDTH 100

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} color;

color img[IMG_HEIGHT][IMG_WIDTH];

/* Function to convert a color image to a grayscale image */
void grayscale() {
    int i, j;
    unsigned char r, g, b, gray;

    for (i = 0; i < IMG_HEIGHT; i++) {
        for (j = 0; j < IMG_WIDTH; j++) {
            r = img[i][j].red;
            g = img[i][j].green;
            b = img[i][j].blue;
            gray = (r * 0.3) + (g * 0.59) + (b * 0.11);

            img[i][j].red = gray;
            img[i][j].green = gray;
            img[i][j].blue = gray;
        }
    }
}

/* Function to invert the colors of an image */
void invert_colors() {
    int i, j;
    unsigned char r, g, b;

    for (i = 0; i < IMG_HEIGHT; i++) {
        for (j = 0; j < IMG_WIDTH; j++) {
            r = img[i][j].red;
            g = img[i][j].green;
            b = img[i][j].blue;

            img[i][j].red = 255 - r;
            img[i][j].green = 255 - g;
            img[i][j].blue = 255 - b;
        }
    }
}

/* Function to flip an image horizontally */
void flip_horizontal() {
    int i, j;
    color temp;

    for (i = 0; i < IMG_HEIGHT; i++) {
        for (j = 0; j < IMG_WIDTH / 2; j++) {
            temp = img[i][j];
            img[i][j] = img[i][IMG_WIDTH - j - 1];
            img[i][IMG_WIDTH - j - 1] = temp;
        }
    }
}

/* Function to flip an image vertically */
void flip_vertical() {
    int i, j;
    color temp;

    for (j = 0; j < IMG_WIDTH; j++) {
        for (i = 0; i < IMG_HEIGHT / 2; i++) {
            temp = img[i][j];
            img[i][j] = img[IMG_HEIGHT - i - 1][j];
            img[IMG_HEIGHT - i - 1][j] = temp;
        }
    }
}

/* Function to save the image as a PPM file */
void save_image(char *filename) {
    int i, j;
    FILE *f;
    char format[3] = "P6\n";
    char resolution[20];
    char max_color[5] = "255\n";

    sprintf(resolution, "%d %d\n", IMG_WIDTH, IMG_HEIGHT);

    f = fopen(filename, "wb");
    fwrite(format, sizeof(char), strlen(format), f);
    fwrite(resolution, sizeof(char), strlen(resolution), f);
    fwrite(max_color, sizeof(char), strlen(max_color), f);

    for (i = 0; i < IMG_HEIGHT; i++) {
        for (j = 0; j < IMG_WIDTH; j++) {
            fwrite(&img[i][j].red, sizeof(unsigned char), 1, f);
            fwrite(&img[i][j].green, sizeof(unsigned char), 1, f);
            fwrite(&img[i][j].blue, sizeof(unsigned char), 1, f);
        }
    }

    fclose(f);
}

int main() {
    int choice;
    char filename[50];

    printf("Welcome to the Image Editor!\n");
    printf("Please select an option from the menu below:\n\n");

    do {
        printf("1. Convert image to grayscale\n");
        printf("2. Invert colors of image\n");
        printf("3. Flip image horizontally\n");
        printf("4. Flip image vertically\n");
        printf("5. Save image\n");
        printf("0. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                grayscale();
                printf("Image converted to grayscale!\n");
                break;
            case 2:
                invert_colors();
                printf("Colors of image inverted!\n");
                break;
            case 3:
                flip_horizontal();
                printf("Image flipped horizontally!\n");
                break;
            case 4:
                flip_vertical();
                printf("Image flipped vertically!\n");
                break;
            case 5:
                printf("Please enter a filename (including extension) to save the image: ");
                scanf("%s", filename);
                save_image(filename);
                printf("Image saved as %s!\n", filename);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

        printf("\n");
    } while (choice != 0);

    return 0;
}