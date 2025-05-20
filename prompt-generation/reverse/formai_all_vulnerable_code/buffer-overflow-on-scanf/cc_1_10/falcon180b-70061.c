//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define CHAR_SET ".,-+*0123456789ABCDEF"

void print_ascii_art(char *image_data) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", CHAR_SET[image_data[i * WIDTH + j] & 0x0F]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char filename[100];
    char *image_data;
    int width, height, i, j;

    printf("Enter the filename of the image: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    image_data = malloc(file_size);
    if (image_data == NULL) {
        printf("Error: could not allocate memory.\n");
        exit(1);
    }

    fread(image_data, file_size, 1, fp);
    fclose(fp);

    width = *((int *)image_data);
    height = *((int *)&image_data[4]);

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int pixel = *(int *)&image_data[54 + i * width + j];
            int r = (pixel >> 16) & 0xFF;
            int g = (pixel >> 8) & 0xFF;
            int b = pixel & 0xFF;

            int avg = (r + g + b) / 3;

            if (avg < 128) {
                image_data[i * WIDTH + j] = 0;
            } else {
                image_data[i * WIDTH + j] = 1;
            }
        }
    }

    print_ascii_art(image_data);

    free(image_data);

    return 0;
}