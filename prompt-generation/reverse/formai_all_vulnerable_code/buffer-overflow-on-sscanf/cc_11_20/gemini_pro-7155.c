//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

#define paranoia_is_good_mkay 1

int main(int argc, char **argv) {
  int32_t a, b, c;
  char input[1024];

  printf("Enter two numbers: ");
  if (fgets(input, sizeof(input), stdin) == NULL) {
    fprintf(stderr, "Error reading input\n");
    return EXIT_FAILURE;
  }

  // Check if the input is valid
  if (sscanf(input, "%" SCNd32 " %" SCNd32, &a, &b) != 2) {
    fprintf(stderr, "Invalid input\n");
    return EXIT_FAILURE;
  }

  // Check if the numbers are valid
  if (a < 0 || b < 0) {
    fprintf(stderr, "Invalid numbers\n");
    return EXIT_FAILURE;
  }

  // Check if the numbers are too large
  if (a > INT32_MAX / 2 || b > INT32_MAX / 2) {
    fprintf(stderr, "Numbers too large\n");
    return EXIT_FAILURE;
  }

  // Check if the result will overflow
  if (a > INT32_MAX - b) {
    fprintf(stderr, "Result will overflow\n");
    return EXIT_FAILURE;
  }

  // Check if the result will underflow
  if (a < INT32_MIN + b) {
    fprintf(stderr, "Result will underflow\n");
    return EXIT_FAILURE;
  }

  // Check if the result is zero
  if (a == 0 && b == 0) {
    c = 0;
  } else {
    // Check if the result is negative
    if (a < 0 || b < 0) {
      c = -1;
    } else {
      c = 1;
    }

    // Check if the result is odd
    if (a % 2 == 1 || b % 2 == 1) {
      c *= -1;
    }
  }

  // Check if the result is even
  if (c % 2 == 0) {
    printf("The result is even\n");
  } else {
    printf("The result is odd\n");
  }

  return EXIT_SUCCESS;
}