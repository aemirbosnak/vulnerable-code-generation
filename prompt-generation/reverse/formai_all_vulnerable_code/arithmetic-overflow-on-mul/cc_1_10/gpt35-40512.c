//FormAI DATASET v1.0 Category: Arithmetic ; Style: excited
#include <stdio.h>

// Welcome to the most exciting arithmetic program you have ever seen!
// Are you ready to have some fun with numbers? Let's get started!

int main() {

  int number1 = 10;
  int number2 = 5;

  int sum = number1 + number2;
  int difference = number1 - number2;
  int product = number1 * number2;
  int quotient = number1 / number2;
  int modulus = number1 % number2;

  // Let's print out our results to see what we've got!

  printf("The Sum of %d and %d is: %d\n", number1, number2, sum);
  printf("The Difference of %d and %d is: %d\n", number1, number2, difference);
  printf("The Product of %d and %d is: %d\n", number1, number2, product);
  printf("The Quotient of %d and %d is: %d\n", number1, number2, quotient);
  printf("The Modulus of %d and %d is: %d\n", number1, number2, modulus);

  printf("*drumroll please*\n");

  // Now, let's do some more exciting arithmetic with user input!

  int userNumber1;
  int userNumber2;

  printf("Enter your two favorite numbers: ");
  scanf("%d %d", &userNumber1, &userNumber2);

  int userSum = userNumber1 + userNumber2;
  int userDifference = userNumber1 - userNumber2;
  int userProduct = userNumber1 * userNumber2;
  int userQuotient = userNumber1 / userNumber2;
  int userModulus = userNumber1 % userNumber2;

  printf("Your Numbers Are %d and %d WOW So Cool! \n", userNumber1, userNumber2);

  printf("The Sum of Your Numbers is: %d\n", userSum);
  printf("The Difference of Your Numbers is: %d\n", userDifference);
  printf("The Product of Your Numbers is: %d\n", userProduct);
  printf("The Quotient of Your Numbers is: %d\n", userQuotient);
  printf("The Modulus of Your Numbers is: %d\n", userModulus);

  printf("That was absolutely thrilling! Thanks for playing!\n");

  // End of program. Hope you had as much fun as we did!

  return 0;
}