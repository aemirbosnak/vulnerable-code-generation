//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the supported color codes
#define COLOR_BLACK      "\033[0;30m"
#define COLOR_RED        "\033[0;31m"
#define COLOR_GREEN      "\033[0;32m"
#define COLOR_YELLOW     "\033[0;33m"
#define COLOR_BLUE       "\033[0;34m"
#define COLOR_MAGENTA    "\033[0;35m"
#define COLOR_CYAN       "\033[0;36m"
#define COLOR_WHITE      "\033[0;37m"

// Define the reset code
#define COLOR_RESET      "\033[0;0m"

// Define the function to convert a color name to a color code
char *color_code_converter(char *color_name) {
  // Convert the color name to lowercase
  char *lower_color_name = strdup(color_name);
  for (int i = 0; lower_color_name[i] != '\0'; i++) {
    lower_color_name[i] = tolower(lower_color_name[i]);
  }

  // Check if the color name is supported
  if (strcmp(lower_color_name, "black") == 0) {
    return COLOR_BLACK;
  } else if (strcmp(lower_color_name, "red") == 0) {
    return COLOR_RED;
  } else if (strcmp(lower_color_name, "green") == 0) {
    return COLOR_GREEN;
  } else if (strcmp(lower_color_name, "yellow") == 0) {
    return COLOR_YELLOW;
  } else if (strcmp(lower_color_name, "blue") == 0) {
    return COLOR_BLUE;
  } else if (strcmp(lower_color_name, "magenta") == 0) {
    return COLOR_MAGENTA;
  } else if (strcmp(lower_color_name, "cyan") == 0) {
    return COLOR_CYAN;
  } else if (strcmp(lower_color_name, "white") == 0) {
    return COLOR_WHITE;
  } else {
    return NULL;
  }
}

// Define the function to print a string in a specified color
void print_in_color(char *color_code, char *string) {
  // Print the color code
  printf("%s", color_code);

  // Print the string
  printf("%s", string);

  // Reset the color
  printf("%s", COLOR_RESET);
}

// Define the main function
int main() {
  // Get the color name from the user
  char color_name[100];
  printf("Enter a color name: ");
  scanf("%s", color_name);

  // Convert the color name to a color code
  char *color_code = color_code_converter(color_name);

  // If the color code is not NULL, print the string in the specified color
  if (color_code != NULL) {
    print_in_color(color_code, "This is a test string.");
  } else {
    printf("Invalid color name.");
  }

  return 0;
}