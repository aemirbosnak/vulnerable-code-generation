//FormAI DATASET v1.0 Category: Arithmetic ; Style: excited
#include <stdio.h>

int main() {
  int num1, num2;
  printf("I am so excited to show you what I can do with some C arithmetic! Please enter two numbers: ");
  scanf("%d %d", &num1, &num2);
  
  int sum = num1 + num2;
  printf("The sum of %d and %d is %d!\n", num1, num2, sum);
  
  int diff = num1 - num2;
  if (diff < 0) {
    diff = -diff;
    printf("But don't worry, I made the difference positive for you.\n");
  }
  printf("The difference between %d and %d is %d!\n", num1, num2, diff);
  
  int prod = num1 * num2;
  printf("The product of %d and %d is %d!\n", num1, num2, prod);
  
  double quot;
  if (num2 == 0) {
    printf("Oops, can't divide by zero. Please enter a nonzero number: ");
    scanf("%d", &num2);
  }
  quot = (double)num1 / num2;
  printf("The quotient of %d and %d is %.2f!\n", num1, num2, quot);
  
  int mod = num1 % num2;
  printf("The remainder when %d is divided by %d is %d!\n", num1, num2, mod);
  
  printf("Wow, that was amazing don't you think? Do you want to try again? Type 'y' for yes or 'n' for no: ");
  char ans;
  scanf(" %c", &ans);
  
  while (ans == 'y') {
    printf("Great! Let's do some more math. Please enter two numbers again: ");
    scanf("%d %d", &num1, &num2);
    
    sum = num1 + num2;
    printf("The sum of %d and %d is %d!\n", num1, num2, sum);
    
    diff = num1 - num2;
    if (diff < 0) {
      diff = -diff;
      printf("But don't worry, I made the difference positive for you.\n");
    }
    printf("The difference between %d and %d is %d!\n", num1, num2, diff);
    
    prod = num1 * num2;
    printf("The product of %d and %d is %d!\n", num1, num2, prod);
    
    if (num2 == 0) {
      printf("Oops, can't divide by zero. Please enter a nonzero number: ");
      scanf("%d", &num2);
    }
    quot = (double)num1 / num2;
    printf("The quotient of %d and %d is %.2f!\n", num1, num2, quot);
    
    mod = num1 % num2;
    printf("The remainder when %d is divided by %d is %d!\n", num1, num2, mod);
    
    printf("That was so much fun! Do you want to try again? Type 'y' for yes or 'n' for no: ");
    scanf(" %c", &ans);
  }
  
  printf("Aww, you don't want to do any more math? That's okay, we had a great time. See you later!\n");
  
  return 0;
}