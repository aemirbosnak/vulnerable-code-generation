//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
//Enumerations
typedef enum {
  FALSE,
  TRUE
}BOOL;

//Prototypes
int* sieve_of_eratosthenes(const int n);
int* generate_primes_upto_given_number(const int n);
void print_array(const int* const array, const int size);

//Definitions
int* sieve_of_eratosthenes(const int n) {
  //Initialize the array
  BOOL* primes = (BOOL*)calloc((n + 1), sizeof(BOOL));
  for (int i = 0; i <= n; i++) {
    primes[i] = TRUE;
  }
  //Sieve out the non-primes
  for (int i = 2; i <= n; i++) {
    if (primes[i] == TRUE) {
      for (int j = i * i; j <= n; j += i) {
        primes[j] = FALSE;
      }
    }
  }
  //Count the number of primes
  int count = 0;
  for (int i = 2; i <= n; i++) {
    if (primes[i] == TRUE) {
      count++;
    }
  }
  //Allocate memory for the array of primes
  int* prime_numbers = (int*)malloc(count * sizeof(int));
  //Store the primes in the array
  int index = 0;
  for (int i = 2; i <= n; i++) {
    if (primes[i] == TRUE) {
      prime_numbers[index++] = i;
    }
  }
  //Free the memory allocated for the boolean array
  free(primes);
  //Return the array of primes
  return prime_numbers;
}
int* generate_primes_upto_given_number(const int n) {
  if (n <= 1) {
    return NULL;
  }
  return sieve_of_eratosthenes(n);
}
void print_array(const int* const array, const int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
//Driver code
int main() {
  int n;
  printf("Enter a positive integer: ");
  scanf("%d", &n);
  int* prime_numbers = generate_primes_upto_given_number(n);
  if (prime_numbers == NULL) {
    printf("No prime numbers found.\n");
  } else {
    printf("The prime numbers upto %d are: ", n);
    print_array(prime_numbers, n);
    free(prime_numbers);
  }
  return 0;
}