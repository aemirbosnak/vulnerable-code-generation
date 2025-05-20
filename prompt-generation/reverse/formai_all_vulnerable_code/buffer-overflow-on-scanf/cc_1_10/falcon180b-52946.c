//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

// struct to hold pixel information
typedef struct {
    int x;
    int y;
    char intensity;
} pixel_t;

// function to print ASCII art
void print_ascii_art(pixel_t pixels[], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", pixels[i * width + j].intensity);
        }
        printf("\n");
    }
}

// function to read image file and convert to ASCII art
void image_to_ascii_art(char* filename, pixel_t pixels[], int width, int height) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fseek(fp, 54, SEEK_SET); // skip header
    fread(pixels, sizeof(pixel_t), width * height, fp);

    fclose(fp);
}

int main() {
    pixel_t pixels[MAX_WIDTH * MAX_HEIGHT];
    int width, height;

    // read image file
    char filename[100];
    printf("Enter image filename: ");
    scanf("%s", filename);
    image_to_ascii_art(filename, pixels, MAX_WIDTH, MAX_HEIGHT);

    // determine image dimensions
    for (int i = 0; i < MAX_WIDTH * MAX_HEIGHT; i++) {
        if (pixels[i].intensity!= 0) {
            width = i % MAX_WIDTH + 1;
            height = i / MAX_WIDTH + 1;
            break;
        }
    }

    // print ASCII art
    print_ascii_art(pixels, width, height);

    return 0;
}