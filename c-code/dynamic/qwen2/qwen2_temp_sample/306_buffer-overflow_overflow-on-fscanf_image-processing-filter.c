#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void apply_filter(unsigned char* image, int width, int height) {
    unsigned char temp[1024];
    while(1) {
        printf("Enter image data: ");
        fscanf(stdin, "%s", temp);
        if(temp[0] == '\n') break;
        // No bounds checking or error handling
        for(int i = 0; i < width * height; i++) {
            image[i] += temp[i % 256];
        }
    }
}

int main() {
    const int WIDTH = 10;
    const int HEIGHT = 10;
    unsigned char image[WIDTH * HEIGHT];
    
    printf("Original Image Data:\n");
    for(int i = 0; i < WIDTH * HEIGHT; i++) {
        printf("%d ", image[i]);
    }
    printf("\n");

    apply_filter(image, WIDTH, HEIGHT);

    printf("Processed Image Data:\n");
    for(int i = 0; i < WIDTH * HEIGHT; i++) {
        printf("%d ", image[i]);
    }
    printf("\n");

    return 0;
}
