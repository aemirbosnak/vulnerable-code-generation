//FormAI DATASET v1.0 Category: Math exercise ; Style: detailed
/* This program generates a random Math exercise program for students, which contains
addition, subtraction, multiplication and division questions.
The program also calculates the time taken by the student to complete the quiz and returns a grade. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int numQuestions, correctAnswers = 0, answer, flag, op, num1, num2;
  float score;
  clock_t t1, t2;
  
  printf("Welcome to the Math Exercise Program\n");
  
  printf("Enter the number of questions you want to practice: ");
  scanf("%d", &numQuestions);
  
  t1 = clock(); // Start timer
  
  for(int i = 1; i <= numQuestions; i++) {
    
    // Generate random numbers and operator
    num1 = rand() % 51;
    num2 = rand() % 51;
    op = rand() % 4;
    
    switch(op) {
      case 0: // Addition question
        printf("%d. %d + %d = ", i, num1, num2);
        answer = num1 + num2;
        break;
      case 1: // Subtraction question
        printf("%d. %d - %d = ", i, num1, num2);
        answer = num1 - num2;
        break;
      case 2: // Multiplication question
        printf("%d. %d x %d = ", i, num1, num2);
        answer = num1 * num2;
        break;
      case 3: // Division question
        flag = 0;
        do {
          num1 = rand() % 101;
          num2 = rand() % 51 + 1;
          if(num1 % num2 == 0) {
            flag = 1;
            break;
          }
        } while(flag != 1);
        printf("%d. %d / %d = ", i, num1, num2);
        answer = num1 / num2;
        break;
    }
    
    // Take user input and check answer
    int userAnswer;
    scanf("%d", &userAnswer);
    if(userAnswer == answer) {
      printf("Correct!\n");
      correctAnswers++;
    }
    else {
      printf("Incorrect! The correct answer is %d\n", answer);
    }
  }
  
  t2 = clock(); // Stop timer
  
  // Calculate and print score
  score = (float) correctAnswers / numQuestions * 100;
  printf("Your score is %.2f\n", score);
  
  // Calculate and print time taken
  float timeTaken = (float)(t2 - t1) / CLOCKS_PER_SEC;
  printf("You took %.2f seconds to complete the quiz\n", timeTaken);
  
  // Give a grade based on score
  if(score >= 90) {
    printf("Congratulations! You got an A+!\n");
  }
  else if(score >= 80) {
    printf("Well done! You got an A!\n");
  }
  else if(score >= 70) {
    printf("Good job! You got a B!\n");
  }
  else if(score >= 60) {
    printf("Not bad! You got a C!\n");
  }
  else {
    printf("Sorry, you failed. You need to practice more.\n");
  }
  
  return 0;
}