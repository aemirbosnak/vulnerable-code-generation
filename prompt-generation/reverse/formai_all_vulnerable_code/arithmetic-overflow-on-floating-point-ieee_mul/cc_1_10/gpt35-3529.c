//FormAI DATASET v1.0 Category: Unit converter ; Style: intelligent
#include<stdio.h>

int main()
{
  float km, m, cm, inch, feet;

  int option;

  printf("Welcome to the Intelligent Unit Converter\n");

  printf("\nWhich conversion would you like to perform today?\n");
  printf("1. Kilometers to Miles\n");
  printf("2. Meters to Centimeters\n");
  printf("3. Inches to Feet\n");
  printf("4. Quit\n");

  printf("Enter your choice: ");
  scanf("%d", &option);

  switch(option)
  {
    case 1:
      printf("Enter distance in kilometers: ");
      scanf("%f", &km);

      m = km * 0.621371;
      printf("%.2f km is equal to %.2f miles", km, m);
      break;

    case 2:
      printf("Enter distance in meters: ");
      scanf("%f", &m);

      cm = m * 100;
      printf("%.2f m is equal to %.2f cm", m, cm);
      break;

    case 3:
      printf("Enter distance in inches: ");
      scanf("%f", &inch);

      feet = inch / 12;
      printf("%.2f inches is equal to %.2f feet", inch, feet);
      break;

    case 4:
      printf("Thank you for using the Intelligent Unit Converter");
      break;
    default:
      printf("Invalid option selected");
      break;
  }

  return 0;
}