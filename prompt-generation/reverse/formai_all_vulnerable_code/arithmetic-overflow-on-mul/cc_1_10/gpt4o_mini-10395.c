//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: calm
#include <stdio.h>
#include <stdlib.h>

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
        printf("Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    char header[3];
    fscanf(file, "%s", header);
    if (header[0] != 'P' || header[1] != '6') {
        printf("Unsupported file format. Only P6 (PPM) supported.\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    Image *img = malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    
    int maxval;
    fscanf(file, "%d", &maxval);
    fgetc(file); // Consume the newline character after maxval

    img->pixels = malloc(img->width * img->height * sizeof(Pixel));
    fread(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void apply_grayscale(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char gray = (img->pixels[i].r + img->pixels[i].g + img->pixels[i].b) / 3;
        img->pixels[i].r = gray;
        img->pixels[i].g = gray;
        img->pixels[i].b = gray;
    }
}

void free_image(Image *img) {
    free(img->pixels);
    free(img);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];

    Image *image = load_image(input_file);
    
    apply_grayscale(image);
    
    save_image(output_file, image);
    
    printf("Grayscale image saved as: %s\n", output_file);
    
    free_image(image);
    return EXIT_SUCCESS;
}