//FormAI DATASET v1.0 Category: Image compression ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define BLOCK_SIZE 8 // block size (8x8) to split the image
#define Q_FACTOR 50 // quality factor for compression

int main(void) {
  int img_width, img_height;
  uint8_t *img_data = NULL;

  // read input image
  FILE *fp = fopen("input_image.raw", "rb");
  if (fp == NULL) {
    printf("Error: failed to open input image file\n");
    exit(EXIT_FAILURE);
  }

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  img_width = sqrt(size); // assume square input image
  img_height = img_width;

  img_data = (uint8_t*) malloc(size * sizeof(uint8_t));

  fread(img_data, sizeof(uint8_t), size, fp);
  fclose(fp);

  // compress image
  int num_blocks = img_width / BLOCK_SIZE;

  for (int i = 0; i < num_blocks; i++) {
    for (int j = 0; j < num_blocks; j++) {
      int block_start = i * BLOCK_SIZE * img_width + j * BLOCK_SIZE;
      int block_end = block_start + (BLOCK_SIZE * img_width) + BLOCK_SIZE;

      // apply Discrete Cosine Transform (DCT) to block
      float f[BLOCK_SIZE][BLOCK_SIZE];
      for (int u = 0; u < BLOCK_SIZE; u++) {
        for (int v = 0; v < BLOCK_SIZE; v++) {
          float sum = 0.0;
          for (int x = 0; x < BLOCK_SIZE; x++) {
            for (int y = 0; y < BLOCK_SIZE; y++) {
              sum += (float) img_data[block_start + x * img_width + y] * cos((2 * x + 1) * u * M_PI / 16.0) * cos((2 * y + 1) * v * M_PI / 16.0);
            }
          }
          sum *= (1.0 / sqrt(2.0 * BLOCK_SIZE)) * (u == 0 ? 1.0 / sqrt(2.0) : 1.0) * (v == 0 ? 1.0 / sqrt(2.0) : 1.0);
          f[u][v] = sum;
        }
      }

      // quantize DCT coefficients
      int q_table[BLOCK_SIZE][BLOCK_SIZE] = {{16, 11, 10, 16, 24, 40, 51, 61},
                                             {12, 12, 14, 19, 26, 58, 60, 55},
                                             {14, 13, 16, 24, 40, 57, 69, 56},
                                             {14, 17, 22, 29, 51, 87, 80, 62},
                                             {18, 22, 37, 56, 68, 109, 103, 77},
                                             {24, 35, 55, 64, 81, 104, 113, 92},
                                             {49, 64, 78, 87, 103, 121, 120, 101},
                                             {72, 92, 95, 98, 112, 100, 103, 99}};

      for (int u = 0; u < BLOCK_SIZE; u++) {
        for (int v = 0; v < BLOCK_SIZE; v++) {
          int q = q_table[u][v] * Q_FACTOR;
          int s = (int) round(f[u][v] / q);
          f[u][v] = q * s;
        }
      }

      // apply Inverse Discrete Cosine Transform (IDCT) to block
      uint8_t img_block[BLOCK_SIZE][BLOCK_SIZE];
      for (int x = 0; x < BLOCK_SIZE; x++) {
        for (int y = 0; y < BLOCK_SIZE; y++) {
          float sum = 0.0;
          for (int u = 0; u < BLOCK_SIZE; u++) {
            for (int v = 0; v < BLOCK_SIZE; v++) {
              float c_u = u == 0 ? 1.0 / sqrt(2.0) : 1.0;
              float c_v = v == 0 ? 1.0 / sqrt(2.0) : 1.0;
              sum += c_u * c_v * f[u][v] * cos((2 * x + 1) * u * M_PI / 16.0) * cos((2 * y + 1) * v * M_PI / 16.0);
            }
          }
          sum *= 0.25;
          img_block[x][y] = (uint8_t) round(sum);
        }
      }

      // store compressed block in output image
      for (int x = 0; x < BLOCK_SIZE; x++) {
        for (int y = 0; y < BLOCK_SIZE; y++) {
          int idx = (i * BLOCK_SIZE + x) * img_width + (j * BLOCK_SIZE + y);
          img_data[idx] = img_block[x][y];
        }
      }
    }
  }

  // write compressed image to file
  FILE *fout = fopen("output_image.raw", "wb");
  fwrite(img_data, sizeof(uint8_t), size, fout);
  fclose(fout);

  free(img_data);

  return 0;
}