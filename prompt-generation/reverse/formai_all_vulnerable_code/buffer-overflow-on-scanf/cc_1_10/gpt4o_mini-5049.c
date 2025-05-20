//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480
#define MAX_COLOR_VALUE 255

typedef unsigned char pixel[3]; // RGB pixel

pixel image[HEIGHT][WIDTH]; // Original image
pixel flipped[HEIGHT][WIDTH]; // Flipped image

void loadImage(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(1);
    }
    fseek(file, 54, SEEK_SET); // Skip the BMP header
    fread(image, sizeof(pixel), WIDTH * HEIGHT, file);
    fclose(file);
}

void saveImage(const char *filename, pixel img[HEIGHT][WIDTH]) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file %s for saving.\n", filename);
        exit(1);
    }
    
    unsigned char header[54] = {
        'B', 'M', // BMP signature
        0, 0, 0, 0, // File size in bytes (placeholder)
        0, 0, 0, 0, // Reserved
        54, 0, 0, 0, // Start of pixel array
        40, 0, 0, 0, // Number of bytes in the header
        WIDTH & 0xFF, (WIDTH >> 8) & 0xFF, (WIDTH >> 16) & 0xFF, (WIDTH >> 24) & 0xFF, // Image width
        HEIGHT & 0xFF, (HEIGHT >> 8) & 0xFF, (HEIGHT >> 16) & 0xFF, (HEIGHT >> 24) & 0xFF, // Image height
        1, 0, // Number of color planes
        24, 0, // Bits per pixel
        0, 0, 0, 0, // Compression
        0, 0, 0, 0, // Image size (can be 0 for uncompressed)
        0, 0, 0, 0, // X pixels per meter
        0, 0, 0, 0, // Y pixels per meter
        0, 0, 0, 0, // Total colors
        0, 0, 0, 0  // Important colors
    };

    // Calculate file size
    int fileSize = 54 + WIDTH * HEIGHT * 3;
    header[2] = (unsigned char)(fileSize);
    header[3] = (unsigned char)(fileSize >> 8);
    header[4] = (unsigned char)(fileSize >> 16);
    header[5] = (unsigned char)(fileSize >> 24);

    fwrite(header, sizeof(unsigned char), 54, file);
    fwrite(img, sizeof(pixel), WIDTH * HEIGHT, file);
    fclose(file);
}

void flipImage() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            flipped[y][x][0] = image[y][WIDTH - 1 - x][0]; // R
            flipped[y][x][1] = image[y][WIDTH - 1 - x][1]; // G
            flipped[y][x][2] = image[y][WIDTH - 1 - x][2]; // B
        }
    }
}

void changeBrightness(int value) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            for (int c = 0; c < 3; c++) {
                int newColor = image[y][x][c] + value;
                if (newColor < 0) newColor = 0;
                if (newColor > MAX_COLOR_VALUE) newColor = MAX_COLOR_VALUE;
                image[y][x][c] = newColor;
            }
        }
    }
}

void printMenu() {
    printf("=== Image Processing Menu ===\n");
    printf("1. Load Image\n");
    printf("2. Save Image\n");
    printf("3. Flip Image\n");
    printf("4. Change Brightness\n");
    printf("5. Exit\n");
    printf("=============================\n");
}

int main() {
    int choice;
    char filename[100];
    int brightnessChange;

    while (1) {
        printMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter image filename to load: ");
                scanf("%s", filename);
                loadImage(filename);
                printf("Image loaded successfully!\n");
                break;
            case 2:
                printf("Enter filename to save the image: ");
                scanf("%s", filename);
                saveImage(filename, image);
                printf("Image saved successfully!\n");
                break;
            case 3:
                flipImage();
                printf("Image flipped successfully!\n");
                break;
            case 4:
                printf("Enter brightness change (-255 to 255): ");
                scanf("%d", &brightnessChange);
                changeBrightness(brightnessChange);
                printf("Brightness changed successfully!\n");
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}