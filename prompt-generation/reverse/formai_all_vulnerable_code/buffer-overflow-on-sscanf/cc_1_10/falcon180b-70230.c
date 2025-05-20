//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
  char* name;
  int value;
} BinaryConverter;

BinaryConverter binary_converters[] = {
  {"000", 0},
  {"001", 1},
  {"010", 2},
  {"011", 3},
  {"100", 4},
  {"101", 5},
  {"110", 6},
  {"111", 7}
};

int main() {
  char input_buffer[MAX_LINE_LENGTH];
  char* token;
  int decimal_value = 0;
  int binary_value = 0;
  int i;

  printf("Enter a decimal number: ");
  fgets(input_buffer, MAX_LINE_LENGTH, stdin);

  // Remove newline character
  input_buffer[strcspn(input_buffer, "\n")] = '\0';

  // Convert string to integer
  sscanf(input_buffer, "%d", &decimal_value);

  // Convert decimal to binary
  for (i = 0; i < sizeof(binary_converters) / sizeof(BinaryConverter); i++) {
    if (decimal_value == binary_converters[i].value) {
      strcpy(input_buffer, binary_converters[i].name);
      break;
    }
  }

  // Print result
  printf("Binary equivalent: %s\n", input_buffer);

  return 0;
}