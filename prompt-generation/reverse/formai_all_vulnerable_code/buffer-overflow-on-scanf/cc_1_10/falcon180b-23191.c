//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 24

int main() {
    FILE *imageFile;
    char filename[100];
    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    imageFile = fopen(filename, "rb");
    if (imageFile == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    unsigned char header[54];
    fread(header, 1, 54, imageFile);

    int width, height;
    unsigned int bitDepth;
    fread(&width, 4, 1, imageFile);
    fread(&height, 4, 1, imageFile);
    fread(&bitDepth, 4, 1, imageFile);

    if (bitDepth!= 24) {
        printf("Error: image must be 24-bit RGB.\n");
        exit(1);
    }

    unsigned char *data = malloc(WIDTH * HEIGHT * 3);
    fread(data, 3, WIDTH * HEIGHT, imageFile);
    fclose(imageFile);

    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int index = y * WIDTH + x;
            int r = data[index * 3 + 0];
            int g = data[index * 3 + 1];
            int b = data[index * 3 + 2];

            int asciiValue = (((r >> 2) & 0x3F) << 2) | (((g >> 3) & 0x3F) << 1) | ((b >> 3) & 0x3F);
            printf("%c", asciiValue);
        }
        printf("\n");
    }

    free(data);
    return 0;
}