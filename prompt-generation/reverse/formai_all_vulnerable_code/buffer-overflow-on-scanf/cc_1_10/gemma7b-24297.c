//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Donald Knuth
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main() {
  double d, f, t, r, z;
  long l, h, w, n, m, i, j, k, x, y;

  printf("Welcome to the Ultimate Unit Converter!\n");

  printf("Please select an option:\n");
  printf("1. Convert meters to kilometers\n");
  printf("2. Convert liters to gallons\n");
  printf("3. Convert kilograms to pounds\n");
  printf("4. Convert degrees to radians\n");
  printf("5. Convert Fahrenheit to Celsius\n");

  scanf("%d", &n);

  switch (n) {
    case 1:
      printf("Enter the number of meters: ");
      scanf("%lf", &d);
      f = d * 1000;
      printf("The number of kilometers is: %.2lf\n", f);
      break;
    case 2:
      printf("Enter the number of liters: ");
      scanf("%lf", &d);
      t = d * 1000;
      printf("The number of gallons is: %.2lf\n", t);
      break;
    case 3:
      printf("Enter the number of kilograms: ");
      scanf("%lf", &d);
      r = d * 2.20462;
      printf("The number of pounds is: %.2lf\n", r);
      break;
    case 4:
      printf("Enter the number of degrees: ");
      scanf("%lf", &d);
      z = d * PI / 180;
      printf("The number of radians is: %.2lf\n", z);
      break;
    case 5:
      printf("Enter the temperature in Fahrenheit: ");
      scanf("%lf", &d);
      x = (d - 32) * 5 / 9;
      printf("The temperature in Celsius is: %.2lf\n", x);
      break;
  }

  return 0;
}