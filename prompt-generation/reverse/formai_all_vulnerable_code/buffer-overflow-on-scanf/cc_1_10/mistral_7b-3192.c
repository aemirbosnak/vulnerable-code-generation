//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Relaxed style function name with a wink
void fibonacci_sequence_generator(int n, int *fib_seq) {
  if (n <= 0) {
    printf("Oops! You forgot to provide a positive number, buddy.\n");
    exit(EXIT_FAILURE);
  }

  // Base cases
  if (n == 1) {
    fib_seq[0] = 0;
    fib_seq[1] = 1;
    printf("Fibonacci sequence with %d elements:\n", n);
    printf("%d\n", fib_seq[0]);
    return;
  }

  if (n == 2) {
    fib_seq[0] = 0;
    fib_seq[1] = 1;
    fib_seq[2] = 1;
    printf("Fibonacci sequence with %d elements:\n", n);
    printf("%d %d\n", fib_seq[0], fib_seq[1]);
    return;
  }

  // Recursive case
  fib_seq[0] = 0;
  fib_seq[1] = 1;
  fib_seq[2] = 1;
  int i;
  for (i = 3; i < n; i++) {
    fib_seq[i] = fib_seq[i - 1] + fib_seq[i - 2];
  }
  printf("Fibonacci sequence with %d elements:\n", n);
  for (i = 0; i < n; i++) {
    printf("%d ", fib_seq[i]);
  }
  printf("\n");
}

// Main function
int main() {
  int n;
  printf("Hey there! What's the length of the Fibonacci sequence you want to generate?\n");
  scanf("%d", &n);

  if (n <= 0) {
    printf("Uh-oh! You need to provide a positive number, buddy.\n");
    return EXIT_FAILURE;
  }

  int *fib_seq = (int *)calloc(n, sizeof(int));
  fibonacci_sequence_generator(n, fib_seq);

  free(fib_seq);
  return EXIT_SUCCESS;
}