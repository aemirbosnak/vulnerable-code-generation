//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COLOR 255
#define MIN_COLOR 0

typedef struct {
   unsigned char R;
   unsigned char G;
   unsigned char B;
} Pixel;

typedef struct {
   Pixel **row;
   int width;
   int height;
} Image;

Image *create_image(int width, int height) {
   Image *image = malloc(sizeof(Image));
   Pixel **row = malloc(sizeof(Pixel*) * height);
   
   for (int i = 0; i < height; i++) {
      row[i] = malloc(sizeof(Pixel) * width);
      for (int j = 0; j < width; j++) {
         row[i][j].R = 0;
         row[i][j].G = 0;
         row[i][j].B = 0;
      }
   }
   
   image->row = row;
   image->width = width;
   image->height = height;
   return image;
}

void free_image(Image *image) {
   for (int i = 0; i < image->height; i++) {
      free(image->row[i]);
   }
   free(image->row);
   free(image);
}

Image *read_ppm(const char *filename) {
   FILE *file = fopen(filename, "rb");
   char format[3];
   int width, height, max_color;
   
   fscanf(file, "%s\n", format);
   fscanf(file, "%d %d\n", &width, &height);
   fscanf(file, "%d\n", &max_color);
   
   Image *image = create_image(width, height);
   
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         fscanf(file, "%c%c%c", &image->row[i][j].R, &image->row[i][j].G, &image->row[i][j].B);
      }
   }
   fclose(file);
   return image;
}

void write_ppm(const char *filename, Image *image) {
   FILE *file = fopen(filename, "wb");
   fprintf(file, "P6\n");
   fprintf(file, "%d %d\n", image->width, image->height);
   fprintf(file, "%d\n", MAX_COLOR);
   
   for (int i = 0; i < image->height; i++) {
      for (int j = 0; j < image->width; j++) {
         fwrite(&image->row[i][j].R, sizeof(unsigned char), 1, file);
         fwrite(&image->row[i][j].G, sizeof(unsigned char), 1, file);
         fwrite(&image->row[i][j].B, sizeof(unsigned char), 1, file);
      }
   }
   fclose(file);
}

void flip_image(Image *image) {
   for (int i = 0; i < image->height / 2; i++) {
      for (int j = 0; j < image->width; j++) {
         Pixel temp = image->row[i][j];
         image->row[i][j] = image->row[image->height - 1 - i][j];
         image->row[image->height - 1 - i][j] = temp;
      }
   }
}

void adjust_brightness(Image *image, int brightness) {
   for (int i = 0; i < image->height; i++) {
      for (int j = 0; j < image->width; j++) {
         int R = (int)(image->row[i][j].R) + brightness;
         int G = (int)(image->row[i][j].G) + brightness;
         int B = (int)(image->row[i][j].B) + brightness;
         
         if (R > MAX_COLOR) {
            R = MAX_COLOR;
         }
         if (R < MIN_COLOR) {
            R = MIN_COLOR;
         }
         if (G > MAX_COLOR) {
            G = MAX_COLOR;
         }
         if (G < MIN_COLOR) {
            G = MIN_COLOR;
         }
         if (B > MAX_COLOR) {
            B = MAX_COLOR;
         }
         if (B < MIN_COLOR) {
            B = MIN_COLOR;
         }
         image->row[i][j].R = (unsigned char)R;
         image->row[i][j].G = (unsigned char)G;
         image->row[i][j].B = (unsigned char)B;
      }
   }
}

void adjust_contrast(Image *image, double contrast) {
   double F = (259 * (contrast + 255)) / (255 * (259 - contrast));
   
   for (int i = 0; i < image->height; i++) {
      for (int j = 0; j < image->width; j++) {
         double R = (double)(image->row[i][j].R);
         double G = (double)(image->row[i][j].G);
         double B = (double)(image->row[i][j].B);

         R = F * (R - 128) + 128;
         G = F * (G - 128) + 128;
         B = F * (B - 128) + 128;
         
         if (R > MAX_COLOR) {
            R = MAX_COLOR;
         }
         if (R < MIN_COLOR) {
            R = MIN_COLOR;
         }
         if (G > MAX_COLOR) {
            G = MAX_COLOR;
         }
         if (G < MIN_COLOR) {
            G = MIN_COLOR;
         }
         if (B > MAX_COLOR) {
            B = MAX_COLOR;
         }
         if (B < MIN_COLOR) {
            B = MIN_COLOR;
         }
         image->row[i][j].R = (unsigned char)round(R);
         image->row[i][j].G = (unsigned char)round(G);
         image->row[i][j].B = (unsigned char)round(B);
      }
   }
}

int main(int argc, char **argv) {
   if (argc < 2) {
      printf("Usage: %s [input file] [output file] [flip] [brightness] [contrast]\n", argv[0]);
      exit(1);
   }
   
   Image *image = read_ppm(argv[1]);
   
   if (argc >= 4 && strcmp(argv[3], "flip") == 0) {
      flip_image(image);
   }
   
   if (argc >= 5) {
      int brightness = atoi(argv[4]);
      adjust_brightness(image, brightness);
   }
   
   if (argc >= 6) {
      double contrast = atof(argv[5]);
      adjust_contrast(image, contrast);
   }
   
   write_ppm(argv[2], image);
   free_image(image);
   return 0;
}