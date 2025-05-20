//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Defines the number of bits in a watermark
#define WATERMARK_SIZE (8)

// Type definition for an image pixel
typedef struct {
   uint8_t red;
   uint8_t green;
   uint8_t blue;
   uint8_t alpha;
} Pixel;

// Function to embed a watermark into an image
void embed_watermark(Pixel* image, int width, int height, uint64_t watermark) {
   // Iterate over the image pixels
   for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
         // Get the pixel at the current position
         Pixel* pixel = &image[y * width + x];

         // Extract the least significant bit of each color channel
         uint8_t red_bit = pixel->red & 1;
         uint8_t green_bit = pixel->green & 1;
         uint8_t blue_bit = pixel->blue & 1;

         // Set the least significant bit of each color channel to the next bit of the watermark
         pixel->red = (pixel->red & ~1) | (watermark & 1);
         pixel->green = (pixel->green & ~1) | ((watermark >> 1) & 1);
         pixel->blue = (pixel->blue & ~1) | ((watermark >> 2) & 1);

         // Shift the watermark to the next bit
         watermark >>= 3;
      }
   }
}

// Function to extract a watermark from an image
uint64_t extract_watermark(Pixel* image, int width, int height) {
   // Initialize the watermark to 0
   uint64_t watermark = 0;

   // Iterate over the image pixels
   for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
         // Get the pixel at the current position
         Pixel* pixel = &image[y * width + x];

         // Extract the least significant bit of each color channel
         uint8_t red_bit = pixel->red & 1;
         uint8_t green_bit = pixel->green & 1;
         uint8_t blue_bit = pixel->blue & 1;

         // Shift the watermark to the next bit
         watermark <<= 3;

         // Set the next bit of the watermark to the extracted bit
         watermark |= (red_bit | green_bit | blue_bit);
      }
   }

   // Return the watermark
   return watermark;
}

// Function to read an image from a file
Pixel* read_image(char* filename, int* width, int* height) {
   // Open the image file
   FILE* file = fopen(filename, "rb");
   if (file == NULL) {
      printf("Error opening image file\n");
      return NULL;
   }

   // Read the image header
   uint16_t magic_number;
   fread(&magic_number, sizeof(uint16_t), 1, file);

   // Check if the image is a BMP file
   if (magic_number != 0x4D42) {
      printf("Error: Image is not a BMP file\n");
      fclose(file);
      return NULL;
   }

   // Skip the next 8 bytes of the header
   fseek(file, 8, SEEK_CUR);

   // Read the image width and height
   fread(width, sizeof(int), 1, file);
   fread(height, sizeof(int), 1, file);

   // Skip the rest of the header
   fseek(file, 28, SEEK_CUR);

   // Allocate memory for the image pixels
   Pixel* image = malloc(sizeof(Pixel) * (*width) * (*height));
   if (image == NULL) {
      printf("Error allocating memory for image pixels\n");
      fclose(file);
      return NULL;
   }

   // Read the image pixels
   fread(image, sizeof(Pixel), (*width) * (*height), file);

   // Close the image file
   fclose(file);

   // Return the image pixels
   return image;
}

// Function to write an image to a file
void write_image(char* filename, Pixel* image, int width, int height) {
   // Open the image file
   FILE* file = fopen(filename, "wb");
   if (file == NULL) {
      printf("Error opening image file\n");
      return;
   }

   // Write the image header
   uint16_t magic_number = 0x4D42;
   fwrite(&magic_number, sizeof(uint16_t), 1, file);

   // Skip the next 8 bytes of the header
   fseek(file, 8, SEEK_CUR);

   // Write the image width and height
   fwrite(&width, sizeof(int), 1, file);
   fwrite(&height, sizeof(int), 1, file);

   // Skip the rest of the header
   fseek(file, 28, SEEK_CUR);

   // Write the image pixels
   fwrite(image, sizeof(Pixel), width * height, file);

   // Close the image file
   fclose(file);
}

// Main function
int main(int argc, char** argv) {
   // Check if the user specified an input image file and an output image file
   if (argc != 3) {
      printf("Usage: %s <input_image> <output_image>\n", argv[0]);
      return 1;
   }

   // Read the input image
   int width;
   int height;
   Pixel* image = read_image(argv[1], &width, &height);
   if (image == NULL) {
      return 1;
   }

   // Generate a watermark
   uint64_t watermark = 0x123456789ABCDEF0;

   // Embed the watermark into the image
   embed_watermark(image, width, height, watermark);

   // Write the watermarked image to the output file
   write_image(argv[2], image, width, height);

   // Free the memory allocated for the image
   free(image);

   // Success!
   return 0;
}