//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void apply_watermark(unsigned char *img, unsigned char *watermark, int w, int h, int i, int j) {
    int k = w * h;
    for (int p = 0; p < k; p++) {
        unsigned char pixel = img[p];
        pixel = pixel & ~(0b10000000 << (i * 8));
        pixel |= watermark[p] << (i * 8);
        img[p] = pixel;
    }
}

int main() {
    FILE *in_img, *out_img;
    char img_name[100], watermark_name[100], out_name[100];
    unsigned char *img, *watermark;

    printf("Enter the name of the original image file: ");
    scanf("%s", img_name);
    in_img = fopen(img_name, "rb");
    if (in_img == NULL) {
        printf("Error: Could not open %s for reading.\n", img_name);
        return 1;
    }

    printf("Enter the name of the watermark image file: ");
    scanf("%s", watermark_name);
    watermark = fread(NULL, 1, 0, in_img);

    printf("Enter the name of the output image file: ");
    scanf("%s", out_name);
    out_img = fopen(out_name, "wb");
    if (out_img == NULL) {
        printf("Error: Could not open %s for writing.\n", out_name);
        return 1;
    }

    int w = 0, h = 0;
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            w = w | (watermark[i * 8 + j] & 0b10000000) << (i * 8);
            h = h | (watermark[i * 8 + j] & 0b10000000) << (i * 8);
        }
    }
    w = w | (watermark[i * 8 + j] & 0b10000000) << (i * 8);
    h = h | (watermark[i * 8 + j] & 0b10000000) << (i * 8);

    img = malloc(w * h);
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            img[i * w + j] = watermark[i * 8 + j];
        }
    }

    apply_watermark(img, watermark, w, h, 0, 0);
    fwrite(img, 1, w * h, out_img);

    free(img);
    fclose(in_img);
    fclose(out_img);

    printf("Watermarking complete. Image saved as %s.\n", out_name);

    return 0;
}