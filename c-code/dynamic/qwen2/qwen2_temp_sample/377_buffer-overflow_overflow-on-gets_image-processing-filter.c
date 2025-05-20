#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define FILTER_SIZE 256

void applyFilter(char *inputImage, char *outputImage) {
    int width = *(int *)inputImage;
    int height = *(int *)(inputImage + sizeof(int));
    int size = width * height;

    // Simulate a simple filter operation
    for (int i = 0; i < size; i++) {
        outputImage[i] = inputImage[i];
    }
}

int main() {
    char *inputImage = malloc(FILTER_SIZE);
    char *outputImage = malloc(FILTER_SIZE);

    if (!inputImage || !outputImage) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    printf("Enter image data: ");
    gets(inputImage);  // This is unsafe

    applyFilter(inputImage, outputImage);

    printf("Filtered image saved to outputImage\n");

    free(inputImage);
    free(outputImage);

    return 0;
}
