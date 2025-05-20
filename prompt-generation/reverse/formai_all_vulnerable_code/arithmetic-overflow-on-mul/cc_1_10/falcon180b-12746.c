//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to convert image to ASCII art
void image_to_ascii(char *filename, int width, int height) {
    FILE *fp;
    char ch;
    int i, j, count = 0;
    unsigned char *image;

    // Open the image file
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Read the image data
    fseek(fp, 54, SEEK_SET); // Skip header
    image = (unsigned char *) malloc(width * height * 3);
    fread(image, width * height * 3, 1, fp);
    fclose(fp);

    // Convert the image to ASCII art
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int red = image[count++] & 0xFF;
            int green = image[count++] & 0xFF;
            int blue = image[count++] & 0xFF;

            double brightness = (red + green + blue) / 3.0;

            if (brightness < 0.3) {
                printf(" ");
            } else if (brightness < 0.6) {
                printf(".");
            } else if (brightness < 0.9) {
                printf(":");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int main() {
    char filename[100];
    int width, height;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Get the image dimensions
    FILE *fp = fopen(filename, "rb");
    fseek(fp, 18, SEEK_SET);
    fread(&width, 4, 1, fp);
    fread(&height, 4, 1, fp);
    fclose(fp);

    // Convert the image to ASCII art
    image_to_ascii(filename, width, height);

    return 0;
}