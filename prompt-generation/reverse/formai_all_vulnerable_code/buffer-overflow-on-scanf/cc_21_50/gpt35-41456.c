//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: peaceful
#include <stdio.h>

int main() {
   FILE *fptr, *fptr2;
   int height, width, max, pixel, brightness, contrast, choice;
   char filename[20];

   printf("Enter filename to open: ");
   scanf("%s", filename);

   fptr = fopen(filename, "r");
   printf("\n1. Flip Image horizontally\n2. Flip Image vertically\n3. Change brightness\n4. Change contrast\n5. Save and Exit\n");

   printf("\nEnter your choice: ");
   scanf("%d", &choice);

   fscanf(fptr, "P3\n%d %d\n%d\n", &width, &height, &max);
   int img[height][width][3];

   // Reading Pixel Values
   for(int i = 0; i < height; i++) {
      for(int j = 0; j < width; j++) {
         for(int k = 0; k < 3; k++) {
            fscanf(fptr, "%d", &pixel);
            img[i][j][k] = pixel;
         }
      }
   }

   // Flip Image Horizontally
   if(choice == 1) {
      for(int i = 0; i < height; i++) {
         for(int j = 0; j < width/2; j++) {
            for(int k = 0; k < 3; k++) {
               int temp = img[i][j][k];
               img[i][j][k] = img[i][width-1-j][k];
               img[i][width-1-j][k] = temp;
            }
         }
      }
      printf("\nImage Flipped Horizontally!\n");
   }

   // Flip Image Vertically
   else if(choice == 2) {
      for(int i = 0; i < height/2; i++) {
         for(int j = 0; j < width; j++) {
            for(int k = 0; k < 3; k++) {
               int temp = img[i][j][k];
               img[i][j][k] = img[height-1-i][j][k];
               img[height-1-i][j][k] = temp;
            }
         }
      }
      printf("\nImage Flipped Vertically!\n");
   }

   // Change Brightness
   else if(choice == 3) {
      printf("\nEnter Brightness Level (-255 to 255): ");
      scanf("%d", &brightness);
      for(int i = 0; i < height; i++) {
         for(int j = 0; j < width; j++) {
            for(int k = 0; k < 3; k++) {
               img[i][j][k] += brightness;
               if(img[i][j][k] < 0) img[i][j][k] = 0;
               if(img[i][j][k] > 255) img[i][j][k] = 255;
            }
         }
      }
      printf("\nBrightness Changed!\n");
   }

   // Change Contrast
   else if(choice == 4) {
      printf("\nEnter Contrast Level (-255 to 255): ");
      scanf("%d", &contrast);
      float contrast_factor = (259*(contrast+255))/(255*(259-contrast));
      for(int i = 0; i < height; i++) {
         for(int j = 0; j < width; j++) {
            for(int k = 0; k < 3; k++) {
               img[i][j][k] = contrast_factor*(img[i][j][k] - 128) + 128;
               if(img[i][j][k] < 0) img[i][j][k] = 0;
               if(img[i][j][k] > 255) img[i][j][k] = 255;
            }
         }
      }
      printf("\nContrast Changed!\n");
   }

   // Save and Exit
   else if(choice == 5) {
      fptr2 = fopen("output.ppm", "w");
      fprintf(fptr2, "P3\n%d %d\n%d\n", width, height, max);
      for(int i = 0; i < height; i++) {
         for(int j = 0; j < width; j++) {
            for(int k = 0; k < 3; k++) {
               fprintf(fptr2, "%d ", img[i][j][k]);
            }
         }
         fprintf(fptr2, "\n");
      }
      printf("\nImage Saved as output.ppm!\n");
      fclose(fptr2);
   }

   else printf("Invalid choice!\n");
   fclose(fptr);

   return 0;
}