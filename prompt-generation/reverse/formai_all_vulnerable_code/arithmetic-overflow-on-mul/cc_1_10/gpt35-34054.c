//FormAI DATASET v1.0 Category: Image Editor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} pixel;

typedef struct {
  int width;
  int height;
  pixel *pixels;
} image;

void load_image(image *img, char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    printf("Unable to open %s for reading\n", filename);
    return;
  }
  char buffer[16];
  fgets(buffer, sizeof(buffer), fp);
  if (strcmp(buffer, "P6\n") != 0) {
    printf("Invalid file format\n");
    fclose(fp);
    return;
  }
  fgets(buffer, sizeof(buffer), fp);
  sscanf(buffer, "%d %d\n", &img->width, &img->height);
  fgets(buffer, sizeof(buffer), fp);
  if (strcmp(buffer, "255\n") != 0) {
    printf("Invalid file format\n");
    fclose(fp);
    return;
  }
  img->pixels = (pixel *)malloc(sizeof(pixel) * img->width * img->height);
  fread(img->pixels, sizeof(pixel), img->width * img->height, fp);
  fclose(fp);
}

void save_image(image *img, char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (!fp) {
    printf("Unable to open %s for writing\n", filename);
    return;
  }
  fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);
  fwrite(img->pixels, sizeof(pixel), img->width * img->height, fp);
  fclose(fp);
}

void flip_image(image *img) {
  pixel tmp;
  for (int y = 0; y < img->height / 2; y++) {
    for (int x = 0; x < img->width; x++) {
      tmp = img->pixels[y * img->width + x];
      img->pixels[y * img->width + x] = img->pixels[(img->height - 1 - y) * img->width + x];
      img->pixels[(img->height - 1 - y) * img->width + x] = tmp;
    }
  }
}

void grayscale_image(image *img) {
  for (int i = 0; i < img->width * img->height; i++) {
    int gray = (img->pixels[i].r + img->pixels[i].g + img->pixels[i].b) / 3;
    img->pixels[i].r = img->pixels[i].g = img->pixels[i].b = gray;
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <image file>\n", argv[0]);
    return 0;
  }
  image img;
  load_image(&img, argv[1]);
  flip_image(&img);
  grayscale_image(&img);
  save_image(&img, "output.ppm");
  free(img.pixels);
  return 0;
}