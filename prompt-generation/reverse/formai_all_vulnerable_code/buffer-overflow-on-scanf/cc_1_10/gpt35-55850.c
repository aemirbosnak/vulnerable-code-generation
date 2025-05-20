//FormAI DATASET v1.0 Category: Math exercise ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int correctCount = 0;
  int wrongCount = 0;

  srand(time(NULL));

  printf("Welcome to Math Exercise!\n");

  while (1) {
    int num1 = rand() % 10 + 1;
    int num2 = rand() % 10 + 1;
    int operation = rand() % 3 + 1;
    int answer;
    char op;

    switch (operation) {
      case 1:
        answer = num1 + num2;
        op = '+';
        break;
      case 2:
        answer = num1 - num2;
        op = '-';
        break;
      case 3:
        answer = num1 * num2;
        op = '*';
        break;
    }

    printf("\nWhat is %d %c %d?\n", num1, op, num2);

    int userAnswer;
    scanf("%d", &userAnswer);

    if (userAnswer == answer) {
      printf("Correct!\n");
      correctCount++;
    } else {
      printf("Wrong! The answer is %d.\n", answer);
      wrongCount++;
    }

    printf("Score: %d/%d\n", correctCount, correctCount + wrongCount);
    printf("Press Q to quit or any key for next question.\n");

    char choice;
    scanf(" %c", &choice);

    if (choice == 'q' || choice == 'Q') {
      printf("Thanks for playing!\n");
      break;
    }
  }

  return 0;
}