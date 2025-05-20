//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>
#include <math.h>

// Define the C Unit Converter function
void unit_converter(double value, int from_unit, int to_unit) {
  switch (from_unit) {
    case 0: // Meters
      switch (to_unit) {
        case 1: // Kilometers
          printf("%f kilometers is equal to %f meters.\n", value, value * 1000);
          break;
        case 2: // Centimeters
          printf("%f centimeters is equal to %f meters.\n", value, value * 0.01);
          break;
        default:
          printf("Invalid unit conversion.\n");
          break;
      }
      break;
    case 1: // Kilometers
      switch (to_unit) {
        case 0: // Meters
          printf("%f kilometers is equal to %f meters.\n", value, value * 1000);
          break;
        case 2: // Centimeters
          printf("%f kilometers is equal to %f centimeters.\n", value, value * 1000 * 100);
          break;
        default:
          printf("Invalid unit conversion.\n");
          break;
      }
      break;
    case 2: // Centimeters
      switch (to_unit) {
        case 0: // Meters
          printf("%f centimeters is equal to %f meters.\n", value, value * 0.01);
          break;
        case 1: // Kilometers
          printf("%f centimeters is equal to %f kilometers.\n", value, value * 0.001);
          break;
        default:
          printf("Invalid unit conversion.\n");
          break;
      }
      break;
    default:
      printf("Invalid unit conversion.\n");
      break;
  }
}

int main() {
  double value;
  int from_unit, to_unit;

  printf("Enter the value: ");
  scanf("%lf", &value);

  printf("Enter the from unit (0 for meters, 1 for kilometers, 2 for centimeters): ");
  scanf("%d", &from_unit);

  printf("Enter the to unit (0 for meters, 1 for kilometers, 2 for centimeters): ");
  scanf("%d", &to_unit);

  unit_converter(value, from_unit, to_unit);

  return 0;
}