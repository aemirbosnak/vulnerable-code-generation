//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel pixels[MAX_HEIGHT][MAX_WIDTH];
} Image;

void load_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file.\n");
        exit(1);
    }
    fread(&(img->width), sizeof(int), 1, file);
    fread(&(img->height), sizeof(int), 1, file);
    fread(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error saving file.\n");
        exit(1);
    }
    fwrite(&(img->width), sizeof(int), 1, file);
    fwrite(&(img->height), sizeof(int), 1, file);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flip_image_horizontal(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            Pixel temp = img->pixels[y][x];
            img->pixels[y][x] = img->pixels[y][img->width - 1 - x];
            img->pixels[y][img->width - 1 - x] = temp;
        }
    }
}

void adjust_brightness_contrast(Image *img, int brightness, float contrast) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            Pixel *p = &img->pixels[y][x];
            int r = (int)p->r + brightness;
            int g = (int)p->g + brightness;
            int b = (int)p->b + brightness;

            r = (int)((((float)(r - 128)) * contrast) + 128);
            g = (int)((((float)(g - 128)) * contrast) + 128);
            b = (int)((((float)(b - 128)) * contrast) + 128);

            p->r = (r < 0 ? 0 : (r > 255 ? 255 : r));
            p->g = (g < 0 ? 0 : (g > 255 ? 255 : g));
            p->b = (b < 0 ? 0 : (b > 255 ? 255 : b));
        }
    }
}

void print_menu() {
    printf("Image Processing Menu:\n");
    printf("1. Flip Image Horizontally\n");
    printf("2. Adjust Brightness and Contrast\n");
    printf("3. Quit\n");
}

int main() {
    Image img;
    load_image("input.img", &img);
    
    int choice;
    do {
        print_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                flip_image_horizontal(&img);
                printf("Image flipped horizontally!\n");
                break;
            case 2: {
                int brightness;
                float contrast;
                printf("Enter brightness adjustment (-255 to 255): ");
                scanf("%d", &brightness);
                printf("Enter contrast adjustment (0.0 to 3.0): ");
                scanf("%f", &contrast);
                adjust_brightness_contrast(&img, brightness, contrast);
                printf("Brightness and contrast adjusted!\n");
                break;
            }
            case 3:
                save_image("output.img", &img);
                printf("Changes saved to output.img\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}