//FormAI DATASET v1.0 Category: Unit converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>

void welcomeMessage() {
  printf("Welcome to Happy Converter!\n");
  printf("This program can convert temperature, distance, and weight units.\n");
  printf("You will be asked to select the unit type you would like to convert and enter a value.\n");
  printf("Let's start! Press enter to continue.\n");
  getchar();
  printf("\n");
}

int main() {
  int unitType;
  double value, result;

  welcomeMessage();

  do {
    printf("\t\tUnit Converter\n");
    printf("\t--------------------------------------------------------\n");
    printf("\tChoose the type of unit you want to convert:\n");
    printf("\t1. Temperature\n");
    printf("\t2. Distance\n");
    printf("\t3. Weight\n");
    printf("\t4. Exit\n");
    printf("\t--------------------------------------------------------\n");
    printf("Enter your option (1/2/3/4): ");
    scanf("%d", &unitType);

    switch(unitType) {
      case 1:
        printf("Enter the temperature in Celsius: ");
        scanf("%lf", &value);
        result = (value * 9/5) + 32;
        printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", value, result);
        break;
      case 2:
        printf("Enter the distance in kilometers: ");
        scanf("%lf", &value);
        result = value * 0.621371;
        printf("%.2lf kilometers is equal to %.2lf miles.\n", value, result);
        break;
      case 3:
        printf("Enter the weight in kilograms: ");
        scanf("%lf", &value);
        result = value * 2.20462;
        printf("%.2lf kilograms is equal to %.2lf pounds.\n", value, result);
        break;
      case 4:
        printf("Thank you for using Happy Converter!\n");
        exit(0);
      default:
        printf("Invalid input. Please try again.\n");
    }
  } while (1);

  return 0;
}