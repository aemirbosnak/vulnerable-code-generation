//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint;

int main() {
  char *input = NULL;
  size_t inputlen = 0;
  ssize_t inputchars;
  int value = 0;
  int index = 0;
  int pos = 0;
  int base = 10;

  printf("Enter a number to convert: ");
  inputchars = getline(&input, &inputlen, stdin);
  if (inputchars == -1) {
    printf("Error reading input\n");
    return EXIT_FAILURE;
  } else {
    input[inputchars - 1] = '\0';
  }

  if (strstr(input, "0b") != NULL) {
    base = 2;
    index = 2;
  } else if (strstr(input, "0o") != NULL) {
    base = 8;
    index = 2;
  } else if (strstr(input, "0x") != NULL) {
    base = 16;
    index = 2;
  }

  for (int i = index; i < inputchars - 1; i++) {
    if (input[i] >= '0' && input[i] <= '9') {
      pos = input[i] - '0';
    } else if (input[i] >= 'a' && input[i] <= 'f') {
      pos = input[i] - 'a' + 10;
    } else if (input[i] >= 'A' && input[i] <= 'F') {
      pos = input[i] - 'A' + 10;
    } else {
      printf("Invalid character '%c' in input\n", input[i]);
      return EXIT_FAILURE;
    }
    value = value * base + pos;
  }

  printf("%s in base %d is %d in base 10\n", input, base, value);

  free(input);
  return EXIT_SUCCESS;
}