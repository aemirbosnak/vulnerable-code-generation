//FormAI DATASET v1.0 Category: Funny ; Style: surprised
#include <stdio.h>

int main() {
  int num1 = 10;
  int num2 = 20;
  int sum = num1 + num2;

  printf("The sum of %d and %d is %d\n", num1, num2, sum);
  
  if(sum%2==0) {
    printf("Wow, the sum is even!\n");
  }
  else {
    printf("What a surprise, the sum is odd!\n");
  }

  char c = 'A';
  printf("The ASCII value of %c is %d\n", c, c);

  int a = 10;
  int b = 20;
  int *ptr1 = &a;
  int *ptr2 = &b;

  printf("Value of *ptr1 = %d\n", *ptr1);
  printf("Value of *ptr2 = %d\n", *ptr2);

  printf("Swapping values using pointers...\n");
  int temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;

  printf("Value of *ptr1 after swap = %d\n", *ptr1);
  printf("Value of *ptr2 after swap = %d\n", *ptr2);

  printf("Now, let's play a game. Guess the number!\n");
  int secret_num = 42;
  int guess;

  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    
    if(guess<secret_num) {
      printf("Too low, try again!\n");
    }
    else if(guess>secret_num) {
      printf("Too high, try again!\n");
    }
    else {
      printf("Congratulations, you guessed the secret number %d!\n", secret_num);
    }
  } while(guess!=secret_num);

  printf("All done, program exiting. Surprised?\n");

  return 0;
}