//FormAI DATASET v1.0 Category: Image compression ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BLOCK_SIZE 8

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} RGB;

typedef struct {
    int width;
    int height;
    RGB *pixels;
} Image;

static const double Q[BLOCK_SIZE][BLOCK_SIZE] = {
    {16, 11, 10, 16, 24, 40, 51, 61},
    {12, 12, 14, 19, 26, 58, 60, 55},
    {14, 13, 16, 24, 40, 57, 69, 56},
    {14, 17, 22, 29, 51, 87, 80, 62},
    {18, 22, 37, 56, 68, 109, 103, 77},
    {24, 35, 55, 64, 81, 104, 113, 92},
    {49, 64, 78, 87, 103, 121, 120, 101},
    {72, 92, 95, 98, 112, 100, 103, 99}
};

void write_compressed_file(const char *filename, unsigned char *data, size_t size) {
    FILE *fp = fopen(filename, "wb");
    if (fp) {
        fwrite(data, 1, size, fp);
        fclose(fp);
        printf("Saved compressed file to %s\n", filename);
    } else {
        printf("Error saving compressed file\n");
    }
}

unsigned char *compress_image(Image *image, size_t *size) {
    int i, j, k, l, y, x;
    int h_blocks, v_blocks;
    double dct[BLOCK_SIZE][BLOCK_SIZE];
    double temp[BLOCK_SIZE][BLOCK_SIZE];
    double quantized[BLOCK_SIZE][BLOCK_SIZE];
    double idct[BLOCK_SIZE][BLOCK_SIZE];
    double factor, sum_r, sum_g, sum_b;
    unsigned char *output, *p;
    RGB *pixels = image->pixels;
    size_t output_size = 0;

    h_blocks = ceil(image->width / (float)BLOCK_SIZE);
    v_blocks = ceil(image->height / (float)BLOCK_SIZE);

    output_size = 2 + h_blocks * v_blocks * 3 * BLOCK_SIZE * BLOCK_SIZE; // header size + data size
    output = (unsigned char *) malloc(output_size);

    if (!output) {
        printf("Error allocating memory for compressed image\n");
        return NULL;
    }

    p = output;
    *p++ = (unsigned char)((image->width >> 8) & 0xFF);
    *p++ = (unsigned char)(image->width & 0xFF);
    *p++ = (unsigned char)((image->height >> 8) & 0xFF);
    *p++ = (unsigned char)(image->height & 0xFF);

    for (i = 0; i < v_blocks; i++) {
        for (j = 0; j < h_blocks; j++) {
            for (k = 0; k < BLOCK_SIZE; k++) {
                for (l = 0; l < BLOCK_SIZE; l++) {
                    x = (j * BLOCK_SIZE) + l;
                    y = (i * BLOCK_SIZE) + k;
                    if (x < image->width && y < image->height) {
                        dct[k][l] = 0;
                        for (y = 0; y < BLOCK_SIZE; y++) {
                            for (x = 0; x < BLOCK_SIZE; x++) {
                                factor = ((x == 0) ? 1 / sqrt(BLOCK_SIZE) : sqrt(2) / sqrt(BLOCK_SIZE)) * ((y == 0) ? 1 / sqrt(BLOCK_SIZE) : sqrt(2) / sqrt(BLOCK_SIZE));
                                dct[k][l] += factor * pixels[(i * BLOCK_SIZE + y) * image->width + (j * BLOCK_SIZE + x)].r * Q[y][x];
                            }
                        }
                    } else {
                        dct[k][l] = 0;
                    }
                }
            }

            factor = pow(2, 3);
            for (k = 0; k < BLOCK_SIZE; k++) {
                for (l = 0; l < BLOCK_SIZE; l++) {
                    quantized[k][l] = round(dct[k][l] / factor);
                }
            }

            memcpy(temp, quantized, sizeof(temp));

            factor = pow(2, 3);
            for (k = 0; k < BLOCK_SIZE; k++) {
                for (l = 0; l < BLOCK_SIZE; l++) {
                    idct[k][l] = 0;
                    for (y = 0; y < BLOCK_SIZE; y++) {
                        for (x = 0; x < BLOCK_SIZE; x++) {
                            factor = ((x == 0) ? 1 / sqrt(BLOCK_SIZE) : sqrt(2) / sqrt(BLOCK_SIZE)) * ((y == 0) ? 1 / sqrt(BLOCK_SIZE) : sqrt(2) / sqrt(BLOCK_SIZE));
                            idct[k][l] += factor * temp[y][x] * Q[y][x];
                        }
                    }
                    idct[k][l] = round(idct[k][l]);
                }
            }

            sum_r = sum_g = sum_b = 0;
            for (k = 0; k < BLOCK_SIZE; k++) {
                for (l = 0; l < BLOCK_SIZE; l++) {
                    x = (j * BLOCK_SIZE) + l;
                    y = (i * BLOCK_SIZE) + k;
                    if (x < image->width && y < image->height) {
                        sum_r += (idct[k][l] * Q[k][l] + 128) * ((double)pixels[y * image->width + x].r / 255.0);
                        sum_g += (idct[k][l] * Q[k][l] + 128) * ((double)pixels[y * image->width + x].g / 255.0);
                        sum_b += (idct[k][l] * Q[k][l] + 128) * ((double)pixels[y * image->width + x].b / 255.0);
                    }
                }
            }

            *p++ = (unsigned char)(round(sum_r / (BLOCK_SIZE * BLOCK_SIZE)));
            *p++ = (unsigned char)(round(sum_g / (BLOCK_SIZE * BLOCK_SIZE)));
            *p++ = (unsigned char)(round(sum_b / (BLOCK_SIZE * BLOCK_SIZE)));
        }
    }

    *size = output_size;
    return output;
}

Image *decompress_image(unsigned char *data) {
    int i, j, k, l, y, x;
    int h_blocks, v_blocks;
    int width, height;
    double dct[BLOCK_SIZE][BLOCK_SIZE];
    double temp[BLOCK_SIZE][BLOCK_SIZE];
    double quantized[BLOCK_SIZE][BLOCK_SIZE];
    double idct[BLOCK_SIZE][BLOCK_SIZE];
    double factor, sum_r, sum_g, sum_b;
    unsigned char *p = data;
    Image *image;

    width = (*p++ << 8) | *p++;
    height = (*p++ << 8) | *p++;

    h_blocks = ceil(width / (float)BLOCK_SIZE);
    v_blocks = ceil(height / (float)BLOCK_SIZE);

    image = (Image *) malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = (RGB *) malloc(width * height * sizeof(RGB));

    if (!image->pixels) {
        printf("Error allocating memory for decompressed image\n");
        return NULL;
    }

    for (i = 0; i < v_blocks; i++) {
        for (j = 0; j < h_blocks; j++) {
            for (k = 0; k < BLOCK_SIZE; k++) {
                for (l = 0; l < BLOCK_SIZE; l++) {
                    x = (j * BLOCK_SIZE) + l;
                    y = (i * BLOCK_SIZE) + k;

                    if (x < width && y < height) {
                        dct[k][l] = 0;
                        for (y = 0; y < BLOCK_SIZE; y++) {
                            for (x = 0; x < BLOCK_SIZE; x++) {
                                factor = ((x == 0) ? 1 / sqrt(BLOCK_SIZE) : sqrt(2) / sqrt(BLOCK_SIZE)) * ((y == 0) ? 1 / sqrt(BLOCK_SIZE) : sqrt(2) / sqrt(BLOCK_SIZE));
                                quantized[y][x] = (double)(*p++ - 128) / pow(2, 3);
                                dct[k][l] += factor * quantized[y][x] * Q[k][l];
                            }
                        }

                        memcpy(temp, dct, sizeof(temp));

                        factor = pow(2, 3);
                        for (k = 0; k < BLOCK_SIZE; k++) {
                            for (l = 0; l < BLOCK_SIZE; l++) {
                                idct[k][l] = 0;
                                for (y = 0; y < BLOCK_SIZE; y++) {
                                    for (x = 0; x < BLOCK_SIZE; x++) {
                                        factor = ((x == 0) ? 1 / sqrt(BLOCK_SIZE) : sqrt(2) / sqrt(BLOCK_SIZE)) * ((y == 0) ? 1 / sqrt(BLOCK_SIZE) : sqrt(2) / sqrt(BLOCK_SIZE));
                                        idct[k][l] += factor * temp[y][x] * Q[y][x];
                                    }
                                }
                                idct[k][l] = round(idct[k][l]);
                            }
                        }

                        sum_r = sum_g = sum_b = 0;
                        for (k = 0; k < BLOCK_SIZE; k++) {
                            for (l = 0; l < BLOCK_SIZE; l++) {
                                x = (j * BLOCK_SIZE) + l;
                                y = (i * BLOCK_SIZE) + k;
                                if (x < width && y < height) {
                                    sum_r += (idct[k][l] * Q[k][l] + 128) * ((double)(*p++) / 255.0);
                                    sum_g += (idct[k][l] * Q[k][l] + 128) * ((double)(*p++) / 255.0);
                                    sum_b += (idct[k][l] * Q[k][l] + 128) * ((double)(*p++) / 255.0);
                                }
                            }
                        }

                        image->pixels[y * width + x].r = (unsigned char)round(sum_r);
                        image->pixels[y * width + x].g = (unsigned char)round(sum_g);
                        image->pixels[y * width + x].b = (unsigned char)round(sum_b);
                    }
                }
            }
        }
    }

    return image;
}

int main() {
    Image image;
    unsigned char *compressed_data;
    size_t compressed_size;
    Image *decompressed_image;

    // read image
    FILE *fp = fopen("input_image.rgb", "rb");
    if (!fp) {
        printf("Error opening input file\n");
        return 1;
    }

    image.width = 256;
    image.height = 256;
    image.pixels = (RGB *) malloc(256 * 256 * sizeof(RGB));

    if (!image.pixels) {
        printf("Error allocating memory for input image\n");
        return 1;
    }

    fread(image.pixels, sizeof(RGB), image.width * image.height, fp);
    fclose(fp);

    // compress image
    compressed_data = compress_image(&image, &compressed_size);

    // write compressed file
    write_compressed_file("compressed.dat", compressed_data, compressed_size);

    // decompress image
    decompressed_image = decompress_image(compressed_data);

    // save decompressed image
    fp = fopen("output_image.rgb", "wb");
    if (!fp) {
        printf("Error opening output file\n");
        return 1;
    }

    fwrite(decompressed_image->pixels, sizeof(RGB), decompressed_image->width * decompressed_image->height, fp);
    fclose(fp);

    // cleanup
    free(compressed_data);
    free(image.pixels);
    free(decompressed_image->pixels);
    free(decompressed_image);

    return 0;
}