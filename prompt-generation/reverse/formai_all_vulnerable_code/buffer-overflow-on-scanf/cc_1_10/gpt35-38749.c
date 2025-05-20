//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declaring prototype functions for flipping and adjusting brightness
void flip_image(char *input_file, char *output_file);
void adjust_brightness(char *input_file, char *output_file, int adjustment);

int main(){
   char input_file[100], output_file[100];
   int choice, adjustment;
   
   printf("Enter input file name: ");
   scanf("%s", input_file);
   
   printf("Enter output file name: ");
   scanf("%s", output_file);

   printf("\nSelect an operation to perform:\n");
   printf("1. Flip Image\n");
   printf("2. Adjust Brightness\n");
   printf("Enter your choice: ");
   
   scanf("%d", &choice);

   switch (choice){
      case 1:
         flip_image(input_file, output_file); //calling flip image function
         printf("Image flipped successfully!\n");
         break;
      case 2:
         printf("Enter brightness adjustment value (between -255 and 255): ");
         scanf("%d", &adjustment);
         adjust_brightness(input_file, output_file, adjustment); //calling brightness adjustment function
         printf("Brightness adjusted successfully!\n");
         break;
      default:
         printf("Invalid choice!");
   }

   return 0;
}

void flip_image(char *input_file, char *output_file){
   FILE *in_file, *out_file;
   unsigned char *buffer;
   
   int width, height, maxval, row, col, i;
   char magic_number[128];

   in_file = fopen(input_file, "rb"); //open input file in read-mode with binary format
   out_file = fopen(output_file, "wb"); //open output file in write-mode with binary format

   if(in_file == NULL || out_file == NULL) { //check for valid file streams
      printf("Error opening file!\n");
      exit(1);
   }

   //Scan the dimensions of the PNM image
   fscanf(in_file, "%s\n%d %d\n%d\n", magic_number, &width, &height, &maxval);

   //Allocate memory for PNM image data
   buffer = (unsigned char*) malloc(width * height * sizeof(unsigned char));
   
   //Read PNM image data
   fread(buffer, sizeof(unsigned char), width * height, in_file);

   //Flip the PNM image vertically
   for(row = height-1; row >= 0; row--) {
      for(col = 0; col < width; col++) {
         fprintf(out_file,"%c", buffer[row * width + col]);
      }
   }

   //Free the memory held by the buffer
   free(buffer);
   
   //Close the files
   fclose(in_file);
   fclose(out_file);
}

void adjust_brightness(char *input_file, char *output_file, int adjustment){
   FILE *in_file, *out_file;
   unsigned char *buffer;
   
   int width, height, maxval, row, col, i;
   char magic_number[128];

   in_file = fopen(input_file, "rb"); //open input file in read-mode with binary format
   out_file = fopen(output_file, "wb"); //open output file in write-mode with binary format

   if(in_file == NULL || out_file == NULL) { //check for valid file streams
      printf("Error opening file!\n");
      exit(1);
   }

   //Scan the dimensions of the PNM image
   fscanf(in_file, "%s\n%d %d\n%d\n", magic_number, &width, &height, &maxval);

   //Allocate memory for PNM image data
   buffer = (unsigned char*) malloc(width * height * sizeof(unsigned char));
   
   //Read PNM image data
   fread(buffer, sizeof(unsigned char), width * height, in_file);

   //Adjust the brightness of the PNM image
   for(row = 0; row < height; row++) {
      for(col = 0; col < width; col++) {
         int pixel = buffer[row * width + col] + adjustment;
         pixel = pixel > 255 ? 255 : pixel;
         pixel = pixel < 0 ? 0 : pixel;
         buffer[row * width + col] = pixel;
      }
   }

   //Write the new PNM image data
   fprintf(out_file, "%s\n%d %d\n%d\n", magic_number, width, height, maxval);
   fwrite(buffer, sizeof(unsigned char), width * height, out_file);

   //Free the memory held by the buffer
   free(buffer);
   
   //Close the files
   fclose(in_file);
   fclose(out_file);
}