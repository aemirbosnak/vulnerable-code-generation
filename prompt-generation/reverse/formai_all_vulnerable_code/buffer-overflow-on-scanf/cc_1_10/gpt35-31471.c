//FormAI DATASET v1.0 Category: Temperature Converter ; Style: puzzling
/* Welcome to the mysterious land of temperature conversion! Prepare to be puzzled!
 * This program will convert temperatures from Celsius to Fahrenheit and Fahrenheit to Celsius
 * But beware, there are hidden clues and secret formulas to discover.
 */

#include <stdio.h>

int main() {
  printf("Welcome to the temperature converter!\n");
  printf("What would you like to convert? (Celsius or Fahrenheit)\n");

  char choice[20];
  scanf("%s", choice);

  if (strcmp(choice, "Celsius") == 0) {
    printf("Enter the temperature in Celsius: ");
    double celsius;
    scanf("%lf", &celsius);

    double fahrenheit = celsius * 9 / 5 + 32;

    printf("The temperature in Fahrenheit is: %lf\n", fahrenheit);
    printf("But wait, there's more...\n");
    printf("The magic number for converting Celsius to Fahrenheit is 32, but why?\n");
    printf("Think about the freezing (0C) and boiling (100C) points of water...\n");
    printf("Could there be a connection?\n");
    printf("Let the mystery unfold...\n");
  }
  
  else if (strcmp(choice, "Fahrenheit") == 0) {
    printf("Enter the temperature in Fahrenheit: ");
    double fahrenheit;
    scanf("%lf", &fahrenheit);

    double celsius = (fahrenheit - 32) * 5 / 9;

    printf("The temperature in Celsius is: %lf\n", celsius);
    printf("But what does the number 9/5 represent in the conversion formula?\n");
    printf("Perhaps it is the slope of a line...or maybe it's something more mysterious...\n");
    printf("Let the temperature conversion secrets reveal themselves...\n");
  }
  
  else {
    printf("Invalid input. Please try again.\n");
  }

  printf("Thank you for using the temperature converter.\n");
  printf("May the temperature mysteries continue to intrigue you...\n");

  return 0;
}