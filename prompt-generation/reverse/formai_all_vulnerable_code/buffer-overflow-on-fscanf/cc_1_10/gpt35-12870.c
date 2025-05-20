//FormAI DATASET v1.0 Category: Image Editor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define constants for maximum image dimensions
#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

// Define struct for image data
typedef struct {
    int width;
    int height;
    int pixels[MAX_HEIGHT][MAX_WIDTH][3];
} Image;

// Function to read an image from a PPM file
void read_image(char* filename, Image* img) {
    FILE* fp = fopen(filename, "r");
    char magic_number[3];
    fscanf(fp, "%s\n%d %d\n%d\n", magic_number, &img->width, &img->height, &(int){0});
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int r, g, b;
            fscanf(fp, "%d %d %d", &r, &g, &b);
            img->pixels[i][j][0] = r;
            img->pixels[i][j][1] = g;
            img->pixels[i][j][2] = b;
        }
    }
    fclose(fp);
}

// Function to write an image to a PPM file
void write_image(char* filename, Image* img) {
    FILE* fp = fopen(filename, "w");
    fprintf(fp, "P3\n%d %d\n%d\n", img->width, img->height, 255);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fprintf(fp, "%d %d %d\n", img->pixels[i][j][0], img->pixels[i][j][1], img->pixels[i][j][2]);
        }
    }
    fclose(fp);
}

// Function to apply a grayscale filter to an image
void grayscale(Image* img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int avg = (img->pixels[i][j][0] + img->pixels[i][j][1] + img->pixels[i][j][2]) / 3;
            img->pixels[i][j][0] = avg;
            img->pixels[i][j][1] = avg;
            img->pixels[i][j][2] = avg;
        }
    }
}

// Function to apply a sepia filter to an image
void sepia(Image* img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int r = img->pixels[i][j][0];
            int g = img->pixels[i][j][1];
            int b = img->pixels[i][j][2];
            img->pixels[i][j][0] = (int)(0.393*r + 0.769*g + 0.189*b);
            img->pixels[i][j][1] = (int)(0.349*r + 0.686*g + 0.168*b);
            img->pixels[i][j][2] = (int)(0.272*r + 0.534*g + 0.131*b);
        }
    }
}

// Function to rotate an image 90 degrees clockwise
void rotate(Image* img) {
    Image rotated;
    rotated.width = img->height;
    rotated.height = img->width;
    for (int i = 0; i < rotated.height; i++) {
        for (int j = 0; j < rotated.width; j++) {
            rotated.pixels[i][j][0] = img->pixels[img->height-j-1][i][0];
            rotated.pixels[i][j][1] = img->pixels[img->height-j-1][i][1];
            rotated.pixels[i][j][2] = img->pixels[img->height-j-1][i][2];
        }
    }
    *img = rotated;
}

// Main function to run the image editor
int main() {
    // Read image from file
    Image img;
    read_image("input.ppm", &img);

    // Apply filters and transformations
    grayscale(&img);
    sepia(&img);
    rotate(&img);

    // Write image to file
    write_image("output.ppm", &img);

    // Exit program
    return 0;
}