//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to read input image
void read_image(char* filename, int** img, int* width, int* height) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error reading image file.\n");
        exit(1);
    }

    fseek(fp, 18, SEEK_SET); // Skip header
    fread(img, sizeof(int), *width * *height, fp);
    fclose(fp);
}

// Function to write output image
void write_image(char* filename, int** img, int width, int height) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error writing image file.\n");
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n255\n", width, height);
    fwrite(img[0], sizeof(int), width * height, fp);
    fclose(fp);
}

// Function to flip image horizontally
void flip_horizontal(int** img, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            int temp = img[i][j];
            img[i][j] = img[i][width - j - 1];
            img[i][width - j - 1] = temp;
        }
    }
}

// Function to change brightness/contrast
void change_brightness_contrast(int** img, int width, int height, float brightness, float contrast) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int value = img[i][j];
            float new_value = ((value / 255.0) * contrast) + brightness;
            if (new_value > 255) {
                new_value = 255;
            } else if (new_value < 0) {
                new_value = 0;
            }
            img[i][j] = round(new_value * 255);
        }
    }
}

int main() {
    char input_file[100];
    char output_file[100];
    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    int** img = malloc(sizeof(int*) * 1000);
    int width, height;
    read_image(input_file, img, &width, &height);

    printf("Enter brightness (0-100): ");
    float brightness = (float)scanf("%f", &brightness) / 100;

    printf("Enter contrast (0-100): ");
    float contrast = (float)scanf("%f", &contrast) / 100;

    flip_horizontal(img, width, height);
    change_brightness_contrast(img, width, height, brightness, contrast);

    write_image(output_file, img, width, height);

    return 0;
}