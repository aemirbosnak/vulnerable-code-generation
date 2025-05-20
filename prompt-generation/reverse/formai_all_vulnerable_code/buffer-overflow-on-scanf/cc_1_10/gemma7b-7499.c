//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void color_converter(char **color_code)
{
  int red, green, blue, alpha;
  char temp[20];

  printf("Enter the RGB values (separated by commas): ");
  scanf("%s", temp);

  // Convert the string to integers
  red = atoi(strtok(temp, ","));
  green = atoi(strtok(NULL, ","));
  blue = atoi(strtok(NULL, ","));
  alpha = atoi(strtok(NULL, ","));

  // Validate the values
  if (red < 0 || red > 255)
  {
    printf("Error: Red value out of range.\n");
    return;
  }
  if (green < 0 || green > 255)
  {
    printf("Error: Green value out of range.\n");
    return;
  }
  if (blue < 0 || blue > 255)
  {
    printf("Error: Blue value out of range.\n");
    return;
  }
  if (alpha < 0 || alpha > 255)
  {
    printf("Error: Alpha value out of range.\n");
    return;
  }

  // Create the color code
  *color_code = malloc(20);
  sprintf(*color_code, "rgba(%d, %d, %d, %d)", red, green, blue, alpha);
}

int main()
{
  char *color_code;
  color_converter(&color_code);
  printf("Your color code is: %s\n", color_code);
  free(color_code);

  return 0;
}