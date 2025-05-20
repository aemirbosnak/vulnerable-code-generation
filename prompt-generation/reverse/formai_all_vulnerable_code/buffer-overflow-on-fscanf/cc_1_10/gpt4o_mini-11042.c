//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

Image *load_ppm(const char *filename);
void save_ppm(const char *filename, Image *image);
void invert_colors(Image *image);
void free_image(Image *image);
void display_menu();

int main() {
    char input_filename[100];
    char output_filename[100];
    Image *image = NULL;
    int choice;

    printf("Welcome to Retro Image Editor!\n");
    printf("Please enter the input PPM file name (with .ppm extension): ");
    scanf("%s", input_filename);

    image = load_ppm(input_filename);
    if (!image) {
        printf("Failed to load image!\n");
        return 1;
    }

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                invert_colors(image);
                printf("Colors inverted! \n");
                break;
            case 2:
                printf("Enter output PPM file name (with .ppm extension): ");
                scanf("%s", output_filename);
                save_ppm(output_filename, image);
                printf("Image saved as %s\n", output_filename);
                break;
            case 3:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    } while (choice != 3);

    free_image(image);
    return 0;
}

void display_menu() {
    printf("\n--- Menu ---\n");
    printf("1. Invert Colors\n");
    printf("2. Save Image\n");
    printf("3. Exit\n");
}

Image *load_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    char header[3];
    fscanf(file, "%s", header);
    if (strcmp(header, "P6") != 0) {
        printf("Unsupported PPM format! Only binary P6 supported.\n");
        fclose(file);
        return NULL;
    }

    Image *image = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d", &image->width, &image->height);
    int maxval;
    fscanf(file, "%d", &maxval);
    fgetc(file); // Consume the newline after maxval

    image->pixels = (Pixel *)malloc(image->width * image->height * sizeof(Pixel));
    fread(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
    return image;
}

void save_ppm(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

void invert_colors(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->pixels[i].r = 255 - image->pixels[i].r;
        image->pixels[i].g = 255 - image->pixels[i].g;
        image->pixels[i].b = 255 - image->pixels[i].b;
    }
}

void free_image(Image *image) {
    if (image) {
        free(image->pixels);
        free(image);
    }
}