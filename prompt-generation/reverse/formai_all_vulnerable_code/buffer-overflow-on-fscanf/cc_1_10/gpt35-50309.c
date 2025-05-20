//FormAI DATASET v1.0 Category: Image Editor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
   int width, height, max_val;
   char format[3];
   
   FILE *input_file = fopen("input.ppm", "r");
   fscanf(input_file,"%s", format);
   fscanf(input_file,"%d %d", &width, &height);
   fscanf(input_file,"%d", &max_val);

   int image[width][height][3];

   for(int i=0; i<width; i++) {
      for(int j=0; j<height; j++) {
         fscanf(input_file,"%d %d %d", &image[i][j][0], &image[i][j][1], &image[i][j][2]);
      }      
   }

   fclose(input_file);
   
   // Applying romantic filter to the image
   
   for(int i=0; i<width; i++) {
      for(int j=0; j<height; j++) {
         int r = image[i][j][0];
         int g = image[i][j][1];
         int b = image[i][j][2];
         
         int new_r = (r + g + b)/3;
         int new_g = (r + g)/2;
         int new_b = b*(r+g)/(r+g+b);

         image[i][j][0] = new_r;
         image[i][j][1] = new_g;
         image[i][j][2] = new_b;
      }      
   }
   
   FILE *output_file = fopen("output.ppm", "w");
   fprintf(output_file,"%s\n", format);
   fprintf(output_file,"%d %d\n", width, height);
   fprintf(output_file,"%d\n", max_val);
   
   for(int i=0; i<width; i++) {
      for(int j=0; j<height; j++) {
         fprintf(output_file,"%d %d %d\n", image[i][j][0], image[i][j][1], image[i][j][2]);
      }      
   }

   fclose(output_file);
   
   printf("Romantic filter applied successfully to the PPM image.\n");
   
   return 0;
}