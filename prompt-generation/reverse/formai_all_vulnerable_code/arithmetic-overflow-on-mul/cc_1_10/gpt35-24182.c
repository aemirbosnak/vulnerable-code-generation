//FormAI DATASET v1.0 Category: Unit converter ; Style: visionary
#include <stdio.h>

int main() {
  int choice, temp;
  float measurement, result;

  printf("Welcome to the visionary unit converter!\n\n");

  printf("Please select an option from the menu below:\n");
  printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");
  printf("3. Kilometers to Miles\n4. Miles to Kilometers\n");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("\nEnter temperature in Celsius: ");
      scanf("%d", &temp);
      result = (temp * 9/5) + 32;
      printf("%d Celsius = %.2f Fahrenheit\n", temp, result);
      break;
      
    case 2:
      printf("\nEnter temperature in Fahrenheit: ");
      scanf("%d", &temp);
      result = (temp - 32) * 5/9;
      printf("%d Fahrenheit = %.2f Celsius\n", temp, result);
      break;
      
    case 3:
      printf("\nEnter length in kilometers: ");
      scanf("%f", &measurement);
      result = measurement * 0.621371;
      printf("%.2f Kilometers = %.2f Miles\n", measurement, result);
      break;
      
    case 4:
      printf("\nEnter length in miles: ");
      scanf("%f", &measurement);
      result = measurement * 1.60934;
      printf("%.2f Miles = %.2f Kilometers\n", measurement, result);
      break;
      
    default:
      printf("\nInvalid option selected!\n");
      break;
  }

  return 0;
}