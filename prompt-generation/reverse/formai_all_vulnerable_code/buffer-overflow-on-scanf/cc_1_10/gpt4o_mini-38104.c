//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel **pixels;
} Image;

Image *load_image(const char *filename);
void save_image(const Image *image, const char *filename);
void invert_colors(Image *image);
void flip_image(Image *image);
void free_image(Image *image);
void print_menu();
void execute_choice(Image *image, int choice);

int main() {
    char filename[256];
    printf("Enter the PPM image file name to edit: ");
    scanf("%s", filename);

    Image *image = load_image(filename);
    if (!image) {
        printf("Error loading image: %s\n", filename);
        return 1;
    }

    int choice;
    do {
        print_menu();
        printf("Choose an operation (0 to exit): ");
        scanf("%d", &choice);
        execute_choice(image, choice);
    } while (choice != 0);

    free_image(image);
    return 0;
}

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    char header[3];
    fscanf(file, "%2s\n", header);
    if (strcmp(header, "P3") != 0) {
        fclose(file);
        return NULL; // Only supports P3 format
    }

    Image *image = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d\n", &image->width, &image->height);

    image->pixels = (Pixel **)malloc(image->height * sizeof(Pixel *));
    for (int i = 0; i < image->height; ++i) {
        image->pixels[i] = (Pixel *)malloc(image->width * sizeof(Pixel));
        for (int j = 0; j < image->width; ++j) {
            fscanf(file, "%d %d %d", &image->pixels[i][j].r,
                   &image->pixels[i][j].g, &image->pixels[i][j].b);
        }
    }

    fclose(file);
    return image;
}

void save_image(const Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return;
    }

    fprintf(file, "P3\n%d %d\n255\n", image->width, image->height);
    for (int i = 0; i < image->height; ++i) {
        for (int j = 0; j < image->width; ++j) {
            fprintf(file, "%d %d %d ", image->pixels[i][j].r,
                    image->pixels[i][j].g, image->pixels[i][j].b);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void invert_colors(Image *image) {
    for (int i = 0; i < image->height; ++i) {
        for (int j = 0; j < image->width; ++j) {
            image->pixels[i][j].r = 255 - image->pixels[i][j].r;
            image->pixels[i][j].g = 255 - image->pixels[i][j].g;
            image->pixels[i][j].b = 255 - image->pixels[i][j].b;
        }
    }
    printf("Image colors inverted.\n");
}

void flip_image(Image *image) {
    for (int i = 0; i < image->height; ++i) {
        for (int j = 0; j < image->width / 2; ++j) {
            Pixel temp = image->pixels[i][j];
            image->pixels[i][j] = image->pixels[i][image->width - j - 1];
            image->pixels[i][image->width - j - 1] = temp;
        }
    }
    printf("Image flipped horizontally.\n");
}

void free_image(Image *image) {
    for (int i = 0; i < image->height; ++i) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

void print_menu() {
    printf("Menu:\n");
    printf("1. Invert Colors\n");
    printf("2. Flip Image Horizontally\n");
    printf("3. Save Image\n");
    printf("0. Exit\n");
}

void execute_choice(Image *image, int choice) {
    char filename[256];
    switch (choice) {
        case 1:
            invert_colors(image);
            break;
        case 2:
            flip_image(image);
            break;
        case 3:
            printf("Enter filename to save: ");
            scanf("%s", filename);
            save_image(image, filename);
            printf("Image saved as %s.\n", filename);
            break;
        case 0:
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}