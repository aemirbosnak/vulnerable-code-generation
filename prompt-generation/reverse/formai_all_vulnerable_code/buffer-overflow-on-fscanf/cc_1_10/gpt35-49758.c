//FormAI DATASET v1.0 Category: Image Editor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining the maximum image size
#define MAX_SIZE 1000

typedef struct
{
    int width, height;
    int pixels[MAX_SIZE][MAX_SIZE][3];
} Image;

void loadImage(FILE *file, Image *image)
{
    // reading the image width and height
    fscanf(file, "%d %d", &image->width, &image->height);

    // reading the pixel values for each pixel
    for (int y = 0; y < image->height; y++)
    {
        for (int x = 0; x < image->width; x++)
        {
            fscanf(file, "%d %d %d", &image->pixels[x][y][0], &image->pixels[x][y][1], &image->pixels[x][y][2]);
        }
    }
}

void saveImage(FILE *file, Image *image)
{
    // writing the image width and height
    fprintf(file, "%d %d\n", image->width, image->height);

    // writing the pixel values for each pixel
    for (int y = 0; y < image->height; y++)
    {
        for (int x = 0; x < image->width; x++)
        {
            fprintf(file, "%d %d %d ", image->pixels[x][y][0], image->pixels[x][y][1], image->pixels[x][y][2]);
        }
        fprintf(file, "\n");
    }
}

void invertColors(Image *image)
{
    // inverting the pixel colors
    for (int y = 0; y < image->height; y++)
    {
        for (int x = 0; x < image->width; x++)
        {
            image->pixels[x][y][0] = 255 - image->pixels[x][y][0];
            image->pixels[x][y][1] = 255 - image->pixels[x][y][1];
            image->pixels[x][y][2] = 255 - image->pixels[x][y][2];
        }
    }
}

void changeBrightness(Image *image, int value)
{
    // changing the pixel brightness
    for (int y = 0; y < image->height; y++)
    {
        for (int x = 0; x < image->width; x++)
        {
            image->pixels[x][y][0] += value;
            image->pixels[x][y][1] += value;
            image->pixels[x][y][2] += value;

            // making sure the pixel values stay within the valid range
            if (image->pixels[x][y][0] < 0)
                image->pixels[x][y][0] = 0;
            if (image->pixels[x][y][1] < 0)
                image->pixels[x][y][1] = 0;
            if (image->pixels[x][y][2] < 0)
                image->pixels[x][y][2] = 0;
            if (image->pixels[x][y][0] > 255)
                image->pixels[x][y][0] = 255;
            if (image->pixels[x][y][1] > 255)
                image->pixels[x][y][1] = 255;
            if (image->pixels[x][y][2] > 255)
                image->pixels[x][y][2] = 255;
        }
    }
}

void applyFilter(Image *image, int filter[3][3])
{
    // applying the filter to the image
    Image temp;
    memcpy(&temp, image, sizeof(Image));
    int r, g, b;
    for (int y = 1; y < image->height - 1; y++)
    {
        for (int x = 1; x < image->width - 1; x++)
        {
            r = g = b = 0;
            for (int ty = 0; ty < 3; ty++)
            {
                for (int tx = 0; tx < 3; tx++)
                {
                    r += temp.pixels[x + tx - 1][y + ty - 1][0] * filter[ty][tx];
                    g += temp.pixels[x + tx - 1][y + ty - 1][1] * filter[ty][tx];
                    b += temp.pixels[x + tx - 1][y + ty - 1][2] * filter[ty][tx];
                }
            }
            image->pixels[x][y][0] = r;
            image->pixels[x][y][1] = g;
            image->pixels[x][y][2] = b;

            // making sure the pixel values stay within the valid range
            if (image->pixels[x][y][0] < 0)
                image->pixels[x][y][0] = 0;
            if (image->pixels[x][y][1] < 0)
                image->pixels[x][y][1] = 0;
            if (image->pixels[x][y][2] < 0)
                image->pixels[x][y][2] = 0;
            if (image->pixels[x][y][0] > 255)
                image->pixels[x][y][0] = 255;
            if (image->pixels[x][y][1] > 255)
                image->pixels[x][y][1] = 255;
            if (image->pixels[x][y][2] > 255)
                image->pixels[x][y][2] = 255;
        }
    }
}

void printImage(Image *image)
{
    // printing the image to the console
    for (int y = 0; y < image->height; y++)
    {
        for (int x = 0; x < image->width; x++)
        {
            printf("(%d,%d,%d) ", image->pixels[x][y][0], image->pixels[x][y][1], image->pixels[x][y][2]);
        }
        printf("\n");
    }
}

int main()
{
    FILE *file;
    Image image;

    // loading the image from a file
    file = fopen("image.ppm", "r");
    loadImage(file, &image);
    fclose(file);

    // inverting the colors of the image
    invertColors(&image);

    // applying a brightness adjustment of 50 to the image
    changeBrightness(&image, 50);

    // applying a 3x3 filter to the image
    int filter[3][3] = {
        {0, -1, 0},
        {-1, 5, -1},
        {0, -1, 0}};
    applyFilter(&image, filter);

    // saving the modified image to a file
    file = fopen("modified.ppm", "w");
    saveImage(file, &image);
    fclose(file);

    // printing the modified image to the console
    printImage(&image);

    return 0;
}