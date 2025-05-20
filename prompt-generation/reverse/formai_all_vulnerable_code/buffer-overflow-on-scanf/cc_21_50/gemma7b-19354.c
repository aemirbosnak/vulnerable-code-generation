//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
  int from_num, to_num, from_unit, to_unit;

  printf("Enter the number you want to convert: ");
  scanf("%d", &from_num);

  printf("Enter the unit you want to convert from: ");
  scanf("%d", &from_unit);

  printf("Enter the unit you want to convert to: ");
  scanf("%d", &to_unit);

  switch (from_unit) {
    case 1:
      switch (to_unit) {
        case 2:
          to_num = from_num * 2;
          break;
        case 3:
          to_num = from_num * 3;
          break;
        case 4:
          to_num = from_num * 4;
          break;
        case 5:
          to_num = from_num * 5;
          break;
      }
      break;
    case 2:
      switch (to_unit) {
        case 1:
          to_num = from_num / 2;
          break;
        case 3:
          to_num = from_num * 2;
          break;
        case 4:
          to_num = from_num * 3;
          break;
        case 5:
          to_num = from_num * 5;
          break;
      }
      break;
    case 3:
      switch (to_unit) {
        case 1:
          to_num = from_num / 3;
          break;
        case 2:
          to_num = from_num * 2;
          break;
        case 4:
          to_num = from_num * 3;
          break;
        case 5:
          to_num = from_num * 5;
          break;
      }
      break;
    case 4:
      switch (to_unit) {
        case 1:
          to_num = from_num / 4;
          break;
        case 2:
          to_num = from_num * 2;
          break;
        case 3:
          to_num = from_num * 3;
          break;
        case 5:
          to_num = from_num * 5;
          break;
      }
      break;
    case 5:
      switch (to_unit) {
        case 1:
          to_num = from_num / 5;
          break;
        case 2:
          to_num = from_num * 2;
          break;
        case 3:
          to_num = from_num * 3;
          break;
        case 4:
          to_num = from_num * 4;
          break;
      }
      break;
  }

  printf("The converted number is: %d", to_num);

  return 0;
}