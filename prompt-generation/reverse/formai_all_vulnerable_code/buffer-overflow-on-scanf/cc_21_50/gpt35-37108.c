//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: realistic
#include <stdio.h>

int main() {
   int i, j, rows, cols, choice, brightness, contrast;

   printf("Enter the number of rows and columns of the image: ");
   scanf("%d %d", &rows, &cols);

   int image[rows][cols];

   printf("Enter the pixel values of the image:\n");

   for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
         scanf("%d", &image[i][j]);
      }
   }

   printf("Image Processing Menu\n");
   printf("1. Flip Image Horizontally\n");
   printf("2. Flip Image Vertically\n");
   printf("3. Change Brightness\n");
   printf("4. Change Contrast\n");
   printf("Enter your choice: ");
   scanf("%d", &choice);

   switch (choice) {
      case 1:
         for (i = 0; i < rows; i++) {
            for (j = 0; j < cols / 2; j++) {
               int temp = image[i][j];
               image[i][j] = image[i][cols - j - 1];
               image[i][cols - j - 1] = temp;
            }
         }
         break;
      case 2:
         for (i = 0; i < rows / 2; i++) {
            for (j = 0; j < cols; j++) {
               int temp = image[i][j];
               image[i][j] = image[rows - i - 1][j];
               image[rows - i - 1][j] = temp;
            }
         }
         break;
      case 3:
         printf("Enter the brightness value (-255 to 255): ");
         scanf("%d", &brightness);
         for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
               image[i][j] += brightness;
               if (image[i][j] < 0) {
                  image[i][j] = 0;
               }
               if (image[i][j] > 255) {
                  image[i][j] = 255;
               }
            }
         }
         break;
      case 4:
         printf("Enter the contrast value (-100 to 100): ");
         scanf("%d", &contrast);
         float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
         for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
               image[i][j] = factor * (image[i][j] - 128) + 128;
               if (image[i][j] < 0) {
                  image[i][j] = 0;
               }
               if (image[i][j] > 255) {
                  image[i][j] = 255;
               }
            }
         }
         break;
      default:
         printf("Invalid choice!\n");
         return 0;
   }

   printf("Processed Image:\n");
   for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
         printf("%d ", image[i][j]);
      }
      printf("\n");
   }
   return 0;
}