//FormAI DATASET v1.0 Category: Math exercise ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_QUESTIONS 10 // Number of questions in the quiz

int main() {
  srand(time(NULL)); // Seed random number generator with current time
  int score = 0; // Initialize score counter to 0
  
  printf("Welcome to the Math Quiz!\n");
  
  for (int i = 0; i < NUM_QUESTIONS; i++) {
    int num1 = rand() % 10 + 1; // Generate random number between 1 and 10
    int num2 = rand() % 10 + 1; // Generate second random number between 1 and 10
    int operator = rand() % 4; // Generate random number between 0 and 3 to represent operator
    
    double answer; // Declare variable to hold user's answer
    
    switch(operator) {
      case 0: // Addition
        printf("What is %d + %d? ", num1, num2);
        answer = num1 + num2;
        break;
      case 1: // Subtraction
        printf("What is %d - %d? ", num1, num2);
        answer = num1 - num2;
        break;
      case 2: // Multiplication
        printf("What is %d * %d? ", num1, num2);
        answer = num1 * num2;
        break;
      case 3: // Division
        printf("What is %d / %d (rounded to 2 decimal places)? ", num1, num2);
        answer = (double) num1 / (double) num2;
        answer = roundf(answer * 100) / 100; // Round to 2 decimal places
        break;
    }
    
    double user_answer;
    scanf("%lf", &user_answer);
    
    if (user_answer == answer) {
      printf("Correct!\n");
      score++; // Increase score counter if answer is correct
    } else {
      printf("Incorrect. The correct answer is %.2lf\n", answer);
    }
  }
  
  printf("Your final score is %d/%d", score, NUM_QUESTIONS);
  
  return 0;
}