//FormAI DATASET v1.0 Category: Unit converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {

  printf("Welcome to the shocking Unit Converter!\n");

  float num;
  int option;
  float result;

  printf("\nEnter a number to convert: ");
  scanf("%f", &num);

  printf("Select a conversion option: \n");
  printf("1. Celsius to Fahrenheit\n");
  printf("2. Kilometers to Miles\n");
  printf("3. Meters to Feet\n");
  printf("4. Kilograms to Pounds\n");
  printf("5. Exit\n");

  printf("Enter an option: ");
  scanf("%d", &option);

  switch(option) {
    case 1:
      result = (num * 9/5) + 32;
      printf("%f Celsius is %f Fahrenheit\n", num, result);
      break;
    case 2:
      result = num / 1.609;
      printf("%f Kilometers is %f Miles\n", num, result);
      break;
    case 3:
      result = num * 3.281;
      printf("%f Meters is %f Feet\n", num, result);
      break;
    case 4:
      result = num * 2.205;
      printf("%f Kilograms is %f Pounds\n", num, result);
      break;
    case 5:
      printf("Thanks for using the shocking Unit Converter! Goodbye.\n");
      exit(0);
    default:
      printf("Invalid option. Try again.\n");
      break;
  }

  return(0);
}