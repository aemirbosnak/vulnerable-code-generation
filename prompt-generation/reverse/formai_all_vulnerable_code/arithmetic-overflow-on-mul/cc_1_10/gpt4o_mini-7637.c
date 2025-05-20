//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: curious
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel* pixels;
} Image;

Image* load_ppm(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }
    
    char header[3];
    fscanf(file, "%s", header);
    if (header[0] != 'P' || header[1] != '6') {
        fprintf(stderr, "Unsupported PPM format\n");
        fclose(file);
        return NULL;
    }

    Image* img = (Image*)malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int maxColor;
    fscanf(file, "%d", &maxColor);
    fgetc(file); // Read the newline character after maxColor

    img->pixels = (Pixel*)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    
    return img;
}

void save_ppm(const char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Could not save file");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void apply_grayscale(Image* img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char avg = (img->pixels[i].r + img->pixels[i].g + img->pixels[i].b) / 3;
        img->pixels[i].r = avg;
        img->pixels[i].g = avg;
        img->pixels[i].b = avg;
    }
}

void free_image(Image* img) {
    free(img->pixels);
    free(img);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image* img = load_ppm(argv[1]);
    if (!img) {
        return EXIT_FAILURE;
    }

    apply_grayscale(img);
    save_ppm(argv[2], img);

    free_image(img);
    printf("Grayscale image saved as %s\n", argv[2]);
    
    return EXIT_SUCCESS;
}