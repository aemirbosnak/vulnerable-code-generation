//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to convert image to ASCII art
void imageToASCII(char *filename, int width, int height) {
    FILE *fp;
    int i, j, k, l;
    char ch;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }

    // Get the size of the image file
    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for the image data
    unsigned char *data = (unsigned char *) malloc(filesize);

    // Read the image data from the file
    fread(data, filesize, 1, fp);
    fclose(fp);

    // Convert the image data to ASCII art
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int index = (i * width + j) * 3;
            int red = data[index];
            int green = data[index + 1];
            int blue = data[index + 2];
            int brightness = (red + green + blue) / 3;

            if (brightness < 128) {
                printf(" ");
            } else if (brightness < 256) {
                printf(".");
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

    // Get the filename, width, and height from the user
    printf("Enter the filename: ");
    scanf("%s", filename);
    printf("Enter the width: ");
    scanf("%d", &width);
    printf("Enter the height: ");
    scanf("%d", &height);

    // Convert the image to ASCII art
    imageToASCII(filename, width, height);

    return 0;
}