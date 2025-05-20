//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <input> <output>", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *input = fopen(argv[1], "r");
  if (!input) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  FILE *output = fopen(argv[2], "w");
  if (!output) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  char line[1024];
  while (fgets(line, sizeof(line), input)) {
    // Remove whitespace
    char *ptr = line;
    while (*ptr == ' ' || *ptr == '\t') {
      ptr++;
    }

    // Convert to integer
    int value = 0;
    for (; *ptr != '\0'; ptr++) {
      if (*ptr >= '0' && *ptr <= '9') {
        value = value * 10 + *ptr - '0';
      } else if (*ptr >= 'a' && *ptr <= 'f') {
        value = value * 16 + *ptr - 'a' + 10;
      } else if (*ptr >= 'A' && *ptr <= 'F') {
        value = value * 16 + *ptr - 'A' + 10;
      } else {
        fprintf(output, "Invalid character: %c", *ptr);
        continue;
      }
    }

    // Convert to binary
    char binary[33];
    int i = 0;
    while (value > 0) {
      binary[i++] = value & 1 ? '1' : '0';
      value >>= 1;
    }
    binary[i] = '\0';

    // Reverse the binary string
    int length = strlen(binary);
    for (int j = 0; j < length / 2; j++) {
      char temp = binary[j];
      binary[j] = binary[length - 1 - j];
      binary[length - 1 - j] = temp;
    }

    // Print the binary string
    fprintf(output, "%s", binary);
  }

  fclose(input);
  fclose(output);

  return EXIT_SUCCESS;
}