//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 1024
#define BINARY_PREFIX "0b"

void binary_to_decimal(char *binary_string) {
  int i, j, sum = 0;
  char digit;

  for (i = 0; binary_string[i] != '\0'; i++) {
    digit = binary_string[i];
    if (digit >= '0' && digit <= '9') {
      sum *= 10;
      sum += (digit - '0');
    } else if (digit >= 'a' && digit <= 'f') {
      sum *= 16;
      sum += (digit - 'a' + 10);
    } else if (digit >= 'A' && digit <= 'F') {
      sum *= 16;
      sum += (digit - 'A' + 10);
    }
  }
  printf("%d\n", sum);
}

void decimal_to_binary(int number) {
  int i, j, binary[MAX_LENGTH] = {0};
  char digit;

  do {
    binary[i++] = (number % 2) + '0';
    number /= 2;
  } while (number > 0);

  for (i = 0; i < MAX_LENGTH; i++) {
    if (binary[i] != '0') {
      break;
    }
  }

  j = i - 1;
  while (j >= 0) {
    digit = binary[j];
    binary[j] = binary[i];
    binary[i] = digit;
    j--;
  }

  printf("%s\n", binary);
}

int main() {
  char binary_string[] = "11010110";
  int number = strtol(binary_string, NULL, 2);

  binary_to_decimal(binary_string);
  decimal_to_binary(number);

  return 0;
}