//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: retro
/* Introducing the Retro Color Code Converter! */

#include <stdio.h>
#include <stdlib.h>

/* Vintage Color Codes */
typedef enum {
  BLACK = 0x00,
  DARK_BLUE = 0x01,
  DARK_GREEN = 0x02,
  DARK_CYAN = 0x03,
  DARK_RED = 0x04,
  DARK_MAGENTA = 0x05,
  DARK_YELLOW = 0x06,
  LIGHT_GRAY = 0x07,
  DARK_GRAY = 0x08,
  BLUE = 0x09,
  GREEN = 0x0A,
  CYAN = 0x0B,
  RED = 0x0C,
  MAGENTA = 0x0D,
  YELLOW = 0x0E,
  WHITE = 0x0F,
} Color;

/* Color Names */
char *color_names[] = {
  "Black",
  "Dark Blue",
  "Dark Green",
  "Dark Cyan",
  "Dark Red",
  "Dark Magenta",
  "Dark Yellow",
  "Light Gray",
  "Dark Gray",
  "Blue",
  "Green",
  "Cyan",
  "Red",
  "Magenta",
  "Yellow",
  "White",
};

/* Function to Convert Color Code to Color Name */
char *color_code_to_name(Color color) {
  if (color < 0 || color > WHITE) {
    return "Invalid Color Code";
  }
  return color_names[color];
}

/* Function to Convert Color Name to Color Code */
Color color_name_to_code(char *color_name) {
  int i;
  for (i = 0; i <= WHITE; i++) {
    if (!strcmp(color_name, color_names[i])) {
      return (Color) i;
    }
  }
  return -1;
}

/* Main Function */
int main(int argc, char *argv[]) {
  int choice;
  char buffer[256];
  Color color;
  char *color_name;

  /* Welcome Message */
  printf("Welcome to the Retro Color Code Converter!\n\n");

  /* Loop until User Exits */
  while (1) {
    /* Display Menu */
    printf("\nPlease select an option:\n");
    printf("1. Convert Color Code to Name\n");
    printf("2. Convert Color Name to Code\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");

    /* Get User Input */
    scanf("%d", &choice);

    /* Handle User Choice */
    switch (choice) {
      case 1:
        /* Convert Color Code to Name */
        printf("Enter a color code (0-15): ");
        scanf("%d", &color);
        color_name = color_code_to_name(color);
        printf("Color Name: %s\n", color_name);
        break;
      case 2:
        /* Convert Color Name to Code */
        printf("Enter a color name: ");
        scanf("%s", buffer);
        color = color_name_to_code(buffer);
        if (color == -1) {
          printf("Invalid Color Name\n");
        } else {
          printf("Color Code: %d\n", color);
        }
        break;
      case 3:
        /* Exit */
        printf("Thank you for using the Retro Color Code Converter!\n");
        return 0;
      default:
        /* Invalid Input */
        printf("Invalid Choice. Please try again.\n");
    }
  }
}