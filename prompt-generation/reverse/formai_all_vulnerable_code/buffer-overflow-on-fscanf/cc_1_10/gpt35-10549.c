//FormAI DATASET v1.0 Category: Image Editor ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 200
#define HEIGHT 200

// function to read pixel color values from an image file
void readFile(char* filename, int* arr) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: file not found\n");
        exit(1);
    }

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
}

// function to write pixel color values to a new image file
void writeFile(char* filename, int* arr) {
    FILE* file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error: could not write to file\n");
        exit(1);
    }

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

// function to invert colors of an image
void invertColors(int* arr) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        arr[i] = 255 - arr[i];
    }
}

// function to blur an image
void blurImage(int* arr) {
    int temp[WIDTH * HEIGHT];

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            int total = 0;
            int numPixels = 0;

            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
                        continue;
                    }

                    // add colors of neighboring pixels
                    total += arr[x*WIDTH + y];
                    numPixels++;
                }
            }

            // calculate average color and store in temp array
            temp[i*WIDTH + j] = total / numPixels;
        }
    }

    // copy temp array into original array
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int pixels[WIDTH * HEIGHT];
    readFile("image.txt", pixels);

    // invert colors
    invertColors(pixels);
    writeFile("inverted_image.txt", pixels);

    // blur image
    blurImage(pixels);
    writeFile("blurred_image.txt", pixels);

    return 0;
}