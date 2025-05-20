//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_VALUE 255

void print_usage() {
    printf("Usage: image_editor <input.ppm> <output.ppm> <operation>\n");
    printf("Operations:\n");
    printf("  invert\n");
}

int read_ppm(const char *filename, unsigned char **pixels, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open input file");
        return -1;
    }
    
    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P6") != 0) {
        fclose(file);
        fprintf(stderr, "Unsupported format. Only P6 (binary) PPM supported.\n");
        return -1;
    }
    
    fscanf(file, "%d %d", width, height);
    int maxval;
    fscanf(file, "%d", &maxval);
    fgetc(file);  // Consume the newline after maxval

    if (maxval != MAX_COLOR_VALUE) {
        fclose(file);
        fprintf(stderr, "Unsupported max color value. Only %d supported.\n", MAX_COLOR_VALUE);
        return -1;
    }

    int size = (*width) * (*height) * 3; // 3 bytes per pixel (RGB)
    *pixels = (unsigned char *)malloc(size);
    if (!*pixels) {
        fclose(file);
        fprintf(stderr, "Memory allocation error\n");
        return -1;
    }

    fread(*pixels, 1, size, file);
    fclose(file);
    return 0;
}

void invert_colors(unsigned char *pixels, int width, int height) {
    int size = width * height * 3;
    for (int i = 0; i < size; i++) {
        pixels[i] = MAX_COLOR_VALUE - pixels[i]; // Invert color
    }
}

int write_ppm(const char *filename, unsigned char *pixels, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open output file");
        return -1;
    }

    fprintf(file, "P6\n%d %d\n%d\n", width, height, MAX_COLOR_VALUE);
    int size = width * height * 3;
    fwrite(pixels, 1, size, file);
    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return -1;
    }

    unsigned char *pixels = NULL;
    int width, height;

    if (read_ppm(argv[1], &pixels, &width, &height) != 0) {
        return -1;
    }

    if (strcmp(argv[3], "invert") == 0) {
        invert_colors(pixels, width, height);
    } else {
        fprintf(stderr, "Unknown operation: %s\n", argv[3]);
        free(pixels);
        return -1;
    }

    if (write_ppm(argv[2], pixels, width, height) != 0) {
        free(pixels);
        return -1;
    }

    free(pixels);
    return 0;
}