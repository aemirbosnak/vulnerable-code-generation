//FormAI DATASET v1.0 Category: Unit converter ; Style: artistic
#include <stdio.h>

void printHeader()
{
  printf("===================================\n");
  printf("     Artistic Unit Converter\n");
  printf("===================================\n");
}

int main()
{
  double inputValue;
  char inputType, outputType;
  double convertedValue;

  printHeader();
  
  // Input
  printf("\nEnter an input value: ");
  scanf("%lf", &inputValue);
  printf("Enter the input type (C, F or K): ");
  scanf(" %c", &inputType);
  printf("Enter the output type (C, F or K): ");
  scanf(" %c", &outputType);
  
  // Conversion
  if (inputType == 'C' && outputType == 'F')
  {
    convertedValue = (inputValue * 9.0/5.0) + 32.0;
    printf("%.2lf degrees Celsius is %.2lf degrees Fahrenheit\n", inputValue, convertedValue);
  }
  else if (inputType == 'C' && outputType == 'K')
  {
    convertedValue = inputValue + 273.15;
    printf("%.2lf degrees Celsius is %.2lf Kelvin\n", inputValue, convertedValue);
  }
  else if (inputType == 'F' && outputType == 'C')
  {
    convertedValue = (inputValue - 32.0) * 5.0/9.0; 
    printf("%.2lf degrees Fahrenheit is %.2lf degrees Celsius\n", inputValue, convertedValue);
  }
  else if (inputType == 'F' && outputType == 'K')
  {
    convertedValue = (inputValue + 459.67) * 5.0/9.0; 
    printf("%.2lf degrees Fahrenheit is %.2lf Kelvin\n", inputValue, convertedValue);
  }
  else if (inputType == 'K' && outputType == 'C')
  {
    convertedValue = inputValue - 273.15;
    printf("%.2lf Kelvin is %.2lf degrees Celsius\n", inputValue, convertedValue);
  }
  else if (inputType == 'K' && outputType == 'F')
  {
    convertedValue = (inputValue * 9.0/5.0) - 459.67;
    printf("%.2lf Kelvin is %.2lf degrees Fahrenheit\n", inputValue, convertedValue);
  }
  else
  {
    printf("Invalid input or output type\n");
    return 1;
  }
  
  printf("\nThank you for using Artistic Unit Converter!\n");
  return 0;
}