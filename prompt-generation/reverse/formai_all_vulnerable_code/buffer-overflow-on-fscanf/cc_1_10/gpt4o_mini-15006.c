//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: decentralized
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

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Unable to open file");
        return NULL;
    }
    
    // PPM Header (assuming the file is a P3 PPM format)
    char header[3];
    fscanf(fp, "%s", header);
    
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported file format\n");
        fclose(fp);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    fscanf(fp, "%d %d", &img->width, &img->height);
    int max_color_value;
    fscanf(fp, "%d", &max_color_value);
    fgetc(fp); // Skip the newline after max color value

    img->data = malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);
    
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Unable to open file");
        return;
    }
    
    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}

void flip_image(Image *img) {
    for (int y = 0; y < img->height; ++y) {
        for (int x = 0; x < img->width / 2; ++x) {
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + (img->width - 1 - x)];
            img->data[y * img->width + (img->width - 1 - x)] = temp;
        }
    }
}

void adjust_brightness(Image *img, int value) {
    for (int y = 0; y < img->height; ++y) {
        for (int x = 0; x < img->width; ++x) {
            Pixel *p = &img->data[y * img->width + x];
            p->r = (unsigned char) fmin(fmax(p->r + value, 0), 255);
            p->g = (unsigned char) fmin(fmax(p->g + value, 0), 255);
            p->b = (unsigned char) fmin(fmax(p->b + value, 0), 255);
        }
    }
}

void adjust_contrast(Image *img, float factor) {
    for (int y = 0; y < img->height; ++y) {
        for (int x = 0; x < img->width; ++x) {
            Pixel *p = &img->data[y * img->width + x];
            p->r = (unsigned char) fmin(fmax((p->r - 128) * factor + 128, 0), 255);
            p->g = (unsigned char) fmin(fmax((p->g - 128) * factor + 128, 0), 255);
            p->b = (unsigned char) fmin(fmax((p->b - 128) * factor + 128, 0), 255);
        }
    }
}

void print_usage(const char *prog_name) {
    printf("Usage: %s <input.ppm> <output.ppm> <flip|brightness|contrast> [args]\n", prog_name);
    printf("   flip: Flip the image horizontally.\n");
    printf("   brightness: Adjust brightness. Usage: brightness <value>\n");
    printf("   contrast: Adjust contrast. Usage: contrast <factor>\n");
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = load_image(argv[1]);
    if (!img) return EXIT_FAILURE;

    if (strcmp(argv[3], "flip") == 0) {
        flip_image(img);
    } else if (strcmp(argv[3], "brightness") == 0 && argc == 5) {
        int brightness_value = atoi(argv[4]);
        adjust_brightness(img, brightness_value);
    } else if (strcmp(argv[3], "contrast") == 0 && argc == 5) {
        float contrast_value = atof(argv[4]);
        adjust_contrast(img, contrast_value);
    } else {
        print_usage(argv[0]);
        free_image(img);
        return EXIT_FAILURE;
    }

    save_image(argv[2], img);
    free_image(img);
    
    return EXIT_SUCCESS;
}