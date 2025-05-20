//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 40

typedef struct {
    char *data;
    int width;
    int height;
} Image;

int get_pixel(Image *image, int x, int y) {
    int index = y * image->width + x;
    if (index >= 0 && index < image->width * image->height) {
        return image->data[index];
    }
    return 0;
}

void print_ascii_art(Image *image) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            int pixel = get_pixel(image, j, i);
            if (pixel == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    Image image;
    FILE *fp;
    char filename[100];
    int i, j;

    // Open the image file
    printf("Enter the filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Cannot open the file.\n");
        exit(1);
    }

    // Read the image header
    fseek(fp, 0, SEEK_SET);
    fread(&image.width, sizeof(int), 1, fp);
    fread(&image.height, sizeof(int), 1, fp);

    // Allocate memory for the image data
    image.data = malloc(image.width * image.height);
    if (image.data == NULL) {
        printf("Error: Cannot allocate memory.\n");
        exit(1);
    }

    // Read the image data
    fseek(fp, 54, SEEK_SET);
    fread(image.data, sizeof(char), image.width * image.height, fp);

    // Close the image file
    fclose(fp);

    // Print the ASCII art
    printf("The ASCII art is:\n");
    print_ascii_art(&image);

    return 0;
}