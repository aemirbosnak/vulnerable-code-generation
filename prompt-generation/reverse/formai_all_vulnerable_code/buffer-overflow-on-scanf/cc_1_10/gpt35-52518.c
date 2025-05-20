//FormAI DATASET v1.0 Category: Math exercise ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num1, num2, op, answer, correct=0, wrong=0;

  srand(time(NULL)); // Seed random number generator with current time

  printf("Welcome to the Math Exercise program!\n");

  while (1) { // Infinite loop
    num1 = rand() % 100; // Generate random number between 0 and 99
    num2 = rand() % 100; // Generate another random number between 0 and 99

    op = rand() % 4; // Choose random operator: 0:+, 1:-, 2:*, 3:/

    switch (op) {
      case 0:
        printf("%d + %d = ", num1, num2);
        answer = num1 + num2;
        break;
      case 1:
        printf("%d - %d = ", num1, num2);
        answer = num1 - num2;
        break;
      case 2:
        printf("%d * %d = ", num1, num2);
        answer = num1 * num2;
        break;
      case 3:
        printf("%d / %d = ", num1*num2, num2); // Make the dividend a multiple of the divisor
        answer = num1;
        break;
    }

    int user_answer;
    scanf("%d", &user_answer);

    if (user_answer == answer) {
      printf("Correct! Great job!\n");
      correct++;
    } else {
      printf("Wrong answer! The correct answer is %d. Better luck next time!\n", answer);
      wrong++;
    }

    printf("You have answered %d questions correctly and %d questions incorrectly.\n", correct, wrong);

    printf("Do you want to continue? (y/n): ");
    char choice;
    scanf(" %c", &choice); // The space before %c is important to ignore whitespace characters

    if (choice == 'n' || choice == 'N') {
      printf("Thank you for using the Math Exercise program! Goodbye!\n");
      break; // Break out of the loop
    }
  }

  return 0;
}