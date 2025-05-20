#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  float distance;
  int unit_from, unit_to;

  printf("Enter the distance: ");
  scanf("%f", &distance);

  printf("Enter the unit you are converting from: ");
  scanf("%d", &unit_from);

  printf("Enter the unit you are converting to: ");
  scanf("%d", &unit_to);

  switch (unit_from) {
    case 1:
      unit_from = 100;
      break;
    case 2:
      unit_from = 1000;
      break;
    case 3:
      unit_from = 1000000;
      break;
    case 4:
      unit_from = 2.54;
      break;
    case 5:
      unit_from = 3.28;
      break;
    case 6:
      unit_from = 1609;
      break;
  }

  switch (unit_to) {
    case 1:
      unit_to = 100;
      break;
    case 2:
      unit_to = 1000;
      break;
    case 3:
      unit_to = 1000000;
      break;
    case 4:
      unit_to = 2.54;
      break;
    case 5:
      unit_to = 3.28;
      break;
    case 6:
      unit_to = 1609;
      break;
  }

  distance *= unit_from;
  distance /= unit_to;

  printf("The converted distance is: %.2f", distance);

  return 0;
}
