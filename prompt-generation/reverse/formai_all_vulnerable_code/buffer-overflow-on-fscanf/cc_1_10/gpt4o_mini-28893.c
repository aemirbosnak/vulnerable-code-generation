//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: visionary
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

void free_image(Image *image) {
    free(image->pixels);
    image->pixels = NULL;
}

Image* load_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    char format[3];
    fscanf(file, "%2s", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported format (only P6 is supported)\n");
        fclose(file);
        return NULL;
    }
    
    Image *image = malloc(sizeof(Image));
    fscanf(file, "%d %d", &image->width, &image->height);
    int max_val;
    fscanf(file, "%d", &max_val);
    fgetc(file); // consume the newline after max_val

    image->pixels = malloc(image->width * image->height * sizeof(Pixel));
    fread(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
    return image;
}

void save_ppm(const char *filename, const Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file for writing");
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

void display_menu() {
    printf("Image Editor Menu:\n");
    printf("1. Invert Colors\n");
    printf("2. Save Image\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        return 1;
    }

    Image *image = load_ppm(argv[1]);
    if (!image) {
        return 1;
    }

    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                invert_colors(image);
                printf("Colors inverted.\n");
                break;
            case 2:
                save_ppm(argv[2], image);
                printf("Image saved as %s.\n", argv[2]);
                break;
            case 3:
                free_image(image);
                free(image);
                printf("Exiting the editor.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}