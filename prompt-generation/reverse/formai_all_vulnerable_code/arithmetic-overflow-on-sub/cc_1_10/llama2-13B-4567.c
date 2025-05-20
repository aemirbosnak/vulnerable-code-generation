//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define a recursive function to calculate the factorial of a given number
int factorial(int n) {
  if (n == 0) {
    return 1; // base case
  }

  // recursive case
  return n * factorial(n-1);
}

int main() {
  int choice;

  // print a menu of options
  printf("Welcome to the Factorial Fiesta!\n");
  printf("Please select an option from the following menu:\n");
  printf("1. Calculate the factorial of a given number\n");
  printf("2. Explore the beautiful garden\n");
  printf("3. Take a nap under the shade of the tree\n");
  printf("4. Play with the friendly squirrels\n");
  printf("5. Enjoy a refreshing drink from the fountain\n");

  // get the user's selection
  scanf("%d", &choice);

  // handle user's selection
  switch (choice) {
    case 1: {
      int num;
      printf("Enter a number: ");
      scanf("%d", &num);
      printf("The factorial of %d is %d\n", num, factorial(num));
      break;
    }
    case 2: {
      printf("Let's explore the beautiful garden together!\n");
      // code to explore the garden
      break;
    }
    case 3: {
      printf("Take a nap under the shade of the tree, and let's dream of "
             "factorials together!\n");
      // code to nap
      break;
    }
    case 4: {
      printf("Let's play with the friendly squirrels! They love "
             "factorials too!\n");
      // code to play with squirrels
      break;
    }
    case 5: {
      printf("Let's enjoy a refreshing drink from the fountain! "
             "Factorials are thirsty work, you know!\n");
      // code to drink from fountain
      break;
    }
    default:
      printf("Invalid selection. Please try again.\n");
      break;
  }

  return 0;
}