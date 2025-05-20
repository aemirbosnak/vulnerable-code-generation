//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: surprised
#include <stdio.h>

// Function to print a surprised message
void surprised(int depth) {
  if (depth == 1) {
    printf("OH MY GOSH! \n");
  } else if (depth == 2) {
    printf("WHOA, WAIT A MINUTE! \n");
  } else if (depth == 3) {
    printf("GASP! ARE YOU SERIOUS?! \n");
  } else {
    printf("OMG, I CAN'T BELIEVE IT! \n");
  }
}

// Function to calculate factorial using recursion
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n-1);
  }
}

int main() {
  int n = 5;
  int depth = 0;

  // Call the function with a depth of 0
  surprised(depth);

  // Calculate the factorial of 5 using recursion
  n = factorial(n);

  // Call the function again with a depth of 1
  surprised(depth + 1);

  // Calculate the factorial of 5 again using recursion
  n = factorial(n);

  // Call the function again with a depth of 2
  surprised(depth + 2);

  // Calculate the factorial of 5 again using recursion
  n = factorial(n);

  // Call the function again with a depth of 3
  surprised(depth + 3);

  // Print the final result
  printf("The factorial of 5 is: %d\n", n);

  return 0;
}