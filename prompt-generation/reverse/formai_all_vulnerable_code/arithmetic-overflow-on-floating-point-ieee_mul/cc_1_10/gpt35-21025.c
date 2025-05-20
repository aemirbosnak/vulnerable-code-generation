//FormAI DATASET v1.0 Category: Unit converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
void displayMenu(void);
double lengthConversion(double value, int fromUnit, int toUnit);
double massConversion(double value, int fromUnit, int toUnit);
double temperatureConversion(double value, int fromUnit, int toUnit);

/* Main Function */
int main(void)
{
  int option, fromUnit, toUnit;
  double value, result;

  displayMenu();

  printf("\nEnter an option from the menu: ");
  scanf("%d", &option);

  switch(option)
  {
    case 1:
      printf("\nLength Conversion\n");
      printf("From (1-3): ");
      scanf("%d", &fromUnit);
      printf("To (1-3): ");
      scanf("%d", &toUnit);
      printf("Value: ");
      scanf("%lf", &value);

      result = lengthConversion(value, fromUnit, toUnit);

      printf("%.2lf units\n", result);
      break;

    case 2:
      printf("\nMass Conversion\n");
      printf("From (1-3): ");
      scanf("%d", &fromUnit);
      printf("To (1-3): ");
      scanf("%d", &toUnit);
      printf("Value: ");
      scanf("%lf", &value);

      result = massConversion(value, fromUnit, toUnit);

      printf("%.2lf units\n", result);
      break;

    case 3:
      printf("\nTemperature Conversion\n");
      printf("From (1-3): ");
      scanf("%d", &fromUnit);
      printf("To (1-3): ");
      scanf("%d", &toUnit);
      printf("Value: ");
      scanf("%lf", &value);

      result = temperatureConversion(value, fromUnit, toUnit);

      printf("%.2lf units\n", result);
      break;

    default:
      printf("Invalid Option\n");
      break;
  }

  return 0;
}

/* Function Definitions */

/* This function displays the menu */
void displayMenu(void)
{
  printf("Unit Converter\n");
  printf("1. Length Conversion\n");
  printf("2. Mass Conversion\n");
  printf("3. Temperature Conversion\n");
}

/* This function converts length units */
double lengthConversion(double value, int fromUnit, int toUnit)
{
  double result;

  if(fromUnit == 1 && toUnit == 2) /* Meters to Feet */
  {
    result = value * 3.28084;
  }
  else if(fromUnit == 1 && toUnit == 3) /* Meters to Inches */
  {
    result = value * 39.3701;
  }
  else if(fromUnit == 2 && toUnit == 1) /* Feet to Meters */
  {
    result = value * 0.3048;
  }
  else if(fromUnit == 2 && toUnit == 3) /* Feet to Inches */
  {
    result = value * 12;
  }
  else if(fromUnit == 3 && toUnit == 1) /* Inches to Meters */
  {
    result = value * 0.0254;
  }
  else if(fromUnit == 3 && toUnit == 2) /* Inches to Feet */
  {
    result = value * 0.0833333;
  }
  else /* Invalid */
  {
    printf("Invalid units\n");
  }

  return result;
}

/* This function converts mass units */
double massConversion(double value, int fromUnit, int toUnit)
{
  double result;

  if(fromUnit == 1 && toUnit == 2) /* Kilograms to Pounds */
  {
    result = value * 2.20462;
  }
  else if(fromUnit ==  1 && toUnit == 3) /* Kilograms to Ounces */
  {
    result = value * 35.274;
  }
  else if(fromUnit == 2 && toUnit == 1) /* Pounds to Kilograms */
  {
    result = value * 0.453592;
  }
  else if(fromUnit == 2 && toUnit == 3) /* Pounds to Ounces */
  {
    result = value * 16.0;
  }
  else if(fromUnit == 3 && toUnit == 1) /* Ounces to Kilograms */
  {
    result = value * 0.0283495;
  }
  else if(fromUnit == 3 && toUnit == 2) /* Ounces to Pounds */
  {
    result = value * 0.0625;
  }
  else /* Invalid */
  {
    printf("Invalid units\n");
  }

  return result;
}

/* This function converts temperature units */
double temperatureConversion(double value, int fromUnit, int toUnit)
{
  double result;

  if(fromUnit == 1 && toUnit == 2) /* Celsius to Fahrenheit */
  {
    result = (value * 9.0/5.0) + 32.0;
  }
  else if(fromUnit == 1 && toUnit == 3) /* Celsius to Kelvin */
  {
    result = value + 273.15;
  }
  else if(fromUnit == 2 && toUnit == 1) /* Fahrenheit to Celsius */
  {
    result = (value - 32.0) * 5.0/9.0;
  }
  else if(fromUnit == 2 && toUnit == 3) /* Fahrenheit to Kelvin */
  {
    result = (value - 32.0) * 5.0/9.0 + 273.15;
  }
  else if(fromUnit == 3 && toUnit == 1) /* Kelvin to Celsius */
  {
    result = value - 273.15;
  }
  else if(fromUnit == 3 && toUnit == 2) /* Kelvin to Fahrenheit */
  {
    result = (value - 273.15) * 9.0/5.0 + 32.0;
  }
  else /* Invalid */
  {
    printf("Invalid units\n");
  }

  return result;
}