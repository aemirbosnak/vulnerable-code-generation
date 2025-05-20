//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <inttypes.h>

// Function prototypes
void error(char const *s)
{
    perror(s);
    exit(EXIT_FAILURE);
}

// Read an image
void read_image(char *filename, int *width, int *height, unsigned char **image)
{
    FILE *file;
    unsigned char *ptr;
    int size;

    if ((file = fopen(filename, "r")) == NULL)
        error("Unable to open image file");

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    *image = (unsigned char*)malloc(size);
    if (*image == NULL)
        error("Unable to allocate memory");

    fread(*image, 1, size, file);
    fclose(file);

    *width = size / (*height * 3);
    *height = *width / 3;
    ptr = *image;
    for (int i = 0; i < *width; i++) {
        int r = *(ptr + 0) << 2;
        int g = *(ptr + 1) << 2;
        int b = *(ptr + 2) << 2;
        *(ptr + 0) = 255 - r;
        *(ptr + 1) = 255 - g;
        *(ptr + 2) = 255 - b;
        ptr += 3;
    }
}

// Flip image horizontally
void flip_image(unsigned char *image, int width, int height)
{
    unsigned char *ptr;
    int i;

    for (i = 0; i < width; i++) {
        ptr = image + i * 3;
        for (int j = 0; j < height; j++) {
            *(ptr + 2 * j) = *(ptr + j * 3 + 2);
            *(ptr + 2 * j + 1) = *(ptr + j * 3);
            *(ptr + 2 * j + 2) = *(ptr + j * 3 + 1);
            ptr += 3;
        }
    }
}

// Change brightness/contrast of image
void change_brightness_contrast(unsigned char *image, int width, int height)
{
    unsigned char *ptr;
    float brightness, contrast;
    int i;

    printf("Enter brightness (0.0 - 1.0): ");
    scanf("%f", &brightness);
    printf("Enter contrast (0.0 - 1.0): ");
    scanf("%f", &contrast);

    brightness = brightness / 255.0;
    contrast = contrast / 255.0;

    for (i = 0; i < width; i++) {
        ptr = image + i * 3;
        for (int j = 0; j < height; j++) {
            int r, g, b;
            r = (*(ptr + 0)) * brightness + ((*(ptr + 1)) * contrast);
            g = (*(ptr + 1)) * brightness + ((*(ptr + 2)) * contrast);
            b = (*(ptr + 2)) * brightness + ((*(ptr + 0)) * contrast);
            *(ptr + 0) = r;
            *(ptr + 1) = g;
            *(ptr + 2) = b;
            ptr += 3;
        }
    }
}

int main(int argc, char *argv[])
{
    int width, height;
    unsigned char *image;
    char filename[100];
    int choice;

    printf("1. Read image\n2. Flip image\n3. Change brightness/contrast\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter image filename: ");
            scanf("%s", filename);
            read_image(filename, &width, &height, &image);
            break;
        case 2:
            flip_image(image, width, height);
            break;
        case 3:
            change_brightness_contrast(image, width, height);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}