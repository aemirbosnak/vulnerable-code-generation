//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Function to convert image to ASCII art
void imageToASCII(char* filename, int width, int height) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    unsigned char header[54];
    fread(header, 1, 54, fp);

    int bytesPerPixel = header[28] * header[29] * header[30];
    unsigned char* pixelData = malloc(width * height * bytesPerPixel);
    fread(pixelData, 1, width * height * bytesPerPixel, fp);

    int x, y, i, j, value, brightness;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            value = 0;
            for (i = 0; i < bytesPerPixel; i++) {
                brightness = pixelData[(y * width + x) * bytesPerPixel + i] / 255.0;
                value += brightness * (i + 1);
            }

            printf("%c", value % 95 + 32);
        }
        printf("\n");
    }

    free(pixelData);
    fclose(fp);
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    int width, height;
    FILE* fp = fopen(filename, "rb");
    if (fp!= NULL) {
        fseek(fp, 18, SEEK_SET);
        fread(&width, 4, 1, fp);
        fread(&height, 4, 1, fp);
        fclose(fp);
    } else {
        printf("Error reading file dimensions.\n");
        exit(1);
    }

    imageToASCII(filename, width, height);

    return 0;
}