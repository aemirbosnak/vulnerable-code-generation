//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 60

// Function to convert RGB values to grayscale
int toGray(int red, int green, int blue) {
   return (red + green + blue) / 3;
}

// Function to convert a pixel to ASCII character
char getPixelChar(int grayscale) {
   const char *asciiChars = " .:-=+*#%@";
   int charCount = strlen(asciiChars);
   int stepSize = 255 / (charCount - 1);
   int index = grayscale / stepSize;
   return asciiChars[index];
}

// Function to print the ASCII art
void printASCII(int width, int height, char asciiArt[MAX_WIDTH][MAX_HEIGHT]) {
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         putchar(asciiArt[j][i]);
      }
      putchar('\n');
   }
}

// Main function
int main(int argc, char *argv[]) {
   if (argc < 2) {
      printf("Error: Please specify the image file.\n");
      return 1;
   }
   FILE *imageFile = fopen(argv[1], "rb");
   if (!imageFile) {
      printf("Error: Unable to open image file.\n");
      return 1;
   }
   char dummy[54];
   fread(&dummy, sizeof(char), 54, imageFile); // Skip image header
   int width = fgetc(imageFile);
   int height = fgetc(imageFile);
   char asciiArt[MAX_WIDTH][MAX_HEIGHT];
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         int blue = fgetc(imageFile);
         int green = fgetc(imageFile);
         int red = fgetc(imageFile);
         int grayscale = toGray(red, green, blue);
         asciiArt[j][i] = getPixelChar(grayscale);
      }
      fgetc(imageFile); // Skip padding
   }
   fclose(imageFile);
   printASCII(width, height, asciiArt);
   return 0;
}