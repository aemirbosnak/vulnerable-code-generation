//FormAI DATASET v1.0 Category: Image Editor ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>

// This function will scramble RGB values of each pixel
void scramble_pixels(unsigned char* pixels, int num_pixels) {
    for (int i = 0; i < num_pixels; i++) {
        unsigned char r = pixels[i * 3];
        unsigned char g = pixels[i * 3 + 1];
        unsigned char b = pixels[i * 3 + 2];
        pixels[i * 3] = b;
        pixels[i * 3 + 1] = r;
        pixels[i * 3 + 2] = g;
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: paranoid_image_editor <input_file> <output_file>\n");
        return 1;
    }

    char* input_file = argv[1];
    char* output_file = argv[2];

    FILE* fp = fopen(input_file, "rb");
    if (!fp) {
        printf("Error opening input file.\n");
        return 1;
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp); // bitmap header is exactly 54 bytes

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int num_pixels = width * height;
    int pixel_offset = *(int*)&header[10];

    unsigned char* pixels = malloc(num_pixels * 3); // 3 bytes per pixel (RGB)
    fseek(fp, pixel_offset, SEEK_SET);
    fread(pixels, sizeof(unsigned char), num_pixels * 3, fp); // read pixel data

    scramble_pixels(pixels, num_pixels); // scramble pixel data

    FILE* fp_out = fopen(output_file, "wb");
    fwrite(header, sizeof(unsigned char), 54, fp_out); // write header
    fwrite(pixels, sizeof(unsigned char), num_pixels * 3, fp_out); // write pixel data

    fclose(fp);
    fclose(fp_out);

    printf("Done.\n");

    return 0;
}