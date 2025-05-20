//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 40
#define MAX_SIZE MAX_WIDTH * MAX_HEIGHT

void print_ascii_art(char ascii_art[], int width, int height);

int main()
{
   char message[MAX_SIZE];
   int width, height, length, i, j, k;
   printf("Enter your message: ");
   fgets(message, MAX_SIZE, stdin);
   length = strlen(message) - 1; 
   printf("Enter the width of the ASCII art (max 80): ");
   scanf("%d", &width);
   printf("Enter the height of the ASCII art (max 40): ");
   scanf("%d", &height);

   if (width > MAX_WIDTH || height > MAX_HEIGHT) {
      printf("Exceeds maximum dimensions. Exiting...\n");
      return 0;
   }

   int rows = (length + width - 1) / width;
   int cols = (length + rows - 1) / rows;
   int spaces = width - cols;
   
   char ascii_art[MAX_SIZE];
   memset(ascii_art, ' ', MAX_SIZE);

   for (i = 0; i < length; i++)
   {
      if (message[i] == '\n') continue; 
      ascii_art[i + i / width * spaces] = message[i];
   }

   print_ascii_art(ascii_art, width, height);

   return 0;
}

void print_ascii_art(char ascii_art[], int width, int height)
{
   int i, j;
   for (i = 0; i < height; i++)
   {
      for (j = 0; j < width; j++)
      {
         putchar(ascii_art[i * width + j]);
      }
      putchar('\n');
   }
}