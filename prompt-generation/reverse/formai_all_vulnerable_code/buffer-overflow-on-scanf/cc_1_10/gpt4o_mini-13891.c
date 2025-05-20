//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define WIDTH  256
#define HEIGHT 256

uint8_t image[HEIGHT][WIDTH];

void load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Cannot open file");
        exit(1);
    }
    fread(image, sizeof(uint8_t), WIDTH * HEIGHT, file);
    fclose(file);
}

void save_image(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Cannot create file");
        exit(1);
    }
    fwrite(image, sizeof(uint8_t), WIDTH * HEIGHT, file);
    fclose(file);
}

void display_image() {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            uint8_t pixel = image[y][x];
            if (pixel < 128) {
                putchar('#'); // Dark pixel
            } else {
                putchar(' '); // Light pixel
            }
        }
        putchar('\n');
    }
}

void invert_image() {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            image[y][x] = 255 - image[y][x];
        }
    }
}

void apply_blur() {
    uint8_t temp[HEIGHT][WIDTH];
    for (int y = 1; y < HEIGHT - 1; ++y) {
        for (int x = 1; x < WIDTH - 1; ++x) {
            temp[y][x] = (image[y-1][x] +
                           image[y+1][x] +
                           image[y][x-1] +
                           image[y][x+1]) / 4;
        }
    }
    memcpy(image, temp, sizeof(image));
}

void print_menu() {
    printf("Image Editor\n");
    printf("1. Load Image\n");
    printf("2. Display Image\n");
    printf("3. Invert Image\n");
    printf("4. Apply Blur\n");
    printf("5. Save Image\n");
    printf("6. Exit\n");
}

int main() {
    char filename[100];
    int choice;

    while (1) {
        print_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter filename to load: ");
                scanf("%s", filename);
                load_image(filename);
                break;
            case 2:
                display_image();
                break;
            case 3:
                invert_image();
                break;
            case 4:
                apply_blur();
                break;
            case 5:
                printf("Enter filename to save: ");
                scanf("%s", filename);
                save_image(filename);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}