//FormAI DATASET v1.0 Category: Math exercise ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num1, num2, operator, answer, userAns;
  char operators[] = {'+', '-', '*', '/'};
  char operatorSign;
  int numOfQuestions, numOfCorrect = 0, i;

  srand(time(NULL));

  puts("Welcome to Math Challenge!\n");
  puts("This program will give you a set of math exercises to solve.");
  puts("You will have to answer each question as quickly as possible.");
  puts("Are you ready to begin?\n");

  puts("How many questions would you like to answer?");
  scanf("%d", &numOfQuestions);

  for(i = 0; i < numOfQuestions; i++) {
    num1 = rand() % 101;
    num2 = rand() % 101;
    operator = rand() % 4;

    operatorSign = operators[operator];

    if(operator == 0) {
      answer = num1 + num2;
    }
    else if(operator == 1) {
      answer = num1 - num2;
    }
    else if(operator == 2) {
      answer = num1 * num2;
    }
    else {
      answer = num1 / num2;
    }

    printf("Question #%d: %d %c %d = ", i+1, num1, operatorSign, num2);
    scanf("%d", &userAns);

    if(userAns == answer) {
      puts("Correct! Great job!");
      numOfCorrect++;
    }
    else {
      puts("Sorry, that is incorrect.");
      printf("The correct answer is: %d\n", answer);
    }
    puts("");
  }

  puts("Congratulations on completing the Math Challenge!");
  printf("You answered %d out of %d questions correctly.\n", numOfCorrect, numOfQuestions);

  return 0;
}