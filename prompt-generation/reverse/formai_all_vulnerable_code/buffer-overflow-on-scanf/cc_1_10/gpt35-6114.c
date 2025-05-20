//FormAI DATASET v1.0 Category: Math exercise ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

// function to generate random numbers between 1 and 50
int randomNumber() {
  return rand() % 50 + 1;
}

int main() {

  // initialize variables for the game
  int num1, num2, answer, userAnswer, count = 0;
  char operator[4] = {'+', '-', '*', '/'};

  // seed the random number generator
  srand(time(0));

  printf("Welcome to Math Exercise Program \n\n");

  // loop through 10 questions
  for (int i = 0; i < 10; i++) {

    // set the operation randomly
    char op = operator[rand() % 4];

    // generate two random numbers
    num1 = randomNumber();
    num2 = randomNumber();

    // show the question to the user
    printf("Question %d: What is %d %c %d? ", i+1, num1, op, num2);

    // get the answer
    scanf("%d", &userAnswer);

    // calculate the answer based on the operation and the numbers
    switch(op) {
      case '+':
        answer = num1 + num2;
        break;
      case '-':
        answer = num1 - num2;
        break;
      case '*':
        answer = num1 * num2;
        break;
      case '/':
        answer = num1 / num2;
        break;
    }

    // check if the user's answer is correct
    if (answer == userAnswer) {
      printf("Correct! \n\n");
      count++;
    } else {
      printf("Incorrect. The correct answer is %d \n\n", answer);
    }
  }

  // show the user's score
  printf("You scored %d out of 10!\n", count);
  
  return 0;
}