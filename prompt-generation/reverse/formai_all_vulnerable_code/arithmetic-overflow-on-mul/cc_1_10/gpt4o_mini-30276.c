//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1) // To ensure proper memory alignment for BMP files

typedef struct
{
    unsigned short type;
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset;
} BMPHeader;

typedef struct
{
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bits_per_pixel;
    unsigned int compression;
    unsigned int size_image;
    int x_pixels_per_meter;
    int y_pixels_per_meter;
    unsigned int colors_used;
    unsigned int colors_important;
} InfoHeader;

void apply_watermark(unsigned char *image, const char *watermark, int width, int height, int wm_width, int wm_height)
{
    int x_offset = 10; // X coordinate for watermark
    int y_offset = 10; // Y coordinate for watermark

    for (int y = 0; y < wm_height; ++y)
    {
        for (int x = 0; x < wm_width; ++x)
        {
            if (x + x_offset < width && y + y_offset < height) {
                // Simple watermark application: averaging
                unsigned char *pixel = image + (y + y_offset) * width * 3 + (x + x_offset) * 3; // RGB format
                pixel[0] = (pixel[0] + watermark[y * wm_width + x]) / 2; // Red
                pixel[1] = (pixel[1] + watermark[y * wm_width + x]) / 2; // Green
                pixel[2] = (pixel[2] + watermark[y * wm_width + x]) / 2; // Blue
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <input_bmp> <output_bmp> <watermark_image>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    FILE *output_file = fopen(argv[2], "wb");
    FILE *watermark_file = fopen(argv[3], "rb");

    if (!input_file || !output_file || !watermark_file)
    {
        printf("Error: Unable to open files.\n");
        return 1;
    }

    BMPHeader bmp_header;
    InfoHeader info_header;
    
    fread(&bmp_header, sizeof(BMPHeader), 1, input_file);
    fread(&info_header, sizeof(InfoHeader), 1, input_file);

    if (bmp_header.type != 0x4D42) // 'BM'
    {
        printf("Error: Not a BMP file.\n");
        fclose(input_file);
        fclose(output_file);
        fclose(watermark_file);
        return 1;
    }

    unsigned char *image = (unsigned char *)malloc(info_header.size_image);
    fseek(input_file, bmp_header.offset, SEEK_SET);
    fread(image, info_header.size_image, 1, input_file);

    // Load watermark
    unsigned char *watermark = (unsigned char *)malloc(10 * 10); // Assuming 10x10 watermark for simplicity
    fread(watermark, 10 * 10, 1, watermark_file);

    apply_watermark(image, watermark, info_header.width, info_header.height, 10, 10);

    fseek(output_file, 0, SEEK_SET);
    fwrite(&bmp_header, sizeof(BMPHeader), 1, output_file);
    fwrite(&info_header, sizeof(InfoHeader), 1, output_file);
    fseek(output_file, bmp_header.offset, SEEK_SET);
    fwrite(image, info_header.size_image, 1, output_file);

    fclose(input_file);
    fclose(output_file);
    fclose(watermark_file);
    free(image);
    free(watermark);

    printf("Watermark applied successfully!\n");

    return 0;
}