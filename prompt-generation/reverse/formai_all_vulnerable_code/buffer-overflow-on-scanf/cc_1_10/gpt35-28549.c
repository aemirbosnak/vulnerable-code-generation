//FormAI DATASET v1.0 Category: Math exercise ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  int x, y, z, answer;
  
  srand(time(NULL)); // initialize the random number generator
  
  printf("Welcome to the Math Exercise!\n");
  printf("You will be given a series of mathematical problems to solve.\n");
  printf("Let's begin!\n\n");
  
  for(int i=1; i<=10; i++) // generate 10 questions in total
  {
    x = rand() % 20 + 1; // generate a random number between 1 and 20
    y = rand() % 20 + 1;
    z = rand() % 2;
    
    if(z == 0) { // addition question
      
      printf("Question %d: What is %d + %d?\n", i, x, y);
      printf("Answer: ");
      scanf("%d", &answer);
      
      if(answer == x+y) {
        printf("Correct!\n\n");
      }
      else {
        printf("Incorrect. The correct answer is %d.\n\n", x+y);
      }
    }
    else { // subtraction question
      
      printf("Question %d: What is %d - %d?\n", i, x, y);
      printf("Answer: ");
      scanf("%d", &answer);
      
      if(answer == x-y) {
        printf("Correct!\n\n");
      }
      else {
        printf("Incorrect. The correct answer is %d.\n\n", x-y);
      }
    }
  }
  
  printf("Congratulations! You completed all 10 questions.\n");
  
  return 0;
}