//FormAI DATASET v1.0 Category: Image Editor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to get the image height */
int get_height(char *filename) {
    FILE *fptr = fopen(filename, "rb");
    if (fptr == NULL) {
        printf("Error: File does not exist!");
        exit(1);
    }

    fseek(fptr, 22, SEEK_SET); // Skips the header info
    int height;
    fread(&height, sizeof(height), 1, fptr); // Reads the image height
    fclose(fptr);
    return height;
}

/* Function to get the image width */
int get_width(char *filename) {
    FILE *fptr = fopen(filename, "rb");
    if (fptr == NULL) {
        printf("Error: File does not exist!");
        exit(1);
    }

    fseek(fptr, 18, SEEK_SET); // Skips the header info
    int width;
    fread(&width, sizeof(width), 1, fptr); // Reads the image width
    fclose(fptr);
    return width;
}

/* Function to read the image data into a 2D array */
void read_image(char *filename, int **image_data) {
    FILE *fptr = fopen(filename, "rb");
    if (fptr == NULL) {
        printf("Error: File does not exist!");
        exit(1);
    }

    int height = get_height(filename);
    int width = get_width(filename);

    fseek(fptr, 54, SEEK_SET); // Skips the header info

    // Reads the image data into the 2D array
    for (int i = height-1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            int pixel_data;
            fread(&pixel_data, sizeof(pixel_data), 1, fptr);
            image_data[i][j] = pixel_data;
        }
    }

    fclose(fptr);
}

/* Function to write the image data from 2D array back to file */
void write_image(char *filename, int **image_data) {
    FILE *fptr = fopen(filename, "wb");
    if (fptr == NULL) {
        printf("Error: Unable to create file!");
        exit(1);
    }

    int height = get_height(filename);
    int width = get_width(filename);

    // Writes the header info back to file
    fseek(fptr, 0, SEEK_SET);
    char header[54];
    fread(&header, sizeof(header), 1, fptr);
    fwrite(&header, sizeof(header), 1, fptr);

    // Writes the image data from the 2D array back to file
    fseek(fptr, 54, SEEK_SET);
    for (int i = height-1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            int pixel_data = image_data[i][j];
            fwrite(&pixel_data, sizeof(pixel_data), 1, fptr);
        }
    }

    fclose(fptr);
}

/* Function to flip an image vertically */
void flip_vertical(char *filename) {
    int height = get_height(filename);
    int width = get_width(filename);

    int **image_data = (int**) malloc(sizeof(int*) * height);

    for (int i = 0; i < height; i++) {
        image_data[i] = (int*) malloc(sizeof(int) * width);
    }

    read_image(filename, image_data);

    // Flips the image vertically
    for (int i = 0; i < height/2; i++) {
        for (int j = 0; j < width; j++) {
            int temp = image_data[i][j];
            image_data[i][j] = image_data[height-i-1][j];
            image_data[height-i-1][j] = temp;
        }
    }

    write_image(filename, image_data);

    printf("Image flipped vertically!");
}

/* Function to rotate an image 90 degrees clockwise */
void rotate_clockwise(char *filename) {
    int height = get_height(filename);
    int width = get_width(filename);

    int **image_data = (int**) malloc(sizeof(int*) * width);
    for (int i = 0; i < width; i++) {
        image_data[i] = (int*) malloc(sizeof(int) * height);
    }

    read_image(filename, image_data);

    // Rotates the image clockwise
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int temp = image_data[i][j];
            image_data[i][j] = image_data[width-j-1][i];
            image_data[width-j-1][i] = temp;
        }
    }

    write_image(filename, image_data);

    printf("Image rotated 90 degrees clockwise!");
}

int main() {
    char filename[] = "image.bmp";

    flip_vertical(filename);

    rotate_clockwise(filename);

    return 0;
}