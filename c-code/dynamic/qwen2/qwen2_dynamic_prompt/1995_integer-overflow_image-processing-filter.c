#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 1024
#define HEIGHT 768

void apply_filter(unsigned char *image) {
    int i, j;
    unsigned char *output = (unsigned char *)malloc(WIDTH * HEIGHT * sizeof(unsigned char));
    
    if (!output) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int index = i * WIDTH + j;
            output[index] = image[index];
        }
    }

    // Integer overflow vulnerability
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int index = i * WIDTH + j;
            output[index] += 256; // This will cause an overflow for values greater than 239
        }
    }

    // Copy back to original image buffer
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int index = i * WIDTH + j;
            image[index] = output[index];
        }
    }

    free(output);
}

int main() {
    unsigned char *image = (unsigned char *)malloc(WIDTH * HEIGHT * sizeof(unsigned char));
    
    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize image with some values
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i] = i % 256;
    }

    apply_filter(image);

    // Print first 10 pixels for demonstration
    printf("First 10 pixels after applying filter:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", image[i]);
    }
    printf("\n");

    free(image);
    return 0;
}
