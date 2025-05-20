//FormAI DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int numQuestions;
  printf("Let's do some math exercises!\n");
  printf("How many questions would you like to answer? ");
  scanf("%d", &numQuestions);

  // Seed random number generator with current time
  srand(time(NULL));

  int numCorrect = 0;
  for (int i = 0; i < numQuestions; i++) {
    // Generate two random numbers between 1 and 10
    int num1 = rand() % 10 + 1;
    int num2 = rand() % 10 + 1;

    // Generate random operator (+, -, or *)
    int operatorIndex = rand() % 3;
    char op;
    if (operatorIndex == 0) {
      op = '+';
    } else if (operatorIndex == 1) {
      op = '-';
    } else {
      op = '*';
    }

    // Prompt user for answer
    printf("Question %d: %d %c %d = ", i+1, num1, op, num2);
    int answer;
    scanf("%d", &answer);

    // Check answer and give feedback
    int correctAnswer;
    if (op == '+') {
      correctAnswer = num1 + num2;
    } else if (op == '-') {
      correctAnswer = num1 - num2;
    } else {
      correctAnswer = num1 * num2;
    }

    if (answer == correctAnswer) {
      numCorrect++;
      printf("Correct!\n");
    } else {
      printf("Incorrect! The correct answer is %d.\n", correctAnswer);
    }
  }

  // Give final score
  printf("You answered %d/%d questions correctly. Well done!\n", numCorrect, numQuestions);
  return 0;
}