//FormAI DATASET v1.0 Category: Funny ; Style: active
#include <stdio.h>

int main() {
  printf("Welcome to the wacky world of numbers!\n\n");

  int num1, num2, num3, sum, prod;

  printf("Please enter the first number: ");
  scanf("%d", &num1);

  printf("Please enter the second number: ");
  scanf("%d", &num2);

  printf("Please enter the third number: ");
  scanf("%d", &num3);

  sum = num1 + num2 + num3;
  printf("\nThe sum of the three numbers is: %d\n", sum);

  prod = num1 * num2 * num3;
  printf("\nThe product of the three numbers is: %d\n", prod);

  printf("Now, let's get a little wacky!\n\n");

  int wacky_num1 = num1 % 2;
  int wacky_num2 = num2 % 2;
  int wacky_num3 = num3 % 2;

  if (wacky_num1 == 0 && wacky_num2 == 0 && wacky_num3 == 0) {
    printf("Wow, all three numbers are even! That's so boring...\n");
  } else if (wacky_num1 == 1 && wacky_num2 == 1 && wacky_num3 == 1) {
    printf("Whoa, all three numbers are odd! That's pretty uncommon.\n");
  } else {
    printf("This is getting interesting...we have a mix of even and odd numbers!\n");
  }

  printf("\nHold on tight, we're about to get even wackier...\n\n");

  int big_num = num1;

  if (num2 > big_num) {
    big_num = num2;
  }

  if (num3 > big_num) {
    big_num = num3;
  }

  printf("The biggest number entered is: %d\n", big_num);

  printf("\nPrepare yourself for the wackiest part!\n\n");

  int wacky_sum = 0;
  int counter = 0;

  while (counter <= big_num) {
    wacky_sum = wacky_sum + counter;
    counter++;
  }

  printf("The sum of the numbers from 0 to %d is: %d\n", big_num, wacky_sum);

  printf("\nWhat a wild ride! Thanks for playing with numbers!\n\n");

  return 0;
}