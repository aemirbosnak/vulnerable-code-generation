//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bits_per_pixel;
    uint32_t compression;
    uint32_t image_size;
    int32_t x_pixels_per_meter;
    int32_t y_pixels_per_meter;
    uint32_t colors_used;
    uint32_t important_colors;
} BMPInfoHeader;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;

#pragma pack(pop)

void apply_grayscale(RGB *pixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        uint8_t gray = (pixels[i].red + pixels[i].green + pixels[i].blue) / 3;
        pixels[i].red = gray;
        pixels[i].green = gray;
        pixels[i].blue = gray;
    }
}

RGB *load_bmp(const char *filename, BMPHeader *header, BMPInfoHeader *info) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    fread(header, sizeof(BMPHeader), 1, file);
    fread(info, sizeof(BMPInfoHeader), 1, file);

    int width = info->width;
    int height = info->height;

    fseek(file, header->offset, SEEK_SET);
    RGB *pixels = malloc(width * height * sizeof(RGB));
    
    if (pixels == NULL) {
        perror("Unable to allocate memory for pixels");
        fclose(file);
        return NULL;
    }

    fread(pixels, sizeof(RGB), width * height, file);
    fclose(file);
    return pixels;
}

void save_bmp(const char *filename, BMPHeader *header, BMPInfoHeader *info, RGB *pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to create file");
        return;
    }

    fwrite(header, sizeof(BMPHeader), 1, file);
    fwrite(info, sizeof(BMPInfoHeader), 1, file);

    fseek(file, header->offset, SEEK_SET);
    fwrite(pixels, sizeof(RGB), info->width * info->height, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp>\n", argv[0]);
        return 1;
    }

    BMPHeader header;
    BMPInfoHeader info;

    RGB *pixels = load_bmp(argv[1], &header, &info);
    if (!pixels) {
        return 1;
    }

    apply_grayscale(pixels, info.width, info.height);

    save_bmp(argv[2], &header, &info, pixels);
    
    free(pixels);
    printf("Grayscale image saved as %s\n", argv[2]);
    return 0;
}