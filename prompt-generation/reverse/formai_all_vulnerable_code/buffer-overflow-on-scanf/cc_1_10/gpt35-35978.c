//FormAI DATASET v1.0 Category: Math exercise ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Generate random numbers to use in the exercise
  srand(time(NULL));
  int num1 = rand() % 100 + 1;
  int num2 = rand() % 100 + 1;
  
  // Get the user's answer
  int answer;
  printf("What is the product of %d and %d?\n", num1, num2);
  scanf("%d", &answer);
  
  // Calculate the correct answer and check if it matches the user's answer
  int correct_answer = num1 * num2;
  if (answer == correct_answer) {
    printf("Correct! %d times %d is %d.\n", num1, num2, correct_answer);
  } else {
    printf("Incorrect! %d times %d is %d, not %d.\n", num1, num2, correct_answer, answer);
  }
  
  // Repeat with a division exercise
  num1 = rand() % 100 + 1;
  num2 = rand() % 10 + 1;
  
  printf("What is %d divided by %d, to the nearest whole number?\n", num1, num2);
  scanf("%d", &answer);
  
  correct_answer = num1 / num2;
  if (answer == correct_answer) {
    printf("Correct! %d divided by %d is %d.\n", num1, num2, correct_answer);
  } else {
    printf("Incorrect! %d divided by %d is %d, not %d.\n", num1, num2, correct_answer, answer);
  }
  
  // Repeat with a subtraction exercise
  num1 = rand() % 100 + 1;
  num2 = rand() % 100 + 1;
  
  printf("What is %d minus %d?\n", num1, num2);
  scanf("%d", &answer);
  
  correct_answer = num1 - num2;
  if (answer == correct_answer) {
    printf("Correct! %d minus %d is %d.\n", num1, num2, correct_answer);
  } else {
    printf("Incorrect! %d minus %d is %d, not %d.\n", num1, num2, correct_answer, answer);
  }
  
  return 0;
}