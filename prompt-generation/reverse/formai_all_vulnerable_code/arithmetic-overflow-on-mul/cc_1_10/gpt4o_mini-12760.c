//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1) // Ensure that structure is packed
typedef struct {
    uint16_t file_type;        // File type
    uint32_t file_size;        // File size in bytes
    uint16_t reserved1;        // Reserved
    uint16_t reserved2;        // Reserved
    uint32_t offset_data;      // Offset to image data
} BMPHeader;

typedef struct {
    uint32_t size;             // Size of this header (40 bytes)
    int32_t width;             // Width of bitmap in pixels
    int32_t height;            // Height of bitmap in pixels
    uint16_t planes;           // Number of color planes
    uint16_t bits_per_pixel;   // Bits per pixel
    uint32_t compression;      // Compression type
    uint32_t size_image;       // Size of image data
    int32_t x_pixels_per_meter; // Pixels per meter in X
    int32_t y_pixels_per_meter; // Pixels per meter in Y
    uint32_t colors_used;      // Number of colors
    uint32_t colors_important; // Important colors
} BMPInfoHeader;
#pragma pack(pop)

typedef struct {
    uint8_t *data;            // Pointer to pixel data
    int width;                // Image width
    int height;               // Image height
    int row_padded;           // Row size padded to the nearest multiple of 4
} Image;

Image load_bmp(const char *filename);
void save_bmp(const char *filename, Image img);
void flip_image(Image *img);
void change_brightness_contrast(Image *img, int brightness, float contrast);
void free_image(Image img);

int main() {
    char *input_file = "input.bmp";
    char *output_file = "output_flip.bmp";
    char *output_brightness_contrast = "output_brightness_contrast.bmp";

    Image img = load_bmp(input_file);
    if (!img.data) {
        fprintf(stderr, "Error loading image.\n");
        return 1;
    }

    // Flip the image
    flip_image(&img);
    save_bmp(output_file, img);

    // Change brightness and contrast
    int brightness = 50;  // Increase brightness by 50
    float contrast = 1.5; // Increase contrast
    change_brightness_contrast(&img, brightness, contrast);
    save_bmp(output_brightness_contrast, img);

    free_image(img);
    return 0;
}

Image load_bmp(const char *filename) {
    Image img;
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        img.data = NULL;
        return img;
    }

    BMPHeader bmp_header;
    fread(&bmp_header, sizeof(BMPHeader), 1, file);

    BMPInfoHeader bmp_info_header;
    fread(&bmp_info_header, sizeof(BMPInfoHeader), 1, file);
    
    img.width = bmp_info_header.width;
    img.height = bmp_info_header.height;
    img.row_padded = (img.width * 3 + 3) & (~3);
    img.data = (uint8_t *)malloc(img.row_padded * img.height);

    fseek(file, bmp_header.offset_data, SEEK_SET);
    fread(img.data, sizeof(uint8_t), img.row_padded * img.height, file);
    fclose(file);

    return img;
}

void save_bmp(const char *filename, Image img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error saving image to %s\n", filename);
        return;
    }

    BMPHeader bmp_header = {0x4D42, 54 + img.row_padded * img.height, 0, 0, 54};
    BMPInfoHeader bmp_info_header = {40, img.width, img.height, 1, 24, 0, 0, 0, 0, 0, 0};

    fwrite(&bmp_header, sizeof(BMPHeader), 1, file);
    fwrite(&bmp_info_header, sizeof(BMPInfoHeader), 1, file);
    fwrite(img.data, sizeof(uint8_t), img.row_padded * img.height, file);
    fclose(file);
}

void flip_image(Image *img) {
    int bytes_per_pixel = 3;
    uint8_t *flipped_data = (uint8_t *)malloc(img->row_padded * img->height);
    
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int src_index = (y * img->row_padded) + (x * bytes_per_pixel);
            int dest_index = ((img->height - 1 - y) * img->row_padded) + (x * bytes_per_pixel);
            flipped_data[dest_index] = img->data[src_index];
            flipped_data[dest_index + 1] = img->data[src_index + 1];
            flipped_data[dest_index + 2] = img->data[src_index + 2];
        }
    }

    free(img->data);
    img->data = flipped_data;
}

void change_brightness_contrast(Image *img, int brightness, float contrast) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int index = (y * img->row_padded) + (x * 3);
            for (int c = 0; c < 3; c++) {
                int pixel = img->data[index + c];
                pixel += brightness; // Apply brightness

                // Apply contrast
                pixel = (int)((pixel - 128) * contrast + 128);
                // Clamp the values between 0 and 255
                if (pixel < 0) pixel = 0;
                if (pixel > 255) pixel = 255;

                img->data[index + c] = (uint8_t)pixel;
            }
        }
    }
}

void free_image(Image img) {
    free(img.data);
}