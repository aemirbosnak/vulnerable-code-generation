//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Define the enum for the color codes
enum color_code {
  BLACK = 0,
  BROWN = 1,
  RED = 2,
  ORANGE = 3,
  YELLOW = 4,
  GREEN = 5,
  BLUE = 6,
  VIOLET = 7,
  GRAY = 8,
  WHITE = 9
};

// Define the function to convert a color code to a string
char *color_code_to_string(enum color_code color_code) {
  switch (color_code) {
    case BLACK:
      return "Black";
    case BROWN:
      return "Brown";
    case RED:
      return "Red";
    case ORANGE:
      return "Orange";
    case YELLOW:
      return "Yellow";
    case GREEN:
      return "Green";
    case BLUE:
      return "Blue";
    case VIOLET:
      return "Violet";
    case GRAY:
      return "Gray";
    case WHITE:
      return "White";
    default:
      return "Invalid color code";
  }
}

// Define the main function
int main() {
  // Declare the variables
  enum color_code color_code1, color_code2, color_code3;
  char *color_code1_string, *color_code2_string, *color_code3_string;
  int resistance_value;

  // Prompt the user to enter the first color code
  printf("Enter the first color code (0-9): ");
  scanf("%d", &color_code1);

  // Prompt the user to enter the second color code
  printf("Enter the second color code (0-9): ");
  scanf("%d", &color_code2);

  // Prompt the user to enter the third color code
  printf("Enter the third color code (0-9): ");
  scanf("%d", &color_code3);

  // Convert the color codes to strings
  color_code1_string = color_code_to_string(color_code1);
  color_code2_string = color_code_to_string(color_code2);
  color_code3_string = color_code_to_string(color_code3);

  // Calculate the resistance value
  resistance_value = (color_code1 * 100) + (color_code2 * 10) + color_code3;

  // Print the results
  printf("The first color code is %s (%d).\n", color_code1_string, color_code1);
  printf("The second color code is %s (%d).\n", color_code2_string, color_code2);
  printf("The third color code is %s (%d).\n", color_code3_string, color_code3);
  printf("The resistance value is %d ohms.\n", resistance_value);

  return 0;
}