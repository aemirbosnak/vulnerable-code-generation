//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum width of the ASCII art
#define MAX_WIDTH 80

// Maximum height of the ASCII art
#define MAX_HEIGHT 25

// Array of ASCII characters
char ascii_chars[] = " .,-:;!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

// Function to generate ASCII art from a string
void generate_ascii_art(char *str, int width, int height)
{
  // Check if the string is too long or too wide
  if (strlen(str) > width * height)
  {
    printf("Error: String is too long or too wide.\n");
    return;
  }

  // Create a 2D array to store the ASCII art
  char art[height][width];

  // Initialize the ASCII art array to spaces
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      art[i][j] = ' ';
    }
  }

  // Convert the string to ASCII art
  int index = 0;
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      // Get the next character from the string
      char c = str[index++];

      // Find the ASCII code for the character
      int ascii_code = (int)c;

      // Get the index of the ASCII character in the array
      int ascii_index = ascii_code - 32;

      // Set the ASCII character in the art array
      art[i][j] = ascii_chars[ascii_index];
    }
  }

  // Print the ASCII art
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      printf("%c", art[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  // Get the input string from the user
  char str[100];
  printf("Enter a string: ");
  gets(str);

  // Get the width and height of the ASCII art
  int width, height;
  printf("Enter the width of the ASCII art: ");
  scanf("%d", &width);
  printf("Enter the height of the ASCII art: ");
  scanf("%d", &height);

  // Generate the ASCII art
  generate_ascii_art(str, width, height);

  return 0;
}