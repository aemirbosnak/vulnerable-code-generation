//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

typedef struct _Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct _Image {
    int width;
    int height;
    Pixel **data;
} Image;

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(fp);
        return NULL;
    }

    // Read the header
    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);

    // Allocate memory for the data
    image->data = malloc(image->height * sizeof(Pixel *));
    if (!image->data) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        free(image);
        fclose(fp);
        return NULL;
    }

    for (int i = 0; i < image->height; i++) {
        image->data[i] = malloc(image->width * sizeof(Pixel));
        if (!image->data[i]) {
            fprintf(stderr, "Error: could not allocate memory for image data\n");
            free(image->data);
            free(image);
            fclose(fp);
            return NULL;
        }
    }

    // Read the data
    fread(image->data, sizeof(Pixel), image->width * image->height, fp);

    fclose(fp);

    return image;
}

void free_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->data[i]);
    }
    free(image->data);
    free(image);
}

void print_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            Pixel pixel = image->data[i][j];
            printf("%c", pixel.red);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    print_image(image);

    free_image(image);

    return 0;
}