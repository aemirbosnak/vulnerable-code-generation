//FormAI DATASET v1.0 Category: Unit converter ; Style: accurate
#include<stdio.h>

int main()
{
  int num, choice;
  float meter, km, cm, feet, inch, celcius, fahrenheit, kelvin;

  printf("Welcome to the unit converter\n");
  printf("Choose an option to proceed:\n");
  printf("1. Distance Converter\n");
  printf("2. Temperature Converter\n");
  printf("3. Exit\n");
  scanf("%d", &choice);

  switch(choice)
  {

    case 1: //Distance Converter
      printf("Enter the number you wish to convert:\n");
      scanf("%d", &num);

      meter = num*0.3048;
      km = num*0.0003048;
      cm = num*30.48;
      feet = num;
      inch = num*12.0;

      printf("\nConverting %d feet:\n", num);
      printf("%.3f meters\n", meter);
      printf("%.3f kilometers\n", km);
      printf("%.3f centimeters\n", cm);
      printf("%.3f feet\n", feet);
      printf("%.3f inches\n", inch);
      break;

    case 2: //Temperature Converter
      printf("Enter the temperature in Celcius:\n");
      scanf("%f", &celcius);

      fahrenheit = (celcius*(9.0/5.0))+32.0;
      kelvin = celcius + 273.15;

      printf("\nConverting %.2f degrees Celcius:\n", celcius);
      printf("%.2f degrees Fahrenheit\n", fahrenheit);
      printf("%.2f Kelvin\n", kelvin);
      break;

    case 3:
      printf("Thank you for using the unit converter.\n");
      break;

    default:
      printf("Invalid input. Please try again.\n");
      break;

  }

  return 0;
}