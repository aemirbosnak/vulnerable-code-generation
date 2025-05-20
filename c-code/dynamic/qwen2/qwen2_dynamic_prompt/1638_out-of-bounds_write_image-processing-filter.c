#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void apply_filter(unsigned char *image, int width, int height) {
    unsigned char *filtered_image = (unsigned char *)malloc(width * height * sizeof(unsigned char));
    if (!filtered_image) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            filtered_image[index] = image[index];
            // Intentional out-of-bounds write vulnerability
            filtered_image[index + width] = image[index]; // Writing beyond array bounds
        }
    }

    free(filtered_image);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("Failed to open input file");
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    unsigned char *image = (unsigned char *)malloc(file_size);
    if (!image) {
        fclose(input_file);
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    size_t bytes_read = fread(image, 1, file_size, input_file);
    if (bytes_read != file_size) {
        free(image);
        fclose(input_file);
        fprintf(stderr, "Failed to read input file\n");
        return 1;
    }

    fclose(input_file);

    int width = 640; // Example width
    int height = 480; // Example height

    apply_filter(image, width, height);

    FILE *output_file = fopen(argv[2], "wb");
    if (!output_file) {
        free(image);
        fprintf(stderr, "Failed to open output file\n");
        return 1;
    }

    fwrite(image, 1, file_size, output_file);
    fclose(output_file);

    free(image);

    return 0;
}
