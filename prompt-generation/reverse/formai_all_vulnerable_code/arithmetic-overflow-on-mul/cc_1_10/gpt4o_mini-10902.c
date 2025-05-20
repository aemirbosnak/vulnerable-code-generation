//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 768
#define MAX_FILENAME 256

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    Pixel pixels[MAX_HEIGHT][MAX_WIDTH];
    int width;
    int height;
} Image;

void load_image(const char* filename, Image* img) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Unable to load image file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fread(&img->width, sizeof(int), 1, file);
    fread(&img->height, sizeof(int), 1, file);
    fread(img->pixels, sizeof(Pixel), img->width * img->height, file);
    
    fclose(file);
}

void save_image(const char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: Unable to save image file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fwrite(&img->width, sizeof(int), 1, file);
    fwrite(&img->height, sizeof(int), 1, file);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    
    fclose(file);
}

void apply_grayscale(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            Pixel* p = &img->pixels[y][x];
            unsigned char gray = (unsigned char)(0.3 * p->r + 0.59 * p->g + 0.11 * p->b);
            p->r = gray;
            p->g = gray;
            p->b = gray;
        }
    }
}

void apply_inversion(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            Pixel* p = &img->pixels[y][x];
            p->r = 255 - p->r;
            p->g = 255 - p->g;
            p->b = 255 - p->b;
        }
    }
}

void apply_mirror(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            Pixel temp = img->pixels[y][x];
            img->pixels[y][x] = img->pixels[y][img->width - x - 1];
            img->pixels[y][img->width - x - 1] = temp;
        }
    }
}

void print_menu() {
    printf("Post-Apocalyptic Image Editor\n");
    printf("1. Load Image\n");
    printf("2. Save Image\n");
    printf("3. Apply Grayscale\n");
    printf("4. Apply Inversion\n");
    printf("5. Mirror Image\n");
    printf("6. Exit\n");
}

int main() {
    Image img;
    char filename[MAX_FILENAME];
    int choice;

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter image filename to load: ");
                scanf("%s", filename);
                load_image(filename, &img);
                printf("Image loaded successfully.\n");
                break;
            case 2:
                printf("Enter filename to save the image: ");
                scanf("%s", filename);
                save_image(filename, &img);
                printf("Image saved successfully.\n");
                break;
            case 3:
                apply_grayscale(&img);
                printf("Grayscale applied.\n");
                break;
            case 4:
                apply_inversion(&img);
                printf("Inversion applied.\n");
                break;
            case 5:
                apply_mirror(&img);
                printf("Image mirrored.\n");
                break;
            case 6:
                printf("Exiting... Watch out for mutants!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    
    return 0;
}