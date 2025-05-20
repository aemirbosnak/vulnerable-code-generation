//FormAI DATASET v1.0 Category: Image Steganography ; Style: ephemeral
//Ephemeral Image Steganography Program
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//Struct for storing pixel data
typedef struct {
   uint8_t r, g, b;
} Pixel;

//Function for checking the file format of the image
int check_file_format(FILE *file) {
   uint8_t check_bytes[2];
   fread(check_bytes, 1, 2, file);
   if (check_bytes[0] == 'B' && check_bytes[1] == 'M') {
      return 1;   //Bitmap image format
   }
   return 0;
}

//Function for hiding data in the image
void hide_data(Pixel **image, int width, int height, char *data, int data_length) {
   int x = 0, y = 0, bit_count = 0;
   while (bit_count < data_length * 8) {
      uint8_t pixel_byte = 0;
      for (int b = 0; b < 8; b++) {
         if (bit_count >= data_length * 8) {
            break;
         }
         if (data[bit_count / 8] & (1 << (bit_count % 8))) {
            pixel_byte |= 1 << (7 - b);
         }
         bit_count++;
      }
      if (x >= width) {
         y++;
         x = 0;
      }
      if (y >= height) {
         break;
      }
      image[y][x].r &= 0xFE;
      image[y][x].r |= pixel_byte & 0x01;
      image[y][x].g &= 0xFE;
      image[y][x].g |= (pixel_byte >> 1) & 0x01;
      image[y][x].b &= 0xFE;
      image[y][x].b |= (pixel_byte >> 2) & 0x01;
      x++;
   }
}

//Function for extracting the hidden data from the image
char *extract_data(Pixel **image, int width, int height, int data_length) {
   char *data = malloc(data_length);
   int x = 0, y = 0, bit_count = 0;
   while (bit_count < data_length * 8) {
      uint8_t pixel_byte = 0;
      pixel_byte |= image[y][x].r & 0x01;
      pixel_byte |= (image[y][x].g & 0x01) << 1;
      pixel_byte |= (image[y][x].b & 0x01) << 2;
      data[bit_count / 8] |= (pixel_byte & 0x01) << (bit_count % 8);
      bit_count++;
      if (x >= width) {
         y++;
         x = 0;
      }
      if (y >= height) {
         break;
      }
   }
   return data;
}

int main(int argc, char *argv[]) {
   if (argc != 4) {
      printf("Usage: %s <image file> <input file> <output file>\n", argv[0]);
      return 1;
   }

   //Open the image file
   FILE *image_file = fopen(argv[1], "rb");
   if (!image_file) {
      perror("Could not open image file");
      return 1;
   }

   //Check if the file is in the correct format
   if (check_file_format(image_file) != 1) {
      printf("File is not a valid bitmap image\n");
      return 1;
   }

   //Read the image data into memory
   fseek(image_file, 0, SEEK_END);
   long file_size = ftell(image_file);
   fseek(image_file, 0, SEEK_SET);
   uint8_t *file_data = malloc(file_size);
   fread(file_data, 1, file_size, image_file);
   fclose(image_file);

   //Parse the image header and pixel data
   uint32_t width = *(uint32_t *)&file_data[18];
   uint32_t height = *(uint32_t *)&file_data[22];
   uint32_t pixel_offset = *(uint32_t *)&file_data[10];
   Pixel **image = malloc(height * sizeof(Pixel *));
   for (int y = 0; y < height; y++) {
      image[y] = malloc(width * sizeof(Pixel));
      for (int x = 0; x < width; x++) {
         unsigned int index = pixel_offset + (y * width + x) * 3;
         image[y][x].b = file_data[index];
         image[y][x].g = file_data[index + 1];
         image[y][x].r = file_data[index + 2];
      }
   }

   //Open the input file
   FILE *input_file = fopen(argv[2], "rb");
   if (!input_file) {
      perror("Could not open input file");
      return 1;
   }

   //Determine the length of the input file
   fseek(input_file, 0, SEEK_END);
   int input_size = ftell(input_file);
   fseek(input_file, 0, SEEK_SET);

   //Check if the input file can fit inside the image
   int max_data_length = width * height * 3 / 8;
   if (input_size > max_data_length) {
      printf("Input file is too large to fit inside the image\n");
      return 1;
   }

   //Read the input file into memory
   char *input_data = malloc(input_size);
   fread(input_data, 1, input_size, input_file);
   fclose(input_file);

   //Hide the input file data in the image
   hide_data(image, width, height, input_data, input_size);

   //Save the modified image
   FILE *output_file = fopen(argv[3], "wb");
   if (!output_file) {
      perror("Could not create output file");
      return 1;
   }
   fwrite(file_data, 1, pixel_offset, output_file);
   for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
         fwrite(&image[y][x].b, 1, 1, output_file);
         fwrite(&image[y][x].g, 1, 1, output_file);
         fwrite(&image[y][x].r, 1, 1, output_file);
      }
   }
   fclose(output_file);

   //Extract the hidden data from the image
   char *extracted_data = extract_data(image, width, height, input_size);

   //Print the extracted data
   printf("Extracted data:\n");
   for (int i = 0; i < input_size; i++) {
      printf("%c", extracted_data[i]);
   }
   printf("\n");

   free(file_data);
   free(image);
   free(input_data);
   free(extracted_data);

   return 0;
}