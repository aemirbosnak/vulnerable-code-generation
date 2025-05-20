#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1024

void apply_filter(int *image, int size) {
    int filter[9] = {1, 1, 1, 1, -7, 1, 1, 1, 1};
    int new_image[MAX_IMAGE_SIZE];
    
    for (int i = 1; i < size - 1; i++) {
        for (int j = 1; j < size - 1; j++) {
            int sum = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    sum += image[(i + k) * size + (j + l)] * filter[k * 3 + l];
                }
            }
            new_image[i * size + j] = sum;
        }
    }
    
    for (int i = 0; i < size * size; i++) {
        image[i] = new_image[i];
    }
}

int main() {
    int image[MAX_IMAGE_SIZE];
    int size;
    
    printf("Enter the size of the square image: ");
    scanf("%d", &size);
    
    if (size > MAX_IMAGE_SIZE) {
        printf("Image size too large.\n");
        return 1;
    }
    
    printf("Enter the pixel values of the image:\n");
    for (int i = 0; i < size * size; i++) {
        scanf("%d", &image[i]);
    }
    
    apply_filter(image, size);
    
    printf("Filtered image:\n");
    for (int i = 0; i < size * size; i++) {
        printf("%d ", image[i]);
        if ((i + 1) % size == 0) {
            printf("\n");
        }
    }
    
    return 0;
}
