//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* load_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }
    
    char header[3];
    fscanf(file, "%s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported file format\n");
        fclose(file);
        return NULL;
    }

    Image *img = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int max_val;
    fscanf(file, "%d", &max_val);
    fgetc(file); // consume newline

    img->data = malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);

    return img;
}

void save_ppm(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        return;
    }
    
    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flip_image(Image *img) {
    int row_size = img->width * sizeof(Pixel);
    Pixel *temp_row = malloc(row_size);

    for (int y = 0; y < img->height / 2; y++) {
        memcpy(temp_row, &img->data[y * img->width], row_size);
        memcpy(&img->data[y * img->width], &img->data[(img->height - 1 - y) * img->width], row_size);
        memcpy(&img->data[(img->height - 1 - y) * img->width], temp_row, row_size);
    }
    
    free(temp_row);
}

void adjust_brightness_contrast(Image *img, int brightness, float contrast) {
    for (int i = 0; i < img->width * img->height; i++) {
        int r = img->data[i].r + brightness;
        int g = img->data[i].g + brightness;
        int b = img->data[i].b + brightness;

        r = (int)(contrast * (r - 128) + 128);
        g = (int)(contrast * (g - 128) + 128);
        b = (int)(contrast * (b - 128) + 128);

        img->data[i].r = r < 0 ? 0 : (r > 255 ? 255 : r);
        img->data[i].g = g < 0 ? 0 : (g > 255 ? 255 : g);
        img->data[i].b = b < 0 ? 0 : (b > 255 ? 255 : b);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <action> <value>\n", argv[0]);
        return 1;
    }

    Image *img = load_ppm(argv[1]);
    if (!img) {
        return 1;
    }

    if (strcmp(argv[3], "flip") == 0) {
        flip_image(img);
    } else if (strcmp(argv[3], "bright") == 0) {
        int brightness = atoi(argv[4]);
        adjust_brightness_contrast(img, brightness, 1.0);
    } else if (strcmp(argv[3], "contrast") == 0) {
        float contrast = atof(argv[4]);
        adjust_brightness_contrast(img, 0, contrast);
    } else {
        fprintf(stderr, "Unknown action: %s\n", argv[3]);
        free(img->data);
        free(img);
        return 1;
    }

    save_ppm(argv[2], img);
    free(img->data);
    free(img);
    return 0;
}