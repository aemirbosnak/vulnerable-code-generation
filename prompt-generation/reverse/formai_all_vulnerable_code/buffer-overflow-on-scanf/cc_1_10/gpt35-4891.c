//FormAI DATASET v1.0 Category: Math exercise ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num1, num2, op, ans, user_ans, correct_ans = 0, total_ans = 0;
  char operator[4] = "+-*/";

  printf("Welcome to the Math Exercise Program! Here you'll be given random math problems to solve.\n\n");

  // Use srand to get different random numbers every time the program runs
  srand(time(NULL));

  // Loop through 10 math problems
  for (int i = 1; i <= 10; i++) {
    num1 = rand() % 20 + 1; // Random number between 1 and 20
    num2 = rand() % 20 + 1; // Random number between 1 and 20
    op = rand() % 4; // Random operator (+, -, *, /)

    // Evaluate the math problem based on the random numbers and operator
    switch (operator[op]) {
      case '+':
        ans = num1 + num2;
        break;
      case '-':
        ans = num1 - num2;
        break;
      case '*':
        ans = num1 * num2;
        break;
      case '/':
        ans = num1 / num2;
        break;
    }

    // Ask the user to solve the problem
    printf("Question %d: %d %c %d = ", i, num1, operator[op], num2);
    scanf("%d", &user_ans);

    total_ans++;

    // Check if the user's answer is correct
    if (ans == user_ans) {
      printf("Correct!\n");
      correct_ans++;
    } else {
      printf("Incorrect. The answer is %d.\n", ans);
    }

    printf("\n");
  }

  // Print the user's score
  printf("You got %d out of %d correct. Your score is %.2f%%", correct_ans, total_ans, ((float)correct_ans/total_ans) * 100);

  return 0;
}