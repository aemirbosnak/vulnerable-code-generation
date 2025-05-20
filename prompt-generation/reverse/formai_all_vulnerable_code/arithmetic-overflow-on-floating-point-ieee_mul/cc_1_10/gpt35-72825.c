//FormAI DATASET v1.0 Category: Unit converter ; Style: genious
#include <stdio.h>

int main() {
  int choice;
  float measurement, converted;
  
  printf("Welcome to the Genius Unit Converter!\n");
  
  while (1) {
    printf("\nPlease choose an option:\n");
    printf("1. Inches to Centimeters\n");
    printf("2. Feet to Meters\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Celsius to Fahrenheit\n");
    printf("5. Quit\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
      printf("\nEnter a measurement in inches: ");
      scanf("%f", &measurement);
      converted = measurement * 2.54;
      printf("%.2f inches is equal to %.2f centimeters\n", measurement, converted);
    }
    else if (choice == 2) {
      printf("\nEnter a measurement in feet: ");
      scanf("%f", &measurement);
      converted = measurement * 0.3048;
      printf("%.2f feet is equal to %.2f meters\n", measurement, converted);
    }
    else if (choice == 3) {
      printf("\nEnter a measurement in miles: ");
      scanf("%f", &measurement);
      converted = measurement * 1.60934;
      printf("%.2f miles is equal to %.2f kilometers\n", measurement, converted);
    }
    else if (choice == 4) {
      printf("\nEnter a temperature in Celsius: ");
      scanf("%f", &measurement);
      converted = (measurement * 9 / 5) + 32;
      printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", measurement, converted);
    }
    else if (choice == 5) {
      printf("\nThank you for using the Genius Unit Converter!\n");
      break;
    }
    else {
      printf("\nInvalid choice, please try again!\n");
    }
  }
  
  return 0;
}