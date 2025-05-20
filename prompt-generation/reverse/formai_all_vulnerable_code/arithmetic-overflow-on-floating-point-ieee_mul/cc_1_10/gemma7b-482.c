//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main() {
  char input_buffer[MAX_BUFFER_SIZE];
  float temperature, conversion_factor;
  int conversion_type;

  printf("Enter the temperature: ");
  fgets(input_buffer, MAX_BUFFER_SIZE, stdin);
  temperature = atof(input_buffer);

  printf("Enter the conversion type (C/F/K): ");
  fgets(input_buffer, MAX_BUFFER_SIZE, stdin);
  conversion_type = get_conversion_type(input_buffer);

  switch (conversion_type) {
    case 1:
      conversion_factor = 1.8;
      break;
    case 2:
      conversion_factor = 0.5556;
      break;
    case 3:
      conversion_factor = 2.2222;
      break;
    default:
      printf("Invalid conversion type.\n");
      exit(1);
  }

  conversion_factor *= temperature;

  switch (conversion_type) {
    case 1:
      printf("The converted temperature is: %.2f F.\n", conversion_factor);
      break;
    case 2:
      printf("The converted temperature is: %.2f K.\n", conversion_factor);
      break;
    case 3:
      printf("The converted temperature is: %.2f C.\n", conversion_factor);
      break;
  }

  return 0;
}

int get_conversion_type(char *buffer) {
  if (strcmp(buffer, "C") == 0) {
    return 1;
  } else if (strcmp(buffer, "F") == 0) {
    return 2;
  } else if (strcmp(buffer, "K") == 0) {
    return 3;
  } else {
    return -1;
  }
}