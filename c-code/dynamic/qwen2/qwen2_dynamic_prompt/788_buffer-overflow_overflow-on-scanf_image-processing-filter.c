#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1024

typedef struct {
    int width;
    int height;
    unsigned char pixels[MAX_IMAGE_SIZE * MAX_IMAGE_SIZE];
} Image;

void process_image(Image *img) {
    printf("Processing image with dimensions %dx%d\n", img->width, img->height);
    // Simulate some image processing operations
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i] = img->pixels[i] + 10;
    }
}

int main() {
    Image img;
    printf("Enter image width: ");
    scanf("%d", &img.width);
    printf("Enter image height: ");
    scanf("%d", &img.height);

    if (img.width <= 0 || img.height <= 0 || img.width > MAX_IMAGE_SIZE || img.height > MAX_IMAGE_SIZE) {
        fprintf(stderr, "Invalid image dimensions\n");
        return 1;
    }

    printf("Enter pixel values:\n");
    for (int i = 0; i < img.width * img.height; i++) {
        scanf("%hhu", &img.pixels[i]);
    }

    process_image(&img);

    printf("Processed image saved to output.txt\n");
    FILE *output_file = fopen("output.txt", "wb");
    if (!output_file) {
        perror("Failed to open output file");
        return 1;
    }
    fwrite(img.pixels, sizeof(unsigned char), img.width * img.height, output_file);
    fclose(output_file);

    return 0;
}
