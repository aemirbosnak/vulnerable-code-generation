//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH  256
#define HEIGHT 256

void flip_image(unsigned char *image, int width, int height);
void change_brightness(unsigned char *image, int width, int height, int value);
void change_contrast(unsigned char *image, int width, int height, int value);

int main(void) {
    char choice;
    int brightness = 0;
    int contrast = 0;
    unsigned char image[HEIGHT][WIDTH];
    FILE *input_file = fopen("image.raw", "rb");

    if (input_file == NULL) {
        printf("ERROR: Could not open input file.");
        exit(EXIT_FAILURE);
    }

    fread(image, sizeof(char), WIDTH * HEIGHT, input_file);
    fclose(input_file);

    printf("Welcome to the Image Processor! Choose an option:\n");
    printf(" 1. Flip Image\n 2. Change Brightness\n 3. Change Contrast\n");

    do {
        printf("Enter your choice (1-3): ");
        choice = getchar();
        getchar();  // consume '\n' character

        switch (choice) {
        case '1':
            flip_image((unsigned char*)image, WIDTH, HEIGHT);
            printf("Image flipped!\n");
            break;
        case '2':
            printf("Enter brightness value (-255 to +255): ");
            scanf("%d", &brightness);
            change_brightness((unsigned char*)image, WIDTH, HEIGHT, brightness);
            printf("Brightness changed!\n");
            break;
        case '3':
            printf("Enter contrast value (-127 to +127): ");
            scanf("%d", &contrast);
            change_contrast((unsigned char*)image, WIDTH, HEIGHT, contrast);
            printf("Contrast changed!\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 3.\n");
            break;
        }
    } while (!isdigit(choice));

    FILE *output_file = fopen("processed_image.raw", "wb");

    if (output_file == NULL) {
        printf("ERROR: Could not open output file.");
        exit(EXIT_FAILURE);
    }

    fwrite(image, sizeof(char), WIDTH * HEIGHT, output_file);
    fclose(output_file);

    return 0;
}

void flip_image(unsigned char *image, int width, int height) {
    unsigned char temp;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            temp = *(image + i * width + j);
            *(image + i * width + j) = *(image + i * width + width - j - 1);
            *(image + i * width + width - j - 1) = temp;
        }
    }
}

void change_brightness(unsigned char *image, int width, int height, int value) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_value = *(image + i * width + j) + value;
            *(image + i * width + j) = (unsigned char)(new_value > 255 ? 255 : (new_value < 0 ? 0 : new_value));
        }
    }
}

void change_contrast(unsigned char *image, int width, int height, int value) {
    double factor = (double)(259 * (value + 255)) / (double)(255 * (259 - value));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_value = (int)(factor * ((double)*(image + i * width + j) - 128) + 128);
            *(image + i * width + j) = (unsigned char)(new_value > 255 ? 255 : (new_value < 0 ? 0 : new_value));
        }
    }
}