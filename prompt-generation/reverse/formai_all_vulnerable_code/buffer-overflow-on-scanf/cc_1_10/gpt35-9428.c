//FormAI DATASET v1.0 Category: Image Editor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 640 // image width in pixels
#define HEIGHT 480 // image height in pixels
#define MAX_PIXEL_VALUE 255 // maximum pixel value

// Function to read an image from a PPM file
int **read_image(char *filename) {
    FILE *fp;
    char format[3];
    int width, height, max_pixel_value;
    int **image;
    int row, col;

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read the image format, width, height, and maximum pixel value
    fscanf(fp, "%s\n%d %d\n%d\n", format, &width, &height, &max_pixel_value);
    if (width != WIDTH || height != HEIGHT || max_pixel_value != MAX_PIXEL_VALUE) {
        perror("Error: invalid image dimensions or pixel values");
        exit(1);
    }

    // Allocate memory for the image
    image = (int **)malloc(HEIGHT * sizeof(int *));
    for (row = 0; row < HEIGHT; row++) {
        image[row] = (int *)malloc(WIDTH * sizeof(int));
    }

    // Read the pixel values into the image array
    for (row = 0; row < HEIGHT; row++) {
        for (col = 0; col < WIDTH; col++) {
            fscanf(fp, "%d", &image[row][col]);
        }
    }

    // Close the file and return the image
    fclose(fp);
    return image;
}

// Function to write an image to a PPM file
void write_image(char *filename, int **image) {
    FILE *fp;
    int row, col;
    
    // Open the file for writing
    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Write the image format, width, height, and maximum pixel value
    fprintf(fp, "P2\n%d %d\n%d\n", WIDTH, HEIGHT, MAX_PIXEL_VALUE);

    // Write the pixel values to the file
    for (row = 0; row < HEIGHT; row++) {
        for (col = 0; col < WIDTH; col++) {
            fprintf(fp, "%d ", image[row][col]);
        }
        fprintf(fp, "\n");
    }

    // Close the file
    fclose(fp);
}

// Function to invert the colors of an image
void invert_colors(int **image) {
    int row, col;

    for (row = 0; row < HEIGHT; row++) {
        for (col = 0; col < WIDTH; col++) {
            image[row][col] = MAX_PIXEL_VALUE - image[row][col];
        }
    }
}

// Function to flip an image horizontally
void flip_horizontal(int **image) {
    int row, col, temp;

    for (row = 0; row < HEIGHT; row++) {
        for (col = 0; col < WIDTH / 2; col++) {
            temp = image[row][col];
            image[row][col] = image[row][WIDTH - 1 - col];
            image[row][WIDTH - 1 - col] = temp;
        }
    }
}

int main(void) {
    int **image;
    char filename[20];

    // Read the input image from a PPM file
    printf("Enter the name of the input file: ");
    scanf("%s", filename);
    image = read_image(filename);

    // Invert the colors of the image
    invert_colors(image);

    // Write the inverted image to a new PPM file
    printf("Enter the name of the output file: ");
    scanf("%s", filename);
    write_image(filename, image);

    // Flip the image horizontally
    flip_horizontal(image);

    // Write the flipped image to a new PPM file
    printf("Enter the name of the output file: ");
    scanf("%s", filename);
    write_image(filename, image);

    // Free the memory allocated to the image
    int row;
    for (row = 0; row < HEIGHT; row++) {
        free(image[row]);
    }
    free(image);

    return 0;
}