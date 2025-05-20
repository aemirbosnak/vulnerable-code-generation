//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>

void main() {
  system("clear");
  int choice, temp, unit;
  char name[20];

  printf("Welcome, traveler! What's your name?\n");
  scanf("%s", name);

  printf("Hey, %s, choose your temperature unit:\n", name);
  printf("1. Fahrenheit\n");
  printf("2. Celsius\n");
  printf("3. Kelvin\n");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Please enter the temperature in Fahrenheit:");
      scanf("%d", &temp);
      unit = 1;
      break;
    case 2:
      printf("Please enter the temperature in Celsius:");
      scanf("%d", &temp);
      unit = 2;
      break;
    case 3:
      printf("Please enter the temperature in Kelvin:");
      scanf("%d", &temp);
      unit = 3;
      break;
    default:
      printf("Invalid input. Please try again.\n");
      return;
  }

  switch (unit) {
    case 1:
      temp = (temp - 32) * 5 / 9;
      printf("%s, your temperature in Celsius is: %d\n", name, temp);
      break;
    case 2:
      temp = (temp * 9 / 5) + 32;
      printf("%s, your temperature in Fahrenheit is: %d\n", name, temp);
      break;
    case 3:
      temp = temp - 273.15;
      printf("%s, your temperature in Kelvin is: %d\n", name, temp);
      break;
  }

  system("pause");
}