//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80         // Maximum width of the ASCII output
#define MAX_HEIGHT 80        // Maximum height of the ASCII output
#define ASCII_CHARS "@%#*+=-:. " // Characters used for ASCII art representation
#define ASCII_CHARS_LENGTH 10 // Number of different characters used

typedef struct {
    unsigned char r, g, b;
} RGB;

RGB **load_image(const char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return NULL;
    }

    // Simple PPM header parsing
    char header[3];
    fscanf(file, "%s", header);
    fgetc(file); // Read the newline after header

    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported image format %s\n", header);
        fclose(file);
        return NULL;
    }

    fscanf(file, "%d %d", width, height);
    int max_color_value;
    fscanf(file, "%d", &max_color_value);
    fgetc(file); // Read the newline character after max color value

    RGB **image = malloc(*height * sizeof(RGB *));
    for (int i = 0; i < *height; ++i) {
        image[i] = malloc(*width * sizeof(RGB));
        fread(image[i], sizeof(RGB), *width, file);
    }

    fclose(file);
    return image;
}

void free_image(RGB **image, int height) {
    for (int i = 0; i < height; ++i) {
        free(image[i]);
    }
    free(image);
}

char get_ascii_char(int gray_value) {
    return ASCII_CHARS[(gray_value * ASCII_CHARS_LENGTH) / 256];
}

void convert_to_ascii(RGB **image, int width, int height) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int gray_value = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;
            putchar(get_ascii_char(gray_value));
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int width, height;
    RGB **image = load_image(argv[1], &width, &height);
    
    if (image == NULL) return EXIT_FAILURE;

    float aspect_ratio = (float)width / (float)height;
    int new_width = MAX_WIDTH;
    int new_height = (int)(MAX_HEIGHT / aspect_ratio);

    // Resize if necessary
    if (new_height > MAX_HEIGHT) {
        new_height = MAX_HEIGHT;
        new_width = (int)(new_height * aspect_ratio);
        if (new_width > MAX_WIDTH) {
            new_width = MAX_WIDTH;
        }
    }

    // Print ASCII representation
    convert_to_ascii(image, new_width < width ? new_width : width, 
                     new_height < height ? new_height : height);
    
    // Free allocated memory
    free_image(image, height);
    return EXIT_SUCCESS;
}