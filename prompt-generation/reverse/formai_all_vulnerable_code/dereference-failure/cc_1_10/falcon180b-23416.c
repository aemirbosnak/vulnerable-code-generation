//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#define CHAR_SET ".,-+*#@"

// Function to convert an image to ASCII art
void image_to_ascii(char *image_file, int width, int height) {
    FILE *fp;
    char ch;
    int i, j, k, l, count = 0;
    unsigned char *img;

    // Open the image file
    fp = fopen(image_file, "rb");
    if (fp == NULL) {
        printf("Error: Unable to open image file.\n");
        exit(1);
    }

    // Read the image data
    fseek(fp, 54, SEEK_SET); // Skip header
    img = (unsigned char *)malloc(3 * width * height);
    fread(img, 1, 3 * width * height, fp);
    fclose(fp);

    // Convert the image to ASCII art
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            k = (i * width + j) * 3;
            l = 0;

            while (l < 8 && count < MAX_HEIGHT - 1) {
                ch = CHAR_SET[img[k] / (255 / 8)];
                printf("%c", ch);
                count++;
                k++;
            }

            if (count == MAX_HEIGHT - 1) {
                printf("\n");
                count = 0;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <image_file> <width>\n", argv[0]);
        exit(1);
    }

    int width = atoi(argv[2]);
    if (width <= 0 || width > MAX_WIDTH) {
        printf("Error: Invalid image width.\n");
        exit(1);
    }

    image_to_ascii(argv[1], width, MAX_HEIGHT);

    return 0;
}