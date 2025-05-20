//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLOR_VALUE 255

void read_ppm(const char *filename, unsigned char **image, int *width, int *height);
void save_ppm(const char *filename, unsigned char *image, int width, int height);
void invert_colors(unsigned char *image, int width, int height);
void grayscale(unsigned char *image, int width, int height);
void usage(const char *progname);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    const char *operation = argv[3];

    int width, height;
    unsigned char *image = NULL;

    read_ppm(input_filename, &image, &width, &height);

    if (operation[0] == 'i') {
        invert_colors(image, width, height);
    } else if (operation[0] == 'g') {
        grayscale(image, width, height);
    } else {
        usage(argv[0]);
        free(image);
        return EXIT_FAILURE;
    }

    save_ppm(output_filename, image, width, height);
    free(image);
    return EXIT_SUCCESS;
}

void read_ppm(const char *filename, unsigned char **image, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char buffer[16];
    fgets(buffer, sizeof(buffer), file); // Read the file type
    if (buffer[0] != 'P' || buffer[1] != '6') {
        fprintf(stderr, "Unsupported format (must be 'P6')\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Skip comments
    do {
        fgets(buffer, sizeof(buffer), file);
    } while (buffer[0] == '#');

    sscanf(buffer, "%d %d", width, height);
    fgets(buffer, sizeof(buffer), file); // Read maximum color value

    size_t size = 3 * (*width) * (*height);
    *image = malloc(size);
    if (!*image) {
        perror("Unable to allocate memory");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fread(*image, size, 1, file);
    fclose(file);
}

void save_ppm(const char *filename, unsigned char *image, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file for writing");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "P6\n%d %d\n%d\n", width, height, MAX_COLOR_VALUE);
    fwrite(image, 3 * width * height, 1, file);
    fclose(file);
}

void invert_colors(unsigned char *image, int width, int height) {
    size_t num_pixels = width * height;
    for (size_t i = 0; i < num_pixels * 3; i++) {
        image[i] = MAX_COLOR_VALUE - image[i];
    }
}

void grayscale(unsigned char *image, int width, int height) {
    size_t num_pixels = width * height;
    for (size_t i = 0; i < num_pixels; i++) {
        unsigned char r = image[i * 3];
        unsigned char g = image[i * 3 + 1];
        unsigned char b = image[i * 3 + 2];
        unsigned char gray = (r + g + b) / 3;
        image[i * 3] = gray;
        image[i * 3 + 1] = gray;
        image[i * 3 + 2] = gray;
    }
}

void usage(const char *progname) {
    fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <operation>\n", progname);
    fprintf(stderr, "Operations:\n");
    fprintf(stderr, "    i - Invert colors\n");
    fprintf(stderr, "    g - Convert to grayscale\n");
}