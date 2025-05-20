//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_VALUE 255
#define MAX_WIDTH 800
#define MAX_HEIGHT 800

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    Pixel pixels[MAX_HEIGHT][MAX_WIDTH];
    int width, height;
} Image;

// Function to read PPM file
Image* load_image(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file!\n");
        return NULL;
    }
    
    Image* img = (Image*)malloc(sizeof(Image));

    char format[3];
    int max_color_value;
    fscanf(file, "%s %d %d %d", format, &img->width, &img->height, &max_color_value);
    fread(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);

    return img;
}

// Function to save PPM file
void save_image(const char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");
    fprintf(file, "P6\n%d %d\n%d\n", img->width, img->height, MAX_COLOR_VALUE);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

// Function to apply the surprise filter (Invert colors)
void surprise_filter(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            img->pixels[y][x].r = MAX_COLOR_VALUE - img->pixels[y][x].r;
            img->pixels[y][x].g = MAX_COLOR_VALUE - img->pixels[y][x].g;
            img->pixels[y][x].b = MAX_COLOR_VALUE - img->pixels[y][x].b;
        }
    }
}

// Function to print image dimensions and data (for debugging)
void print_image_info(Image* img) {
    printf("Image Width: %d, Height: %d\n", img->width, img->height);
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            Pixel p = img->pixels[y][x];
            printf("Pixel (%d, %d): R=%d G=%d B=%d\n", x, y, p.r, p.g, p.b);
        }
    }
}

// Function to randomly create surprise colors
void randomize_colors(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            img->pixels[y][x].r = rand() % (MAX_COLOR_VALUE + 1);
            img->pixels[y][x].g = rand() % (MAX_COLOR_VALUE + 1);
            img->pixels[y][x].b = rand() % (MAX_COLOR_VALUE + 1);
        }
    }
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <command>\n", argv[0]);
        return 1;
    }

    Image* img = load_image(argv[1]);
    if (!img) {
        return 1;
    }

    printf("Loaded image successfully: Surprise awaits!\n");

    if (strcmp(argv[3], "invert") == 0) {
        surprise_filter(img);
        printf("Inverted colors! That's a surprise!\n");
    } else if (strcmp(argv[3], "random") == 0) {
        randomize_colors(img);
        printf("Randomly changed colors! What a surprise!\n");
    } else {
        fprintf(stderr, "Unknown command: %s | Available: invert, random\n", argv[3]);
        free(img);
        return 1;
    }

    save_image(argv[2], img);
    printf("Saved modified image as %s! View the masterpiece that's been created!\n", argv[2]);

    free(img);
    return 0;
}