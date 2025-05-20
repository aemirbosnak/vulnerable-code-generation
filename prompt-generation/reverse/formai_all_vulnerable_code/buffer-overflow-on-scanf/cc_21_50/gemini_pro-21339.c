//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define U LLONG_MAX
#define MIN 0
#define S(n) (int)(n)
int main(void) {
  unsigned long long int n;
  char c, op, *e;
  while (1) {
    printf("Enter a number (0 to %llu): ", U);
    if (!scanf("%llu%c", &n, &c)) {
      printf("scanf error!\n");
      return EXIT_FAILURE;
    }
    if (c == '\n' || n < MIN || n > U) {
      printf("Invalid input!\n");
      continue;
    }
    if (op == 'e') {
      return EXIT_SUCCESS;
    }
    while (1) {
      printf("Enter an operation (-, x, /, s, %, e): ");
      if (!scanf(" %c%c", &op, &c)) {
        printf("scanf error!\n");
        return EXIT_FAILURE;
      }
      if (c == '\n') {
        break;
      }
      if (op != 'e') {
        continue;
      }
      break;
    }
    switch (op) {
      case 'e':
        return EXIT_SUCCESS;
      case '-':
        printf("Enter a number (0 to %llu): ", U);
        if (!scanf("%llu%c", &n, &c)) {
          printf("scanf error!\n");
          return EXIT_FAILURE;
        }
        if (c == '\n' || n < MIN || n > U) {
          printf("Invalid input!\n");
          continue;
        }
        printf("%llu\n", U - n);
        continue;
      case 'x':
        printf("Enter a number (0 to %llu): ", U);
        if (!scanf("%llu%c", &n, &c)) {
          printf("scanf error!\n");
          return EXIT_FAILURE;
        }
        if (c == '\n' || n < MIN || n > U) {
          printf("Invalid input!\n");
          continue;
        }
        n *= n;
        if (S(n) == (int)n) {
          printf("%llu\n", n);
        } else {
          printf("Overflow!\n");
        }
        continue;
      case '/':
        printf("Enter a number (0 to %llu): ", U);
        if (!scanf("%llu%c", &n, &c)) {
          printf("scanf error!\n");
          return EXIT_FAILURE;
        }
        if (c == '\n' || n < MIN || n > U) {
          printf("Invalid input!\n");
          continue;
        }
        if (n == 0) {
          printf("Division by 0!\n");
        } else {
          printf("%llu\n", U / n);
        }
        continue;
      case 's':
        n = sqrt(n);
        if (S(n) == (int)n) {
          printf("%llu\n", n);
        } else {
          printf("No perfect square root!\n");
        }
        continue;
      case '%':
        printf("Enter a number (0 to %llu): ", U);
        if (!scanf("%llu%c", &n, &c)) {
          printf("scanf error!\n");
          return EXIT_FAILURE;
        }
        if (c == '\n' || n < MIN || n > U) {
          printf("Invalid input!\n");
          continue;
        }
        printf("%llu\n", n % 2);
        continue;
      default:
        printf("Invalid operation!\n");
        continue;
    }
  }
  return EXIT_SUCCESS;
}