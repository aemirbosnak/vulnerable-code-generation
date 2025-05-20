//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;  // Pointer to image data
} Image;

Image* load_image(const char *filename);
void save_image(const char *filename, Image *img);
void apply_negative_filter(Image *img);
void free_image(Image *img);

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        return 1;
    }

    Image *img = load_image(argv[1]);
    if (!img) {
        fprintf(stderr, "Error loading image.\n");
        return 1;
    }

    apply_negative_filter(img);
    
    save_image(argv[2], img);
    free_image(img);
    
    printf("Image processing complete. Negative filter applied and saved to %s\n", argv[2]);
    return 0;
}

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    // Read PPM header
    char header[3];
    fscanf(file, "%2s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported file format. Only binary PPM (P6) supported.\n");
        fclose(file);
        return NULL;
    }

    int width, height, maxval;
    fscanf(file, "%d %d %d", &width, &height, &maxval);
    fgetc(file);  // Read the newline character after maxval

    Image *img = (Image *)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = (unsigned char *)malloc(width * height * 3);  // 3 bytes per pixel (RGB)

    fread(img->data, 3, width * height, file);
    fclose(file);

    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, 3, img->width * img->height, file);
    fclose(file);
}

void apply_negative_filter(Image *img) {
    for (int i = 0; i < img->width * img->height * 3; i++) {
        img->data[i] = 255 - img->data[i];  // Inverse the color
    }
}

void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}