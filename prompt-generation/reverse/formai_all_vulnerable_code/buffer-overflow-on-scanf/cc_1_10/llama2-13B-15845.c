//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define MAGIC_NUMBER 42

// Declare a curious function to calculate the factorial of a given number
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int main() {
  // Ask the user for their name
  printf("What is your name? ");
  char name[MAX_LENGTH];
  fgets(name, MAX_LENGTH, stdin);

  // Calculate the factorial of the user's name length
  int factorial_name_length = factorial(strlen(name));

  // Print the result in a curious way
  printf("Your name has %d letters, and its factorial is %d!\n", strlen(name), factorial_name_length);

  // Ask the user for a number
  printf("Please enter a number: ");
  int number;
  scanf("%d", &number);

  // Calculate the factorial of the given number
  int factorial_number = factorial(number);

  // Print the result in a curious way
  printf("The factorial of %d is %d!\n", number, factorial_number);

  // Ask the user for a word
  printf("Please enter a word: ");
  char word[MAX_LENGTH];
  fgets(word, MAX_LENGTH, stdin);

  // Calculate the factorial of the word length
  int factorial_word_length = factorial(strlen(word));

  // Print the result in a curious way
  printf("Your word has %d letters, and its factorial is %d!\n", strlen(word), factorial_word_length);

  // Ask the user for a number between 1 and 10
  printf("Please enter a number between 1 and 10: ");
  int number_between_1_and_10;
  scanf("%d", &number_between_1_and_10);

  // Calculate the factorial of the given number
  int factorial_number_between_1_and_10 = factorial(number_between_1_and_10);

  // Print the result in a curious way
  printf("The factorial of %d is %d!\n", number_between_1_and_10, factorial_number_between_1_and_10);

  return 0;
}