//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: systematic
#include <stdio.h>

// Function to print the pattern
void printPattern(int n) {
  int i, j, k, l;

  // Loop to print the upper part of the pattern
  for (i = 1; i <= n / 2; i++) {
    // Loop to print spaces
    for (j = 1; j <= n - i; j++) {
      printf(" ");
    }

    // Loop to print stars
    for (k = 1; k <= 2 * i - 1; k++) {
      printf("*");
    }

    // Move to the next line
    printf("\n");
  }

  // Loop to print the lower part of the pattern
  for (i = n / 2; i >= 1; i--) {
    // Loop to print spaces
    for (j = 1; j <= n - i; j++) {
      printf(" ");
    }

    // Loop to print stars
    for (k = 1; k <= 2 * i - 1; k++) {
      printf("*");
    }

    // Move to the next line
    printf("\n");
  }
}

// Main function
int main() {
  int n;

  // Get the input from the user
  printf("Enter the number of rows: ");
  scanf("%d", &n);

  // Print the pattern
  printPattern(n);

  return 0;
}