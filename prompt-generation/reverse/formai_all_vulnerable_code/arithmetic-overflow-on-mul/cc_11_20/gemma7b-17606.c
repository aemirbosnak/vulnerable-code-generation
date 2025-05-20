//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <math.h>

int main() {
  int unit_from, unit_to, number;

  printf("Enter the unit you want to convert from: ");
  scanf("%d", &unit_from);

  printf("Enter the unit you want to convert to: ");
  scanf("%d", &unit_to);

  printf("Enter the number you want to convert: ");
  scanf("%d", &number);

  switch (unit_from) {
    case 1:
      switch (unit_to) {
        case 2:
          printf("%d liters is equal to %f gallons.\n", number, (number * 1.056) / 10);
          break;
        case 3:
          printf("%d liters is equal to %f quarts.\n", number, (number * 1.056) / 4);
          break;
        case 4:
          printf("%d liters is equal to %f pints.\n", number, (number * 1.056) / 8);
          break;
      }
      break;
    case 2:
      switch (unit_to) {
        case 1:
          printf("%f gallons is equal to %d liters.\n", number, (number * 10) / 1.056);
          break;
        case 3:
          printf("%f gallons is equal to %d quarts.\n", number, (number * 10) / 4);
          break;
        case 4:
          printf("%f gallons is equal to %d pints.\n", number, (number * 10) / 8);
          break;
      }
      break;
    case 3:
      switch (unit_to) {
        case 1:
          printf("%d quarts is equal to %f liters.\n", number, (number * 4) / 1.056);
          break;
        case 2:
          printf("%d quarts is equal to %f gallons.\n", number, (number * 4) / 10);
          break;
        case 4:
          printf("%d quarts is equal to %d pints.\n", number, (number * 4) / 8);
          break;
      }
      break;
    case 4:
      switch (unit_to) {
        case 1:
          printf("%d pints is equal to %f liters.\n", number, (number * 8) / 1.056);
          break;
        case 2:
          printf("%d pints is equal to %f gallons.\n", number, (number * 8) / 10);
          break;
        case 3:
          printf("%d pints is equal to %d quarts.\n", number, (number * 8) / 4);
          break;
      }
      break;
  }

  return 0;
}