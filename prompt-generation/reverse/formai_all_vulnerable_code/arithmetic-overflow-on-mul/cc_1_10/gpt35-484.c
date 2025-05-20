//FormAI DATASET v1.0 Category: Arithmetic ; Style: creative
#include <stdio.h>

int main()
{
  printf("Welcome to the Arithmetic Fun House!\n");
  printf("We're going to start with a little math quiz.\n");
  printf("What is 50 - 18?\n");

  int answer;
  scanf("%d", &answer);

  if(answer == 32)
  {
    printf("You're correct!\n");
  }
  else
  {
    printf("Sorry, that's incorrect. The correct answer is 32.\n");
  }

  printf("Now let's move onto some more complex math.\n");
  printf("Please enter a number.\n");

  int num1;
  scanf("%d", &num1);

  printf("Great! Now enter another number.\n");

  int num2;
  scanf("%d", &num2);

  int sum = num1 + num2;
  printf("The sum of %d and %d is %d.\n", num1, num2, sum);

  int diff = num1 - num2;
  printf("The difference between %d and %d is %d.\n", num1, num2, diff);

  int prod = num1 * num2;
  printf("The product of %d and %d is %d.\n", num1, num2, prod);

  if(num2 != 0)
  {
    float quot = (float)num1 / num2;
    printf("The quotient of %d and %d is %.2f.\n", num1, num2, quot);
  }
  else
  {
    printf("Sorry, you cannot divide by zero.\n");
  }

  printf("Thank you for playing along! Goodbye.\n");

  return 0;
}