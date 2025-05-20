//FormAI DATASET v1.0 Category: Pattern printing ; Style: genious
#include <stdio.h>

int main() {
  int size;
  printf("Enter the size of the pattern (odd number): ");
  scanf("%d", &size);

  // Check if entered size is odd
  if (size % 2 == 0) {
    printf("Please enter an odd number!\n");
    return 0;
  }

  printf("\n");

  // Upper part of the pattern
  for (int i = 0; i < (size / 2) + 1; i++) {
    // Printing spaces
    for (int j = 0; j < size - i - 1; j++) {
      printf(" ");
    }

    // Printing ascending numbers
    for (int j = 0; j <= i; j++) {
      printf("%d", j + 1);
    }

    // Printing descending numbers
    for (int j = i - 1; j >= 0; j--) {
      printf("%d", j + 1);
    }

    printf("\n");
  }

  // Lower part of the pattern
  for (int i = (size / 2) - 1; i >= 0; i--) {
    // Printing spaces
    for (int j = 0; j < size - i - 1; j++) {
      printf(" ");
    }

    // Printing ascending numbers
    for (int j = 0; j <= i; j++) {
      printf("%d", j + 1);
    }

    // Printing descending numbers
    for (int j = i - 1; j >= 0; j--) {
      printf("%d", j + 1);
    }

    printf("\n");
  }

  printf("\n");

  return 0;
}