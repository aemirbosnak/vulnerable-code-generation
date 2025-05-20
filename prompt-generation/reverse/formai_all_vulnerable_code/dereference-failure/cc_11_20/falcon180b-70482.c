//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int image_size, watermark_size, i, j, k, pixel_value, watermark_value;
    int **watermark, **image;

    printf("Enter the size of the image: ");
    scanf("%d", &image_size);

    printf("Enter the size of the watermark: ");
    scanf("%d", &watermark_size);

    image = (int **) malloc(image_size * sizeof(int *));
    watermark = (int **) malloc(watermark_size * sizeof(int *));

    for (i = 0; i < image_size; i++) {
        image[i] = (int *) malloc(image_size * sizeof(int));
    }

    for (i = 0; i < watermark_size; i++) {
        watermark[i] = (int *) malloc(watermark_size * sizeof(int));
    }

    printf("Enter the image data: ");
    for (i = 0; i < image_size; i++) {
        for (j = 0; j < image_size; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    printf("Enter the watermark data: ");
    for (i = 0; i < watermark_size; i++) {
        for (j = 0; j < watermark_size; j++) {
            scanf("%d", &watermark[i][j]);
        }
    }

    for (i = 0; i < image_size; i++) {
        for (j = 0; j < image_size; j++) {
            pixel_value = image[i][j];
            watermark_value = watermark[i % watermark_size][j % watermark_size];

            if (pixel_value > watermark_value) {
                image[i][j] = pixel_value - watermark_value;
            } else {
                image[i][j] = pixel_value + watermark_value;
            }
        }
    }

    printf("Watermarked image data: ");
    for (i = 0; i < image_size; i++) {
        for (j = 0; j < image_size; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < image_size; i++) {
        free(image[i]);
    }
    free(image);

    for (i = 0; i < watermark_size; i++) {
        free(watermark[i]);
    }
    free(watermark);

    return 0;
}