//FormAI DATASET v1.0 Category: Image Editor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program is a simple image editor that can modify the pixel values of a .ppm image file */

void modifyPixel(char *filename, int width, int height, int x, int y, int red, int green, int blue) {
    char magic[3];
    int maxVal;

    // Open the file for reading and writing
    FILE *fp = fopen(filename, "rb+");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Read the header information
    fscanf(fp, "%s", &magic);
    fscanf(fp, "%d %d\n%d\n", &width, &height, &maxVal);

    // Set the file position to the pixel we want to modify
    size_t pixelStart = sizeof(char) * (x + width * y) * 3;
    fseek(fp, pixelStart, SEEK_SET);

    // Write the new pixel values to the file
    fputc(red, fp);
    fputc(green, fp);
    fputc(blue, fp);

    // Close the file
    fclose(fp);

    printf("Pixel (%d, %d) modified to %d %d %d.\n", x, y, red, green, blue);
}

int main() {
    char filename[100];
    int width, height, x, y, r, g, b;

    // Get the file name from the user
    printf("Enter the name of the .ppm image file you want to modify:\n");
    scanf("%s", filename);

    // Get the coordinates and new pixel values from the user
    printf("Enter the x and y coordinates of the pixel you want to modify:\n");
    scanf("%d %d", &x, &y);
    printf("Enter the new RGB values for the pixel separated by spaces:\n");
    scanf("%d %d %d", &r, &g, &b);

    // Modify the pixel in the file
    modifyPixel(filename, width, height, x, y, r, g, b);

    return 0;
}