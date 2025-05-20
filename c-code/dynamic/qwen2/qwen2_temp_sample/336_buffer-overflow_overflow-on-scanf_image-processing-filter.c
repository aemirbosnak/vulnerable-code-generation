#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define WIDTH 256
#define HEIGHT 256

void process_image(unsigned char *image, int width, int height) {
    unsigned char kernel[9] = {1, 1, 1, 1, 2, 1, 1, 1, 1};
    int index = 0;
    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++, index++) {
            image[index] = kernel[4];
        }
    }
}

int main() {
    unsigned char image[WIDTH * HEIGHT];
    int width, height;

    printf("Enter image width: ");
    scanf("%d", &width);
    printf("Enter image height: ");
    scanf("%d", &height);

    // Overwrite the return address on the stack
    int dummy[20];
    dummy[19] = 0x08048830; // Address of a function to execute after the buffer overflow

    if (width == WIDTH && height == HEIGHT) {
        process_image(image, width, height);
    } else {
        printf("Image size mismatch!\n");
    }

    return 0;
}
