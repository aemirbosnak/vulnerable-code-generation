//FormAI DATASET v1.0 Category: Arithmetic ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num1, num2, ans;
  char op;
  srand(time(NULL));

  printf("Let's play a game of arithmetic!\n");
  printf("Type 'q' to quit.\n");

  while (1) {
    num1 = rand() % 100;
    num2 = rand() % 100;

    switch (rand() % 4) {
      case 0:
        op = '+';
        ans = num1 + num2;
        break;
      case 1:
        op = '-';
        ans = num1 - num2;
        break;
      case 2:
        op = '*';
        ans = num1 * num2;
        break;
      case 3:
        op = '/';
        ans = num1 / num2;
        break;
    }

    printf("%d %c %d = ", num1, op, num2);

    int user_ans;
    scanf("%d", &user_ans);

    if (user_ans == ans) {
      printf("Correct!\n");
    } else if (user_ans == 'q' || user_ans == 'Q') {
      printf("Thanks for playing.");
      break;
    } else {
      printf("Incorrect. The answer is %d.\n", ans);
    }
  }
  return 0;
}