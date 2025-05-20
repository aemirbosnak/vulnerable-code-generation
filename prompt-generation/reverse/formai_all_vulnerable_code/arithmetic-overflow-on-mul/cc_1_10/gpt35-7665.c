//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: expert-level
#include <stdio.h>

// function to convert pixel intensity to ASCII character
char ascii_char(int intensity) {
    if (intensity >= 230) {
        return ' ';
    } else if (intensity >= 200) {
        return '.';
    } else if (intensity >= 170) {
        return '*';
    } else if (intensity >= 140) {
        return ':';
    } else if (intensity >= 110) {
        return 'o';
    } else if (intensity >= 80) {
        return '&';
    } else if (intensity >= 50) {
        return '8';
    } else {
        return '@';
    }
}

int main() {
    // open image file
    FILE *fp = fopen("image.bmp", "rb");

    // read BMP header
    unsigned char bmp_header[54];
    fread(bmp_header, sizeof(unsigned char), 54, fp);

    // extract image dimensions and data
    int width = *(int *)&bmp_header[18];
    int height = *(int *)&bmp_header[22];
    int padding = 0;
    while ((width * 3 + padding) % 4 != 0) {
        padding++;
    }
    int data_size = (width * 3 + padding) * height;
    unsigned char *data = (unsigned char *) malloc(data_size);
    fread(data, sizeof(unsigned char), data_size, fp);

    // close image file
    fclose(fp);

    // convert image to ASCII art and print to console
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = i * (width * 3 + padding) + j * 3;
            int r = data[index + 2];
            int g = data[index + 1];
            int b = data[index];
            int intensity = (r + g + b) / 3;
            printf("%c%c", ascii_char(intensity), ascii_char(intensity));
        }
        printf("\n");
    }

    // free memory
    free(data);

    return 0;
}