//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define WIDTH 80
#define HEIGHT 40
#define MAX_GRAY_LEVEL 255
#define ASCII_CHARS "@%#*+=-:. "

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    Pixel *pixels;
    int width;
    int height;
} Image;

Image* load_image(const char *filename);
void free_image(Image *img);
char pixel_to_ascii(Pixel pixel);
void render_ascii(Image *img);
void clear_screen();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_file.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = load_image(argv[1]);
    if (!img) {
        fprintf(stderr, "Could not load image %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    clear_screen();
    render_ascii(img);
    free_image(img);
    return EXIT_SUCCESS;
}

Image* load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return NULL;

    char header[3];
    fscanf(fp, "%s", header);
    if (strcmp(header, "P6") != 0) {
        fclose(fp);
        return NULL;
    }

    int width, height, max_color;
    fscanf(fp, "%d%d%d", &width, &height, &max_color);
    fgetc(fp); // Skip the newline after max_color

    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = malloc(width * height * sizeof(Pixel));
    
    fread(img->pixels, sizeof(Pixel), width * height, fp);
    fclose(fp);
    
    return img;
}

void free_image(Image *img) {
    if (img) {
        free(img->pixels);
        free(img);
    }
}

char pixel_to_ascii(Pixel pixel) {
    int gray = (pixel.r + pixel.g + pixel.b) / 3;
    int index = (gray * (sizeof(ASCII_CHARS) - 1)) / MAX_GRAY_LEVEL;
    return ASCII_CHARS[index];
}

void render_ascii(Image *img) {
    int ratio = img->width / WIDTH > img->height / HEIGHT ? img->width / WIDTH : img->height / HEIGHT;
    
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            int x = j * ratio;
            int y = i * ratio;
            if (x < img->width && y < img->height) {
                char ascii_char = pixel_to_ascii(img->pixels[y * img->width + x]);
                putchar(ascii_char);
            }
        }
        putchar('\n');
    }
}

void clear_screen() {
    printf("\033[H\033[J");
}