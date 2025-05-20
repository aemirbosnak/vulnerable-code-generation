//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

Image* load_image(const char *filename);
void save_image(const char *filename, Image *img);
void flip_horizontal(Image *img);
void convert_to_grayscale(Image *img);
void free_image(Image *img);
void print_usage();

int main(int argc, char *argv[]) {
    if (argc < 4) {
        print_usage();
        return 1;
    }

    const char *input_file = argv[1];
    const char *operation = argv[2];
    const char *output_file = argv[3];

    Image *img = load_image(input_file);
    if (!img) {
        return 1;
    }

    if (strcmp(operation, "flip") == 0) {
        flip_horizontal(img);
    } else if (strcmp(operation, "grayscale") == 0) {
        convert_to_grayscale(img);
    } else {
        printf("Unknown operation: %s\n", operation);
        free_image(img);
        return 1;
    }

    save_image(output_file, img);
    free_image(img);

    return 0;
}

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    char buffer[16];
    if (!fgets(buffer, sizeof(buffer), file)) {
        fprintf(stderr, "Input not in PPM format\n");
        fclose(file);
        return NULL;
    }

    if (buffer[0] != 'P' || buffer[1] != '6') {
        fprintf(stderr, "Invalid PPM format\n");
        fclose(file);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int max_color;
    fscanf(file, "%d", &max_color);
    fgetc(file); // Read the newline character after max_color

    img->pixels = malloc(img->width * img->height * sizeof(Pixel));
    fread(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error saving file: %s\n", filename);
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flip_horizontal(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width / 2; j++) {
            Pixel temp = img->pixels[i * img->width + j];
            img->pixels[i * img->width + j] = img->pixels[i * img->width + (img->width - j - 1)];
            img->pixels[i * img->width + (img->width - j - 1)] = temp;
        }
    }
}

void convert_to_grayscale(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char gray = (unsigned char)(0.3 * img->pixels[i].r + 0.59 * img->pixels[i].g + 0.11 * img->pixels[i].b);
        img->pixels[i].r = gray;
        img->pixels[i].g = gray;
        img->pixels[i].b = gray;
    }
}

void free_image(Image *img) {
    if (img) {
        free(img->pixels);
        free(img);
    }
}

void print_usage() {
    printf("Usage: image_editor <input_file.ppm> <operation: flip|grayscale> <output_file.ppm>\n");
    printf("Example: image_editor input.ppm flip output.ppm\n");
}