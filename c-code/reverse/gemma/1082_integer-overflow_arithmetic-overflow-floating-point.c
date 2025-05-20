#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  float f;
  int n;
  printf("Enter the number of units: ");
  scanf("%d", &n);

  switch (n) {
    case 1:
      printf("Enter the value in centimeters: ");
      scanf("%f", &f);
      printf("The value in meters is: %.2f", f * 0.01);
      break;
    case 2:
      printf("Enter the value in meters: ");
      scanf("%f", &f);
      printf("The value in kilometers is: %.2f", f * 0.001);
      break;
    case 3:
      printf("Enter the value in kilometers: ");
      scanf("%f", &f);
      printf("The value in miles is: %.2f", f * 0.00062137);
      break;
    case 4:
      printf("Enter the value in inches: ");
      scanf("%f", &f);
      printf("The value in meters is: %.2f", f * 0.0254);
      break;
    case 5:
      printf("Enter the value in feet: ");
      scanf("%f", &f);
      printf("The value in meters is: %.2f", f * 0.3048);
      break;
  }

  return 0;
}
