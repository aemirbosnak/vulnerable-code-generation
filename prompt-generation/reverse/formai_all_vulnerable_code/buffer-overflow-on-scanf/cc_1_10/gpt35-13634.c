//FormAI DATASET v1.0 Category: Math exercise ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.141592

int main() {
  
  printf("Welcome to the math exercise program!\n");
  
  int count = 0;
  double ans;
  double num1, num2;
  char operator;
  
  srand(time(NULL));
  
  while(count < 10) {
    
    // Generate two random numbers between -10 and 10
    num1 = (double) (rand() % 21) - 10;          
    num2 = (double) (rand() % 21) - 10;
    
    // Generate a random operator (+, -, *, /, or %)
    switch(rand() % 5) {
      case 0:
        operator = '+';
        ans = num1 + num2;
        break;
      case 1:
        operator = '-';
        ans = num1 - num2;
        break;
      case 2:
        operator = '*';
        ans = num1 * num2;
        break;
      case 3:
        operator = '/';
        ans = num1 / num2;
        break;
      case 4:
        operator = '%';
        ans = fmod(num1,num2);
        break;
    }
    
    // Ask the user for the answer and check if it's correct
    printf("Question %d: %lf %c %lf = ",count+1,num1,operator,num2);
    double guess;
    scanf("%lf",&guess);
    
    if(guess == ans) {
      printf("Correct!\n\n");
      count++;
    } else if(fabs(guess - ans) < 0.000001) {     // Account for floating point errors
      printf("Almost there, but not quite! The answer was %lf.\n\n",ans);
    } else {
      printf("Incorrect. The answer was %lf.\n\n",ans);
    }
    
  }
  
  printf("Congratulations, you've completed the math exercise program!\n");
  
  return 0;
}