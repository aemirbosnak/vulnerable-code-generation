//FormAI DATASET v1.0 Category: Unit converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>

void displayMenu();
void temperatureConversion();
void lengthConversion();
void weightConversion();

int main()
{
  displayMenu();
  return 0;
}

void displayMenu()
{
  int choice;

  printf("**********************************************\n");
  printf("          Welcome to Unit Converter           \n");
  printf("**********************************************\n");
  printf("1. Temperature Conversion \n");
  printf("2. Length Conversion \n");
  printf("3. Weight Conversion \n");
  printf("4. Exit \n");

  printf("\nEnter your choice: ");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    temperatureConversion();
    break;

  case 2:
    lengthConversion();
    break;

  case 3:
    weightConversion();
    break;

  case 4:
    printf("\nExiting the program...\n");
    exit(0);

  default:
    printf("\nInvalid choice. Please try again.\n\n");
    displayMenu();
  }
}

void temperatureConversion()
{
  int choice;
  float temp;

  printf("\n Temperature Conversion Menu \n");
  printf("\n 1. Celsius to Fahrenheit \n");
  printf("\n 2. Fahrenheit to Celsius \n");
  printf("\n Enter your choice: ");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    printf("\n Enter temperature in Celsius: ");
    scanf("%f", &temp);
    printf("\n Temperature in Fahrenheit = %f", (temp * 9 / 5) + 32);
    break;

  case 2:
    printf("\n Enter temperature in Fahrenheit: ");
    scanf("%f", &temp);
    printf("\n Temperature in Celsius = %f", (temp - 32) * 5 / 9);
    break;

  default:
    printf("\nInvalid choice. Please try again. \n");
    temperatureConversion();
  }
}

void lengthConversion()
{
  int choice;
  float length;

  printf("\n Length Conversion Menu \n");
  printf("\n 1. Meter to Feet \n");
  printf("\n 2. Feet to Meter \n");
  printf("\n Enter your choice: ");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    printf("\n Enter length in meters: ");
    scanf("%f", &length);
    printf("\nLength in feet = %f", length * 3.28084);
    break;

  case 2:
    printf("\n Enter length in feet: ");
    scanf("%f", &length);
    printf("\nLength in meters = %f", length * 0.3048);
    break;

  default:
    printf("\nInvalid choice. Please try again. \n");
    lengthConversion();
  }
}

void weightConversion()
{
  int choice;
  float weight;

  printf("\n Weight Conversion Menu \n");
  printf("\n 1. Kilogram to Pounds \n");
  printf("\n 2. Pounds to Kilogram \n");
  printf("\n Enter your choice: ");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    printf("\n Enter weight in kilograms: ");
    scanf("%f", &weight);
    printf("\nWeight in pounds = %f", weight * 2.20462);
    break;

  case 2:
    printf("\nEnter weight in pounds: ");
    scanf("%f", &weight);
    printf("\nWeight in kilograms = %f", weight * 0.453592);
    break;

  default:
    printf("\nInvalid choice. Please try again. \n");
    weightConversion();
  }
}