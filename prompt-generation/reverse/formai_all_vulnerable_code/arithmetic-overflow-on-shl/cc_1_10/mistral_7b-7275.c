//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE 10

typedef struct {
    uint8_t color;
    int16_t x, y;
} pixel;

pixel pixels[SIZE][SIZE];

void print_binary(uint32_t value) {
    uint32_t i, mask;

    printf("%lX:\t", value);
    for (i = 31; i >= 0; i--) {
        mask = 1 << i;
        printf("%d", (value & mask) >> i);
    }
    printf("\n");
}

void set_pixel(int x, int y, uint8_t color) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) return;
    pixels[y][x].color = color;
}

uint8_t get_pixel_color(int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) return 0;
    return pixels[y][x].color;
}

void fill_square(int x, int y, uint8_t color) {
    int i, j;

    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) return;

    for (i = y; i <= y + 2; i++) {
        for (j = x; j <= x + 2; j++) {
            set_pixel(j, i, color);
        }
    }
}

int main() {
    uint32_t random_number;
    uint8_t color = 0x0F; // blue
    int x, y;

    // Initialize random number generator
    srand(time(NULL));

    // Set initial pixel
    set_pixel(5, 5, color);

    // Print binary representation of color
    printf("Color: ");
    print_binary(color);

    // Fill a 3x3 square with the given color
    fill_square(5, 5, color);

    // Print binary representation of pixels in the square
    printf("\nSquare content:\n");
    for (y = 5; y <= 7; y++) {
        for (x = 5; x <= 7; x++) {
            printf("(%d, %d):\t", x, y);
            print_binary(get_pixel_color(x, y));
        }
        printf("\n");
    }

    // Generate a random number and print its binary representation
    random_number = rand();
    printf("\nRandom number: %d\n", random_number);
    print_binary(random_number);

    return 0;
}