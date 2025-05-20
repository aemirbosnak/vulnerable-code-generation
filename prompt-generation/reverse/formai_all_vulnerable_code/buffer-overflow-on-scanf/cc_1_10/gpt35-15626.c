//FormAI DATASET v1.0 Category: Arithmetic ; Style: puzzling
#include <stdio.h>

int main() {
  int x = 10;
  int y = 2;
  printf("Let's start with a simple question:\n");
  printf("What is 10 divided by 2?\n");
  int ans1;
  scanf("%d", &ans1);

  if (ans1 == x / y) {
    printf("Well done! You're off to a good start.\n");
  } else {
    printf("Nope, try again.\n");
    printf("Hint: Think about the operator used for division.\n");
    int ans2;
    scanf("%d", &ans2);
    if (ans2 == x / y) {
      printf("Finally! You got it right.\n");
    } else {
      printf("Sorry, you're just not cut out for this.\n");
      printf("Let's move on to the next question:\n");
    }
  }

  printf("What is the result of 3 multiplied by 2 plus 7?\n");
  int ans3;
  scanf("%d", &ans3);

  if (ans3 == 13) {
    printf("Congratulations, you're doing great!\n");
  } else {
    printf("Not quite. Try again.\n");
    printf("Hint: Remember the order of operations.\n");
    int ans4;
    scanf("%d", &ans4);
    if (ans4 == 13) {
      printf("Phew! That was a close one.\n");
    } else {
      printf("Sorry, you're just not cut out for this.\n");
      printf("Let's move on to the next question:\n");
    }
  }

  printf("What is the result of 5 plus 5 minus 2?\n");
  int ans5;
  scanf("%d", &ans5);

  if (ans5 == 8) {
    printf("You're a math genius!\n");
  } else {
    printf("Not quite. Try again.\n");
    printf("Hint: Remember the order of operations.\n");
    int ans6;
    scanf("%d", &ans6);
    if (ans6 == 8) {
      printf("Finally! You're really making progress.\n");
    } else {
      printf("Sorry, you're just not cut out for this.\n");
      printf("Better luck next time!\n");
      return 0;
    }
  }

  printf("You have completed the arithmetic challenge!\n");
  printf("Congratulations on your math skills.\n");
  printf("Your reward is a cookie. Enjoy!\n");
  return 0;
}