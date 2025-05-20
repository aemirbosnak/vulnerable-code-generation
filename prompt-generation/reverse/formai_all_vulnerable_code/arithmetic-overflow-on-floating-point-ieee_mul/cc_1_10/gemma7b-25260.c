//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_CONVERSION_NUMBER 10

typedef struct Conversion {
  char unit_from;
  char unit_to;
  double value;
} Conversion;

void convert_temperature(Conversion *conversion) {
  double conversion_factor;
  switch (conversion->unit_from) {
    case 'C':
      conversion_factor = 1.0;
      break;
    case 'F':
      conversion_factor = 1.8 + 0.005556 * conversion->value;
      break;
    case 'K':
      conversion_factor = 1.0 + 0.002778 * conversion->value;
      break;
  }

  conversion->value = conversion_factor * conversion->value;

  switch (conversion->unit_to) {
    case 'C':
      conversion->value = conversion->value - 273.15;
      break;
    case 'F':
      conversion->value = (conversion->value - 273.15) * 1.8 + 32.0;
      break;
    case 'K':
      conversion->value = conversion->value - 273.15;
      break;
  }
}

int main() {
  Conversion conversions[MAX_CONVERSION_NUMBER];
  int i = 0;

  conversions[i].unit_from = 'F';
  conversions[i].unit_to = 'C';
  conversions[i].value = 70.0;

  conversions[i+1].unit_from = 'K';
  conversions[i+1].unit_to = 'F';
  conversions[i+1].value = 20.0;

  for (i = 0; i < MAX_CONVERSION_NUMBER; i++) {
    convert_temperature(&conversions[i]);
  }

  for (i = 0; i < MAX_CONVERSION_NUMBER; i++) {
    printf("Conversion from %c to %c: %.2lf -> %.2lf\n", conversions[i].unit_from, conversions[i].unit_to, conversions[i].value, conversions[i].value);
  }

  return 0;
}