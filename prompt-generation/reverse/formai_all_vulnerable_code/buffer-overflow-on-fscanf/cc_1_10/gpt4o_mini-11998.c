//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: real-life
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

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Cannot open file");
        return NULL;
    }

    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P3") != 0) {
        fprintf(stderr, "Unsupported file format\n");
        fclose(file);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int max_color_value;
    fscanf(file, "%d", &max_color_value);
    
    img->pixels = malloc(img->width * img->height * sizeof(Pixel));

    for (int i = 0; i < img->width * img->height; i++) {
        fscanf(file, "%hhu %hhu %hhu", &img->pixels[i].r, &img->pixels[i].g, &img->pixels[i].b);
    }

    fclose(file);
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Cannot open file for writing");
        return;
    }

    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", img->width, img->height);
    fprintf(file, "255\n");
    
    for (int i = 0; i < img->width * img->height; i++) {
        fprintf(file, "%d %d %d\n", img->pixels[i].r, img->pixels[i].g, img->pixels[i].b);
    }

    fclose(file);
}

void invert_image(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = 255 - img->pixels[i].r;
        img->pixels[i].g = 255 - img->pixels[i].g;
        img->pixels[i].b = 255 - img->pixels[i].b;
    }
}

void free_image(Image *img) {
    if (img) {
        free(img->pixels);
        free(img);
    }
}

void display_menu() {
    printf("Image Editor Menu:\n");
    printf("1. Load Image\n");
    printf("2. Save Image\n");
    printf("3. Invert Colors\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Image *img = NULL;
    int choice;
    char filename[256];

    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter filename to load: ");
                scanf("%s", filename);
                img = load_image(filename);
                if (img) {
                    printf("Image loaded successfully: %dx%d\n", img->width, img->height);
                }
                break;
            case 2:
                if (img) {
                    printf("Enter filename to save: ");
                    scanf("%s", filename);
                    save_image(filename, img);
                    printf("Image saved successfully.\n");
                } else {
                    printf("No image to save.\n");
                }
                break;
            case 3:
                if (img) {
                    invert_image(img);
                    printf("Image colors inverted successfully.\n");
                } else {
                    printf("No image loaded to invert.\n");
                }
                break;
            case 4:
                free_image(img);
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}