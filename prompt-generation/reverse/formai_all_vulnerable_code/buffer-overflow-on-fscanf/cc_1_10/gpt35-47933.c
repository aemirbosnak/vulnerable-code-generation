//FormAI DATASET v1.0 Category: Image Editor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

// Function to create a new image
Image *newImage(int width, int height) {
    Image *image = (Image *)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = (Pixel **)malloc(height * sizeof(Pixel *));
    for (int i = 0; i < height; i++) {
        image->pixels[i] = (Pixel *)malloc(width * sizeof(Pixel));
        for (int j = 0; j < width; j++) {
            image->pixels[i][j].red = 0;
            image->pixels[i][j].green = 0;
            image->pixels[i][j].blue = 0;
        }
    }
    return image;
}

// Function to read an image from a file
Image *readImage(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found\n");
        return NULL;
    }
    char magic_number[3];
    fscanf(file, "%c%c\n", &magic_number[0], &magic_number[1]);
    if (strcmp(magic_number, "P3") != 0) {
        printf("Error: Invalid file format\n");
        return NULL;
    }
    int width = 0, height = 0, max_val = 0;
    fscanf(file, "%d %d\n%d\n", &width, &height, &max_val);
    Image *image = newImage(width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(file, "%d %d %d", &image->pixels[i][j].red, &image->pixels[i][j].green, &image->pixels[i][j].blue);
        }
    }
    fclose(file);
    printf("Image read successfully\n");
    return image;
}

// Function to write an image to a file
void writeImage(Image *image, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: File not created\n");
        return;
    }
    fprintf(file, "P3\n%d %d\n255\n", image->width, image->height);
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fprintf(file, "%d %d %d ", image->pixels[i][j].red, image->pixels[i][j].green, image->pixels[i][j].blue);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    printf("Image written successfully\n");
}

// Function to invert the colors of an image
void invertColors(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            image->pixels[i][j].red = 255 - image->pixels[i][j].red;
            image->pixels[i][j].green = 255 - image->pixels[i][j].green;
            image->pixels[i][j].blue = 255 - image->pixels[i][j].blue;
        }
    }
    printf("Colors inverted successfully\n");
}

// Function to grayscale an image
void grayscale(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int average = (image->pixels[i][j].red + image->pixels[i][j].green + image->pixels[i][j].blue) / 3;
            image->pixels[i][j].red = average;
            image->pixels[i][j].green = average;
            image->pixels[i][j].blue = average;
        }
    }
    printf("Image grayscaled successfully\n");
}

// Function to flip an image horizontally
void flipHorizontal(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            Pixel temp = image->pixels[i][j];
            image->pixels[i][j] = image->pixels[i][image->width - j - 1];
            image->pixels[i][image->width - j - 1] = temp;
        }
    }
    printf("Image flipped horizontally successfully\n");
}

// Function to flip an image vertically
void flipVertical(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            Pixel temp = image->pixels[i][j];
            image->pixels[i][j] = image->pixels[image->height - i - 1][j];
            image->pixels[image->height - i - 1][j] = temp;
        }
    }
    printf("Image flipped vertically successfully\n");
}

// Function to rotate an image 90 degrees clockwise
void rotate90Clockwise(Image *image) {
    int new_width = image->height;
    int new_height = image->width;
    Pixel **new_pixels = (Pixel **)malloc(new_height * sizeof(Pixel *));
    for (int i = 0; i < new_height; i++) {
        new_pixels[i] = (Pixel *)malloc(new_width * sizeof(Pixel));
        for (int j = 0; j < new_width; j++) {
            new_pixels[i][j] = image->pixels[image->height - j - 1][i];
        }
    }
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    image->width = new_width;
    image->height = new_height;
    image->pixels = new_pixels;
    printf("Image rotated 90 degrees clockwise successfully\n");
}

// Main function
int main() {
    Image *image = readImage("input.ppm");
    if (image == NULL) {
        return 1;
    }
    bool is_running = true;
    while (is_running) {
        printf("---------------------------------\n");
        printf("1. Invert Colors\n");
        printf("2. Grayscale\n");
        printf("3. Flip Horizontal\n");
        printf("4. Flip Vertical\n");
        printf("5. Rotate 90 degrees Clockwise\n");
        printf("6. Save and Quit\n");
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        int choice = 0;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                invertColors(image);
                break;
            case 2:
                grayscale(image);
                break;
            case 3:
                flipHorizontal(image);
                break;
            case 4:
                flipVertical(image);
                break;
            case 5:
                rotate90Clockwise(image);
                break;
            case 6:
                writeImage(image, "output.ppm");
                is_running = false;
                break;
            default:
                printf("Error: Invalid choice\n");
        }
    }
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
    return 0;
}