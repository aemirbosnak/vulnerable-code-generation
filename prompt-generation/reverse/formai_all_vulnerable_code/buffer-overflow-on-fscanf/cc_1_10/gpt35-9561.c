//FormAI DATASET v1.0 Category: Image compression ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BLOCK_SIZE 8

static unsigned char img_in[512][512][4];
static unsigned char img_out[512][512][4];

void compress_image(unsigned char* img_in, unsigned char* img_out, int width, int height) {
    unsigned char R, G, B;
    int Y, U, V;

    for (int h = 0; h < height; h += BLOCK_SIZE) {
        for (int w = 0; w < width; w += BLOCK_SIZE) {
            for (int i = h; i < h + BLOCK_SIZE; i++) {
                for (int j = w; j < w + BLOCK_SIZE; j++) {
                    R = *(img_in + i * width * 4 + j * 4);
                    G = *(img_in + i * width * 4 + j * 4 + 1);
                    B = *(img_in + i * width * 4 + j * 4 + 2);

                    Y = (66 * R + 129 * G + 25 * B + 128) >> 8 + 16;
                    U = (-38 * R - 74 * G + 112 * B + 128) >> 8 + 128;
                    V = (112 * R - 94 * G - 18 * B + 128) >> 8 + 128;

                    *(img_out + i * width * 4 + j * 4)     = Y;
                    *(img_out + i * width * 4 + j * 4 + 1) = U;
                    *(img_out + i * width * 4 + j * 4 + 2) = V;
                    *(img_out + i * width * 4 + j * 4 + 3) = *(img_in + i * width * 4 + j * 4 + 3);
                }
            }
        }
    }
}

void decompress_image(unsigned char* img_in, unsigned char* img_out, int width, int height) {
    unsigned char R, G, B;
    int Y, U, V;

    for (int h = 0; h < height; h += BLOCK_SIZE) {
        for (int w = 0; w < width; w += BLOCK_SIZE) {
            for (int i = h; i < h + BLOCK_SIZE; i++) {
                for (int j = w; j < w + BLOCK_SIZE; j++) {
                    Y = *(img_in + i * width * 4 + j * 4);
                    U = *(img_in + i * width * 4 + j * 4 + 1);
                    V = *(img_in + i * width * 4 + j * 4 + 2);

                    R = (298 * Y + 409 * V + 128) >> 8 - 16;
                    G = (298 * Y - 100 * U - 208 * V + 128) >> 8 - 16;
                    B = (298 * Y + 516 * U + 128) >> 8 - 16;

                    *(img_out + i * width * 4 + j * 4)     = R;
                    *(img_out + i * width * 4 + j * 4 + 1) = G;
                    *(img_out + i * width * 4 + j * 4 + 2) = B;
                    *(img_out + i * width * 4 + j * 4 + 3) = *(img_in + i * width * 4 + j * 4 + 3);
                }
            }
        }
    }
}

bool compare_images(unsigned char* img1, unsigned char* img2, int width, int height) {
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            for (int c = 0; c < 3; c++) {
                if (*(img1 + h * width * 4 + w * 4 + c) != *(img2 + h * width * 4 + w * 4 + c)) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    FILE* fp;
    int WIDTH = 0, HEIGHT = 0;
    fp = fopen("sample_img.ppm", "rb");

    if (fp) {
        char header[4];
        fscanf(fp, "%s", header);

        while (*(header + 1)) {
            fscanf(fp, "%s", header);
        }

        fscanf(fp, "%d %d", &WIDTH, &HEIGHT);

        while (fgetc(fp) != '\n');

        fread(img_in, 1, sizeof(img_in), fp);
        fclose(fp);

        printf("Image loaded\n");

        compress_image((unsigned char*)img_in, (unsigned char*)img_out, WIDTH, HEIGHT);
        decompress_image((unsigned char*)img_out, (unsigned char*)img_in, WIDTH, HEIGHT);

        printf("Image compressed and decompressed\n");

        if (compare_images((unsigned char*)img_in, (unsigned char*)img_out, WIDTH, HEIGHT)) {
            printf("Images are the same\n");
        } else {
            printf("Images are not the same\n");
        }
    } else {
        printf("Unable to open file\n");
    }

    return 0;
}