//FormAI DATASET v1.0 Category: Unit converter ; Style: safe
#include <stdio.h>

int main() {
  char from, to;
  double value, result;
 
  printf("\nEnter the unit to convert from (C, F, K, M): ");
  scanf("%c", &from);
 
  printf("Enter the value to convert: ");
  scanf("%lf", &value);
 
  printf("Enter the unit to convert to (C, F, K, M): ");
  scanf(" %c", &to);
 
  if (from == 'C') {
    if (to == 'F') {
      result = (value * 1.8) + 32;
      printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", value, result);
    } else if (to == 'K') {
      result = value + 273.15;
      printf("%.2lf degrees Celsius is equal to %.2lf degrees Kelvin.\n", value, result);
    } else if (to == 'M') {
      result = value * 100;
      printf("%.2lf degrees Celsius is equal to %.2lf millidegrees Celsius.\n", value, result);
    } else {
      printf("Error: Invalid input.\n");
    }
  } else if (from == 'F') {
    if (to == 'C') {
      result = (value - 32) / 1.8;
      printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", value, result);
    } else if (to == 'K') {
      result = (value + 459.67) / 1.8;
      printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Kelvin.\n", value, result);
    } else if (to == 'M') {
      result = (value - 32) * 1000 / 1.8;
      printf("%.2lf degrees Fahrenheit is equal to %.2lf millidegrees Celsius.\n", value, result);
    } else {
      printf("Error: Invalid input.\n");
    }
  } else if (from == 'K') {
    if (to == 'C') {
      result = value - 273.15;
      printf("%.2lf degrees Kelvin is equal to %.2lf degrees Celsius.\n", value, result);
    } else if (to == 'F') {
      result = (value * 1.8) - 459.67;
      printf("%.2lf degrees Kelvin is equal to %.2lf degrees Fahrenheit.\n", value, result);
    } else if (to == 'M') {
      result = (value - 273.15) * 1000;
      printf("%.2lf degrees Kelvin is equal to %.2lf millidegrees Celsius.\n", value, result);
    } else {
      printf("Error: Invalid input.\n");
    }
  } else if (from == 'M') {
    if (to == 'C') {
      result = value / 100;
      printf("%.2lf millidegrees Celsius is equal to %.2lf degrees Celsius.\n", value, result);
    } else if (to == 'F') {
      result = (value * 1.8 / 1000) + 32;
      printf("%.2lf millidegrees Celsius is equal to %.2lf degrees Fahrenheit.\n", value, result);
    } else if (to == 'K') {
      result = value / 1000 + 273.15;
      printf("%.2lf millidegrees Celsius is equal to %.2lf degrees Kelvin.\n", value, result);
    } else {
      printf("Error: Invalid input.\n");
    }
  } else {
    printf("Error: Invalid input.\n");
  }
 
  return 0;
}