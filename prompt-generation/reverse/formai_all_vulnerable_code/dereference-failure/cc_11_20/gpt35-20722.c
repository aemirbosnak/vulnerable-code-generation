//FormAI DATASET v1.0 Category: Image Editor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_FILE_SIZE 1024*1024

#pragma pack(push, 1) // align struct to byte boundary
typedef struct {
    char magic_number[2];
    uint32_t file_size;
    uint16_t reserved1, reserved2;
    uint32_t data_offset;
} BMP_Header;

typedef struct {
    uint32_t header_size, image_width, image_height;
    uint16_t color_planes, bits_per_pixel;
    uint32_t compression_method, image_size, horizontal_resolution, vertical_resolution;
    uint32_t colors_palette, important_colors;
} BMP_Image_Header;
#pragma pack(pop)

int main(int argc, char**argv) {
    FILE* input_file, *output_file;
    char* input_buf, *output_buf;
    BMP_Header bmp_header;
    BMP_Image_Header bmp_image_header;
    uint32_t width, height, padding, pixel_bytes, x, y;
    uint8_t* image_data, *p;

    // Check command line arguments and print usage
    if (argc != 3) {
        printf("Usage: %s <input_file.bmp> <output_file.bmp>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the input file
    input_file = fopen(argv[1], "rb");
    if (!input_file) {
        printf("Failed to open file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Read the BMP header
    fread(&bmp_header, sizeof(bmp_header), 1, input_file);

    // Check the magic number
    if (bmp_header.magic_number[0] != 'B' || bmp_header.magic_number[1] != 'M') {
        printf("Invalid file format: %s is not a BMP file\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Read the BMP image header
    fread(&bmp_image_header, sizeof(bmp_image_header), 1, input_file);

    // Check if the image format is supported
    if (bmp_image_header.bits_per_pixel != 24 || bmp_image_header.compression_method != 0) {
        printf("Unsupported image format\n");
        exit(EXIT_FAILURE);
    }

    // Calculate image parameters
    width = bmp_image_header.image_width;
    height = bmp_image_header.image_height;
    padding = (4 - (width * 3) % 4) % 4;
    pixel_bytes = 3; // RGB

    // Allocate memory for the image data
    image_data = (uint8_t*)malloc(width * height * pixel_bytes);
    if (!image_data) {
        printf("Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    // Read the image data
    fseek(input_file, bmp_header.data_offset - sizeof(bmp_header) - sizeof(bmp_image_header), SEEK_CUR);
    for (y = 0; y < height; ++y) {
        p = image_data + (height - 1 - y) * width * pixel_bytes;
        for (x = 0; x < width; ++x) {
            fread(p, pixel_bytes, 1, input_file);
            p += pixel_bytes;
        }
        fseek(input_file, padding, SEEK_CUR);
    }

    // Close the input file
    fclose(input_file);

    // Allocate memory for the output image data
    output_buf = (char*)calloc(MAX_FILE_SIZE, sizeof(char));
    if (!output_buf) {
        printf("Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    // Copy image data to output buffer
    memcpy(output_buf, &bmp_header, sizeof(bmp_header));
    memcpy(output_buf + sizeof(bmp_header), &bmp_image_header, sizeof(bmp_image_header));
    memcpy(output_buf + bmp_header.data_offset, image_data, width * height * pixel_bytes);

    // Save the output file
    output_file = fopen(argv[2], "wb");
    if (output_file) {
        fwrite(output_buf, MAX_FILE_SIZE, sizeof(char),  output_file);
        fclose(output_file);
    } else {
        printf("Failed to open file: %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    // Free memory
    free(image_data);
    free(output_buf);

    printf("Done!\n");

    return 0;
}