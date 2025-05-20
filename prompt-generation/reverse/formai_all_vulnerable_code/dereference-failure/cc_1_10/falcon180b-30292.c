//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512
#define WATERMARK_WIDTH 128
#define WATERMARK_HEIGHT 128

void add_watermark(unsigned char *image, int width, int height, unsigned char *watermark, int wm_width, int wm_height)
{
    int i, j, k;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            double alpha = (double)image[i * width + j] / 255.0;
            for (k = 0; k < wm_height; k++) {
                int x = j + k * (wm_width - 1) / (height - 1);
                if (x >= 0 && x < width) {
                    image[i * width + j] += watermark[k * wm_width + x] * alpha;
                }
            }
        }
    }
}

int main()
{
    unsigned char *image, *watermark;
    int width, height, wm_width, wm_height;

    image = malloc(IMAGE_WIDTH * IMAGE_HEIGHT * sizeof(unsigned char));
    watermark = malloc(WATERMARK_WIDTH * WATERMARK_HEIGHT * sizeof(unsigned char));

    FILE *fp_image = fopen("image.bmp", "rb");
    fread(image, IMAGE_WIDTH * IMAGE_HEIGHT, sizeof(unsigned char), fp_image);
    fclose(fp_image);

    fp_image = fopen("watermark.bmp", "rb");
    fread(watermark, WATERMARK_WIDTH * WATERMARK_HEIGHT, sizeof(unsigned char), fp_image);
    fclose(fp_image);

    add_watermark(image, IMAGE_WIDTH, IMAGE_HEIGHT, watermark, WATERMARK_WIDTH, WATERMARK_HEIGHT);

    fp_image = fopen("watermarked_image.bmp", "wb");
    fwrite(image, IMAGE_WIDTH * IMAGE_HEIGHT, sizeof(unsigned char), fp_image);
    fclose(fp_image);

    free(image);
    free(watermark);

    return 0;
}