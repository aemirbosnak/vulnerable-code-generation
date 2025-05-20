//FormAI DATASET v1.0 Category: Math exercise ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int a, b, op, ans, userAns, i;
  int correct = 0;

  printf("Welcome to Math exercise program\n");
  printf("Please enter the amount of questions you want to answer: ");
  scanf("%d", &i);

  srand(time(NULL));

  while (i-- > 0) {
    a = rand() % 100;
    b = rand() % 100;
    op = rand() % 4;

    switch (op) {
      case 0:
        printf("%d + %d = ", a, b);
        ans = a + b;
        break;
      case 1:
        printf("%d - %d = ", a, b);
        ans = a - b;
        break;
      case 2:
        printf("%d * %d = ", a, b);
        ans = a * b;
        break;
      case 3:
        printf("%d / %d = ", a*b, b);
        ans = a;
        break;
      default:
        printf("Invalid operator, please try again.\n");
        i++;
        continue;
    }

    scanf("%d", &userAns);

    if (userAns == ans) {
      printf("Correct!\n");
      correct++;
    } else {
      printf("Incorrect, the correct answer is %d.\n", ans);
    }
  }

  printf("You have answered %d out of %d questions correctly.\n", correct, i);

  return 0;
}