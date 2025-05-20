//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: expert-level
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
} RGBAPixel;

bool is_dark(RGBAPixel pixel) {
    uint32_t combined = pixel.red | (pixel.green << 8) | (pixel.blue << 16) | (pixel.alpha << 24);
    return (combined & 0xFFFFFF80) > (~(uint32_t)0 << (CHAR_BIT * sizeof(RGBAPixel) - 1));
}

void print_binary(uint32_t value) {
    printf("0b");
    for (size_t i = 32; i-- > 0;) {
        putchar(value & 1 ? '1' : '0');
        putchar(' ');
        value >>= 1;
    }
    putchar('\n');
}

RGBAPixel process_pixel(RGBAPixel pixel) {
    bool is_dark_new = is_dark(pixel);
    uint8_t intensity = is_dark_new ? 0x80 : 0;

    pixel.red = pixel.red + intensity;
    pixel.green = pixel.green + intensity;
    pixel.blue = pixel.blue + intensity;

    print_binary(pixel.red);
    print_binary(pixel.green);
    print_binary(pixel.blue);

    return pixel;
}

int main() {
    RGBAPixel pixel = {0x4F, 0x4F, 0x4F, 0xFF};
    RGBAPixel processed_pixel = process_pixel(pixel);

    printf("Original pixel RGB: %hhu %hhu %hhu\n", pixel.red, pixel.green, pixel.blue);
    printf("Original pixel RGBA: %hhu %hhu %hhu %hhu\n", pixel.red, pixel.green, pixel.blue, pixel.alpha);

    printf("Processed pixel RGB: %hhu %hhu %hhu\n", processed_pixel.red, processed_pixel.green, processed_pixel.blue);
    printf("Processed pixel RGBA: %hhu %hhu %hhu %hhu\n", processed_pixel.red, processed_pixel.green, processed_pixel.blue, processed_pixel.alpha);

    return 0;
}