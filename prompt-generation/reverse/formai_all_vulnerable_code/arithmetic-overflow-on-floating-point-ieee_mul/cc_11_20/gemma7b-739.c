//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num;
  float fnum;
  char unit;
  float factor = 0;

  printf("Enter the number: ");
  scanf("%f", &fnum);

  printf("Enter the unit: ");
  scanf(" %c", &unit);

  switch (unit) {
    case 'm':
      factor = 1000;
      break;
    case 'kg':
      factor = 1000;
      break;
    case 'g':
      factor = 1000;
      break;
    case 'L':
      factor = 1000;
      break;
    case 't':
      factor = 1000;
      break;
  }

  num = (int)(fnum * factor);

  switch (unit) {
    case 'm':
      printf("The number in meters is: %d", num);
      break;
    case 'kg':
      printf("The number in kilograms is: %d", num);
      break;
    case 'g':
      printf("The number in grams is: %d", num);
      break;
    case 'L':
      printf("The number in liters is: %d", num);
      break;
    case 't':
      printf("The number in tons is: %d", num);
      break;
  }

  return 0;
}