//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert an image to ASCII art
void imageToASCII(char* filename, int width, int height) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    unsigned char header[54];
    fread(header, 1, 54, fp);

    // Check if the file is a valid BMP file
    if (header[0]!= 'B' || header[1]!= 'M') {
        printf("Error: File is not a valid BMP file\n");
        fclose(fp);
        exit(1);
    }

    int filesize = width * height * 3;
    unsigned char* data = malloc(filesize);
    fread(data, 1, filesize, fp);
    fclose(fp);

    // Convert the image data to ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;
            int red = data[index] / 16;
            int green = data[index + 1] / 16;
            int blue = data[index + 2] / 16;

            switch (red) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
                    printf("o");
                    break;
                case 3:
                    printf("O");
                    break;
                case 4:
                    printf("@");
                    break;
                case 5:
                    printf("#");
                    break;
                case 6:
                    printf("$");
                    break;
                case 7:
                    printf("%");
                    break;
                case 8:
                    printf("&");
                    break;
                case 9:
                    printf("*");
                    break;
                case 10:
                    printf("=");
                    break;
                case 11:
                    printf("+");
                    break;
                case 12:
                    printf("-");
                    break;
                case 13:
                    printf("_");
                    break;
                case 14:
                    printf("\\");
                    break;
                case 15:
                    printf("|");
                    break;
            }
        }
        printf("\n");
    }

    free(data);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <filename> <width> <height>\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[2]);
    int height = atoi(argv[3]);

    imageToASCII(argv[1], width, height);

    return 0;
}