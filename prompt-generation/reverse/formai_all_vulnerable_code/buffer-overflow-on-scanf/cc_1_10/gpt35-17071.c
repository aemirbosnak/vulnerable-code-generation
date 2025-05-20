//FormAI DATASET v1.0 Category: Online Examination System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int choice, score = 0;

  printf("Welcome to the C Programming Language Online Exam System!\n\n");

  // ask user if they are ready to start
  printf("Are you ready to start the exam?\n");
  printf("1. Yes\n2. No\n");
  scanf("%d", &choice);

  // if user is not ready, exit the program
  if (choice == 2) {
    printf("Come back when you are ready. Goodbye!");
    exit(0);
  }

  // if user is ready, start the exam
  printf("The exam has started!\n\n");

  // use current time as seed for random number generation
  srand(time(0));

  // generate 10 random questions and check user's answers
  for (int i = 1; i <= 10; i++) {
    int num1 = rand() % 101; // generate number between 0 and 100
    int num2 = rand() % 101;
    int correct_answer = num1 + num2;

    printf("Question %d:\nWhat is %d + %d?\n", i, num1, num2);

    int user_answer;
    scanf("%d", &user_answer);

    if (user_answer == correct_answer) {
      printf("Correct!\n");
      score++;
    }
    else {
      printf("Incorrect. The correct answer is %d.\n", correct_answer);
    }
  }

  // display final score
  printf("\nYour final score is %d/10. Thanks for taking the exam!\n", score);

  return 0;
}