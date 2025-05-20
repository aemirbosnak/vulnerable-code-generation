//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   // set seed for random generator
   srand(time(NULL));

   // initialize variables
   int width, height, numColors;
   char pixelChar;
   int** pixelArt;

   // get user input for dimensions and number of colors
   printf("Enter width of pixel art (in pixels): ");
   scanf("%d", &width);
   printf("Enter height of pixel art (in pixels): ");
   scanf("%d", &height);
   printf("Enter number of colors (between 2 and 8): ");
   scanf("%d", &numColors);
   
   // validate user input
   while (numColors < 2 || numColors > 8) {
      printf("Invalid input. Enter number of colors (between 2 and 8): ");
      scanf("%d", &numColors);
   }
   
   // allocate memory for pixel art array
   pixelArt = (int**)malloc(height * sizeof(int*));
   for (int i = 0; i < height; i++) {
      pixelArt[i] = (int*)malloc(width * sizeof(int));
   }
   
   // generate random pixel art
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         pixelArt[i][j] = rand() % numColors;
      }
   }
   
   // initialize pixel characters based on number of colors
   if (numColors == 2) {
      pixelChar = '#';
   } else if (numColors == 3) {
      pixelChar = '@';
   } else if (numColors == 4) {
      pixelChar = '%';
   } else if (numColors == 5) {
      pixelChar = '+';
   } else if (numColors == 6) {
      pixelChar = '-';
   } else if (numColors == 7) {
      pixelChar = '*';
   } else {
      pixelChar = '=';
   }
   
   // print pixel art
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         printf("%c ", pixelChar);
      }
      printf("\n");
   }
   
   // free allocated memory
   for (int i = 0; i < height; i++) {
      free(pixelArt[i]);
   }
   free(pixelArt);

   return 0;
}