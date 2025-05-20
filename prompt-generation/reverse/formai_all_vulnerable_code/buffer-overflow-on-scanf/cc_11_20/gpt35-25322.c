//FormAI DATASET v1.0 Category: Temperature Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // for boolean values

int main() {
  // User input variables
  float temperature;
  char type;
  // Output variables
  float convertedTemperature;
  char outputType;
  // Loop control variables
  bool exitProgram = false;
  bool validInput = false;

  printf("\nTemperature Converter\n------------------------\n");

  while (!exitProgram) {

    // Loop to validate user input
    while (!validInput) {
      printf("\nEnter temperature to convert (e.g. 32F): ");
      scanf("%f%c", &temperature, &type);
      if (type != 'F' && type != 'C') {
        printf("Invalid input! Try again.\n");
      } else {
        validInput = true;
      }
    }

    if (type == 'F') {
      convertedTemperature = (temperature - 32) * (5.0 / 9.0);
      outputType = 'C';
    } else {
      convertedTemperature = (temperature * 9.0 / 5.0) + 32;
      outputType = 'F';
    }

    printf("%.2f%c is %.2f%c\n",temperature,type,convertedTemperature,outputType);

    // Loop to validate whether user wants to continue or not
    validInput = false;
    while (!validInput) {
      printf("\nDo you want to convert another temperature? (Y/N): ");
      char choice;
      scanf(" %c", &choice);
      if (choice == 'N' || choice == 'n') {
        exitProgram = true;
        validInput = true;
      } else if (choice == 'Y' || choice == 'y') {
        validInput = true;
      } else {
        printf("Invalid input! Try again.\n");
      }
    }
  }

  printf("\nThank you for using Temperature Converter!\n");

  return 0;
}