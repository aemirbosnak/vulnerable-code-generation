//FormAI DATASET v1.0 Category: Educational ; Style: inquisitive
#include <stdio.h>

int main() {

  int n;

  printf("Enter a number: ");
  scanf("%d", &n);

  if (n > 1) {

    int i, flag = 0;

    for (i = 2; i <= n / 2; i++) {

      if (n % i == 0) {

        flag = 1;
        break;

      }

    }

    if (flag == 0)
      printf("%d is a prime number.", n);
    else
      printf("%d is not a prime number.", n);

  } else {

    printf("Input number must be greater than 1.");

  }

  return 0;

}

/*
 * Program to check if user input is prime or not
 * 
 * In this program, the user is prompted to enter a number and the program
 * checks if it is a prime number or not. It uses a for loop to check all 
 * numbers from 2 to half the input value to see if any are factors.
 * If any factors are found, the program sets a flag to 1 to indicate
 * that the number is not prime. If no factors are found, the program
 * sets the flag to 0 to indicate that the number is prime.
 * Finally, the program prints out a message to indicate whether the
 * input value is prime or not.
 * 
 * This program demonstrates the use of if-else statements, for loops, 
 * and variables in C programming. It is a useful tool for learning about
 * basic programming concepts and logic.
 */