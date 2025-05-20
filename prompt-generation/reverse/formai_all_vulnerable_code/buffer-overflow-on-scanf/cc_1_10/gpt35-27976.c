//FormAI DATASET v1.0 Category: Image Editor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_COMMAND_LENGTH 10
#define MAX_COLOR_VALUE 255

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

Image *load_image(const char *filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    char p[2];
    fscanf(file, "%s", p);
    if (p[0] != 'P' || p[1] != '3') {
        printf("Error: invalid file format\n");
        exit(1);
    }

    int width, height;
    fscanf(file, "%d %d", &width, &height);

    int color_depth;
    fscanf(file, "%d", &color_depth);
    if (color_depth != MAX_COLOR_VALUE) {
        printf("Error: unsupported color depth\n");
        exit(1);
    }

    // allocate memory for image data
    Image *image = (Image*) malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = (Pixel*) malloc(sizeof(Pixel) * width * height);

    // read pixel data
    for (int i = 0; i < width * height; i++) {
        int r, g, b;
        fscanf(file, "%d %d %d", &r, &g, &b);
        image->data[i].r = (unsigned char) r;
        image->data[i].g = (unsigned char) g;
        image->data[i].b = (unsigned char) b;
    }

    fclose(file);
    return image;
}

void save_image(Image *image, const char *filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: could not create file\n");
        exit(1);
    }

    fprintf(file, "P3\n%d %d\n%d\n", image->width, image->height, MAX_COLOR_VALUE);

    for (int i = 0; i < image->width * image->height; i++) {
        fprintf(file, "%d %d %d\n", image->data[i].r, image->data[i].g, image->data[i].b);
    }

    fclose(file);
}

void apply_grayscale_filter(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned int gray = (unsigned int) (0.3 * image->data[i].r + 0.59 * image->data[i].g + 0.11 * image->data[i].b);
        image->data[i].r = gray;
        image->data[i].g = gray;
        image->data[i].b = gray;
    }
}

void apply_invert_filter(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i].r = MAX_COLOR_VALUE - image->data[i].r;
        image->data[i].g = MAX_COLOR_VALUE - image->data[i].g;
        image->data[i].b = MAX_COLOR_VALUE - image->data[i].b;
    }
}

void apply_brightness_filter(Image *image, int delta) {
    for (int i = 0; i < image->width * image->height; i++) {
        int r = (int) image->data[i].r + delta;
        int g = (int) image->data[i].g + delta;
        int b = (int) image->data[i].b + delta;

        if (r < 0) r = 0;
        if (r > MAX_COLOR_VALUE) r = MAX_COLOR_VALUE;
        if (g < 0) g = 0;
        if (g > MAX_COLOR_VALUE) g = MAX_COLOR_VALUE;
        if (b < 0) b = 0;
        if (b > MAX_COLOR_VALUE) b = MAX_COLOR_VALUE;

        image->data[i].r = (unsigned char) r;
        image->data[i].g = (unsigned char) g;
        image->data[i].b = (unsigned char) b;
    }
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    Image *image = load_image(filename);
    printf("Image loaded successfully!\n");

    char command[MAX_COMMAND_LENGTH];
    do {
        printf("----------------------------------------\n");
        printf("Commands:\n");
        printf("  G - Grayscale filter\n");
        printf("  I - Invert filter\n");
        printf("  B <delta> - Brightness filter\n");
        printf("  S - Save image\n");
        printf("  Q - Quit\n");
        printf("Enter command: ");
        scanf("%s", command);

        if (command[0] == 'G') {
            apply_grayscale_filter(image);
            printf("Grayscale filter applied!\n");
        } else if (command[0] == 'I') {
            apply_invert_filter(image);
            printf("Invert filter applied!\n");
        } else if (command[0] == 'B') {
            int delta;
            sscanf(command + 1, "%d", &delta);
            apply_brightness_filter(image, delta);
            printf("Brightness filter (delta = %d) applied!\n", delta);
        } else if (command[0] == 'S') {
            save_image(image, filename);
            printf("Image saved successfully!\n");
        } else if (command[0] != 'Q') {
            printf("Invalid command!\n");
        }
    } while (command[0] != 'Q');

    free(image->data);
    free(image);

    return 0;
}