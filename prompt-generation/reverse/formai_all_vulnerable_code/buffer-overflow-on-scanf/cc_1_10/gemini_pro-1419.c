//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Is the number prime?
bool is_prime(int number) {
  if (number < 2) {
    return false;
  }
  for (int i = 2; i * i <= number; i++) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  // Let the user choose the range of numbers to check
  int start, end;
  printf("Enter the starting number: ");
  scanf("%d", &start);
  printf("Enter the ending number: ");
  scanf("%d", &end);

  // Validate the input
  if (start < 0 || end < 0 || start > end) {
    printf("Invalid input. Please enter valid numbers.\n");
    return 1;
  }

  // Declare an array to store the prime numbers
  int *prime_numbers = malloc(sizeof(int) * (end - start + 1));
  if (prime_numbers == NULL) {
    printf("Failed to allocate memory. Exiting now.\n");
    return 1;
  }

  // Find the prime numbers in the given range
  int prime_count = 0;
  for (int i = start; i <= end; i++) {
    if (is_prime(i)) {
      prime_numbers[prime_count++] = i;  
    }
  }

  // Print the prime numbers
  printf("The prime numbers in the range %d to %d are:\n", start, end);
  for (int i = 0; i < prime_count; i++) {
    printf("%d ", prime_numbers[i]);
  }
  printf("\n");

  // Free the allocated memory
  free(prime_numbers);

  return 0;
}