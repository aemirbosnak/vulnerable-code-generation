#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 800
#define MAX_HEIGHT 600

int main(int argc, char *argv[]) {
    FILE *file;
    unsigned char header[54];
    unsigned int image_dimensions[2];
    unsigned char *image_data;

    if (argc != 2) {
        printf("Usage: ./image_reader <image_file>\n");
        return 1;
    }

    file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fread(header, sizeof(unsigned char), 54, file);

    fscanf(file, "%u %u", &image_dimensions[0], &image_dimensions[1]);

    image_data = (unsigned char *)malloc(image_dimensions[0] * image_dimensions[1] * 3);
    fread(image_data, sizeof(unsigned char), image_dimensions[0] * image_dimensions[1] * 3, file);

    fclose(file);

    // Vulnerable code: Processing image_data without proper bounds checking
    // ...

    return 0;
}
