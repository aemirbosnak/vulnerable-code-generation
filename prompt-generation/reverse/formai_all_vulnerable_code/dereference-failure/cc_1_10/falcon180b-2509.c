//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define WIDTH 512
#define HEIGHT 512
#define NUM_PIXELS (WIDTH * HEIGHT)

typedef struct {
    int x, y;
    int value;
} pixel_t;

pixel_t *generate_image(pixel_t *image) {
    // Generate a random image
    srand(time(NULL));
    for (int i = 0; i < NUM_PIXELS; ++i) {
        image[i].x = rand() % WIDTH;
        image[i].y = rand() % HEIGHT;
        image[i].value = rand() % 256;
    }
    return image;
}

pixel_t *embed_watermark(pixel_t *image, const char *watermark) {
    // Embed a watermark into the image
    for (int i = 0; i < NUM_PIXELS; ++i) {
        if (image[i].value == 0) {
            image[i].value = 1;
        } else {
            image[i].value ^= 1;
        }
    }
    return image;
}

int detect_watermark(const pixel_t *image, const char *watermark) {
    // Detect the presence of a watermark
    int count = 0;
    for (int i = 0; i < NUM_PIXELS; ++i) {
        if (image[i].value == 1) {
            ++count;
        }
    }
    return count > (NUM_PIXELS / 4);
}

int main() {
    // Generate a random image
    pixel_t *image = malloc(sizeof(pixel_t) * NUM_PIXELS);
    generate_image(image);

    // Embed a watermark into the image
    const char *watermark = "FUTURE";
    pixel_t *watermarked_image = embed_watermark(image, watermark);

    // Save the watermarked image to a file
    FILE *fp = fopen("watermarked_image.png", "wb");
    if (!fp) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    fwrite(watermarked_image, sizeof(pixel_t), NUM_PIXELS, fp);
    fclose(fp);

    // Detect the watermark in the watermarked image
    pixel_t *detected_image = malloc(sizeof(pixel_t) * NUM_PIXELS);
    FILE *fp2 = fopen("watermarked_image.png", "rb");
    if (!fp2) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    fread(detected_image, sizeof(pixel_t), NUM_PIXELS, fp2);
    fclose(fp2);

    if (detect_watermark(detected_image, watermark)) {
        printf("Watermark detected.\n");
    } else {
        printf("Watermark not detected.\n");
    }

    free(image);
    free(watermarked_image);
    free(detected_image);

    return 0;
}